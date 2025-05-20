//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Baggage types
#define NORMAL 0
#define FRAGILE 1
#define OVERSIZE 2

// Baggage handling statuses
#define IN_TRANSIT 0
#define ARRIVING 1
#define DEPARTING 2
#define UNLOADED 3

// Random number generator
#define RAND_MAX 2147483647

// Simulation parameters
#define NUM_BAGS 1000
#define NUM_CONVEYOR_BELTS 10
#define NUM_TERMINALS 3

// Baggage struct
typedef struct baggage {
  int type;
  int status;
  int arrival_time;
  int departure_time;
  int current_conveyor_belt;
  int destination_terminal;
} baggage_t;

// Conveyor belt struct
typedef struct conveyor_belt {
  baggage_t *baggages[NUM_BAGS];
  int num_baggages;
} conveyor_belt_t;

// Terminal struct
typedef struct terminal {
  conveyor_belt_t *conveyor_belts[NUM_CONVEYOR_BELTS];
  int num_conveyor_belts;
} terminal_t;

// Airport struct
typedef struct airport {
  terminal_t *terminals[NUM_TERMINALS];
  int num_terminals;
} airport_t;

// Function to generate random baggage
baggage_t *generate_baggage() {
  baggage_t *baggage = malloc(sizeof(baggage_t));
  baggage->type = rand() % 3;
  baggage->status = IN_TRANSIT;
  baggage->arrival_time = rand() % 100;
  baggage->departure_time = rand() % 100;
  baggage->current_conveyor_belt = -1;
  baggage->destination_terminal = rand() % NUM_TERMINALS;
  return baggage;
}

// Function to initialize the airport
airport_t *initialize_airport() {
  airport_t *airport = malloc(sizeof(airport_t));
  airport->num_terminals = NUM_TERMINALS;
  for (int i = 0; i < NUM_TERMINALS; i++) {
    airport->terminals[i] = malloc(sizeof(terminal_t));
    airport->terminals[i]->num_conveyor_belts = NUM_CONVEYOR_BELTS;
    for (int j = 0; j < NUM_CONVEYOR_BELTS; j++) {
      airport->terminals[i]->conveyor_belts[j] = malloc(sizeof(conveyor_belt_t));
      airport->terminals[i]->conveyor_belts[j]->num_baggages = 0;
    }
  }
  return airport;
}

// Function to simulate the baggage handling system
void simulate_baggage_handling(airport_t *airport) {
  // Create a list of bags
  baggage_t *bags[NUM_BAGS];
  for (int i = 0; i < NUM_BAGS; i++) {
    bags[i] = generate_baggage();
  }

  // Simulate the baggage handling system
  for (int i = 0; i < 1000; i++) {
    // Update the status of each bag
    for (int j = 0; j < NUM_BAGS; j++) {
      switch (bags[j]->status) {
        case IN_TRANSIT:
          // Check if the bag has arrived at its destination terminal
          if (bags[j]->arrival_time == i) {
            bags[j]->status = ARRIVING;
          }
          break;
        case ARRIVING:
          // Find a conveyor belt to put the bag on
          for (int k = 0; k < NUM_CONVEYOR_BELTS; k++) {
            if (airport->terminals[bags[j]->destination_terminal]->conveyor_belts[k]->num_baggages < NUM_BAGS) {
              airport->terminals[bags[j]->destination_terminal]->conveyor_belts[k]->baggages[airport->terminals[bags[j]->destination_terminal]->conveyor_belts[k]->num_baggages] = bags[j];
              airport->terminals[bags[j]->destination_terminal]->conveyor_belts[k]->num_baggages++;
              bags[j]->current_conveyor_belt = k;
              bags[j]->status = DEPARTING;
              break;
            }
          }
          break;
        case DEPARTING:
          // Check if the bag has reached its departure time
          if (bags[j]->departure_time == i) {
            bags[j]->status = UNLOADED;
          }
          break;
        case UNLOADED:
          // Remove the bag from the conveyor belt
          for (int k = 0; k < NUM_CONVEYOR_BELTS; k++) {
            if (airport->terminals[bags[j]->destination_terminal]->conveyor_belts[k]->baggages[j] == bags[j]) {
              airport->terminals[bags[j]->destination_terminal]->conveyor_belts[k]->baggages[j] = NULL;
              airport->terminals[bags[j]->destination_terminal]->conveyor_belts[k]->num_baggages--;
              break;
            }
          }
          break;
      }
    }
  }
}

// Function to print the status of the airport
void print_airport_status(airport_t *airport) {
  for (int i = 0; i < NUM_TERMINALS; i++) {
    printf("Terminal %d:\n", i);
    for (int j = 0; j < NUM_CONVEYOR_BELTS; j++) {
      printf("  Conveyor belt %d: ", j);
      for (int k = 0; k < NUM_BAGS; k++) {
        if (airport->terminals[i]->conveyor_belts[j]->baggages[k] != NULL) {
          printf("%d ", airport->terminals[i]->conveyor_belts[j]->baggages[k]->type);
        }
      }
      printf("\n");
    }
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the airport
  airport_t *airport = initialize_airport();

  // Simulate the baggage handling system
  simulate_baggage_handling(airport);

  // Print the status of the airport
  print_airport_status(airport);

  return 0;
}