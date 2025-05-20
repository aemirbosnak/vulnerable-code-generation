//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_WEIGHT 50

// Structure for the baggage
typedef struct {
  int baggage_id;
  float weight;
} Baggage;

// Structure for the conveyor belt
typedef struct {
  Baggage *baggage;
  int current_num_baggages;
  int max_num_baggages;
} ConveyorBelt;

// Function to generate a random weight for a baggage
float generate_random_weight() {
  return (float)rand()/(float)(RAND_MAX/MAX_WEIGHT);
}

// Function to generate a random baggage
Baggage generate_random_baggage(int baggage_id) {
  Baggage baggage;
  baggage.baggage_id = baggage_id;
  baggage.weight = generate_random_weight();
  return baggage;
}

// Function to print the baggage info
void print_baggage_info(Baggage baggage) {
  printf("Baggage %d: %.2f kg\n", baggage.baggage_id, baggage.weight);
}

// Function to print the conveyor belt status
void print_conveyor_belt_status(ConveyorBelt *conveyor_belt) {
  printf("Conveyor Belt Status:\n");
  printf("Number of baggages: %d/%d\n", conveyor_belt->current_num_baggages, conveyor_belt->max_num_baggages);
  for (int i = 0; i < conveyor_belt->current_num_baggages; i++) {
    print_baggage_info(conveyor_belt->baggage[i]);
  }
}

// Function to add a baggage to the conveyor belt
void add_baggage_to_conveyor_belt(ConveyorBelt *conveyor_belt, Baggage baggage) {
  conveyor_belt->baggage[conveyor_belt->current_num_baggages] = baggage;
  conveyor_belt->current_num_baggages++;
}

// Function to remove a baggage from the conveyor belt
void remove_baggage_from_conveyor_belt(ConveyorBelt *conveyor_belt, int index) {
  for (int i = index; i < conveyor_belt->current_num_baggages - 1; i++) {
    conveyor_belt->baggage[i] = conveyor_belt->baggage[i+1];
  }
  conveyor_belt->current_num_baggages--;
}

// Function to simulate the operation of the baggage handling system
void simulate_baggage_handling_system(int num_baggages, int max_num_baggages, int num_iterations) {
  ConveyorBelt conveyor_belt;
  conveyor_belt.max_num_baggages = max_num_baggages;
  conveyor_belt.baggage = (Baggage *)malloc(max_num_baggages * sizeof(Baggage));
  conveyor_belt.current_num_baggages = 0;

  // Generate the initial set of baggages
  for (int i = 0; i < num_baggages; i++) {
    Baggage baggage = generate_random_baggage(i+1);
    add_baggage_to_conveyor_belt(&conveyor_belt, baggage);
  }

  // Simulate the operation of the baggage handling system for num_iterations iterations
  for (int i = 0; i < num_iterations; i++) {
    // Randomly select a baggage
    int index = rand() % conveyor_belt.current_num_baggages;
    Baggage selected_baggage = conveyor_belt.baggage[index];
    // Remove the selected baggage from the conveyor belt
    remove_baggage_from_conveyor_belt(&conveyor_belt, index);
    // Print the status of the conveyor belt
    printf("Iteration %d\n", i+1);
    print_conveyor_belt_status(&conveyor_belt);
    // Add the selected baggage back on the conveyor belt
    add_baggage_to_conveyor_belt(&conveyor_belt, selected_baggage);
  }
}

int main() {
  srand((unsigned int)time(NULL));
  simulate_baggage_handling_system(20, MAX_BAGGAGE, 10);
  return 0;
}