/*Видалити з рядка симетричні початок та кінець. Наприклад, рядок ‘abcdefba’ перетворюється у ‘cdef*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000
void Change(char *s);

int main()
{
  char s[N];
  printf("Input S : ");
  fgets(s, N, stdin);
  Change(s);
  puts(s);
}

void Change(char *s)
{
  int n = strlen(s) - 1;
  int k = 0;
  for(int i = 0; i < n/2; i++)
  {
    if(s[i] == s[n - i - 1])
    {
      s[i] = ' ';
      s[n-i-1] = '\0';
      k++;
    }
    else{
      break;
    }
  }
  for(int i = 0;  i < n - k; i++ )
  {
    s[i] = s[k+i];
  }

}
