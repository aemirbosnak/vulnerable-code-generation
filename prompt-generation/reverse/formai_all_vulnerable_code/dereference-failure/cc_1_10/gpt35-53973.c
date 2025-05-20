//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <time.h>

int main() {
  // Get the current time
  time_t current_time;
  struct tm *current_time_info;
  time(&current_time);
  current_time_info = localtime(&current_time);

  // Set the travel time
  struct tm travel_time_info = *current_time_info;
  travel_time_info.tm_year = 1969 - 1900;
  travel_time_info.tm_mon = 7; // August
  travel_time_info.tm_mday = 15;
  travel_time_info.tm_hour = 9;
  travel_time_info.tm_min = 32;
  travel_time_info.tm_sec = 0;
  time_t travel_time = mktime(&travel_time_info);

  printf("Welcome to the Time Travel Simulator!\n\n");

  // Mimic the countdown to time travel
  printf("Initializing time travel sequence...\n");
  for (int i = 5; i > 0; i--) {
    printf("%d...\n", i);
    sleep(1);
  }

  printf("\nTraveling to the past...\n\n");

  // Check if the travel time is in the past or future
  if (difftime(travel_time, current_time) < 0) { // Traveling to the past
    printf("Arrived at the specified time:\n");
    printf("%s", asctime(&travel_time_info));

    // Check the day of the week
    int day_of_week = travel_time_info.tm_wday;
    switch (day_of_week) {
      case 0:
        printf("It's Sunday!\n");
        break;
      case 1:
        printf("It's Monday!\n");
        break;
      case 2:
        printf("It's Tuesday!\n");
        break;
      case 3:
        printf("It's Wednesday!\n");
        break;
      case 4:
        printf("It's Thursday!\n");
        break;
      case 5:
        printf("It's Friday!\n");
        break;
      case 6:
        printf("It's Saturday!\n");
        break;
    }
  } else { // Traveling to the future
    printf("Oops, seems like we're heading to the future! Please set the time travel to the past.\n");
  }

  return 0;
}