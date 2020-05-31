#include <stdio.h>
#include <stdlib.h>
#define N 1000

typedef struct Person{
  char name[N]; char st[N]; unsigned height; //ім'я, стать, зріст
} Person;
void Inp_person(Person *per); //ввести дані людини
void Check_height(Person *p, int n); //знайти людей з однаковим зростом
int main()
{
  int n;
  printf("Input the number of people : ");
  scanf("%d", &n);
  Person p[N];
  for(int i = 0; i < n; i++)
  {
    Person per;
    Inp_person(&per);
    p[i] = per;
  }
  Check_height(p,n);

}
void Inp_person(Person *per)
{
  printf("Name : ");
  scanf("%s",&(per -> name));
  printf("Sex : ");
  scanf("%s",&(per -> st));
  printf("Height : ");
  scanf("%u",&(per -> height)); //fgets(per -> height, N, stdin);
}
void Check_height(Person *p, int n)
{
  for(int i = 0; i < n - 1; i++)
  {
      for(int j = i + 1; j < n; j++)
      {
        if(p[i].height == p[j].height)
        {
          printf("%s and %s are the same height\n",p[i].name, p[j].name);
        }
      }
  }
}
