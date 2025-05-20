//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define the number of floors in the elevator
#define NUM_FLOORS 10

// Define the elevator floor structure
typedef struct Floor {
  int floor_number;
  struct Floor* next_floor;
} Floor;

// Create a linked list of elevator floors
Floor* create_floor_list() {
  Floor* head = malloc(sizeof(Floor));
  head->floor_number = 1;
  head->next_floor = NULL;

  Floor* tail = head;
  for (int i = 2; i <= NUM_FLOORS; i++) {
    tail->next_floor = malloc(sizeof(Floor));
    tail = tail->next_floor;
    tail->floor_number = i;
    tail->next_floor = NULL;
  }

  return head;
}

// Simulate the elevator movement
void simulate_elevator(Floor* floor_list) {
  // Get the current floor number
  int current_floor = floor_list->floor_number;

  // Get the destination floor number
  int destination_floor = rand() % NUM_FLOORS + 1;

  // Check if the destination floor is different from the current floor
  if (destination_floor != current_floor) {
    // Move the elevator to the destination floor
    while (current_floor != destination_floor) {
      // Increment the current floor number
      current_floor++;

      // Print the current floor number
      printf("Current floor: %d\n", current_floor);

      // Sleep for a random amount of time
      sleep(rand() % 3);
    }

    // Print the destination floor number
    printf("Destination floor: %d\n", destination_floor);
  } else {
    printf("Already on the destination floor: %d\n", destination_floor);
  }
}

int main() {
  // Create the elevator floor list
  Floor* floor_list = create_floor_list();

  // Simulate the elevator movement
  simulate_elevator(floor_list);

  return 0;
}