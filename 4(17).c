#include <stdio.h>
#include <math.h>

double Function(double x, double eps)
{
  double y = 1;
  double z = 1;

  while(fabs(z)>=eps)
  {
    z = -z*x*x;
    y += z;
  }
  return y;
}
int main()
{
  double x, eps;
  printf("x=");
  scanf("%lf",&x);

  printf("eps=");
  scanf("%lf",&eps);

  printf("f(x)=%lf\n", Function(x,eps));
  printf("1/(1+x*x) = %lf ",1/(1+x*x));
}
