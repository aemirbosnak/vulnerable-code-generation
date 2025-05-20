//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: puzzling
#include <stdio.h>
#include <time.h>

int main()
{
  time_t current_time;
  struct tm * time_info;
  char timeString[9];
  int year, month, day, hour, minute, second;

  // Obtain current time
  current_time = time(NULL);
  time_info = localtime(&current_time);

  // Set time information to the year 1900
  time_info->tm_year = 0;
  time_info->tm_mday = 1;
  mktime(time_info);

  // Output current time and the time in 1900
  strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
  printf("Current time: %s\n", timeString);

  strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", time_info);
  printf("Time travel to the year 1900:\n%s\n", timeString);

  // Prompt user for birth year, month, and day
  printf("Enter your birth year: ");
  scanf("%d", &year);
  getchar();

  printf("Enter your birth month: ");
  scanf("%d", &month);
  getchar();

  printf("Enter your birth day: ");
  scanf("%d", &day);
  getchar();

  // Set time information to the user's birthdate
  time_info->tm_year = year - 1900;
  time_info->tm_mon = month - 1;
  time_info->tm_mday = day;
  mktime(time_info);

  // Output user's birthdate and their age at the time of time travel
  strftime(timeString, sizeof(timeString), "%Y-%m-%d", time_info);
  printf("You were born on %s.\n", timeString);

  year -= 1900;
  if (year > 0)
    printf("You are %d years old when time traveling to the year 1900.\n", time_info->tm_year - year);
  else
    printf("You haven't even been born yet when time traveling to the year 1900!\n");

  // Prompt user for desired time
  printf("Enter a desired year: ");
  scanf("%d", &year);
  getchar();

  printf("Enter a desired month: ");
  scanf("%d", &month);
  getchar();

  printf("Enter a desired day: ");
  scanf("%d", &day);
  getchar();

  printf("Enter a desired hour: ");
  scanf("%d", &hour);
  getchar();

  printf("Enter a desired minute: ");
  scanf("%d", &minute);
  getchar();

  printf("Enter a desired second: ");
  scanf("%d", &second);
  getchar();

  // Set time information to the user's desired time
  time_info->tm_year = year - 1900;
  time_info->tm_mon = month - 1;
  time_info->tm_mday = day;
  time_info->tm_hour = hour;
  time_info->tm_min = minute;
  time_info->tm_sec = second;
  mktime(time_info);

  // Output user's desired time and the difference in time travel
  strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", time_info);
  printf("You have traveled to the following date and time:\n%s\n", timeString);

  if (year > 0)
    printf("The time difference is %d years, %d months, %d days, %d hours, %d minutes, and %d seconds.\n", year, month-1, day-1, hour, minute, second);
  else
    printf("The time difference is 0 years, %d months, %d days, %d hours, %d minutes, and %d seconds.\n", month-1, day-1, hour, minute, second);

  return 0;
}