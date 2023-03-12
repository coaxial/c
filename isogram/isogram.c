#include "isogram.h"
#include <stdint.h>

bool is_isogram(const char phrase[]) {
   // This revised implementation submitted after mentor feedback, reading
   // about the bitwise solution, and reimplementing it.
   // Comments added for my own sake, when reading through the program again
   // after I've forgotten how it works.

   // Bail on NULL.
   if (!phrase) {
      return false;
   }

   // Keep track of the letters we've already seen using a 32 bit bitfield.
   // The alphabet is reversed because it makes bitwise operations easier when
   // updating the bitfield.
   // 10987654321098765432109876543210    Bit index (0--31, total 32)
   //       zyxwvutsrqponmlkjihgfedcba    Bit meaning
   // 00000000000000000000000000000000    Bit set == letter seen in phrase
   uint32_t alphabet_bitfield = 0;

   // The input can be mixed case, but we only care about the actual letters,
   // not their case.
   for(; *phrase; phrase++) {
      char offset = 0;
      char letter = *phrase;

      // To set the right bit in alphabet_bitfield, we need to calculate the
      // offset from the character's ASCII value to the position in
      // alphabet_bitfield.
      // 'a' is 97, so 'a' - 'a' == 0.
      // 'A' is 65, so 'A' - 'A' == 0.
      // => 'a' and 'A' will both match alphabet_bitfield's bit 0.
      if ('a' <= letter && letter <= 'z') {
         offset = 'a'; // 97
      } else if ('A' <= letter && letter <= 'Z') {
         offset = 'A'; // 65
      }

      // If offset is still 0, the character is not [azAZ].
      bool is_not_letter = !offset;
      // Only letters are relevant for isograms.
      if (is_not_letter) {
         continue;
      }

      // Check current letter against previously seen ones.
      bool is_duplicate_letter = (alphabet_bitfield & (1 << (letter - offset))) != 0;
      if (is_duplicate_letter) {
         // Letter already seen, not an isogram.
         return false;
      } else {
         // Letter hasn't been seen yet, update the alphabet_bitfield.
         alphabet_bitfield |= (1 << (letter - offset));
      }

   }

   // Every letter is unique, we have an isogram.
   return true;
}
