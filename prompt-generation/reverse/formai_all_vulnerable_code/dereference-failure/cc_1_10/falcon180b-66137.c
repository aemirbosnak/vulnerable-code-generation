//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <locale.h>

struct tm* get_date(char* str);
char* format_date(struct tm* date, char* format);

int main(int argc, char* argv[]) {
  if (argc!= 3) {
    printf("Usage: %s <date> <format>\n", argv[0]);
    return 1;
  }

  setlocale(LC_TIME, "");
  char* date_str = argv[1];
  char* format_str = argv[2];

  struct tm* date = get_date(date_str);
  if (!date) {
    printf("Invalid date\n");
    return 1;
  }

  char* result = format_date(date, format_str);
  printf("%s\n", result);

  return 0;
}

struct tm* get_date(char* str) {
  struct tm date;
  memset(&date, 0, sizeof(struct tm));

  int year, month, day, hour, minute, second;
  sscanf(str, "%d-%d-%d %d:%d:%d", &day, &month, &year, &hour, &minute, &second);

  date.tm_year = year - 1900;
  date.tm_mon = month - 1;
  date.tm_mday = day;
  date.tm_hour = hour;
  date.tm_min = minute;
  date.tm_sec = second;

  return &date;
}

char* format_date(struct tm* date, char* format) {
  char* result = malloc(100);
  strftime(result, 100, format, date);
  return result;
}