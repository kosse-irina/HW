/*Створити бінарний файл в якому записані дійсні числа. Написати функцію яка за імям файла підраховує середнє дійсних чисел, що в ньому записано.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inp(char *name)
{
  int n;
  FILE *f;
  printf("n = ");
  scanf("%d",&n);

  f = fopen(name, "wb");
  for(int i = 0; i < n; i++)
  {
    int x;
    printf("Input number : ");
    scanf("%d", &x);
    fwrite(&x, sizeof(int), 1, f);
  }
  fclose(f);
}

int ktparn(char *name){ //кількість парних
  FILE *f = fopen(name, "rb");
  int *r = (int*) malloc(sizeof(int));
  int n = 0;
  while(!feof(f)){
    int c;
    fread(&c, sizeof(int), 1, f);
    r[n] = c;
    n++;
    r = (int *) realloc(r, sizeof(int));
  }
    fclose(f);
  float s = 0;
  for(int i = 0; i < n - 1; ++i){
    if(r[i] % 2 == 0){
      s++;
    }
  }
  free(r);
  return s;
}

int ktkv(char *name){ //кількість квадратів  непарних чисел
  FILE *f = fopen(name, "rb");
  int *r = (int*) malloc(sizeof(int));
  int n = 0;
  while(!feof(f)){
    int c;
    fread(&c, sizeof(int), 1, f);
    r[n] = c;
    n++;
    r = (int *) realloc(r, sizeof(int));
  }
    fclose(f);
  int s = 0;
  for(int i = 0; i < n - 1; ++i){
    if(((int) sqrt(r[i]) )*((int) sqrt(r[i]) ) == r[i] && r[i] % 2 == 1){
      s++;
    }
  }
  free(r);
  return s;
}

int rizn(char *name){ //різниця між найбільшим парним і найменшим непарним
  FILE *f = fopen(name, "rb");
  int *r = (int*) malloc(sizeof(int));
  int n = 0;
  while(!feof(f)){
    int c;
    fread(&c, sizeof(int), 1, f);
    r[n] = c;
    n++;
    r = (int *) realloc(r, sizeof(int));
  }
    fclose(f);
  int s1 = 0;
  int s2 = 0;
  int max_par = 0;
  int min_nepar = 1;
  for(int i = 0; i < n - 1; ++i){
    if(r[i] % 2 == 0 && r[i] > max_par && s1 == 1){
      max_par = r[i];
    }
    if(r[i] % 2 == 0  && s1 == 0) {max_par = r[i]; s1++;}
    if(abs(r[i] % 2) == 1 && r[i] < min_nepar && s2 == 1){
      min_nepar = r[i];}
    if(abs(r[i] % 2) == 1  && s2 == 0) {min_nepar = r[i]; s2++;}
  }
  free(r);
  return max_par - min_nepar;
}

int ktkomp(char *name){ //кількість компонент  у найдовшій  зростаючій послідовності
  FILE *f = fopen(name, "rb");
  int *r = (int*) malloc(sizeof(int));
  int n = 0;
  while(!feof(f)){
    int c;
    fread(&c, sizeof(int), 1, f);
    r[n] = c;
    n++;
    r = (int *) realloc(r, sizeof(int));
  }
    fclose(f);
  int s = 1;
  int d = r[1] - r[0];
  for(int i = 1; i < n - 2; ++i){
    if((r[i] < r[i+1]) && ((r[i+1] - r[i]) == d ) && s!=0){
      s++;
    }
    if((r[i] < r[i+1]) && s == 0){
      s++;
      d = r[i+1] - r[i];
    }
    if(r[i] >= r[i+1]){ s = 0; d = 0;}
    if(r[i] < r[i+1] && ((r[i+1] - r[i]) != d)){
      d = r[i+1] - r[i];
      s = 1;
    }

    }
  free(r);
  return s+1;
}

int main(){
  char *name = "123.dat";
  inp(name);
  printf("k = %d", ktparn(name));
  printf("k = %d", ktkv(name));
  printf("k = %d", rizn(name));
  printf("k = %d", ktkomp(name));
}
