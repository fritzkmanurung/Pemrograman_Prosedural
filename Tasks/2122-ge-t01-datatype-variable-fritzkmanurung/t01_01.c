// 12S21014 - Fritz Kevin Manurung
// 12S21039 - Widya Indah Sari Manurung

#include <stdio.h>

int main(int _argv, char **_argc)
{
 unsigned int angka;
   scanf("%u", &angka);
   char huruf;
   scanf(" %c", &huruf);
   int bollean;
   scanf("%d", &bollean);
   float fraction;
   scanf("%f", &fraction);

   printf("%u\n%c\n%d\n%.3f\n", angka, huruf, bollean, fraction);

  return 0;
}
