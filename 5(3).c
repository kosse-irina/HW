/*Інвертуйте бітове представлення даного числа та виведіть двійкове представлення та десяткове для цієї інверсії.*/
#include <stdio.h>
#include <math.h>

int main()
{
  unsigned x,x1 = 0;
  unsigned arr[32];

  printf("x=");
  scanf("%u", &x);
  unsigned n = x;

  for(int i = 0; i < sizeof(unsigned)*8; i++)
  {
    arr[i] = x & 1;
    x = x >> 1;
  }
  printf("Bit: ");
  for(int i = sizeof(unsigned)*8-1; i >= 0 ; i--){
    printf("%u",arr[i]);
  }
  printf("\nInversion: ");
  for(int i = 0; i < sizeof(unsigned)*8; i++){
    printf("%u",arr[i]);
    x1 += arr[31-i] * pow(2,i);
  }
  printf("\nInversion number: %u",x1);
}
