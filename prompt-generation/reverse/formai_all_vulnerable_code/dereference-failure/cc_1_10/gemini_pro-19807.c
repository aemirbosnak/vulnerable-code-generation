//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_CONVEYORS 5
#define NUM_CHECK_IN_COUNTERS 3
#define NUM_FLIGHTS 10

typedef struct {
  int id;
  int weight;
  int destination;
} Bag;

typedef struct {
  int id;
  int speed;
  int length;
} Conveyor;

typedef struct {
  int id;
  int num_bags;
} CheckInCounter;

typedef struct {
  int id;
  int capacity;
  int num_bags;
  Bag* bags;
} Flight;

// Create a new bag
Bag* create_bag(int id, int weight, int destination) {
  Bag* bag = (Bag*)malloc(sizeof(Bag));
  bag->id = id;
  bag->weight = weight;
  bag->destination = destination;
  return bag;
}

// Create a new conveyor
Conveyor* create_conveyor(int id, int speed, int length) {
  Conveyor* conveyor = (Conveyor*)malloc(sizeof(Conveyor));
  conveyor->id = id;
  conveyor->speed = speed;
  conveyor->length = length;
  return conveyor;
}

// Create a new check-in counter
CheckInCounter* create_check_in_counter(int id) {
  CheckInCounter* check_in_counter = (CheckInCounter*)malloc(sizeof(CheckInCounter));
  check_in_counter->id = id;
  check_in_counter->num_bags = 0;
  return check_in_counter;
}

// Create a new flight
Flight* create_flight(int id, int capacity) {
  Flight* flight = (Flight*)malloc(sizeof(Flight));
  flight->id = id;
  flight->capacity = capacity;
  flight->num_bags = 0;
  flight->bags = (Bag**)malloc(capacity * sizeof(Bag*));
  return flight;
}

// Print the details of a bag
void print_bag(Bag* bag) {
  printf("Bag ID: %d\n", bag->id);
  printf("Weight: %d\n", bag->weight);
  printf("Destination: %d\n\n", bag->destination);
}

// Print the details of a conveyor
void print_conveyor(Conveyor* conveyor) {
  printf("Conveyor ID: %d\n", conveyor->id);
  printf("Speed: %d\n", conveyor->speed);
  printf("Length: %d\n\n", conveyor->length);
}

// Print the details of a check-in counter
void print_check_in_counter(CheckInCounter* check_in_counter) {
  printf("Check-in Counter ID: %d\n", check_in_counter->id);
  printf("Number of Bags: %d\n\n", check_in_counter->num_bags);
}

// Print the details of a flight
void print_flight(Flight* flight) {
  printf("Flight ID: %d\n", flight->id);
  printf("Capacity: %d\n", flight->capacity);
  printf("Number of Bags: %d\n\n", flight->num_bags);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create the airport
  Bag* bags[NUM_BAGS];
  Conveyor* conveyors[NUM_CONVEYORS];
  CheckInCounter* check_in_counters[NUM_CHECK_IN_COUNTERS];
  Flight* flights[NUM_FLIGHTS];

  // Create the bags
  for (int i = 0; i < NUM_BAGS; i++) {
    bags[i] = create_bag(i, rand() % 50 + 1, rand() % NUM_FLIGHTS);
  }

  // Create the conveyors
  for (int i = 0; i < NUM_CONVEYORS; i++) {
    conveyors[i] = create_conveyor(i, rand() % 10 + 1, rand() % 100 + 1);
  }

  // Create the check-in counters
  for (int i = 0; i < NUM_CHECK_IN_COUNTERS; i++) {
    check_in_counters[i] = create_check_in_counter(i);
  }

  // Create the flights
  for (int i = 0; i < NUM_FLIGHTS; i++) {
    flights[i] = create_flight(i, rand() % 100 + 1);
  }

  // Print the details of the airport
  printf("Bags:\n");
  for (int i = 0; i < NUM_BAGS; i++) {
    print_bag(bags[i]);
  }

  printf("Conveyors:\n");
  for (int i = 0; i < NUM_CONVEYORS; i++) {
    print_conveyor(conveyors[i]);
  }

  printf("Check-in Counters:\n");
  for (int i = 0; i < NUM_CHECK_IN_COUNTERS; i++) {
    print_check_in_counter(check_in_counters[i]);
  }

  printf("Flights:\n");
  for (int i = 0; i < NUM_FLIGHTS; i++) {
    print_flight(flights[i]);
  }

  return 0;
}