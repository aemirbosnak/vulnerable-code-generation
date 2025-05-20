//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of bags and the number of flights
#define NUM_BAGS 100
#define NUM_FLIGHTS 10

// Define the structure of a bag
typedef struct bag {
  int id;
  int flight_id;
  int weight;
  int destination;
} bag;

// Define the structure of a flight
typedef struct flight {
  int id;
  int destination;
  int capacity;
  int num_bags;
  bag *bags;
} flight;

// Define the structure of the airport
typedef struct airport {
  bag *bags;
  flight *flights;
} airport;

// Create a new airport
airport *create_airport() {
  airport *a = malloc(sizeof(airport));
  a->bags = malloc(sizeof(bag) * NUM_BAGS);
  a->flights = malloc(sizeof(flight) * NUM_FLIGHTS);
  return a;
}

// Destroy an airport
void destroy_airport(airport *a) {
  free(a->bags);
  free(a->flights);
  free(a);
}

// Generate random bags
void generate_bags(airport *a) {
  for (int i = 0; i < NUM_BAGS; i++) {
    a->bags[i].id = i;
    a->bags[i].flight_id = rand() % NUM_FLIGHTS;
    a->bags[i].weight = rand() % 50;
    a->bags[i].destination = rand() % 10;
  }
}

// Generate random flights
void generate_flights(airport *a) {
  for (int i = 0; i < NUM_FLIGHTS; i++) {
    a->flights[i].id = i;
    a->flights[i].destination = rand() % 10;
    a->flights[i].capacity = rand() % 100;
    a->flights[i].num_bags = 0;
    a->flights[i].bags = malloc(sizeof(bag) * a->flights[i].capacity);
  }
}

// Load bags onto flights
void load_bags(airport *a) {
  for (int i = 0; i < NUM_BAGS; i++) {
    flight *f = &a->flights[a->bags[i].flight_id];
    if (f->num_bags < f->capacity) {
      f->bags[f->num_bags++] = a->bags[i];
    }
  }
}

// Unload bags from flights
void unload_bags(airport *a) {
  for (int i = 0; i < NUM_FLIGHTS; i++) {
    flight *f = &a->flights[i];
    for (int j = 0; j < f->num_bags; j++) {
      a->bags[f->bags[j].id] = f->bags[j];
    }
    f->num_bags = 0;
  }
}

// Print the airport
void print_airport(airport *a) {
  printf("Bags:\n");
  for (int i = 0; i < NUM_BAGS; i++) {
    printf("  %d: flight %d, weight %d, destination %d\n", a->bags[i].id, a->bags[i].flight_id, a->bags[i].weight, a->bags[i].destination);
  }
  printf("Flights:\n");
  for (int i = 0; i < NUM_FLIGHTS; i++) {
    printf("  %d: destination %d, capacity %d, num_bags %d\n", a->flights[i].id, a->flights[i].destination, a->flights[i].capacity, a->flights[i].num_bags);
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create an airport
  airport *a = create_airport();

  // Generate random bags and flights
  generate_bags(a);
  generate_flights(a);

  // Load bags onto flights
  load_bags(a);

  // Unload bags from flights
  unload_bags(a);

  // Print the airport
  print_airport(a);

  // Destroy the airport
  destroy_airport(a);

  return 0;
}