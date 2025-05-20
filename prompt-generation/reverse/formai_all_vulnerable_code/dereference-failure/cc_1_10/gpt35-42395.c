//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: imaginative
#include <stdio.h>
#include <time.h>

int main() {
  // Get current time
  time_t current_time = time(NULL);
  
  // Set the time machine
  struct tm *time_machine = localtime(&current_time);
  time_machine->tm_year = 1920 - 1900;  // Travel back to 1920s
  time_machine->tm_mon = 0;
  time_machine->tm_mday = 1;
  time_machine->tm_hour = 0;
  time_machine->tm_min = 0;
  time_machine->tm_sec = 0;
  
  // Travel back in time
  time_t time_travelled = mktime(time_machine);
  
  // Get new time
  struct tm *new_time = localtime(&time_travelled);
  
  // Print the new time
  printf("Welcome to the time machine!\n\n");
  printf("We are currently in the year %d.\n", new_time->tm_year + 1900);
  printf("Let's travel back in time to the 1920s!\n");
  printf("Time machine is activated...\n");
  printf("Travelling back in time...\n");
  printf("Arrived in the year %d.\n\n", new_time->tm_year + 1900);
  
  // Wait for user input to travel to another year
  char input;
  do {
    printf("Enter any key to travel to a new year or 'q' to quit:\n");
    scanf("%c", &input);
    
    // Travel to a new year
    if (input != 'q') {
      int year;
      printf("Enter a year to travel to (1900-2020):\n");
      scanf("%d", &year);
      
      // Check validity of year
      if (year >= 1900 && year <= 2020) {
        time_machine->tm_year = year - 1900;
        time_travelled = mktime(time_machine);
        new_time = localtime(&time_travelled);
      } else {
        printf("Invalid year!\n");
      }
      
      // Print the new time
      printf("Time machine is activated...\n");
      printf("Travelling to the year %d...\n", new_time->tm_year + 1900);
      printf("Arrived in the year %d.\n\n", new_time->tm_year + 1900);
    }
  } while (input != 'q');
  
  // Goodbye message
  printf("Thanks for using the time machine!\n");
  printf("Hope you had a good time travelling through history.\n");
  
  return 0;
}