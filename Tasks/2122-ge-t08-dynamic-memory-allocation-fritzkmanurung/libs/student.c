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
