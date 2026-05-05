#include "repository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void load_dorms(struct dorm_t **dorms, int *dorm_count) {
    FILE *f = fopen("storage/dorm-repository.txt", "r");
    if(!f) return;
    char line[200];
    while(fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\r\n")] = '\0';
        char *name = strtok(line, "|");
        char *cap_str = strtok(NULL, "|");
        char *gender_str = strtok(NULL, "|");
        if(name && cap_str && gender_str) {
            unsigned short cap = atoi(cap_str);
            enum gender_t g = (strcmp(gender_str, "male") == 0) ? GENDER_MALE : GENDER_FEMALE;
            *dorms = realloc(*dorms, (*dorm_count + 1) * sizeof(struct dorm_t));
            (*dorms)[*dorm_count] = create_dorm(name, cap, g);
            (*dorm_count)++;
        }
    }
    fclose(f);
}

void load_students(struct student_t **students, int *student_count) {
    FILE *f = fopen("storage/student-repository.txt", "r");
    if(!f) return;
    char line[200];
    while(fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\r\n")] = '\0';
        char *id = strtok(line, "|");
        char *name = strtok(NULL, "|");
        char *year = strtok(NULL, "|");
        char *gender_str = strtok(NULL, "|");
        if(id && name && year && gender_str) {
            enum gender_t g = (strcmp(gender_str, "male") == 0) ? GENDER_MALE : GENDER_FEMALE;
            *students = realloc(*students, (*student_count + 1) * sizeof(struct student_t));
            (*students)[*student_count] = create_student(id, name, year, g);
            (*student_count)++;
        }
    }
    fclose(f);
}

void save_dorms(struct dorm_t *dorms, int dorm_count) {
    FILE *f = fopen("storage/dorm-repository.txt", "w");
    if(!f) return;
    for(int i = 0; i < dorm_count; i++) {
        fprintf(f, "%s|%d|%s\n", dorms[i].name, dorms[i].capacity, dorms[i].gender == GENDER_MALE ? "male" : "female");
    }
    fclose(f);
}

void save_students(struct student_t *students, int student_count) {
    FILE *f = fopen("storage/student-repository.txt", "w");
    if(!f) return;
    for(int i = 0; i < student_count; i++) {
        fprintf(f, "%s|%s|%s|%s\n", students[i].id, students[i].name, students[i].year, students[i].gender == GENDER_MALE ? "male" : "female");
    }
    fclose(f);
}
