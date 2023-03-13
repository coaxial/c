#include "hamming.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int compute(const char *lhs, const char *rhs) {
   // Strands must be the same length.
   if (strlen(lhs) != strlen(rhs)) {
      return -1;
   }

   // Count number of differences between strands.
   int diff_count = 0;
   while(*lhs != 0) {
      if (*lhs != *rhs) {
         diff_count++;
      }

      lhs++;
      rhs++;
   }

   return diff_count;
}
