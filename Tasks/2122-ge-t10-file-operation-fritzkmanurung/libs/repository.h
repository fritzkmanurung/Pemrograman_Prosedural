#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "dorm.h"
#include "student.h"

void load_dorms(struct dorm_t **dorms, int *dorm_count);
void load_students(struct student_t **students, int *student_count);
void save_dorms(struct dorm_t *dorms, int dorm_count);
void save_students(struct student_t *students, int student_count);

#endif
