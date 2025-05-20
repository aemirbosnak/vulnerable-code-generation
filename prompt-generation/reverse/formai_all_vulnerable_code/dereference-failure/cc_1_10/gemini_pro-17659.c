//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to convert a string to an integer
int strToInt(char *str) {
  int num = 0;
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    num = num * 10 + (str[i] - '0');
  }
  return num;
}

// Function to convert a string to a date
struct tm strToDate(char *str) {
  struct tm tm;
  char *p;

  // Extract the year
  p = strtok(str, "-");
  tm.tm_year = strToInt(p) - 1900;

  // Extract the month
  p = strtok(NULL, "-");
  tm.tm_mon = strToInt(p) - 1;

  // Extract the day
  p = strtok(NULL, "-");
  tm.tm_mday = strToInt(p);

  // Extract the hour
  p = strtok(NULL, ":");
  tm.tm_hour = strToInt(p);

  // Extract the minute
  p = strtok(NULL, ":");
  tm.tm_min = strToInt(p);

  // Extract the second
  p = strtok(NULL, ":");
  tm.tm_sec = strToInt(p);

  return tm;
}

// Function to convert a date to a string
char *dateToStr(struct tm *tm) {
  char *str = malloc(sizeof(char) * 20);
  sprintf(str, "%04d-%02d-%02d %02d:%02d:%02d", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
  return str;
}

int main() {
  // Get the current date and time
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

  // Convert the current date and time to a string
  char *str = dateToStr(tm);

  // Print the current date and time
  printf("Current date and time: %s\n", str);

  // Get a date from the user
  char input[20];
  printf("Enter a date (YYYY-MM-DD HH:MM:SS): ");
  scanf("%s", input);

  // Convert the date from the user to a tm struct
  struct tm tm2 = strToDate(input);

  // Convert the tm struct to a string
  char *str2 = dateToStr(&tm2);

  // Print the date from the user
  printf("Date from the user: %s\n", str2);

  return 0;
}