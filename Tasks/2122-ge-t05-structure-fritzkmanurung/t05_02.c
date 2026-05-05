// 12S21014 - Fritz Kevin Manurung
// 12S21039 - Widya Indah Sari Manurung 

#include <stdio.h>
#include <string.h>

enum gender_t { MALE, FEMALE };
struct student_t {
    char name[40];
    char id[20];
    int year;
    enum gender_t gender;
};

int main(int _argv, char **_argc)
{
    char line[200];
    struct student_t stds[100];
    int count = 0;
    int male = 0, female = 0;

    while(fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\r\n")] = '\0';
        if(strcmp(line, "---") == 0) break;
        if(strcmp(line, "register") == 0) continue;
        if(strlen(line) < 5) continue;
        
        char *name = strtok(line, "|");
        char *id = strtok(NULL, "|");
        char *year_str = strtok(NULL, "|");
        char *gender_str = strtok(NULL, "|");
        if(name && id && year_str && gender_str) {
            strcpy(stds[count].name, name);
            strcpy(stds[count].id, id);
            stds[count].year = 2000;
            if(strcmp(gender_str, "MALE") == 0) {
                stds[count].gender = MALE;
                male++;
            }
            else if(strcmp(gender_str, "FEMALE") == 0) {
                stds[count].gender = FEMALE;
                female++;
            }
            count++;
        }
    }

    printf("%d|%d\n", male, female);
    for(int i = 0; i < count; i++) {
        if(stds[i].gender == MALE) printf("%s|", stds[i].name);
    }
    printf("\n");
    for(int i = 0; i < count; i++) {
        if(stds[i].gender == FEMALE) printf("%s|", stds[i].name);
    }
    printf("\n");
    
    return 0;
}