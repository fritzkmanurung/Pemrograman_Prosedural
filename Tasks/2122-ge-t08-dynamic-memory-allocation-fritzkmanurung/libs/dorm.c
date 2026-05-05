#include "dorm.h"
#include <stdio.h>
#include <string.h>

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender) {
    struct dorm_t dorm;
    strcpy(dorm.name, _name);
    dorm.capacity = _capacity;
    dorm.gender = _gender;
    dorm.residents_num = 0;
    return dorm;
}

void print_dorm(struct dorm_t dorm) {
    printf("%s|%d|%s\n", dorm.name, dorm.capacity, dorm.gender == GENDER_MALE ? "male" : "female");
}
