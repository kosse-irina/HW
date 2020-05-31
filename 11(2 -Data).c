#include <stdio.h>

typedef struct Date
  {
    unsigned day; unsigned month; unsigned year;
  } Date;
void inp(Date *p);
void out(const Date *p);
Date last_day(Date x); //вчорашній день
int Weekday(Date x); //день тижня

int main()
{
  Date k;
  inp(&k);
  Date v = last_day(k);
  out(&v);
  printf("Weekday  %d", Weekday(k));
}

void inp(Date *p)
{
  unsigned day, month, year;
  scanf("%u %u %u", &day, &month, &year ); // const n = ...;
  (*p).day = day;   // p->day = day;
  p -> month = month;
  p -> year = year;
}

void out(const Date *p)
{
    printf("%u %u %u\n", p -> day, p -> month, p -> year);
}
Date last_day(Date x)
{
  Date v;
  v.day = x.day - 1;
  v.month = x.month;
  v.year = x.year;
  int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (v.day == 0){v.day = month[v.month - 1], v.month -= 1;}
  if (v.month == 0){
    v.month = 1;
    v.year--;}

  return v;}
int Weekday(Date x)
{
  int cent[4] = {6, 4, 2, 0};
  int month[12] = {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
  int year = (cent[(x.year/100) % 4] + x.year % 100 + (x.year%100) / 4)%7;
  int s = (month[x.month-1] + x.day + year) % 7;
  if(x.year % 4 == 0 && x.month <= 2){s--;}
  if(s > 2){s--;}
  else{s+=6;}
  return s;
}
