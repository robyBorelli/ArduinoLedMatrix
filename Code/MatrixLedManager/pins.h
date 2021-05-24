//if + is on cols
int ROW_ENABLED   = LOW;
int ROW_DISABLED  = HIGH;
int COL_ENABLED   = HIGH;
int COL_DISABLED  = LOW;
//------------------------

//uncomment if + is on rows
//int ROW_ENABLED   = HIGH;
//int ROW_DISABLED  = LOW;
//int COL_ENABLED   = LOW;
//int COL_DISABLED  = HIGH;
//------------------------

int ROWS = 6;    //the number of phisical rows
int COLS = 24;   //the number of phisical columns
int PINS = 30;   //COLS + ROWS

int WORD_SAPCES = 2; //how many spaces between letters of the same word?

/*ARDUINO PINS--------------------------------------*/ 
int rows[] = {37, 39, 41, 43, 45, 47};//from up to bottom    r0 r1 r2 r3 r4...
int cols[] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,35,33,34,36,38,40,42,44,46}; //from left to right   c0 c1 c2 c3...

//Example: you have a matrix of 5 rows and 4 columns
//int cols[] = {5,4,3,2};     //from left to right   c0 c1 c2 c3...
//int rows[] = {11,10,9,8,7}; //from up to bottom    r0 r1 r2 r3 r4...