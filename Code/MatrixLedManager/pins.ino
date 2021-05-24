void reset(){
  resetRows(0, ROWS-1);
  resetCols(0, COLS-1);
}

void configPins(){
  for (int i = 0; i < ROWS; i++){
    pinMode(rows[i], OUTPUT); 
  }
  for (int i = 0; i < COLS; i++){
    pinMode(cols[i], OUTPUT);  
  }
}

/**
 * reset rows from k to j both inclusive
 */
void resetRows(int k, int j){
  for(int i = k; i <= j; i++)
      digitalWrite(rows[i], ROW_DISABLED);
}

/**
 * reset cols from k to j both inclusive
 */
void resetCols(int k, int j){
  for(int i = k; i <= j; i++)
      digitalWrite(cols[i], COL_DISABLED);
}
