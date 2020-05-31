/*DZ 8
 1)	Петя та Вася кожен день на протязі N годин вимірюють декілька (від 0 до 1000) разів температуру повітря (хоча інколи хтось може забути це зробити). Створіть програму, що дозволить їм ввести ці результати за кожну годину спостережень та підрахує середню температуру кожної години, де сумарна кількість вимірювань була більше 1. Програма повинна передбачити, що після вводу цих N годин вони можуть захотіти ввести наступні M днів таких спостережень. Передбачте можливість коректного завершення при нестачі ресурсів ПК для зберігання та обробки даних. Числа M та N можуть бути дуже великими.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Input_res(double **res, int n1)
{
  res = (double **) malloc(n1 * sizeof(double));
  for(int i = 0; i < n1; i++)
  {  int n2;
      double s = 0;
     printf("Sposterezen za %d godynu : ", i + 1);
     scanf("%d", &n2);
     res[i] = (double *) malloc(n2*sizeof(double));
     for(int j = 0; j < n2; j++)
     {
       printf("%d Sposterezenya : ", j + 1);
       scanf("%lf", &(res[i][j]));
       s += res[i][j];
     }
    printf("Average za %d godynu : %lf\n", i + 1,s/n2);
  }
  unsigned M;
  printf("Input k-t dniv M : ");
  scanf("%u", &M);
  if(M > 0)
  {
    for(unsigned int i = 0; i < M; i++)
    {
      unsigned n3; //к-ть годин
      printf("Kilkist' godyn v %d dni ", i + 1);
      scanf("%u", &n3);
      res = (double **) realloc(res, (n3 + 1) * sizeof(double));
      for(unsigned int k = 0; k < n3; k++)
      {
        unsigned n4; //к-ть спостережень
        double s = 0;
        printf("Kilkist' Sposterezen za %d godyny : ", k + 1);
        scanf("%u", &n4);
        res[n1 + i] = (double *) malloc((n4 + 1) * sizeof(double));
        for(unsigned int j = 0; j < n4; j++)
        {
          printf("%d Sposterezenya : ", j + 1);
          scanf("%lf", &(res[i + n1][j]));
          s += res[n1 + i][j];
        }
      printf("Average za %d godynu : %lf\n", i+1, s/n4);
    }
    n1 += n3;}}
  return n1;
}
 int main()
 {
   int n1; // кiлькiсть годин
   printf("n1 = ");
   scanf("%d", &n1);
   double **res;
   unsigned M = Input_res(res, n1);

   for(unsigned int i = 0; i < M; i++)
   {
     free(res[i]);
   }
   free(res);
 }
