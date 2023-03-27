#include "square_root.h"
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

static bool is_close_enough(int guess, int radicand) {
   return abs((guess * guess) - radicand) < 0.1;
}

static int improve(int guess, int radicand) {
   return ((radicand / guess) + guess) / 2;
}

static int iterate_sqrt(int guess, int radicand) {
   if (is_close_enough(guess, radicand)) {
      return guess;
   }

   return iterate_sqrt(improve(guess, radicand), radicand);
}

int square_root(int radicand) {
   // Start off with 1 as our guess.
   return iterate_sqrt(1, radicand);
}
