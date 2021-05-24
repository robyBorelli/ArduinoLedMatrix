/*
 * A VAILID LETTER is an array of integers and should be formatted as follows:
 * int LETTER[] = {#rows, #cols, binary sequences}; 
 *         --> #rows and #cols are the numbers of row and columns used by LETTER.
 *         --> Each binary sequence rapresents the state of a row, so there are #row binary sequences.
 *         --> Binary sequences are contained in LETTER[2...2+#rows].
 *         --> "1" in pos j of LETTER[i+2] meanas that the led in row i and col j is active.
 * example:
 * int A[] = {5, 4, 0b0110, 0b1001, 0b1111, 0b1001, 0b1001};
 *         --> A[0]=5.              There are 5 binarry sequences (1 for each row).
 *         --> A[1]=4.              Each binary sequence have 4 digits (1 for each col).
 *         --> A[3+2]=A[5]=0b1001   Represents the state of leds in row i-2=5-2=3.
 *         --> The first and the last leds of row 3 are turned on.
 */

/*LETTERS-------------------------------------------*/
int A[] = {5, 4, 0b0110, 0b1001, 0b1111, 0b1001, 0b1001};
int B[] = {5, 4, 0b1110, 0b1010, 0b1111, 0b1001, 0b1111};
int C[] = {5, 4, 0b1111, 0b1000, 0b1000, 0b1000, 0b1111};
int D[] = {5, 4, 0b1110, 0b1001, 0b1001, 0b1001, 0b1110};
int E[] = {5, 4, 0b1111, 0b1000, 0b1111, 0b1000, 0b1111};
int F[] = {5, 4, 0b1111, 0b1000, 0b1110, 0b1000, 0b1000};
int G[] = {5, 4, 0b1110, 0b1000, 0b1011, 0b1001, 0b1111};
int H[] = {5, 4, 0b1001, 0b1001, 0b1111, 0b1001, 0b1001};
int I[] = {5, 3, 0b111,  0b010,  0b010,  0b010,  0b111};
int Y[] = {5, 4, 0b1001, 0b0110, 0b0100, 0b0100, 0b0100};
int L[] = {5, 4, 0b1000, 0b1000, 0b1000, 0b1000, 0b1110};
int M[] = {5, 4, 0b1001, 0b1111, 0b1001, 0b1001, 0b1001};
int N[] = {5, 4, 0b1001, 0b1101, 0b1011, 0b1001, 0b1001};
int O[] = {5, 4, 0b1111, 0b1001, 0b1001, 0b1001, 0b1111};
int P[] = {5, 4, 0b1111, 0b1001, 0b1111, 0b1000, 0b1000};
int Q[] = {5, 4, 0b1111, 0b1001, 0b1001, 0b1110, 0b0001};
int R[] = {5, 4, 0b1111, 0b1001, 0b1111, 0b1010, 0b1001};
int S[] = {5, 4, 0b1111, 0b1000, 0b1111, 0b0001, 0b1111};
int T[] = {5, 3, 0b111,  0b010,  0b010,  0b010,  0b010};
int U[] = {5, 4, 0b1001, 0b1001, 0b1001, 0b1001, 0b1111};
int V[] = {5, 4, 0b1001, 0b1001, 0b1001, 0b1001, 0b0110};
int Z[] = {5, 4, 0b1111, 0b0011, 0b0110, 0b1100, 0b1111};

/*SPECIAL VALUES------------------------------------*/
int SPACE[]        = {5, 1, 0b0,    0b0,    0b0,    0b0,    0b0};
int ONE_SPACE[]    = {5, 1, 0b0,    0b0,    0b0,    0b0,    0b0};
int TWO_SPACES[]   = {5, 2, 0b00,   0b00,   0b00,   0b00,   0b00};
int THREE_SPACES[] = {5, 3, 0b000,  0b000,  0b000,  0b000,  0b000};
int FOUR_SPACES[]  = {5, 4, 0b0000, 0b0000, 0b0000, 0b0000, 0b0000};
int ALL[]          = {5, 4, 0b1111, 0b1111, 0b1111, 0b1111, 0b1111};
int CLR[]          = {5, 4, 0b0000, 0b0000, 0b0000, 0b0000, 0b0000};
int UNS[]          = {5, 2, 0b00,   0b00,   0b00,   0b00,   0b11};
int UPS[]          = {5, 2, 0b11,   0b00,   0b00,   0b00,   0b00};
