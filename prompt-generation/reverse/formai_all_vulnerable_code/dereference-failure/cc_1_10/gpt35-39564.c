//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // initialize variables
  int year, month, day, hour, minute, second;
  char timeTravel;
  
  // get current time using time() function
  time_t currentTime;
  time(&currentTime);
  
  // get localtime using localtime() function
  struct tm *localTime = localtime(&currentTime);

  // assign current time to variables
  year = localTime->tm_year + 1900;
  month = localTime->tm_mon + 1;
  day = localTime->tm_mday;
  hour = localTime->tm_hour;
  minute = localTime->tm_min;
  second = localTime->tm_sec;
  
  // print current time
  printf("Current Time: %d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);
  
  // prompt user to time travel
  printf("Do you want to time travel? (y/n): ");
  scanf(" %c", &timeTravel);
  
  if (timeTravel == 'y' || timeTravel == 'Y') {
    // prompt user to enter time to travel to
    printf("Enter the year (YYYY): ");
    scanf("%d", &year);
    printf("Enter the month (MM): ");
    scanf("%d", &month);
    printf("Enter the day (DD): ");
    scanf("%d", &day);
    printf("Enter the hour (HH): ");
    scanf("%d", &hour);
    printf("Enter the minute (MM): ");
    scanf("%d", &minute);
    printf("Enter the second (SS): ");
    scanf("%d", &second);
    
    // initialize a tm struct with the time to travel to
    struct tm travelTime = {0};
    travelTime.tm_year = year - 1900;
    travelTime.tm_mon = month - 1;
    travelTime.tm_mday = day;
    travelTime.tm_hour = hour;
    travelTime.tm_min = minute;
    travelTime.tm_sec = second;
    
    // convert tm struct to time_t using mktime() function
    time_t travelTime_t = mktime(&travelTime);
    
    // print time travel success message
    printf("Time travel successful!\n");
    
    // get localtime using localtime() function
    struct tm *localTime = localtime(&travelTime_t);
    
    // update variables with time travel time
    year = localTime->tm_year + 1900;
    month = localTime->tm_mon + 1;
    day = localTime->tm_mday;
    hour = localTime->tm_hour;
    minute = localTime->tm_min;
    second = localTime->tm_sec;
  }
  
  // print final time
  printf("Final Time: %d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);
  
  return 0;
}