#include "square_root.h"
#include <math.h>
#include <assert.h>

int square_root(int radicand) {
   assert(!radicand || radicand > 0);

   return sqrt(radicand);
}
