//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of bags that can be processed per hour
#define MAX_BAGS_PER_HOUR 100

// Define the maximum number of hours that the simulation will run
#define MAX_HOURS 10

// Define the probability that a bag will be lost
#define PROBABILITY_OF_LOSS 0.01

// Define the probability that a bag will be delayed
#define PROBABILITY_OF_DELAY 0.05

// Define the structure of a baggage item
typedef struct baggage_item {
  int id;
  int weight;
  int destination;
  int arrival_time;
  int departure_time;
  int lost;
  int delayed;
} baggage_item;

// Define the structure of a baggage carousel
typedef struct baggage_carousel {
  int id;
  int capacity;
  int num_bags;
  baggage_item *bags[MAX_BAGS_PER_HOUR];
} baggage_carousel;

// Define the structure of the airport
typedef struct airport {
  int id;
  int num_carousels;
  baggage_carousel *carousels[MAX_HOURS];
} airport;

// Create a new baggage item
baggage_item *create_baggage_item(int id, int weight, int destination, int arrival_time, int departure_time) {
  baggage_item *bag = malloc(sizeof(baggage_item));
  bag->id = id;
  bag->weight = weight;
  bag->destination = destination;
  bag->arrival_time = arrival_time;
  bag->departure_time = departure_time;
  bag->lost = 0;
  bag->delayed = 0;
  return bag;
}

// Create a new baggage carousel
baggage_carousel *create_baggage_carousel(int id, int capacity) {
  baggage_carousel *carousel = malloc(sizeof(baggage_carousel));
  carousel->id = id;
  carousel->capacity = capacity;
  carousel->num_bags = 0;
  for (int i = 0; i < MAX_BAGS_PER_HOUR; i++) {
    carousel->bags[i] = NULL;
  }
  return carousel;
}

// Create a new airport
airport *create_airport(int id, int num_carousels) {
  airport *airport = malloc(sizeof(airport));
  airport->id = id;
  airport->num_carousels = num_carousels;
  for (int i = 0; i < MAX_HOURS; i++) {
    airport->carousels[i] = NULL;
  }
  return airport;
}

// Add a baggage item to a baggage carousel
void add_baggage_item_to_carousel(baggage_carousel *carousel, baggage_item *bag) {
  if (carousel->num_bags < carousel->capacity) {
    carousel->bags[carousel->num_bags] = bag;
    carousel->num_bags++;
  }
}

// Remove a baggage item from a baggage carousel
baggage_item *remove_baggage_item_from_carousel(baggage_carousel *carousel) {
  if (carousel->num_bags > 0) {
    baggage_item *bag = carousel->bags[carousel->num_bags - 1];
    carousel->num_bags--;
    return bag;
  }
  return NULL;
}

// Simulate the movement of baggage through an airport
void simulate_airport(airport *airport) {
  // Create a random number generator
  srand(time(NULL));

  // Generate baggage items
  for (int i = 0; i < MAX_BAGS_PER_HOUR; i++) {
    int id = rand() % 1000;
    int weight = rand() % 50;
    int destination = rand() % 10;
    int arrival_time = rand() % MAX_HOURS;
    int departure_time = rand() % MAX_HOURS;
    baggage_item *bag = create_baggage_item(id, weight, destination, arrival_time, departure_time);

    // Add the baggage item to a baggage carousel
    baggage_carousel *carousel = airport->carousels[arrival_time];
    add_baggage_item_to_carousel(carousel, bag);
  }

  // Move baggage items through the airport
  for (int i = 0; i < MAX_HOURS; i++) {
    // Get the baggage carousel for the current hour
    baggage_carousel *carousel = airport->carousels[i];

    // Remove baggage items from the carousel
    while (carousel->num_bags > 0) {
      baggage_item *bag = remove_baggage_item_from_carousel(carousel);

      // Check if the baggage item is lost
      if (rand() < PROBABILITY_OF_LOSS) {
        bag->lost = 1;
      }

      // Check if the baggage item is delayed
      if (rand() < PROBABILITY_OF_DELAY) {
        bag->delayed = 1;
      }

      // Add the baggage item to the baggage carousel for the next hour
      baggage_carousel *next_carousel = airport->carousels[i + 1];
      add_baggage_item_to_carousel(next_carousel, bag);
    }
  }

  // Print the results of the simulation
  for (int i = 0; i < MAX_HOURS; i++) {
    baggage_carousel *carousel = airport->carousels[i];
    printf("Hour %d:\n", i);
    printf("  Number of bags: %d\n", carousel->num_bags);
    for (int j = 0; j < carousel->num_bags; j++) {
      baggage_item *bag = carousel->bags[j];
      printf("    Bag %d: weight %d, destination %d, arrival time %d, departure time %d, lost %d, delayed %d\n",
        bag->id, bag->weight, bag->destination, bag->arrival_time, bag->departure_time, bag->lost, bag->delayed);
    }
  }
}

// Main function
int main() {
  // Create an airport
  airport *airport = create_airport(1, 5);

  // Simulate the movement of baggage through the airport
  simulate_airport(airport);

  return 0;
}