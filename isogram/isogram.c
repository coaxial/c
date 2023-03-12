#include "isogram.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool is_isogram(const char phrase[]) {
   if (phrase == NULL) {
      return false;
   }

   bool is_empty_string = !strcmp(phrase, "");
   if (is_empty_string) {
      return true;
   }

   // Convert phrase to lower case ASCII since capitalization is irrelevant for
   // isograms.
   char *lc_phrase = calloc(strlen(phrase), sizeof(*phrase));
   strncpy(lc_phrase, phrase, strlen(phrase));
   for(int i = 0; lc_phrase[i]; i++) {
      lc_phrase[i] = tolower(lc_phrase[i]);
   }

   // Count how many times letters appear in phrase
   char letters_count[26] = { 0 };
   for(int i = 0; lc_phrase[i]; i++) {
      int letter_pos = lc_phrase[i] - 97; // letters_count is indexed after the
                                          // regular alphabet, 0 to 25.

      // Only look at a-z chars, ignore hyphens etc.
      bool char_is_letter = (letter_pos >= 0 && letter_pos < 26);
      if (char_is_letter) {
         letters_count[letter_pos] += 1;

         if (letters_count[letter_pos] > 1) {
            return false;
         }
      }
   }

   return true;
}
