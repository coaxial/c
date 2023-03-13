#include "difference_of_squares.h"
#include <math.h>

unsigned int sum_of_squares(unsigned int number) {
   // https://learnersbucket.com/examples/algorithms/difference-between-square-of-sum-of-numbers-and-sum-of-square-of-numbers/
   return (number * (number + 1) * ((number * 2) + 1)) / 6;
}

unsigned int square_of_sum(unsigned int number) {
   // https://learnersbucket.com/examples/algorithms/difference-between-square-of-sum-of-numbers-and-sum-of-square-of-numbers/
   unsigned int sum = (number * (number + 1)) / 2;
   return sum * sum;
}

unsigned int difference_of_squares(unsigned int number) {
   return square_of_sum(number) - sum_of_squares(number);
}
