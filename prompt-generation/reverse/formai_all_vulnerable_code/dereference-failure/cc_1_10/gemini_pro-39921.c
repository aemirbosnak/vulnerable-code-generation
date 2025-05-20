//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define the states of traffic light
#define RED 0
#define GREEN 1
#define YELLOW 2

// Define the duration of each state (in seconds)
#define RED_DURATION 30
#define GREEN_DURATION 45
#define YELLOW_DURATION 5

// Define the number of intersections
#define NUM_INTERSECTIONS 4

// Define the data structure for each intersection
typedef struct {
  int state;
  int time_remaining;
} Intersection;

// Initialize the traffic light controller
void initialize(Intersection* intersections) {
  for (int i = 0; i < NUM_INTERSECTIONS; i++) {
    intersections[i].state = RED;
    intersections[i].time_remaining = RED_DURATION;
  }
}

// Update the traffic light controller
void update(Intersection* intersections) {
  for (int i = 0; i < NUM_INTERSECTIONS; i++) {
    // Decrement the time remaining for the current state
    intersections[i].time_remaining--;

    // If the time remaining is 0, transition to the next state
    if (intersections[i].time_remaining == 0) {
      switch (intersections[i].state) {
        case RED:
          intersections[i].state = GREEN;
          intersections[i].time_remaining = GREEN_DURATION;
          break;
        case GREEN:
          intersections[i].state = YELLOW;
          intersections[i].time_remaining = YELLOW_DURATION;
          break;
        case YELLOW:
          intersections[i].state = RED;
          intersections[i].time_remaining = RED_DURATION;
          break;
      }
    }
  }
}

// Print the state of the traffic light controller
void print_state(Intersection* intersections) {
  for (int i = 0; i < NUM_INTERSECTIONS; i++) {
    switch (intersections[i].state) {
      case RED:
        printf("Intersection %d: RED\n", i);
        break;
      case GREEN:
        printf("Intersection %d: GREEN\n", i);
        break;
      case YELLOW:
        printf("Intersection %d: YELLOW\n", i);
        break;
    }
  }
}

// Main function
int main() {
  // Allocate memory for the traffic light controller
  Intersection* intersections = malloc(sizeof(Intersection) * NUM_INTERSECTIONS);

  // Initialize the traffic light controller
  initialize(intersections);

  // Update the traffic light controller for 100 seconds
  for (int i = 0; i < 100; i++) {
    update(intersections);
  }

  // Print the state of the traffic light controller
  print_state(intersections);

  // Free the memory allocated for the traffic light controller
  free(intersections);

  return 0;
}