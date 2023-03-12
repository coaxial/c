#include "armstrong_numbers.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

bool is_armstrong_number(int candidate) {
   // An Armstrong number is a number where the sum of each digit to the power
   // of the total number of digits is equal to the number itself.
   // i.e. 1^3 + 5^3 + 3^3 = 153 => 153 is an Armstrong number
   //      1^3 + 0^3 + 0^3 = 3   => 100 isn't one

   if (candidate == 0) {
      return true;
   }

   if (candidate < 0) {
      return false;
   }

   int digits_count = log10(abs(candidate)) + 1;
   int armstrong_calc = 0; // Tracks the calculation result.

   // Copy candidate to avoid mutating it and failing the final comparison.
   int leftover_digits = 0;
   if (!memcpy(&leftover_digits, &candidate, sizeof(candidate))) {
      return -1;
   }

   for(int i = 0; i < digits_count; i++) {
      // Get the rightmost digit.
      int digit = leftover_digits % 10;
      // Remove the digit from the remaining digits.
      leftover_digits /= 10;
      armstrong_calc += pow(digit, digits_count);
   }

   return (armstrong_calc == candidate);
}
