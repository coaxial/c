#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 20

typedef struct {
   uint8_t grade;
   char name[MAX_NAME_LENGTH];
} student_t;

typedef struct {
   size_t count;
   student_t students[MAX_STUDENTS];
} roster_t;

roster_t *init_roster(roster_t *NewRoster);
bool add_student(roster_t *Roster, char *name, uint8_t grade);
roster_t get_grade(roster_t *Roster, int grade);
int compare_grades(const void *a, const void *b);
int compare_names(const void *p1, const void *p2);
roster_t *sort_roster(roster_t *Roster);

#endif
