// 12S21014 - Fritz Kevin Manurung
// 12S21039 - Widya Indah Sari Manurung

#include <stdio.h>

int main(int _argv, char **_argc)
{
  int x, y, z, a, b;
  scanf("%d %d %d", &x, &y, &z);

  a=x>>y;
  b=a==z;

  printf("%d\n%d\n", a, b);

  return 0;
}
