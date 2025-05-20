//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int id;
  int weight;
  int destination;
} Baggage;

typedef struct {
  int id;
  int capacity;
  int num_bags;
  Baggage* bags;
} ConveyorBelt;

typedef struct {
  int id;
  int num_belts;
  ConveyorBelt* belts;
} Airport;

// Creates a new airport with the given number of conveyor belts.
Airport* create_airport(int num_belts) {
  Airport* airport = (Airport*)malloc(sizeof(Airport));
  airport->id = rand() % 10000;
  airport->num_belts = num_belts;
  airport->belts = (ConveyorBelt*)malloc(sizeof(ConveyorBelt) * num_belts);
  for (int i = 0; i < num_belts; i++) {
    airport->belts[i].id = rand() % 10000;
    airport->belts[i].capacity = rand() % 100;
    airport->belts[i].num_bags = 0;
    airport->belts[i].bags = (Baggage*)malloc(sizeof(Baggage) * airport->belts[i].capacity);
  }
  return airport;
}

// Creates a new baggage with the given weight and destination.
Baggage* create_baggage(int weight, int destination) {
  Baggage* baggage = (Baggage*)malloc(sizeof(Baggage));
  baggage->id = rand() % 10000;
  baggage->weight = weight;
  baggage->destination = destination;
  return baggage;
}

// Adds the given baggage to the given conveyor belt.
void add_baggage_to_belt(ConveyorBelt* belt, Baggage* baggage) {
  if (belt->num_bags < belt->capacity) {
    belt->bags[belt->num_bags] = *baggage;
    belt->num_bags++;
  }
}

// Moves the baggage from the given conveyor belt to the next conveyor belt.
void move_baggage(Airport* airport, ConveyorBelt* belt) {
  if (belt->num_bags > 0) {
    ConveyorBelt* next_belt = &airport->belts[(belt->id + 1) % airport->num_belts];
    for (int i = 0; i < belt->num_bags; i++) {
      add_baggage_to_belt(next_belt, &belt->bags[i]);
    }
    belt->num_bags = 0;
  }
}

// Simulates the movement of baggage through the airport.
void simulate_airport(Airport* airport) {
  while (1) {
    // Create a new baggage with a random weight and destination.
    Baggage* baggage = create_baggage(rand() % 100, rand() % airport->num_belts);

    // Add the baggage to the first conveyor belt.
    add_baggage_to_belt(&airport->belts[0], baggage);

    // Move the baggage through the airport.
    for (int i = 0; i < airport->num_belts; i++) {
      move_baggage(airport, &airport->belts[i]);
    }

    // Check if the baggage has reached its destination.
    if (baggage->destination == airport->num_belts - 1) {
      // The baggage has reached its destination.
      printf("Baggage %d has arrived at its destination on belt %d.\n", baggage->id, baggage->destination);
    }
  }
}

// Frees the memory allocated for the airport.
void destroy_airport(Airport* airport) {
  for (int i = 0; i < airport->num_belts; i++) {
    free(airport->belts[i].bags);
  }
  free(airport->belts);
  free(airport);
}

int main() {
  // Create a new airport with 10 conveyor belts.
  Airport* airport = create_airport(10);

  // Simulate the movement of baggage through the airport.
  simulate_airport(airport);

  // Free the memory allocated for the airport.
  destroy_airport(airport);

  return 0;
}