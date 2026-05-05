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
            if(strcmp(gender_str, "MALE") == 0) male++;
            else if(strcmp(gender_str, "FEMALE") == 0) female++;
        }
    }

    printf("%d|%d\n", male, female);
    
    return 0;
}