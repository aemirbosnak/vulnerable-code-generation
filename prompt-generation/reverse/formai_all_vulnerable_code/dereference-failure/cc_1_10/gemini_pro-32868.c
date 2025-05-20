//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_DATE_LENGTH 11
#define MAX_MONTH_NAME_LENGTH 10

typedef enum {
  SUNDAY,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY
} DayOfWeek;

typedef struct {
  unsigned short year;
  unsigned char month;
  unsigned char day;
  DayOfWeek day_of_week;
} Date;

static const char *month_names[] = {
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December"
};

static unsigned short days_in_month[] = {
  31,
  28,
  31,
  30,
  31,
  30,
  31,
  31,
  30,
  31,
  30,
  31
};

static unsigned short days_in_year[] = {
  365,
  366
};

static unsigned short days_in_leap_year[] = {
  366,
  365
};

static unsigned short days_in_non_leap_year[] = {
  365,
  365
};

static unsigned short days_in_month_and_year(unsigned short year, unsigned char month) {
  return days_in_month[month - 1] + ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 1 : 0);
}

static unsigned short days_in_year_and_month(unsigned short year, unsigned char month) {
  return days_in_year[(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 1 : 0] + days_in_month[month - 1];
}

static DayOfWeek day_of_week(unsigned short year, unsigned char month, unsigned char day) {
  unsigned short days_since_epoch = 0;
  for (unsigned short y = 1900; y < year; y++) {
    days_since_epoch += days_in_year[y % 4 == 0 ? 1 : 0];
  }
  for (unsigned char m = 1; m < month; m++) {
    days_since_epoch += days_in_month[m - 1];
  }
  days_since_epoch += day - 1;
  return (DayOfWeek) (days_since_epoch % 7);
}

static int parse_date(const char *str, Date *date) {
  char *endptr;
  date->year = strtoul(str, &endptr, 10);
  if (*endptr != '-') {
    return -1;
  }
  date->month = strtoul(endptr + 1, &endptr, 10);
  if (*endptr != '-') {
    return -1;
  }
  date->day = strtoul(endptr + 1, &endptr, 10);
  if (*endptr != '\0') {
    return -1;
  }
  date->day_of_week = day_of_week(date->year, date->month, date->day);
  return 0;
}

static void print_date(const Date *date) {
  printf("%s %hu, %hu\n", month_names[date->month - 1], date->day, date->year);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <date>\n", argv[0]);
    return EXIT_FAILURE;
  }
  Date date;
  if (parse_date(argv[1], &date) != 0) {
    fprintf(stderr, "Invalid date: %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  print_date(&date);
  return EXIT_SUCCESS;
}