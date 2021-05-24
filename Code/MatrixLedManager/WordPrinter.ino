void animWord(int **yourWord, int letters, int startingCol, int endCol, int cycles){
  if (startingCol < endCol){
  	for (int i = startingCol; i <= endCol; i++){
  		drawWord(yourWord, letters, i, cycles);
  	}
  }else{
    for (int i = startingCol; i >= endCol; i--){
      drawWord(yourWord, letters, i, cycles);
    }
  }
}

/**
 * Given a word, prints it sequencially.
 * @param yourWord     : the word to print. REQUIRE to be a valid word.
 * @param letters      : the number of letters contained in the word.
 * @param cycles       : the number of times that each letter is printed.
 * @param startingCol  : The column on which the function starts to print on. 
 *                       REQUIRE to be a valid column index.
 */
void drawWord(int **yourWord, int letters, int startingCol, int cycles){
  /*
   * Example:
   * fullSequence = {
   *  {101010, ......., 1001000}  //all sequences for row 1
   *  {101010, ......., 1001000}  //all sequences for row 2
   *  ...
   *  {101010, ......., 1001000}  //all sequences for row totalRows
   *  }
   *  
   *  fullSequnce[0] = {1010, 101010, ..., 1010}       //meaning row 0
   *                    fullSequence[0][0]             //the binary seqeunce for yourWord[0][2]
   *                                                   //meaning first letter and first binarySequence (meaning first row of first letter)
   *                                                   
   *  fullSequnce[i] = {1010, 101010, ..., 1010}       //meaning row i
   *                    fullSequence[i][j]             //the binary seqeunce for yourWord[j][2+i]
   *                                                   //meaning letter j and so (2+i) binarySequence  (meaning row 2+i of letter j)
   *  
   */
  int fullSequence[ROWS][letters] = {};
  int colsPerLetter[letters];
  int totalCols = 0;

  //producing fullSequence
  //aka merging letters
  for (int i = 0; i < ROWS; i++){        //scanning rows           
    for (int j = 0; j < letters; j++){   //scanning letters
      // yourWord[j]         is letter j
      // yourWord[j][i+2]    is letter j in row i
      // fullSequence[i][j]  is a "small" row
      // we need to copy the rows of letter i in 
      // the corresponding "small" rows of fullSequence

      fullSequence[i][j] = yourWord[j][i+2];
      fullSequence[i][j] = fullSequence[i][j] << WORD_SAPCES; //adding spaces

      if (i == 0){
      	  // col for letter j
      	  // equals to letter_j[1]
          colsPerLetter[j] = yourWord[j][1] + WORD_SAPCES; //adding spaces
          totalCols += colsPerLetter[j];
          //we do that just 1 time per letter 
          //aka i = 0
      }
    }
  }
  
  int activePerRow[6] = {};  //number of led activated in the row i
  int activeTot = 0;         //number of total leds activated
  int delPerRow[ROWS] =  {}; //time we can give to the row i
  int delTot = 19000;        //time we can give to entire matrix
  
  int currentCol = 0, jcol = 0, c = 0, actives = 0;
  for (int k = 0; k < ROWS; k++){
    currentCol = startingCol;
    actives = 0;
    for (int j = 0; j < letters; j++){
      jcol = colsPerLetter[j];
      for (int i = 0; i < jcol && currentCol < COLS; i++){
        c = bitRead(fullSequence[k][j], jcol-i-1);
        if(currentCol >= 0 && c == 1){
          actives++;
        }
        currentCol++;
      }
    }

    activePerRow[k] = actives;
    activeTot += actives;
  }
  
  for (int i = 0; i < 6; i++){
    delPerRow[i] = (int)((float)((float)activePerRow[i]/(float)activeTot)*delTot);
  }
  
  //calling drawBigRow
  for (int j = 0; j < cycles; j++){
    for(int i = 0; i < ROWS; i++){
          drawBigRow(fullSequence[i], i, letters, totalCols, colsPerLetter, startingCol, delPerRow[i]);
  }}
}


/*PRIVATE METHOD, CALLED BY DRAWWORD.*/
void drawBigRow(int *bigRow, int currentRow, int letters, int totalCols, int *colsPerLetter, int startingCol, int del){
  int c = 0;
  //we need currentcol because i is relative to each letter
  int currentCol = startingCol;

  for (int j = 0; j < letters; j++){
    //j is a row of letter j
    int jcol = colsPerLetter[j];
    for (int i = 0; i < jcol && currentCol < COLS; i++){
      //bitRead(...,0)      -> LSB
      //bitread(...,jcol-1) -> MSB
      //c is the i of letter j in the current row
      c = bitRead(bigRow[j], jcol-i-1);
      if(currentCol >= 0 && c == 1){
	      digitalWrite(cols[currentCol], COL_ENABLED);
	    }
      currentCol++;
    }
  }
  //start row
  digitalWrite(rows[currentRow], ROW_ENABLED);
  delayMicroseconds(del);
  //end row
  digitalWrite(rows[currentRow], ROW_DISABLED);
  //end cols
  resetCols(0, COLS-1); //VERY IMPORTANT
}
