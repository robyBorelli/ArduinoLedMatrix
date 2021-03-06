//#include "alphabet_5_4_.h" //a collection of letters
#include "alphabet_6_5_.h"   //a collection of letters
#include "words.h"           //a collection of words
#include "pins.h"            //defines hardware pins and related costants

/* ===================================================
 * package name    :     MatrixLedManager
 * author          :     Roberto Borelli
 * version         :     1.0.0
 * last update     :     24/05/2021
 * 
 * SPECIFIC===========================================
 * Manage a m*n matrix of leds to write letters and words.
 * drawWord          (word, letters, startingCol, cycles)
 * animWord          (word, letters, startingCol, endCol, cycles)
 * drawWordInPlace   (word, letters, startingCol, cycles)
 * animWordInPlace   (word, letters, startingCol, endCol, cycles)
 * drawLetter        (letter, startingCol, cycles)
 * animLetter        (letter, startingCol, endCol, cycles)
 * 
 * INVARIANT==========================================
 * THE MATRIX IS CLEAR AND RESETTED
 * In the setup: the call to reset() makes the invariant true.
 * In the loop:  you can call one of: drawWord, drawWordInPlace, drawLetter
 *                While executing these methods, the matrix state changes.
 *                After execution the matrix become clear and resetted.
 */
 
void setup() {
  configPins();
  reset();
  scanf_anim(0.5);
}

void loop() {
  animWord(HELLO, 5, COLS, -28, 4);
  animWord(WORLD, 5, COLS, -28, 4);
  animWord(GITHUB, 6, COLS, -40, 4);

  drawWord(GIT, 3, 0, 200);
}
