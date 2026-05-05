// 12S21014 - Fritz Kevin Manurung

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv)
{
    struct student_t *students = NULL;
    struct dorm_t *dorms = NULL;
    int student_count = 0;
    int dorm_count = 0;
    
    char line[255];
    while(fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\r\n")] = '\0';
        if(strcmp(line, "---") == 0) break;
        
        char *cmd = strtok(line, "#");
        if(cmd == NULL) continue;
        
        if(strcmp(cmd, "student-add") == 0) {
            char *id = strtok(NULL, "#");
            char *name = strtok(NULL, "#");
            char *year = strtok(NULL, "#");
            char *gender_str = strtok(NULL, "#");
            if(id && name && year && gender_str) {
                enum gender_t g = (strcmp(gender_str, "male") == 0) ? GENDER_MALE : GENDER_FEMALE;
                students = realloc(students, (student_count + 1) * sizeof(struct student_t));
                students[student_count] = create_student(id, name, year, g);
                student_count++;
            }
        } 
        else if(strcmp(cmd, "dorm-add") == 0) {
            char *name = strtok(NULL, "#");
            char *cap_str = strtok(NULL, "#");
            char *gender_str = strtok(NULL, "#");
            if(name && cap_str && gender_str) {
                unsigned short cap = atoi(cap_str);
                enum gender_t g = (strcmp(gender_str, "male") == 0) ? GENDER_MALE : GENDER_FEMALE;
                dorms = realloc(dorms, (dorm_count + 1) * sizeof(struct dorm_t));
                dorms[dorm_count] = create_dorm(name, cap, g);
                dorm_count++;
            }
        }
        else if(strcmp(cmd, "student-print-all") == 0) {
            for(int i = 0; i < student_count; i++) print_student(students[i]);
        }
        else if(strcmp(cmd, "dorm-print-all") == 0) {
            for(int i = 0; i < dorm_count; i++) print_dorm(dorms[i]);
        }
        else if(strcmp(cmd, "student-print-all-detail") == 0) {
            for(int i = 0; i < student_count; i++) print_student_detail(students[i]);
        }
        else if(strcmp(cmd, "dorm-print-all-detail") == 0) {
            for(int i = 0; i < dorm_count; i++) print_dorm_detail(dorms[i]);
        }
        else if(strcmp(cmd, "assign-student") == 0 || strcmp(cmd, "move-student") == 0) {
            char *id = strtok(NULL, "#");
            char *dorm_name = strtok(NULL, "#");
            if(id && dorm_name) {
                int s_idx = -1;
                for(int i = 0; i < student_count; i++) {
                    if(strcmp(students[i].id, id) == 0) { s_idx = i; break; }
                }
                int d_idx = -1;
                for(int i = 0; i < dorm_count; i++) {
                    if(strcmp(dorms[i].name, dorm_name) == 0) { d_idx = i; break; }
                }
                
                if(s_idx >= 0 && d_idx >= 0) {
                    void (*action)(struct student_t *, struct dorm_t *) = NULL;
                    if(students[s_idx].dorm == NULL) action = assign_student;
                    else action = move_student;
                    action(&students[s_idx], &dorms[d_idx]);
                }
            }
        }
    }
    
    if(students) free(students);
    if(dorms) free(dorms);
    return 0;
}
