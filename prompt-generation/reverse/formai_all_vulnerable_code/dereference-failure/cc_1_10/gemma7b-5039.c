//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DAYS 365
#define MAX_MONTHS 12
#define MAX_YEARS 100

typedef struct Date {
  int year;
  int month;
  int day;
} Date;

Date parse_date(char *date_str) {
  Date date;

  char *year_str = strtok(date_str, "-");
  date.year = atoi(year_str);

  char *month_str = strtok(NULL, "-");
  date.month = atoi(month_str);

  char *day_str = strtok(NULL, "-");
  date.day = atoi(day_str);

  return date;
}

int days_until(Date date1, Date date2) {
  int days_until = 0;

  int years_diff = date1.year - date2.year;
  for (int i = 0; i < years_diff; i++) {
    days_until += 365;
  }

  int months_diff = date1.month - date2.month;
  for (int i = 0; i < months_diff; i++) {
    days_until += 30;
  }

  days_until += date1.day - date2.day;

  return days_until;
}

int main() {
  char *date_str1 = "2023-01-01";
  char *date_str2 = "2023-01-03";

  Date date1 = parse_date(date_str1);
  Date date2 = parse_date(date_str2);

  int days_until_result = days_until(date1, date2);

  printf("The number of days until %s is %d.", date_str2, days_until_result);

  return 0;
}