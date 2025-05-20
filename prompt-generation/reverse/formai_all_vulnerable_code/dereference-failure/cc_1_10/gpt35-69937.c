//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: random
#include <stdio.h>
#include <time.h>

int main() {
  time_t current_time;
  struct tm * time_info;
  char time_string[50];

  time(&current_time);
  time_info = localtime(&current_time);
  
  strftime(time_string, 50, "%Y-%m-%d %H:%M:%S", time_info);
  printf("Welcome to the Time Travel Simulator! Current date and time: %s\n", time_string);

  int year, month, day, hour, minute;
  printf("Enter the year you want to travel to: ");
  scanf("%d", &year);
  
  printf("Enter the month you want to travel to (1-12): ");
  scanf("%d", &month);

  while (month < 1 || month > 12) {
    printf("Invalid input, please enter a number between 1 and 12: ");
    scanf("%d", &month);
  }

  printf("Enter the day you want to travel to (1-31): ");
  scanf("%d", &day);

  while (day < 1 || day > 31) {
    printf("Invalid input, please enter a number between 1 and 31: ");
    scanf("%d", &day);
  }

  printf("Enter the hour you want to travel to (0-23): ");
  scanf("%d", &hour);

  while (hour < 0 || hour > 23) {
    printf("Invalid input, please enter a number between 0 and 23: ");
    scanf("%d", &hour);
  }

  printf("Enter the minute you want to travel to (0-59): ");
  scanf("%d", &minute);

  while (minute < 0 || minute > 59) {
    printf("Invalid input, please enter a number between 0 and 59: ");
    scanf("%d", &minute);
  }

  time_info->tm_year = year - 1900;
  time_info->tm_mon = month - 1;
  time_info->tm_mday = day;
  time_info->tm_hour = hour;
  time_info->tm_min = minute;
  time_info->tm_sec = 0;

  current_time = mktime(time_info);
  time_info = localtime(&current_time);
  strftime(time_string, 50, "%Y-%m-%d %H:%M:%S", time_info);
  
  int years_passed = year - (time_info->tm_year + 1900);
  printf("You have traveled to %s, %d years have passed!\n", time_string, years_passed);  

  return 0;
}