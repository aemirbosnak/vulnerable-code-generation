//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_CHECK_IN_COUNTERS 10
#define NUM_BAGGAGE_CLAIMS 10

typedef struct bag {
  int id;
  int weight;
  int destination;
} bag;

typedef struct check_in_counter {
  int id;
  int num_bags_checked_in;
  int total_weight_checked_in;
} check_in_counter;

typedef struct baggage_claim {
  int id;
  int num_bags_claimed;
  int total_weight_claimed;
} baggage_claim;

// Create a new bag
bag* create_bag(int id, int weight, int destination) {
  bag* new_bag = malloc(sizeof(bag));
  new_bag->id = id;
  new_bag->weight = weight;
  new_bag->destination = destination;
  return new_bag;
}

// Create a new check-in counter
check_in_counter* create_check_in_counter(int id) {
  check_in_counter* new_check_in_counter = malloc(sizeof(check_in_counter));
  new_check_in_counter->id = id;
  new_check_in_counter->num_bags_checked_in = 0;
  new_check_in_counter->total_weight_checked_in = 0;
  return new_check_in_counter;
}

// Create a new baggage claim
baggage_claim* create_baggage_claim(int id) {
  baggage_claim* new_baggage_claim = malloc(sizeof(baggage_claim));
  new_baggage_claim->id = id;
  new_baggage_claim->num_bags_claimed = 0;
  new_baggage_claim->total_weight_claimed = 0;
  return new_baggage_claim;
}

// Check in a bag
void check_in_bag(bag* bag, check_in_counter* check_in_counter) {
  check_in_counter->num_bags_checked_in++;
  check_in_counter->total_weight_checked_in += bag->weight;
}

// Claim a bag
void claim_bag(bag* bag, baggage_claim* baggage_claim) {
  baggage_claim->num_bags_claimed++;
  baggage_claim->total_weight_claimed += bag->weight;
}

// Simulate the airport baggage handling system
void simulate_airport_baggage_handling_system() {
  // Create bags
  bag* bags[NUM_BAGS];
  for (int i = 0; i < NUM_BAGS; i++) {
    bags[i] = create_bag(i, rand() % 50 + 1, rand() % NUM_BAGGAGE_CLAIMS);
  }

  // Create check-in counters
  check_in_counter* check_in_counters[NUM_CHECK_IN_COUNTERS];
  for (int i = 0; i < NUM_CHECK_IN_COUNTERS; i++) {
    check_in_counters[i] = create_check_in_counter(i);
  }

  // Create baggage claims
  baggage_claim* baggage_claims[NUM_BAGGAGE_CLAIMS];
  for (int i = 0; i < NUM_BAGGAGE_CLAIMS; i++) {
    baggage_claims[i] = create_baggage_claim(i);
  }

  // Check in bags
  for (int i = 0; i < NUM_BAGS; i++) {
    check_in_bag(bags[i], check_in_counters[rand() % NUM_CHECK_IN_COUNTERS]);
  }

  // Claim bags
  for (int i = 0; i < NUM_BAGS; i++) {
    claim_bag(bags[i], baggage_claims[bags[i]->destination]);
  }

  // Print statistics
  printf("Total number of bags: %d\n", NUM_BAGS);
  printf("Total number of check-in counters: %d\n", NUM_CHECK_IN_COUNTERS);
  printf("Total number of baggage claims: %d\n", NUM_BAGGAGE_CLAIMS);
  for (int i = 0; i < NUM_CHECK_IN_COUNTERS; i++) {
    printf("Check-in counter %d: %d bags, %d kg\n", check_in_counters[i]->id, check_in_counters[i]->num_bags_checked_in, check_in_counters[i]->total_weight_checked_in);
  }
  for (int i = 0; i < NUM_BAGGAGE_CLAIMS; i++) {
    printf("Baggage claim %d: %d bags, %d kg\n", baggage_claims[i]->id, baggage_claims[i]->num_bags_claimed, baggage_claims[i]->total_weight_claimed);
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Simulate the airport baggage handling system
  simulate_airport_baggage_handling_system();

  return 0;
}