//FormAI DATASET v1.0 Category: Date and time ; Style: content
/* A Unique C Example Program to Retrieve and Manipulate Date and Time*/

#include <stdio.h>
#include <time.h>

int main(){
  time_t curr_time;
  struct tm *curr_tm;
  char time_string[100];

  // Get current time in seconds
  curr_time = time(NULL);

  // Convert the current time to the local time zone
  curr_tm = localtime(&curr_time);

  // Format the current time as a string
  strftime(time_string, sizeof(time_string), "%c", curr_tm);

  // Print the current time
  printf("Current Time = %s\n", time_string);

  // Retrieve individual components of the current time
  int year = curr_tm->tm_year + 1900;
  int month = curr_tm->tm_mon + 1;
  int day = curr_tm->tm_mday;
  int hour = curr_tm->tm_hour;
  int minute = curr_tm->tm_min;
  int second = curr_tm->tm_sec;

  // Print the individual components of the current time
  printf("Year = %d\n", year);
  printf("Month = %d\n", month);
  printf("Day = %d\n", day);
  printf("Hour = %d\n", hour);
  printf("Minute = %d\n", minute);
  printf("Second = %d\n", second);

  // Increase the current time by one day
  curr_time += 24 * 60 * 60;

  // Convert the updated current time to the local time zone
  curr_tm = localtime(&curr_time);

  // Format the updated current time as a string
  strftime(time_string, sizeof(time_string), "%c", curr_tm);

  // Print the updated current time
  printf("Updated Time = %s", time_string);

  return 0;
}