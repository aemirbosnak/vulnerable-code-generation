//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TIME_TRAVEL_DIST 10000000000LL

int main(int argc, char *argv[]) {
  time_t now;
  struct tm *tm;
  int year, month, day, hour, minute, second;

  if (argc != 7) {
    fprintf(stderr, "Usage: %s year month day hour minute second\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  year = atoi(argv[1]);
  month = atoi(argv[2]);
  day = atoi(argv[3]);
  hour = atoi(argv[4]);
  minute = atoi(argv[5]);
  second = atoi(argv[6]);

  if (year < 1900 || year > 2100) {
    fprintf(stderr, "Invalid year: %d\n", year);
    exit(EXIT_FAILURE);
  }

  if (month < 1 || month > 12) {
    fprintf(stderr, "Invalid month: %d\n", month);
    exit(EXIT_FAILURE);
  }

  if (day < 1 || day > 31) {
    fprintf(stderr, "Invalid day: %d\n", day);
    exit(EXIT_FAILURE);
  }

  if (hour < 0 || hour > 23) {
    fprintf(stderr, "Invalid hour: %d\n", hour);
    exit(EXIT_FAILURE);
  }

  if (minute < 0 || minute > 59) {
    fprintf(stderr, "Invalid minute: %d\n", minute);
    exit(EXIT_FAILURE);
  }

  if (second < 0 || second > 59) {
    fprintf(stderr, "Invalid second: %d\n", second);
    exit(EXIT_FAILURE);
  }

  now = time(NULL);
  tm = localtime(&now);

  tm->tm_year = year - 1900;
  tm->tm_mon = month - 1;
  tm->tm_mday = day;
  tm->tm_hour = hour;
  tm->tm_min = minute;
  tm->tm_sec = second;

  if (tm->tm_year < tm->tm_mon || tm->tm_year > tm->tm_mday || tm->tm_mon < tm->tm_hour || tm->tm_mon > tm->tm_min || tm->tm_hour < tm->tm_sec || tm->tm_hour > tm->tm_mday || tm->tm_min < tm->tm_sec || tm->tm_min > tm->tm_mday || tm->tm_sec < tm->tm_hour || tm->tm_sec > tm->tm_mday) {
    fprintf(stderr, "Invalid date and time: %s\n", asctime(tm));
    exit(EXIT_FAILURE);
  }

  now = mktime(tm);

  printf("You have traveled back in time to %s", asctime(tm));

  while (1) {
    sleep(1);

    now += 1;

    tm = localtime(&now);

    printf("\rYou have traveled back in time to %s", asctime(tm));
  }

  return EXIT_SUCCESS;
}