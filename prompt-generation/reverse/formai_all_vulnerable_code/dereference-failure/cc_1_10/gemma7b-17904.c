//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER_SIZE 256

typedef struct DateConverter {
  char buffer[MAX_BUFFER_SIZE];
  time_t timestamp;
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
} DateConverter;

DateConverter *createDateConverter() {
  DateConverter *converter = malloc(sizeof(DateConverter));
  converter->buffer[0] = '\0';
  converter->timestamp = time(NULL);
  converter->year = 0;
  converter->month = 0;
  converter->day = 0;
  converter->hour = 0;
  converter->minute = 0;
  converter->second = 0;
  return converter;
}

void convertDate(DateConverter *converter) {
  char *dateStr = converter->buffer;
  time_t timestamp = converter->timestamp;

  struct tm *tm = localtime(&timestamp);
  converter->year = tm->tm_year + 1900;
  converter->month = tm->tm_mon + 1;
  converter->day = tm->tm_mday;
  converter->hour = tm->tm_hour;
  converter->minute = tm->tm_min;
  converter->second = tm->tm_sec;

  sprintf(dateStr, "%d-%d-%d %d:%d:%d", converter->year, converter->month, converter->day, converter->hour, converter->minute, converter->second);
}

int main() {
  DateConverter *converter = createDateConverter();
  convertDate(converter);

  printf("Date: %s\n", converter->buffer);

  free(converter);

  return 0;
}