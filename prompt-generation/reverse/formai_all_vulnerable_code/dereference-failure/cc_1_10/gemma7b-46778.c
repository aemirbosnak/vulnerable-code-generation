//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER_SIZE 256

typedef struct DateConverter {
  char *month_name;
  int day;
  int year;
} DateConverter;

int main() {
  DateConverter *converter = malloc(sizeof(DateConverter));
  converter->month_name = malloc(MAX_BUFFER_SIZE);
  converter->day = 0;
  converter->year = 0;

  printf("Enter the month name (e.g. January, February): ");
  scanf("%s", converter->month_name);

  printf("Enter the day of the month (1-31): ");
  scanf("%d", &converter->day);

  printf("Enter the year (e.g. 2023): ");
  scanf("%d", &converter->year);

  time_t timestamp = mktime(NULL);
  struct tm *tm_struct = localtime(&timestamp);

  tm_struct->tm_mon = get_month_number(converter->month_name);
  tm_struct->tm_mday = converter->day;
  tm_struct->tm_year = converter->year;

  printf("The date you entered is: ");
  printf("%d %s %d, %d", tm_struct->tm_mday, converter->month_name, tm_struct->tm_year, tm_struct->tm_hour);

  free(converter->month_name);
  free(converter);

  return 0;
}

int get_month_number(char *month_name) {
  int month_number = 0;

  if (strcmp(month_name, "January") == 0) {
    month_number = 0;
  } else if (strcmp(month_name, "February") == 0) {
    month_number = 1;
  } else if (strcmp(month_name, "March") == 0) {
    month_number = 2;
  } else if (strcmp(month_name, "April") == 0) {
    month_number = 3;
  } else if (strcmp(month_name, "May") == 0) {
    month_number = 4;
  } else if (strcmp(month_name, "June") == 0) {
    month_number = 5;
  } else if (strcmp(month_name, "July") == 0) {
    month_number = 6;
  } else if (strcmp(month_name, "August") == 0) {
    month_number = 7;
  } else if (strcmp(month_name, "September") == 0) {
    month_number = 8;
  } else if (strcmp(month_name, "October") == 0) {
    month_number = 9;
  } else if (strcmp(month_name, "November") == 0) {
    month_number = 10;
  } else if (strcmp(month_name, "December") == 0) {
    month_number = 11;
  } else {
    printf("Error: Invalid month name.\n");
  }

  return month_number;
}