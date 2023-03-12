#include "grains.h"

uint64_t square(uint8_t index) {
   const int MAX_SQUARES = 64;
   if (index == 0 || index > MAX_SQUARES) {
      return 0;
   }

   // 1 is an int, 1ull is an uint64.
   // Bitwise doesn't require math.h but it also works with pow(2, index - 1).
   return 1ull << (index - 1);
}

uint64_t total(void) {
   // https://en.wikipedia.org/wiki/Wheat_and_chessboard_problem#Solutions
   // Multiply by two because square(64) is 2^63.
   return 2 * square(64) - 1;  
}
