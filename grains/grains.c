#include "grains.h"
#include <math.h>

uint64_t square(uint8_t index) {
  return pow(2, index - 1); 
}

uint64_t total(void) {
   // https://en.wikipedia.org/wiki/Wheat_and_chessboard_problem#Solutions
   return 2 * square(64) - 1;  
}
