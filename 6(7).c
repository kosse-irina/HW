/*7) Вводиться масив натуральних чисел заданого розміру N: визначити скільки серед цих чисел повних квадратів простих чисел
*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define N 1000
int inp(unsigned arr[], int d)
{
  for ( int i = 0; i < d; i++)
  {
    printf("arr[%d] = ",i);
    scanf("%u", &arr[i]);
  }
}
bool isPrime(unsigned n){
  if(n%2==0) return (n==2);
  for(unsigned i=3;i<sqrt(n+1);i+=2)
  {
    if (n%i==0) return false;
  }
  return true;
}
bool isSquare(unsigned n){
  unsigned res = 0;
  int x = (int) sqrt(n);
  for (int i = 1; i < x + 1; i++){ //чи є число квадратом
    res += 2*i-1;
  }
  if (n != res) return false;
  else{
    return isPrime(x); // чи є корінь числа простим числом
  }
}

int main()
{
  int d;
  printf("d = ");
  scanf("%d", &d);

  unsigned arr[N];

  inp(arr,d);

  for( int i = 0; i < d; i++)
  {
    if (isSquare(arr[i]))
    {
      printf("Chislo %u kvadrat prostogo\n",arr[i]);
    }
  }
}
