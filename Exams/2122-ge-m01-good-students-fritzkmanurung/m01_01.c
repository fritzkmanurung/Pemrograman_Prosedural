// 12S21014 - Fritz Kevin Manurung

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student_t {
    char id[20];
    char name[100];
    char gpa[10];
};

int main(int _argc, char **_argv) {
    struct student_t *students = NULL;
    int count = 0;
    char line[200];
    
    while(fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\r\n")] = '\0';
        if(strcmp(line, "---") == 0) break;
        
        char *cmd = strtok(line, "#");
        if(cmd == NULL) continue;
        
        if(strcmp(cmd, "student-add") == 0) {
            char *id = strtok(NULL, "#");
            char *name = strtok(NULL, "#");
            char *gpa = strtok(NULL, "#");
            if(id && name && gpa) {
                students = realloc(students, (count + 1) * sizeof(struct student_t));
                strcpy(students[count].id, id);
                strcpy(students[count].name, name);
                strcpy(students[count].gpa, gpa);
                count++;
            }
        }
        else if(strcmp(cmd, "student-show-all") == 0) {
            for(int i = 0; i < count; i++) {
                printf("%s|%s|%s\n", students[i].id, students[i].name, students[i].gpa);
            }
        }
    }
    
    if(students) free(students);
    return 0;
}
