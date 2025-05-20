//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: invasive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define MAX_TIME_TRAVELS 10

// Global variables to track the current time and the number of time travels
time_t current_time;
int num_time_travels = 0;

// Function to simulate time travel
void time_travel(int years) {
  // Check if the number of time travels has exceeded the maximum
  if (num_time_travels >= MAX_TIME_TRAVELS) {
    printf("You have exceeded the maximum number of time travels (%d).\n", MAX_TIME_TRAVELS);
    return;
  }
  
  // Update the current time
  current_time += years * 31557600; // Convert years to seconds
  
  // Increment the number of time travels
  num_time_travels++;
  
  // Print a message to indicate that time travel has occurred
  printf("You have traveled %d years into the future.\n", years);
}

// Function to check if the given year is valid
bool is_valid_year(int year) {
  return year >= 1970 && year <= 2038;
}

// Main function
int main(int argc, char* argv[]) {
  // Set the current time to the current system time
  time(&current_time);

  // Print the current time
  printf("Current time: %s\n", ctime(&current_time));

  // Get the year to time travel to from the command line
  if (argc != 2) {
    printf("Usage: %s <year>\n", argv[0]);
    return EXIT_FAILURE;
  }
  
  int year = atoi(argv[1]);
  
  // Check if the given year is valid
  if (!is_valid_year(year)) {
    printf("Invalid year: %d\n", year);
    return EXIT_FAILURE;
  }
  
  // Time travel to the given year
  time_travel(year);
  
  // Print the new time
  printf("New time: %s\n", ctime(&current_time));
  
  return EXIT_SUCCESS;
}