//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of bags that can be processed per hour
#define MAX_BAGS_PER_HOUR 100

// Define the maximum number of hours that the simulation will run
#define MAX_HOURS 10

// Define the probability that a bag will be delayed
#define DELAY_PROBABILITY 0.1

// Define the minimum and maximum delay time (in minutes)
#define MIN_DELAY 15
#define MAX_DELAY 60

// Define the structure of a bag
typedef struct bag {
  int id;
  int weight;
  int destination;
  int arrival_time;
  int departure_time;
} bag;

// Create a new bag
bag* new_bag(int id, int weight, int destination, int arrival_time) {
  bag* b = malloc(sizeof(bag));
  b->id = id;
  b->weight = weight;
  b->destination = destination;
  b->arrival_time = arrival_time;
  b->departure_time = -1;
  return b;
}

// Process a bag
void process_bag(bag* b) {
  // Check if the bag is delayed
  if (rand() / (RAND_MAX + 1.0) < DELAY_PROBABILITY) {
    // Generate a random delay time
    int delay = MIN_DELAY + rand() % (MAX_DELAY - MIN_DELAY + 1);

    // Update the bag's departure time
    b->departure_time = b->arrival_time + delay;
  } else {
    // Update the bag's departure time
    b->departure_time = b->arrival_time;
  }
}

// Print the status of a bag
void print_bag(bag* b) {
  printf("Bag %d: weight = %d, destination = %d, arrival_time = %d, departure_time = %d\n",
         b->id, b->weight, b->destination, b->arrival_time, b->departure_time);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create an array of bags
  bag* bags[MAX_BAGS_PER_HOUR * MAX_HOURS];

  // Generate bags
  for (int i = 0; i < MAX_BAGS_PER_HOUR * MAX_HOURS; i++) {
    bags[i] = new_bag(i + 1, rand() % 50 + 1, rand() % 10 + 1, rand() % MAX_HOURS + 1);
  }

  // Process bags
  for (int i = 0; i < MAX_BAGS_PER_HOUR * MAX_HOURS; i++) {
    process_bag(bags[i]);
  }

  // Print the status of all bags
  for (int i = 0; i < MAX_BAGS_PER_HOUR * MAX_HOURS; i++) {
    print_bag(bags[i]);
  }

  return 0;
}