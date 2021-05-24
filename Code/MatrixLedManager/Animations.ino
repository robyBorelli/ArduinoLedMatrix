void scanf_anim(float s){
  float del = (s/(ROWS*COLS))*1000;
  for (int i = 0; i < ROWS; i++){
    digitalWrite(rows[i], ROW_ENABLED);
    for (int j = 0; j < COLS; j++){
      digitalWrite(cols[j], COL_ENABLED);
      delay((int)del);
      digitalWrite(cols[j], COL_DISABLED);
    }
    digitalWrite(rows[i], ROW_DISABLED);
  }
}

void fill_anim(float s){
  float del = (s/(ROWS*COLS))*1000;
  for (int i = 0; i < ROWS; i++){
    digitalWrite(rows[i], ROW_ENABLED);
    for (int j = 0; j < COLS; j++){
      digitalWrite(cols[j], COL_ENABLED);
      delay((int)del);
    }

    for (int j = 0; j < COLS; j++){
      digitalWrite(cols[j], COL_DISABLED);
    }
  }

  for (int i = 0; i < ROWS; i++){
    digitalWrite(rows[i], ROW_DISABLED);
  }
}
