void animLetter(int *letter, int startingCol, int endCol, int cycles){
	for (int i = startingCol; i <= endCol; i++){
		drawLetter(letter, i, cycles);
	}
}

void animWordInPlace(int **yourWord, int letters, int startingCol, int endCol, int cycles){
  for (int i = 0; i < letters; i++){
    animLetter(yourWord[i], startingCol, endCol, cycles);
  }
}

/**
 * Given a word, prints it starting each letter by the same column.
 * @param yourWord     : the word to print. REQUIRE to be a valid word.
 * @param letters      : the number of letters contained in the word.
 * @param cycles       : the number of cycles that each letter is printed.
 * @param startCol     : The column on which the function starts to print on. 
 *                       REQUIRE to be a valid column index.
 */
//INVARIANT: for the correctness of drawLetter, AFTER EXECUTIONS, LEAVES A RESETTED MATRIX
void drawWordInPlace(int **yourWord, int letters, int startingCol, int cycles){
  for (int i = 0; i < letters; i++) 
    drawLetter(yourWord[i], startingCol, cycles);
}

/**
 * Given letter, draws it to the matrix @cycles times starting by @startCOl.
 * @param letter       : the letter to print. REQUIRE to be a valid letter.
 * @param cycles       : the number of times that @param letter is printed.
 * @param startCol     : The column on which the function starts to print on. 
 *                       REQUIRE to be a valid column index.
 */
//INVARIANT: for the correctness of drawRow, AFTER EXECUTIONS, LEAVES A RESETTED MATRIX
void drawLetter(int *letter, int startingCol, int cycles){
  int numberOfRows = letter[0];
  int numberOfCols = letter[1];
  for (int j = 0; j < cycles; j++){
      for(int i = 2; i < numberOfRows + 2; i++){
        drawRow(letter[i], i-2, startingCol, numberOfCols);
   }}
}


//INVARIANT: AFTER EXECUTIONS, LEAVES A RESETTED MATRIX
/*PRIVATE METHOD, CALLED BY DRAWLETTER.*/
void drawRow(int sequence, int currentRow, int startingCol, int numberOfCols){
  int c, i;
  for (i = 0; i < numberOfCols + 0 && i<COLS; i++){
    int n = numberOfCols-i-1+startingCol;
    if(n >= 0 && n < numberOfCols){
      c = bitRead(sequence, n);
      if (c == 1){
        //start col
        digitalWrite(cols[i], COL_ENABLED);
      }else {
        digitalWrite(cols[i], COL_DISABLED);
      }
    }
  }
  
  //start row
  digitalWrite(rows[currentRow], ROW_ENABLED);
  delay(1);
  //end row
  digitalWrite(rows[currentRow], ROW_DISABLED);
  
  // end cols
  // VERY IMPORTANT
  // otherwise col remains active
  resetCols(0, COLS-1); 
}
