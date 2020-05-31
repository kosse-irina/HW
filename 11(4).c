#include <stdio.h>
#define N 1000

typedef struct Adress{
  char city[N]; char street[N]; char house[N]; unsigned number;
} Adress;

void Inp_Adress(Adress *adr); //ввести адресу
void Out_Adress(Adress *adr); //вивести адресу

int main()
{
  Adress adr;
  Inp_Adress(&adr);
  Out_Adress(&adr);
}

void Inp_Adress(Adress *adr)
{
  printf("Input city : ");
  fgets(adr -> city, N, stdin);
  printf("Input street : ");
  fgets(adr -> street, N, stdin);
  printf("Input house : ");
  fgets(adr -> house, N, stdin);
  printf("Input room number : ");
  scanf("%u", &(adr -> number));
}
void Out_Adress(Adress *adr)
{
  printf("City : ");
  puts(adr -> city);
  printf("Street : ");
  puts(adr -> street);
  printf("House : ");
  puts(adr -> house);
  printf("Room number : ");
  printf("%u", adr -> number);
}
