/*У файлі записані координати Точок в просторі задані трійкою цілих чисел. Точки записуються в форматі : х1 , х2 , х3 ; х1 , х2, х3;  … - роздільники в трійках пробіли та кома, а між трійками — крапка з комою та пробіл.
Знайти відрізкок з точок цього файлу, що має найбільшу довжину.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int find_coords(char *s);

double len(int x1[3], int x2[3]){
  double l = 0;
  for(int i = 0; i < 3; ++i){
    l += (x1[i] - x2[i]) * (x1[i] - x2[i]);
  }
  return sqrt(l);
}

int main(){
  char *s;
  s = "file4.txt";
  find_coords(s);
}

int find_coords(char *s){
  FILE *f = fopen(s, "r");
  char *r;
  r = (char *) malloc(sizeof(char));
  int n = 0;
  int p = 0;
  while(!feof(f))
  {
    char c;
    fscanf(f,"%c", &c);
    if(c == ' ') {}
    else{r[n] = c;}
    if(c == ';') {p++;}
    n++;
    r = (char *) realloc(r, sizeof(char));}

  fclose(f);
  int x[p][3];
  int k = 0;
  int j = 0;
  int u = 0;
  int t = 0;
  for (int i = 0; i < n; i++)
  {
    if(r[i] == ',' && t >= 1 ){
      x[k][j] = atoi(&r[u + 1]);
      j++;
      u = i;
    }
    if(r[i] == ',' && t < 1 ){
      x[k][j] = atoi(&r[0]);
      t++;
      j++;
      u = i;
    }
    if (r[i] == ';'){
      x[k][j] = atoi(&r[u + 1]);
      k++;
      j = 0;
      u = i;
    }
  }
  free(r);
  double l = 0.0;
  k = 0; j = 0;
  for(int i = 0; i < p - 1; i++)
  {
    for (int b = i + 1; b < p; b++)
    {
      if(len(x[i], x[b]) > l )
      {k = i + 1; j = b + 1; l = len(x[i], x[b]);}
    }
  }
  printf("Max len between %d and %d points", k, j);
  return 1;
}
