#include "student.h"
#include <stdio.h>
#include <string.h>

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender) {
    struct student_t std;
    strcpy(std.id, _id);
    strcpy(std.name, _name);
    strcpy(std.year, _year);
    std.gender = _gender;
    std.dorm = NULL;
    return std;
}

void print_student(struct student_t std) {
    printf("%s|%s|%s|%s\n", std.id, std.name, std.year, std.gender == GENDER_MALE ? "male" : "female");
}

void print_student_detail(struct student_t std) {
    printf("%s|%s|%s|%s|%s\n", std.id, std.name, std.year, std.gender == GENDER_MALE ? "male" : "female", std.dorm == NULL ? "unassigned" : std.dorm->name);
}

void assign_student(struct student_t *student, struct dorm_t *dorm) {
    if (student->gender == dorm->gender && dorm->residents_num < dorm->capacity) {
        student->dorm = dorm;
        dorm->residents_num++;
    }
}

void move_student(struct student_t *student, struct dorm_t *dorm) {
    if (student->dorm == NULL) {
        assign_student(student, dorm);
    } else {
        if (student->gender == dorm->gender && dorm->residents_num < dorm->capacity) {
            student->dorm->residents_num--;
            student->dorm = dorm;
            dorm->residents_num++;
        }
    }
}
