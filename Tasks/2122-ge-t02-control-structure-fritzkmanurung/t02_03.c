// 12S21014 - Fritz Kevin Manurung
// 12S21039 - Widya Manurung

#include <stdio.h>

int main(int _argv, char **_argc)
{
  char operator;
  int x, output, input;
  scanf(" %c",&operator);
  printf("%c\n", operator);
  if (operator=='*')
  {
  x=1;
  }
  else if (operator=='+')
  {
  x=0;
  }
  else if (operator=='-')
  {
  x=0;
  }
  for (int i = 1; i < 5; ++i) {
  scanf("%i",&input);
  printf("%i\n", input);
  if (input == -1) {
  printf("0\n");
  break;
  }
  if (operator=='*')
  {
  output=x*input;
  x=output;
  }
  else if (operator=='+')
  {
  output=x+input;
  x=output;
  }
  else if (operator=='-')
  {
  output=x-input;
  output=-output;
  x=output;
  }
  printf("%i\n", output);
  }

    
  return 0;
}
