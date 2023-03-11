#include "armstrong_numbers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

bool is_armstrong_number(int candidate)
{
   if(candidate == 0)
   {
      return true;
   }

   int digits_count = floor(log10(abs(candidate))) + 1;
   /* Initialize the calculation's result */
   int armstrong_calc = 0;

   // An Armstrong number is a number where the sum of each digit to the power
   // of the total number of digits is equal to the number itself.
   // i.e. 1^3 + 5^3 + 3^3 = 153 => 153 is an Armstrong number
   //      1^3 + 0^3 + 0^3 = 3   => 100 isn't one
   for(int i = 0; i < digits_count; i++)
   {
      int digit = (int)(candidate / pow(10, i)) % 10;
      armstrong_calc += pow(digit, digits_count);
   }

   return (armstrong_calc == candidate);
}
