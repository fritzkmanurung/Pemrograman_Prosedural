// 12S21014 - Fritz Kevin Manurung
// 12S21039 - Widya Manurung

#include <stdio.h>

int main(int _argc, char **_argv)
{

  int a,b;
  scanf("%d", &b);
  int value[b], bil_terkecil, bil_terbesar;
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
  
  printf("%d\n%d\n", bil_terkecil, bil_terbesar);

  return 0;
}
