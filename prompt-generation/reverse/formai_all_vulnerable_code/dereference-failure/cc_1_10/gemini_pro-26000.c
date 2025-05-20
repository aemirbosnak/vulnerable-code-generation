//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: scalable
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Define the maximum number of years to travel
#define MAX_YEARS 100

// Define the structure for a time traveler
typedef struct {
  int year;
  char *name;
} time_traveler;

// Create a time traveler
time_traveler *create_time_traveler(int year, char *name) {
  time_traveler *tt = malloc(sizeof(time_traveler));
  tt->year = year;
  tt->name = name;
  return tt;
}

// Travel through time
void time_travel(time_traveler *tt, int years) {
  tt->year += years;
}

// Print the time traveler's information
void print_time_traveler(time_traveler *tt) {
  printf("Name: %s\n", tt->name);
  printf("Year: %d\n", tt->year);
}

// Free the memory allocated for the time traveler
void free_time_traveler(time_traveler *tt) {
  free(tt->name);
  free(tt);
}

// Main function
int main() {
  // Create a time traveler
  time_traveler *tt = create_time_traveler(2023, "John Doe");

  // Travel through time
  time_travel(tt, 10);

  // Print the time traveler's information
  print_time_traveler(tt);

  // Free the memory allocated for the time traveler
  free_time_traveler(tt);

  return 0;
}