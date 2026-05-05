// 12S21014 - Fritz Kevin Manurung
// 12S21039 - Widya Manurung

#include <stdio.h>

int main(int _argc, char **_argv)
{
  int a,b;
  scanf("%d", &b);
  int value[b], bil_terkecil, bil_terbesar;
  float ratax;
  for ( a = 0; a < b; a++)
  {
    scanf("%d", &value[a]);
  }
  bil_terbesar = value[0];
  bil_terkecil = value[0];
  for ( a = 1; a < b; a++)
  {
    if (bil_terbesar < value[a])
    {
      bil_terbesar = value[a];
    } else if (bil_terkecil > value[a])
    {
      bil_terkecil = value[a];
    }
     

  }
  int len = sizeof(value) / sizeof (*value);
  int sum =0;

  for(int a = 0; a < len; a++)  {
    sum += value[a];
  }

  ratax = (float)sum / (float)len;




  printf("%d\n%d\n%.2f\n", bil_terkecil, bil_terbesar, ratax);

  return 0;
}
