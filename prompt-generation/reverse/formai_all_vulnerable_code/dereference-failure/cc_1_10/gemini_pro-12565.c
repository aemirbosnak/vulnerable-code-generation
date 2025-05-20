//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Baggage handling system simulation
typedef struct baggage {
  int id;
  int weight;
  int destination;
  struct baggage *next;
} baggage;

// Airport simulation
typedef struct airport {
  char *name;
  int num_gates;
  int num_baggage_handlers;
  struct baggage *baggage_queue;
} airport;

// Baggage handler simulation
typedef struct baggage_handler {
  int id;
  int speed;
  int current_baggage;
  struct baggage_handler *next;
} baggage_handler;

// Create a new baggage
baggage *create_baggage(int id, int weight, int destination) {
  baggage *new_baggage = malloc(sizeof(baggage));
  new_baggage->id = id;
  new_baggage->weight = weight;
  new_baggage->destination = destination;
  new_baggage->next = NULL;
  return new_baggage;
}

// Create a new airport
airport *create_airport(char *name, int num_gates, int num_baggage_handlers) {
  airport *new_airport = malloc(sizeof(airport));
  new_airport->name = name;
  new_airport->num_gates = num_gates;
  new_airport->num_baggage_handlers = num_baggage_handlers;
  new_airport->baggage_queue = NULL;
  return new_airport;
}

// Create a new baggage handler
baggage_handler *create_baggage_handler(int id, int speed) {
  baggage_handler *new_baggage_handler = malloc(sizeof(baggage_handler));
  new_baggage_handler->id = id;
  new_baggage_handler->speed = speed;
  new_baggage_handler->current_baggage = -1;
  new_baggage_handler->next = NULL;
  return new_baggage_handler;
}

// Add baggage to the airport queue
void add_baggage_to_queue(airport *airport, baggage *baggage) {
  if (airport->baggage_queue == NULL) {
    airport->baggage_queue = baggage;
  } else {
    baggage->next = airport->baggage_queue;
    airport->baggage_queue = baggage;
  }
}

// Remove baggage from the airport queue
baggage *remove_baggage_from_queue(airport *airport) {
  if (airport->baggage_queue == NULL) {
    return NULL;
  } else {
    baggage *baggage = airport->baggage_queue;
    airport->baggage_queue = baggage->next;
    return baggage;
  }
}

// Assign a baggage handler to a baggage
void assign_baggage_handler_to_baggage(baggage_handler *baggage_handler, baggage *baggage) {
  baggage_handler->current_baggage = baggage->id;
  baggage->next = NULL;
}

// Unassign a baggage handler from a baggage
void unassign_baggage_handler_from_baggage(baggage_handler *baggage_handler) {
  baggage_handler->current_baggage = -1;
}

// Move baggage from the airport queue to the baggage handler
void move_baggage_to_baggage_handler(airport *airport, baggage_handler *baggage_handler) {
  baggage *baggage = remove_baggage_from_queue(airport);
  if (baggage != NULL) {
    assign_baggage_handler_to_baggage(baggage_handler, baggage);
  }
}

// Move baggage from the baggage handler to the destination
void move_baggage_to_destination(baggage_handler *baggage_handler) {
  baggage *baggage = baggage_handler->current_baggage;
  if (baggage != NULL) {
    // Simulate baggage being moved to the destination
    unassign_baggage_handler_from_baggage(baggage_handler);
  }
}

// Simulate the airport baggage handling system
void simulate_airport(airport *airport, baggage_handler *baggage_handlers) {
  // Create a random number of baggage
  int num_baggage = rand() % 100;
  for (int i = 0; i < num_baggage; i++) {
    baggage *baggage = create_baggage(i, rand() % 100, rand() % 10);
    add_baggage_to_queue(airport, baggage);
  }

  // Create a random number of baggage handlers
  int num_baggage_handlers = rand() % 10;
  for (int i = 0; i < num_baggage_handlers; i++) {
    baggage_handler *baggage_handler = create_baggage_handler(i, rand() % 10);
    baggage_handlers = baggage_handler;
  }

  // Simulate the baggage handling system
  while (airport->baggage_queue != NULL) {
    for (baggage_handler *baggage_handler = baggage_handlers; baggage_handler != NULL; baggage_handler = baggage_handler->next) {
      if (baggage_handler->current_baggage == -1) {
        move_baggage_to_baggage_handler(airport, baggage_handler);
      } else {
        move_baggage_to_destination(baggage_handler);
      }
    }
  }
}

// Print the airport baggage handling system simulation results
void print_simulation_results(airport *airport, baggage_handler *baggage_handlers) {
  printf("Airport: %s\n", airport->name);
  printf("Number of gates: %d\n", airport->num_gates);
  printf("Number of baggage handlers: %d\n", airport->num_baggage_handlers);
  printf("Baggage queue:\n");
  for (baggage *baggage = airport->baggage_queue; baggage != NULL; baggage = baggage->next) {
    printf("  ID: %d, Weight: %d, Destination: %d\n", baggage->id, baggage->weight, baggage->destination);
  }
  printf("Baggage handlers:\n");
  for (baggage_handler *baggage_handler = baggage_handlers; baggage_handler != NULL; baggage_handler = baggage_handler->next) {
    printf("  ID: %d, Speed: %d, Current baggage: %d\n", baggage_handler->id, baggage_handler->speed, baggage_handler->current_baggage);
  }
}

// Main function
int main() {
  // Create a random airport
  airport *airport = create_airport("Los Angeles International Airport", 100, 100);

  // Create a random number of baggage handlers
  baggage_handler *baggage_handlers = NULL;
  for (int i = 0; i < 10; i++) {
    baggage_handler *new_baggage_handler = create_baggage_handler(i, rand() % 10);
    new_baggage_handler->next = baggage_handlers;
    baggage_handlers = new_baggage_handler;
  }

  // Simulate the airport baggage handling system
  simulate_airport(airport, baggage_handlers);

  // Print the airport baggage handling system simulation results
  print_simulation_results(airport, baggage_handlers);

  return 0;
}