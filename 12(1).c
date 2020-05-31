#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int Reg(char *s1, char *s2) //всі великі букви переводить в малі
{
  FILE *f1; FILE *f2;
  f1 = fopen(s1, "r");
  f2 = fopen(s2, "w");
  while(!feof(f1))
  {
      char c;
      fscanf(f1,"%c",&c);
      if(isupper(c))
      {
        c = tolower(c);
      }
      fprintf(f2, "%c", c);
  }
  fclose(f1);
  fclose(f2);
  return 1;
}
int Rev(char *s1, char *s2) // записати рядок у зворотньому порядку
{
  FILE *f1; FILE *f2;
  f1 = fopen(s1, "r");
  f2 = fopen(s2, "w");
  char *r;
  r = (char *) malloc(sizeof(char));
  int n = 0;
  while(!feof(f1))
  {
    char c;
    fscanf(f1,"%c", &c);
    r[n] = c;
    n++;
    r = (char *) realloc(r, sizeof(char));
  }
  for(int i = 0; i < n/2; i++)
  {
    char s = r[n - i - 1];
    r[n - i - 1] = r[i];
    r[i] = s;

  }
  for(int i = 0; i < n; i++)
  {
    fwrite(&r[i], sizeof(char),1 ,f2);
  }
  free(r);
  fclose(f1);
  fclose(f2);

  return 1;
}


int main()
{
  char *s1, *s2;
  s1 = "file1.txt";
  s2 = "file2.txt";

  Rev(s1,s2);

}
