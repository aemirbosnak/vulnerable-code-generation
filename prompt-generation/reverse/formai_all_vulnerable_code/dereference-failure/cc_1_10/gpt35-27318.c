//FormAI DATASET v1.0 Category: Date and time ; Style: recursive
#include <stdio.h>
#include <time.h>

void print_time(struct tm *timeinfo) {
  printf("Current time: %02d:%02d:%02d\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}

void print_date(struct tm *timeinfo) {
  printf("Current date: %02d/%02d/%d\n", timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_year + 1900);
}

void recursive_time(int seconds) {
  time_t rawtime;
  struct tm *timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  print_time(timeinfo);

  if (seconds > 0) {
    sleep(1);
    recursive_time(seconds - 1);
  }
}

void recursive_date(int days) {
  time_t rawtime;
  struct tm *timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  print_date(timeinfo);

  if (days > 0) {
    sleep(86400);
    recursive_date(days - 1);
  }
}

int main() {
  int seconds = 10;
  int days = 3;

  printf("Recursive Time:\n");
  recursive_time(seconds);

  printf("Recursive Date:\n");
  recursive_date(days);

  return 0;
}