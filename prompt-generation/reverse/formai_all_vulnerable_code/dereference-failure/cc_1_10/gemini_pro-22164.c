//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the time travel simulator struct
typedef struct {
  int year;
  int month;
  int day;
} Time;

// Create a new time travel simulator
Time *new_time_travel_simulator() {
  Time *time_travel_simulator = malloc(sizeof(Time));
  time_travel_simulator->year = 2023;
  time_travel_simulator->month = 1;
  time_travel_simulator->day = 1;
  return time_travel_simulator;
}

// Free the time travel simulator
void free_time_travel_simulator(Time *time_travel_simulator) {
  free(time_travel_simulator);
}

// Travel to a specific date
void travel_to_date(Time *time_travel_simulator, int year, int month, int day) {
  time_travel_simulator->year = year;
  time_travel_simulator->month = month;
  time_travel_simulator->day = day;
}

// Get the current date
void get_current_date(Time *time_travel_simulator) {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  time_travel_simulator->year = tm->tm_year + 1900;
  time_travel_simulator->month = tm->tm_mon + 1;
  time_travel_simulator->day = tm->tm_mday;
}

// Print the current date
void print_current_date(Time *time_travel_simulator) {
  printf("The current date is: %d-%d-%d\n", time_travel_simulator->year, time_travel_simulator->month, time_travel_simulator->day);
}

// Main function
int main() {
  // Create a new time travel simulator
  Time *time_travel_simulator = new_time_travel_simulator();

  // Travel to a specific date
  travel_to_date(time_travel_simulator, 2024, 2, 29);

  // Get the current date
  get_current_date(time_travel_simulator);

  // Print the current date
  print_current_date(time_travel_simulator);

  // Free the time travel simulator
  free_time_travel_simulator(time_travel_simulator);

  return 0;
}