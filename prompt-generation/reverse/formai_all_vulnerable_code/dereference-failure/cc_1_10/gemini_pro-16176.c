//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct baggage {
  int id;
  int weight;
  int destination;
} baggage;

typedef struct conveyor_belt {
  int id;
  int length;
  int speed;
  struct baggage *baggage;
} conveyor_belt;

typedef struct airport {
  int id;
  char *name;
  int num_conveyor_belts;
  struct conveyor_belt *conveyor_belts;
} airport;

// Create a new airport
airport *create_airport(int id, char *name, int num_conveyor_belts) {
  airport *new_airport = (airport *)malloc(sizeof(airport));
  new_airport->id = id;
  new_airport->name = name;
  new_airport->num_conveyor_belts = num_conveyor_belts;
  new_airport->conveyor_belts = (conveyor_belt *)malloc(sizeof(conveyor_belt) * num_conveyor_belts);
  return new_airport;
}

// Create a new conveyor belt
conveyor_belt *create_conveyor_belt(int id, int length, int speed) {
  conveyor_belt *new_conveyor_belt = (conveyor_belt *)malloc(sizeof(conveyor_belt));
  new_conveyor_belt->id = id;
  new_conveyor_belt->length = length;
  new_conveyor_belt->speed = speed;
  new_conveyor_belt->baggage = NULL;
  return new_conveyor_belt;
}

// Create a new baggage
baggage *create_baggage(int id, int weight, int destination) {
  baggage *new_baggage = (baggage *)malloc(sizeof(baggage));
  new_baggage->id = id;
  new_baggage->weight = weight;
  new_baggage->destination = destination;
  return new_baggage;
}

// Add baggage to a conveyor belt
void add_baggage_to_conveyor_belt(conveyor_belt *conveyor_belt, baggage *baggage) {
  conveyor_belt->baggage = baggage;
}

// Move baggage along a conveyor belt
void move_baggage_along_conveyor_belt(conveyor_belt *conveyor_belt) {
  if (conveyor_belt->baggage != NULL) {
    conveyor_belt->baggage->id++;
  }
}

// Print the status of an airport
void print_airport_status(airport *airport) {
  printf("Airport ID: %d\n", airport->id);
  printf("Airport Name: %s\n", airport->name);
  printf("Number of Conveyor Belts: %d\n", airport->num_conveyor_belts);
  for (int i = 0; i < airport->num_conveyor_belts; i++) {
    printf("Conveyor Belt ID: %d\n", airport->conveyor_belts[i].id);
    printf("Conveyor Belt Length: %d\n", airport->conveyor_belts[i].length);
    printf("Conveyor Belt Speed: %d\n", airport->conveyor_belts[i].speed);
    if (airport->conveyor_belts[i].baggage != NULL) {
      printf("Baggage ID: %d\n", airport->conveyor_belts[i].baggage->id);
      printf("Baggage Weight: %d\n", airport->conveyor_belts[i].baggage->weight);
      printf("Baggage Destination: %d\n", airport->conveyor_belts[i].baggage->destination);
    }
  }
}

int main() {
  // Create a new airport
  airport *airport = create_airport(1, "Heathrow Airport", 5);

  // Create 5 new conveyor belts
  for (int i = 0; i < 5; i++) {
    airport->conveyor_belts[i] = *create_conveyor_belt(i, 100, 10);
  }

  // Create 10 new pieces of baggage
  for (int i = 0; i < 10; i++) {
    baggage *new_baggage = create_baggage(i, 20, i);
    add_baggage_to_conveyor_belt(&airport->conveyor_belts[i % 5], new_baggage);
  }

  // Move baggage along the conveyor belts
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 5; j++) {
      move_baggage_along_conveyor_belt(&airport->conveyor_belts[j]);
    }
  }

  // Print the status of the airport
  print_airport_status(airport);

  return 0;
}