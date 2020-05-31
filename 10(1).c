/*	Вводиться рядки S1 та рядки S2 та натуральне число k. Створіть дві функції: перша створює новий рядок який отримується додаванням рядку S2 в рядок S1 на позицію k-го символу, друга робить теж саме, але при цьому модифікує безпосередньо рядок S1.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000

char* Add1(char *s1, char *s2, int k); //створює новий рядок
void Add2(char *s1, char *s2, int k); //змінює s1

int main()
{
  char s1[N], s2[N];
  int k;

  printf("Input S1 : ");
  fgets(s1, N, stdin);
  printf("Input S2 : ");
  fgets(s2, N, stdin);
  printf("Input k = ");
  scanf("%d",&k);
  char *s3 = Add1(s1,s2,k);
  puts(s3);

  Add2(s1,s2, k);
  puts(s1);
  free(s3);


}

char* Add1(char *s1, char *s2, int k)
{
  k = k-1;
  char *s3 = (char *) malloc((int) (strlen(s1) + strlen(s2)));
  for(int i = 0; i < k; i++ )
  {
      s3[i] = s1[i];
  }
  for(int i = 0; i < (int) strlen(s2) - 1; i++)
      {
        s3[k+i] = s2[i];
      }
  for( int i = k; i < (int) strlen(s1); i++)
    {
      s3[i + strlen(s2) - 1 ] = s1[i];
    }
  return s3;
}
void Add2(char *s1, char *s2, int k)
{
  int n1 = (int) strlen(s1);
  int n2 = (int) strlen(s2) - 1;
  char s[n1 - k];
  for(int i = 0; i < n1 - k ; i++)
  {
      s[i] = s1[k - 1 + i];
  }

  for(int i = 0; i < n1 - k; i++)
  {
    s1[k - 1 + i + n2] = s[i];
  }
  for(int i = k - 1; i < n2 + k - 1; i++ )
  {
    s1[i] = s2[-k + 1 + i];
  }

}
