/*1) Напишить функцію, яка перевіряє, що в даному рядку всі дужки (а їх існує три види: [**],{**},(**) ) розставлено правильно, тобто вираз ї коректним.
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define N 1000

bool Brackets(char *s)
{
  int r1 = 0; int  r2 = 0; int r3 = 0 ;
  for(size_t i = 0; i < strlen(s); i++)
  {
    if (r1 < 0 || r2 < 0 || r3 < 0)
    {
      return false;
    }
    else{
      if(s[i] == '(')
      {
        r1++;
      }
      if(s[i] == ')')
      {
        r1--;
      }
      if(s[i] == '[')
      {
        r2++;
      }
      if(s[i] == ']')
      {
        r2--;
      }
      if(s[i] == '{')
      {
        r3++;
      }
      if(s[i] == '}')
      {
        r3--;
      }
    }
  }
    if (r1 != 0 || r2 != 0 || r3 != 0)
    {
      return false;
    }
    return true;
}

int main()
{
  char s[N];

  printf("Input string : ");
  fgets(s, N, stdin);

  if(Brackets(s) == 0){
    printf("Incorrectly");
  }
  else{
    printf("Correctly");
  }
}
