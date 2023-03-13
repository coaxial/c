#include "grade_school.h"
#include <string.h>
#include <stdlib.h>

// Checks whether the student is already in the roster.
static bool student_already_entered(roster_t *Roster, char *name) {
   if (Roster->count > 0) { // No duplicates in an empty roster.
      for (size_t i = 0; i < Roster->count; i++) {
         if (!strcmp(Roster->students[i].name, name)) {
            return true;
         }
      }
   }
   
   // No student by that name in the roster.
   return false;
}

roster_t *init_roster(roster_t *Roster) {
  // Reset the given roster.
   Roster->count = 0;
  // TODO: Is there a less verbose way here to reset the values?
   memset(Roster->students, 0, sizeof(Roster->students));

   return Roster;
}

// Sorts students by ascending grades.
int compare_grades(const void *a, const void *b) {
   const student_t *sa = a;
   const student_t *sb = b;

   if (sa->grade > sb->grade) {
      return 1;
   } else if (sa->grade < sb->grade) {
      return -1;
   } else {
      return 0;
   }
}

// Sorts students by alphabetical order on name.
int compare_names(const void *a, const void *b) {
   const student_t *sa = a;
   const student_t *sb = b;

   return strcmp(sa->name, sb->name);
}

roster_t *sort_roster(roster_t *Roster) {
   // No sorting required if there aren't at least 2 students.
   if (Roster->count >= 2) {
      qsort(Roster->students, Roster->count, sizeof(Roster->students[0]), compare_names);
      qsort(Roster->students, Roster->count, sizeof(Roster->students[0]), compare_grades);
   }

   return Roster;
}

bool add_student(roster_t *Roster, char *name, uint8_t grade) {
   // We can't process names that are longer than the limit. minus 1 to account
   // for the null terminator.
   bool name_too_short = strlen(name) > MAX_NAME_LENGTH - 1;
   if (name_too_short) {
      return false;
   }
   
   if (student_already_entered(Roster, name)) {
      return false;
   }

   student_t NewStudent;
   // TODO: Is this the correct way to ensure the strncpy worked?
   // TODO: Am I right in copying MAX_NAME_LENGTH - 1 since the name string
   // needs one more byte for the \0 terminator?
   if (!strncpy(NewStudent.name, name, MAX_NAME_LENGTH - 1)) {
      return false;
   }
   NewStudent.grade = grade;

   int new_student_id = Roster->count;
   Roster->students[new_student_id] = NewStudent;
   Roster->count++;

   sort_roster(Roster);

   return true;

}

// Get all students from given grade.
roster_t get_grade(roster_t *Roster, int grade) {
   roster_t GradeRoster = {
     .count=0,
     // TODO: Why do I need {{0}} here and not {0}? I'm getting `error: missing
     // braces around initializer [-Werror=missing-braces]` otherwise.
     .students={{0}}
   };

   for (size_t i = 0; i < Roster->count; i++) {
      if (Roster->students[i].grade == grade) {
         GradeRoster.students[GradeRoster.count] = Roster->students[i];
         GradeRoster.count++;
      }
   }

   return GradeRoster;
}
