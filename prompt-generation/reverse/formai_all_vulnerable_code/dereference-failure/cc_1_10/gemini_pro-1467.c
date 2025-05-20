//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
} CyberpunkDate;

typedef struct {
  char *month_names[12];
  char *day_names[7];
} CyberpunkCalendar;

CyberpunkCalendar cyberpunk_calendar = {
  .month_names = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
  },
  .day_names = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
  }
};

CyberpunkDate cyberpunk_date_from_string(char *date_string) {
  CyberpunkDate date;

  char *month_str = strtok(date_string, "/");
  char *day_str = strtok(NULL, "/");
  char *year_str = strtok(NULL, "/");

  int i;
  for (i = 0; i < 12; i++) {
    if (strcmp(month_str, cyberpunk_calendar.month_names[i]) == 0) {
      date.month = i + 1;
      break;
    }
  }

  date.day = atoi(day_str);
  date.year = atoi(year_str);

  return date;
}

char *cyberpunk_date_to_string(CyberpunkDate date) {
  char *date_string = malloc(20);

  sprintf(date_string, "%s %d, %d", cyberpunk_calendar.month_names[date.month - 1], date.day, date.year);

  return date_string;
}

int main() {
  char *date_string = "Jan/1/2023";

  CyberpunkDate date = cyberpunk_date_from_string(date_string);

  printf("Cyberpunk Date: %s\n", cyberpunk_date_to_string(date));

  return 0;
}