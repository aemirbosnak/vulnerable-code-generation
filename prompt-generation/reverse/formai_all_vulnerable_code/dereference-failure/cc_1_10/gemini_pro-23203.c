//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the baggage types
#define SMALL_BAGS 0
#define MEDIUM_BAGS 1
#define LARGE_BAGS 2

// Define the belt speeds
#define SLOW_BELT_SPEED 1
#define MEDIUM_BELT_SPEED 2
#define FAST_BELT_SPEED 3

// Define the number of belts
#define NUM_BELTS 3

// Define the maximum number of bags on a belt
#define MAX_BAGS_ON_BELT 10

// Define the simulation time
#define SIMULATION_TIME 600

// Create the baggage handling system
struct baggage_handling_system {
  int num_belts;
  int belt_speeds[NUM_BELTS];
  int num_bags_on_belt[NUM_BELTS];
  int total_bags_handled;
};

// Create a new baggage handling system
struct baggage_handling_system* create_baggage_handling_system(int num_belts) {
  struct baggage_handling_system* system = malloc(sizeof(struct baggage_handling_system));
  system->num_belts = num_belts;
  
  srand(time(NULL));

  // Assign random speeds to the belts.
  for (int i = 0; i < NUM_BELTS; i++) {
    system->belt_speeds[i] = rand() % 3 + 1;
  }

  // Set the number of bags on each belt to 0.
  for (int i = 0; i < NUM_BELTS; i++) {
    system->num_bags_on_belt[i] = 0;
  }

  // Set the total number of bags handled to 0.
  system->total_bags_handled = 0;

  return system;
}

// Destroy the baggage handling system
void destroy_baggage_handling_system(struct baggage_handling_system* system) {
  free(system);
}

// Add a bag to the baggage handling system.
void add_bag(struct baggage_handling_system* system, int bag_type) {
    int belt_number = rand() % NUM_BELTS;
    while (system->num_bags_on_belt[belt_number] == MAX_BAGS_ON_BELT) {
        belt_number = rand() % NUM_BELTS;
    }
    system->num_bags_on_belt[belt_number]++;
    system->total_bags_handled++;
    printf("Added a bag of type %d to belt %d.\n", bag_type, belt_number);
}

// Move the bags on the baggage handling system.
void move_bags(struct baggage_handling_system* system) {
  for (int i = 0; i < NUM_BELTS; i++) {
    if (system->num_bags_on_belt[i] > 0) {
      system->num_bags_on_belt[i]--;
      printf("Moved a bag from belt %d.\n", i);
    }
  }
}

// Simulate the baggage handling system
void simulate_baggage_handling_system(struct baggage_handling_system* system, int simulation_time) {
  for (int i = 0; i < simulation_time; i++) {
    add_bag(system, rand() % 3);
    move_bags(system);
  }
}

// Print the statistics of the baggage handling system
void print_statistics(struct baggage_handling_system* system) {
  printf("Total bags handled: %d\n", system->total_bags_handled);
  for (int i = 0; i < NUM_BELTS; i++) {
    printf("Belt %d: %d bags handled\n", i, system->num_bags_on_belt[i]);
  }
}

int main() {
  // Create the baggage handling system
  struct baggage_handling_system* system = create_baggage_handling_system(NUM_BELTS);

  // Simulate the baggage handling system
  simulate_baggage_handling_system(system, SIMULATION_TIME);

  // Print the statistics of the baggage handling system
  print_statistics(system);

  // Destroy the baggage handling system
  destroy_baggage_handling_system(system);

  return 0;
}