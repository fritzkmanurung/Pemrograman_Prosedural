// 12S21014 - Fritz Kevin Manurung 
// 12S21039 - Widya Indah Sari Manurung

#include "StudentDormitory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student_t create_student(char *_id, char *_name, char *_year, char *_study_program, enum gender_t _gender)
{


  struct student_t std;
  
  //CODE
  
  strcpy(std.id, _id);
  strcpy(std.name, _name);
  strcpy(std.year, _year);
  strcpy(std.study_program, _study_program);
  std.gender = _gender;

  
  return std;
}

struct dorm_t create_dorm(char *_dormitory_name, unsigned short _capacity, enum status_t _status, enum type_t _type)
{
  struct dorm_t dorm_;

  //CODE
  strcpy(dorm_.dormitory_name, _dormitory_name);
  dorm_.capacity = _capacity;
  dorm_.status = _status;
  dorm_.type = _type;
  dorm_.residents_num  = 0;

  return dorm_;
} 
  
void print_students(struct student_t *_students, int size ){

  //CODE

}

void print_dorms(struct dorm_t *_dorm, int size){
  
  //CODE
  
}

void print_dorm(struct dorm_t _dorm ){
  
  //CODE
  
}

void print_students_dorm(struct student_dormitory_t *students_dorms, int students_size, struct dorm_t *dorms, int droms_size, struct student_t *students)
{
  int assigned_to[100];
  for (int i = 0; i < students_size; i++) assigned_to[i] = -1;

  for(int d = 0; d < droms_size; d++) {
      int assigned_count = 0;
      for(int s = 0; s < students_size; s++) {
          if(assigned_to[s] == -1) {
              if((dorms[d].type == FOR_MALE && students[s].gender == MALE) ||
                 (dorms[d].type == FOR_FEMALE && students[s].gender == FEMALE)) {
                  if(dorms[d].capacity > 0) {
                      assigned_to[s] = d;
                      dorms[d].capacity--;
                      dorms[d].residents_num++;
                      assigned_count++;
                  }
              }
          }
      }
      
      if(dorms[d].capacity > 0) dorms[d].status = A;
      else dorms[d].status = NA;
      
      printf("\n%s#%d#%s#%s\n", dorms[d].dormitory_name, dorms[d].capacity, 
             (dorms[d].status == A ? "Available" : "Not Available"),
             (dorms[d].type == FOR_MALE ? "For Male" : "For Female"));
             
      if(assigned_count == 0) {
          printf("0\n");
      } else {
          for(int s = 0; s < students_size; s++) {
              if(assigned_to[s] == d) {
                  printf("%s#%s#%s#%s\n", students[s].id, students[s].name, students[s].year, students[s].study_program);
              }
          }
      }
  }
}

void assign_students(struct student_dormitory_t *students_dorms, struct dorm_t *dorms, struct student_t *students, int size_dorms, int size_students){
  
  //CODE
  /*
  char id[12];
  char name[100];
  char year[5];
  char study_program[40];
  enum gender_t gender;
  */
  //12S20999#Wiro Sableng#2020#Information Systems#MALE


  printf("Students:\n");
  for(int i = 0; i < size_students; i++){
    printf("%s#%s#%s#%s#", students[i].id, students[i].name, students[i].year, students[i].study_program);
    if(students[i].gender == 0) printf("MALE\n");
    else printf("FEMALE\n");
  }
  /*
  char dormitory_name[20];
  int capacity;
  enum status_t status;
  enum type_t type;
  int residents_num;
  */
  printf("\nDorms:\n");
  for(int i = 0;i < size_dorms; i++){
    printf("%s#%d#", dorms[i].dormitory_name, dorms[i].capacity);
    if(dorms[i].capacity > dorms[i].residents_num) printf("Available#");
    else printf("Not Available#");
    if(dorms[i].type == 0) printf("For Male\n");
    else printf("For Female\n");
  }
  
}

struct dorm_t check_dorm(struct dorm_t *dorms, int size, enum type_t gender)
{
  struct dorm_t temp;
  
  //CODE

  return temp;
}
