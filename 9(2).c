/*2) Напишить дві функції: інверсія даного рядку  та перевірка, що рядок є симетричним*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define N 1000

void Inversion(char *s);
bool Symmetry(char *s);

int main()
{
  char s[N];
  printf("Input string : ");
  fgets(s, N, stdin);

  int x = Symmetry(s);
  printf("%d\n", x);

  Inversion(s);
  printf("%s", s);
}

bool Symmetry(char *s)
{
  bool b = true;
  int x = strlen(s) - 1;
  char t[x];
  int y = 0;
  for(int i = 0; i < x; i++)
  {
    {
      t[x - i - 1] = s[i];
    }
  }
  for(int i = 0; i < x; i++)
  {
    if (t[i] != s[i] ) { b = false; }
    else{ y++;  }
  }
  if(y == x ){  b = true; }
  return b;
}

void Inversion(char *s)
{
  int x = strlen(s) - 1;
  for(int i = 0; i < x / 2; i++)
  {
    char t = s[i];
    s[i] = s[x - i - 1];
    s[x - i - 1] = t;
  }
}
