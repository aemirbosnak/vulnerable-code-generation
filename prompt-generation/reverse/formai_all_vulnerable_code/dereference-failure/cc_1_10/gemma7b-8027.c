//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct DateTime {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
} DateTime;

DateTime convert_string_to_datetime(char *date_string) {
  DateTime datetime;

  // Parse the date string
  char *year_str = strtok(date_string, "-");
  char *month_str = strtok(NULL, "-");
  char *day_str = strtok(NULL, "-");
  char *hour_str = strtok(NULL, ":");
  char *minute_str = strtok(NULL, ":");
  char *second_str = strtok(NULL, ":");

  // Convert the parsed values to integers
  datetime.year = atoi(year_str);
  datetime.month = atoi(month_str);
  datetime.day = atoi(day_str);
  datetime.hour = atoi(hour_str);
  datetime.minute = atoi(minute_str);
  datetime.second = atoi(second_str);

  return datetime;
}

int main() {
  char *date_string = "2023-04-01 12:00:00";
  DateTime datetime = convert_string_to_datetime(date_string);

  // Print the converted datetime
  printf("Year: %d\n", datetime.year);
  printf("Month: %d\n", datetime.month);
  printf("Day: %d\n", datetime.day);
  printf("Hour: %d\n", datetime.hour);
  printf("Minute: %d\n", datetime.minute);
  printf("Second: %d\n", datetime.second);

  return 0;
}