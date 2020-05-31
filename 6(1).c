/*Введіть масив дійсних чисел розміру d. Напишить функцію, яка обчислює  значення наступної функції: E(100*(x[i+1] - x[i]*x[i])*(x[i+1] - x[i]*x[i]) + (x[i]-1)*(x[i]-1) */
#include <stdio.h>
#include <math.h>
#define N 1

double inp(double arr[], int d)
{
  for(int i = 0; i < d; i++)
  {
    printf("a[%d] = ", i);
    scanf("%lf", &arr[i] );
  }
  return 0;
}
double res(double x[], int d)
{
  double result = 0;
  for (int i = 0; i < d - 1; i++)
  {
    result += 100*(x[i+1] - x[i]*x[i])*(x[i+1] - x[i]*x[i]) + (x[i]-1)*(x[i]-1);
  }
  return result;
}
int main()
{
  double arr[N];
  int d;

  printf("d = ");
  scanf("%d", &d );

  inp(arr,d);
  printf("Result = %lf", res(arr,d));
}
