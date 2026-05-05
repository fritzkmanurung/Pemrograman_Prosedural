// 12S21014 - Fritz Kevin Manurung
// 12S21039 - Widya Manurung

#include <stdio.h>

int main(int _argv, char **_argc)
{
  int x;
  scanf("%d", &x);
  if (x == 1) {
    printf("staple food\n");
    printf("you need side dishes\n");
  } else if (x == 2) {
    printf("side dishes\n");
    printf("staple food\n");
    printf("you need vegetables\n");
  } else if (x == 3) {
    printf("vegetables\n");
    printf("side dishes\n");
    printf("staple food\n");
    printf("good\n");
  } else if (x == 4) {
    printf("fruits\n");
    printf("vegetables\n");
    printf("side dishes\n");
    printf("staple food\n");
    printf("very good\n");
  } else if (x == 5) {
    printf("milk\n");
    printf("fruits\n");
    printf("vegetables\n");
    printf("side dishes\n");
    printf("staple food\n");
    printf("perfect\n");
  } 


  return 0;
 
}
