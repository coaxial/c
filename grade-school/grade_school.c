#include "grade_school.h"
#include <string.h>
#include <stdlib.h>

// Checks whether the student is already in the roster.
static bool student_already_entered(roster_t *roster, const char *name) {
   for (size_t i = 0; i < roster->count; i++) {
      if (!strcmp(roster->students[i].name, name)) {
         return true;
      }
   }

   // No student by that name in the roster.
   return false;
}

roster_t *init_roster(roster_t *roster) {
   // Reset the given roster.
   // roster->count = 0;
   // memset(roster->students, 0, sizeof(roster->students));
   *roster = (roster_t) { 0 };

   return roster;
}

// Compare students by grade and then name.
static int compare_studentss(const void *a, const void *b) {
   const student_t *sa = a;
   const student_t *sb = b;

   if (sa->grade > sb->grade) {
      return 1;
   } else if (sa->grade < sb->grade) {
      return -1;
   } else {
      // If grades are the same, order by name.
      return strcmp(sa->name, sb->name);
   }
}

static void sort_roster(roster_t *roster) {
   // No sorting required if there aren't at least 2 students.
   if (roster->count >= 2) {
      qsort(roster->students, roster->count, sizeof(roster->students[0]), compare_studentss);
   }
}

bool add_student(roster_t *roster, const char *name, uint8_t grade) {
   // We can't process names that are longer than the limit. minus 1 to account
   // for the null terminator.
   bool name_too_long = strlen(name) >= MAX_NAME_LENGTH;
   if (name_too_long || student_already_entered(roster, name)) {
      return false;
   }

   student_t new_student = {.grade = grade};
   if (!strncpy(new_student.name, name, MAX_NAME_LENGTH)) {
      return false;
   }

   int new_student_id = roster->count;
   roster->students[new_student_id] = new_student;
   roster->count++;

   sort_roster(roster);

   return true;

}

// Get all students from given grade.
roster_t get_grade(const roster_t *roster, int grade) {
   roster_t grade_roster;
   init_roster(&grade_roster);

   for (size_t i = 0; i < roster->count; i++) {
      if (roster->students[i].grade == grade) {
         grade_roster.students[grade_roster.count] = roster->students[i];
         grade_roster.count++;
      }
   }

   return grade_roster;
}
