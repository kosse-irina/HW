/*Ввести натуральні числа M та N та визначить скільки в них спільних одиничок бітового представлення. Визначить скільки в цих числах взагалі співпадає бітів.*/
#include <stdio.h>
#include <math.h>
int Spilny1(unsigned n,unsigned m){ //спільні '1' у двох чисел

  int sum;
  for(int i = 0; i < sizeof(unsigned)*8; i++)
  {
    int x1 = n & 1;
    int y1 = m & 1;
    if(x1 & y1 == 1){
      sum += 1;
    }
    n = n >> 1;
    m = m >> 1;
  }
  return sum;
}
int Spilnybyty(unsigned n,unsigned m){ //спільні біти у двох чисел

  int sum = 0;
  for(int i = 0; i < sizeof(unsigned)*8; i++)
  {
    int x1 = n & 1;
    int y1 = m & 1;
    if(x1 == y1)
    {
      sum += 1;
    }
    n = n >> 1;
    m = m >> 1;
  }
  return sum;
}
int main()
{
  unsigned n, m;
  printf("n=");
  scanf("%u", &n);

  printf("m=");
  scanf("%u", &m);

  printf("%d", Spilny1(n,m));

  printf("\n%d", Spilnybyty(n,m));
}
