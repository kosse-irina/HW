#include <stdio.h>
typedef struct Rational{ //структура раціонального числа
  int numerator;
  unsigned int denominator;
} Rational;
void Inp(Rational *r); // введення рац. числа
void Out(Rational *r);//виведення
Rational Sum(Rational *r1, Rational *r2);//сума двох чисел
Rational Mult(Rational *r1, Rational *r2);//множення
void Comp(Rational *r1, Rational *r2);//порівняння
void Reduce(Rational *r);//зведення до нескоротного виду
int main()
{
  Rational r1, r2;
  Inp(&r1); Inp(&r2);
  Rational res = Sum(&r1, &r2);
  Out(&res);
  res = Mult(&r1, &r2);
  Out(&res);
  Comp(&r1,&r2);
  Reduce(&r1);
  Out(&r1);
}

void Inp(Rational *r)
{
    int a; unsigned int b;
    do
    {
    printf("Input numerator: ");
    scanf("%d", &a);
    printf("Input denominator: ");
    scanf("%u", &b);
    if(b == 0){
      printf("Error : b == 0. Try another b\n");
    }
    r -> numerator = a; r-> denominator = b;} while(b == 0);
}
void Out(Rational *r)
{
  if (r -> denominator != 1)
  {printf("%d/%u\n", r -> numerator, r -> denominator);}
  if (r -> denominator == 1)
  {printf("%d\n", r -> numerator);}
}
Rational Sum(Rational *r1, Rational *r2)
{
  Rational res;
  res.numerator = r1 -> numerator * r2 -> denominator + r2 -> numerator * r1 -> denominator;
  res.denominator = r1->denominator * r2->denominator;
  return res;
}

Rational Mult(Rational *r1, Rational *r2)
{
  Rational res;
  res.numerator = r1 -> numerator * r2 -> numerator;
  res.denominator = r1 -> denominator * r2 -> denominator;
  return res;
}
void Reduce(Rational *r)
{
  int a, b;
  a = r -> numerator; b = r -> denominator;
  while (a % b != 0)
  {
    int z = b;
    b = a % b;
    a = z;
  }
  r -> numerator = r -> numerator / b;
  r -> denominator = r -> denominator / b;
}

void Comp(Rational *r1, Rational *r2)
{
  int a = r1 -> numerator * r2 -> denominator;
  int b = r2 -> numerator * r1 -> denominator;
  if(a > b){
    printf("r1 > r2\n");
  }
  if(a < b ){
    printf("r2 < r1\n");
  }
  if (a == b){
    printf("r1 = r2\n");}
}
