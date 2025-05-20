//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Time travel constants
#define MAX_TIME_TRAVEL 1000000000 // 1 billion seconds
#define MIN_TIME_TRAVEL -1000000000 // -1 billion seconds

// Define the time traveler struct
typedef struct {
  long int time;
  char *name;
} TimeTraveler;

// Create a new time traveler
TimeTraveler *create_time_traveler(long int time, char *name) {
  TimeTraveler *time_traveler = malloc(sizeof(TimeTraveler));
  time_traveler->time = time;
  time_traveler->name = name;
  return time_traveler;
}

// Destroy a time traveler
void destroy_time_traveler(TimeTraveler *time_traveler) {
  free(time_traveler);
}

// Time travel function
void time_travel(TimeTraveler *time_traveler, long int time) {
  if (time < MIN_TIME_TRAVEL || time > MAX_TIME_TRAVEL) {
    printf("Invalid time travel request. Time must be between %ld and %ld seconds.\n", MIN_TIME_TRAVEL, MAX_TIME_TRAVEL);
    return;
  }

  time_traveler->time = time;
  printf("%s has traveled to %ld seconds.\n", time_traveler->name, time_traveler->time);
}

// Main function
int main() {
  // Create a new time traveler
  TimeTraveler *time_traveler = create_time_traveler(time(NULL), "Marty McFly");

  // Time travel to the past
  time_travel(time_traveler, -1000000);

  // Time travel to the future
  time_travel(time_traveler, 1000000);

  // Destroy the time traveler
  destroy_time_traveler(time_traveler);

  return 0;
}