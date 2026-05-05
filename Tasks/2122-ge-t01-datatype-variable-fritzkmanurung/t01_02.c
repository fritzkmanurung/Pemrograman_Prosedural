// 12S21014 - Fritz Kevin Manurung
// 12S21039 - Widya Indah Sari Manurung

#include <stdio.h>

int main(int _argv, char **_argc)
{
float a, b, c, d, jumlah, ratarata;
  scanf("%f", &a);
  scanf("%f", &b);
  scanf("%f", &c);
  scanf("%f", &d);

jumlah = a + b + c + d;
ratarata = jumlah/4;

printf("%.3f\n%.3f\n", jumlah, ratarata);

  return 0;
}
