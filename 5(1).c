/*Ввести натуральне число M. Поміняйте місцями біти її двійкового запису з номерами i та j (що теж вводяться) та виведіть отримане число в десятковому та шістнадцятковому вигляді.  Наприклад, якщо введено 5, 0 та 1, відповідь 6. */
#include <stdio.h>
#include <math.h>
int main()
{
  unsigned n,i,j;
  unsigned arr[32];
  unsigned x, y;

  printf("n=");
  scanf("%u", &n);

  printf("i=");
  scanf("%u", &i);

  printf("j=");
  scanf("%u", &j);

  for (int i = 0; i < sizeof(unsigned)*8; i++){
    arr[i] = n & 1;
    n = n >> 1;
  }

  x = arr[i];
  y = arr[j];
  arr[i] = y;
  arr[j] = x;

  unsigned res = 0;
  for( int i = sizeof(unsigned)*8; i > 0; i--)
  {
    res += arr[i] * pow(2,i);
  }
  printf("%u",res);
}
