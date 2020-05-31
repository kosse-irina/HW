/*Створити бінарний файл в якому записані дійсні числа. Написати функцію яка за імям файла підраховує середнє дійсних чисел, що в ньому записано.
*/
#include <stdio.h>
#include <stdlib.h>

void inp(char *name)
{
  int n;
  FILE *f;
  printf("n = ");
  scanf("%d",&n);

  f = fopen(name, "wb");
  for(int i = 0; i < n; i++)
  {
    float x;
    printf("Input number : ");
    scanf("%f", &x);
    fwrite(&x, sizeof(float), 1, f);
  }
  fclose(f);
}

float read(char *name){
  FILE *f = fopen(name, "rb");
  float *r = (float*) malloc(sizeof(float));
  int n = 0;
  while(!feof(f)){
    float c;
    fread(&c, sizeof(float), 1, f);
    r[n] = c;
    n++;
    r = (float *) realloc(r, sizeof(float));
  }
    fclose(f);
  float s = 0;
  for(int i = 0; i < n - 1; ++i){
    s += r[i];
  }
  free(r);
  return s/(n-1);
}

int main(){
  char *name = "123.dat";
  inp(name);
  printf("res=%f", read(name));
}
