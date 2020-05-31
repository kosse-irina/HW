#include <stdio.h>

int Fib1(int a) //номер найбільшого числа Фібоначчі, яке не перевищує а
{
int x = 1;
int y = 1;
int res = 0;
int i = 2;
while(x + y < a){
  res = x + y;
  x = y;
  y = res;
  i++;
}
return i;
}
int Fib2(int a) //сума чисел Фібонначі, які менше 1000
{
int x = 1;
int y = 1;
int res = 0;
int i = 2;
int sum = 2;
while(x + y < a){
  res = x + y;
  x = y;
  y = res;
  sum += res;
  i++;
}
return sum;
}
int main()
{
  int a;

  printf(" a=");
  scanf("%d", &a );

  printf(" Fibonacci number is less than a : %d\n", Fib1(a));

  printf(" Fibonacci number smaller than a : %d\n",Fib1(a)+1);

  printf(" The sum of Fibonacci numbers is less than 1000 : %d",Fib2(1000));
}
