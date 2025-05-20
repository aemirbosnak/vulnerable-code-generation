//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <time.h>

int main(void) {
  time_t present_time;
  struct tm* present;
  char time_string[100];

  // Get the present time
  present_time = time(NULL);
  present = localtime(&present_time);

  // Output the present time
  strftime(time_string, sizeof(time_string), "%c", present);
  printf("Present time: %s\n", time_string);

  // Set the time machine
  struct tm time_machine;
  time_machine.tm_year = 109;
  time_machine.tm_mon = 6;
  time_machine.tm_mday = 1;
  time_machine.tm_hour = 0;
  time_machine.tm_min = 0;
  time_machine.tm_sec = 0;

  // Convert the time machine to seconds since the epoch
  time_t time_machine_time = mktime(&time_machine);

  // Output the time machine time
  present = localtime(&time_machine_time);
  strftime(time_string, sizeof(time_string), "%c", present);
  printf("Time machine time: %s\n", time_string);

  // Wait until it's time to travel
  while (present_time < time_machine_time) {
    present_time = time(NULL);
    present = localtime(&present_time);
  }

  // Travel to the past
  printf("\nYou have traveled back in time!\n");

  // Set the time machine to return to the present
  time_machine.tm_year = present->tm_year;
  time_machine.tm_mon = present->tm_mon;
  time_machine.tm_mday = present->tm_mday;
  time_machine.tm_hour = present->tm_hour;
  time_machine.tm_min = present->tm_min;
  time_machine.tm_sec = present->tm_sec;

  // Convert the time machine to seconds since the epoch
  time_machine_time = mktime(&time_machine);

  // Wait until it's time to return to the present
  while (present_time < time_machine_time) {
    present_time = time(NULL);
    present = localtime(&present_time);
  }

  // Return to the present
  printf("\nYou have returned to the present!\n");

  return 0;
}