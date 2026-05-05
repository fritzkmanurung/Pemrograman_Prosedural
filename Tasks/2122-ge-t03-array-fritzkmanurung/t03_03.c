// 12S21014 - Fritz Kevin Manurung
// 12S21039 - Widya Manurung

#include <stdio.h>

int main(int _argc, char **_argv)
{

  int a,b;
  scanf("%d", &b);
  int value[b], bil_terkecil, bil_terbesar,y;
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

  int x[b];
  y = -1;
  for (a = 0; a <= b-2; a++)
  {
    x[a] = value[a+1]-value[a];
    if(x[a]<0)
    {
      x[a] = -x[a];
    }
  }
  for(a = 0; a <= b-2; a++) 
  {
    if(x[a]>y)
    {
      y = x[a];
    }
  }

  printf("%d\n%d\n%.2f\n%d\n", bil_terkecil, bil_terbesar, ratax, y);
  return 0;
}
