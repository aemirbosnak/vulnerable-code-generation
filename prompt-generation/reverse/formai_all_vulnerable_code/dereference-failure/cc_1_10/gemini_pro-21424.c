//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of years the user can travel.
#define MAX_YEARS 100

// Define the minimum number of years the user can travel.
#define MIN_YEARS 1

// Get the current year from the system.
int get_current_year() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  return tm->tm_year + 1900;
}

// Get the year the user wants to travel to.
int get_destination_year() {
  int year;
  printf("Enter the year you want to travel to (1900-%d): ", get_current_year());
  scanf("%d", &year);
  return year;
}

// Validate the user's input.
int validate_input(int year) {
  if (year < MIN_YEARS || year > MAX_YEARS) {
    printf("Invalid year. Please enter a year between %d and %d.\n", MIN_YEARS, MAX_YEARS);
    return 0;
  }
  return 1;
}

// Calculate the time difference between the current year and the destination year.
int calculate_time_difference(int current_year, int destination_year) {
  return destination_year - current_year;
}

// Print the results of the simulation.
void print_results(int time_difference) {
  printf("\nYou have traveled %d years %s.\n", abs(time_difference), time_difference < 0 ? "into the past" : "into the future");
}

int main() {
  // Get the current year.
  int current_year = get_current_year();

  // Get the year the user wants to travel to.
  int destination_year = get_destination_year();

  // Validate the user's input.
  if (!validate_input(destination_year)) {
    return 1;
  }

  // Calculate the time difference between the current year and the destination year.
  int time_difference = calculate_time_difference(current_year, destination_year);

  // Print the results of the simulation.
  print_results(time_difference);

  return 0;
}