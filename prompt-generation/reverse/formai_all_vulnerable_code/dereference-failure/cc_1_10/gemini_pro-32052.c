//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_BAGS 1000
#define NUM_CHECKIN_COUNTERS 10
#define NUM_SECURITY_CHECKS 5
#define NUM_BAGGAGE_CLAIM_CONVEYORS 5

// Baggage status
enum baggage_status {
  CHECKED_IN,
  SECURITY_CHECK,
  BAGGAGE_CLAIM
};

// Baggage struct
typedef struct baggage {
  int id;
  enum baggage_status status;
  pthread_mutex_t lock;
} baggage;

// Airport simulation struct
typedef struct airport {
  baggage *bags;
  pthread_mutex_t checkin_counters[NUM_CHECKIN_COUNTERS];
  pthread_mutex_t security_checks[NUM_SECURITY_CHECKS];
  pthread_mutex_t baggage_claim_conveyors[NUM_BAGGAGE_CLAIM_CONVEYORS];
} airport;

// Initialize the airport simulation
void airport_init(airport *a) {
  a->bags = malloc(sizeof(baggage) * NUM_BAGS);
  for (int i = 0; i < NUM_BAGS; i++) {
    a->bags[i].id = i;
    a->bags[i].status = CHECKED_IN;
    pthread_mutex_init(&a->bags[i].lock, NULL);
  }
  for (int i = 0; i < NUM_CHECKIN_COUNTERS; i++) {
    pthread_mutex_init(&a->checkin_counters[i], NULL);
  }
  for (int i = 0; i < NUM_SECURITY_CHECKS; i++) {
    pthread_mutex_init(&a->security_checks[i], NULL);
  }
  for (int i = 0; i < NUM_BAGGAGE_CLAIM_CONVEYORS; i++) {
    pthread_mutex_init(&a->baggage_claim_conveyors[i], NULL);
  }
}

// Check in a bag
void checkin_bag(airport *a, baggage *b) {
  pthread_mutex_lock(&a->checkin_counters[rand() % NUM_CHECKIN_COUNTERS]);
  pthread_mutex_lock(&b->lock);
  b->status = SECURITY_CHECK;
  pthread_mutex_unlock(&b->lock);
  pthread_mutex_unlock(&a->checkin_counters[rand() % NUM_CHECKIN_COUNTERS]);
}

// Security check a bag
void security_check_bag(airport *a, baggage *b) {
  pthread_mutex_lock(&a->security_checks[rand() % NUM_SECURITY_CHECKS]);
  pthread_mutex_lock(&b->lock);
  b->status = BAGGAGE_CLAIM;
  pthread_mutex_unlock(&b->lock);
  pthread_mutex_unlock(&a->security_checks[rand() % NUM_SECURITY_CHECKS]);
}

// Claim a bag
void claim_bag(airport *a, baggage *b) {
  pthread_mutex_lock(&a->baggage_claim_conveyors[rand() % NUM_BAGGAGE_CLAIM_CONVEYORS]);
  pthread_mutex_lock(&b->lock);
  b->status = CHECKED_IN;
  pthread_mutex_unlock(&b->lock);
  pthread_mutex_unlock(&a->baggage_claim_conveyors[rand() % NUM_BAGGAGE_CLAIM_CONVEYORS]);
}

// Run the airport simulation
void run_airport(airport *a) {
  srand(time(NULL));
  while (1) {
    // Check in bags
    for (int i = 0; i < NUM_BAGS; i++) {
      if (a->bags[i].status == CHECKED_IN) {
        checkin_bag(a, &a->bags[i]);
      }
    }
    // Security check bags
    for (int i = 0; i < NUM_BAGS; i++) {
      if (a->bags[i].status == SECURITY_CHECK) {
        security_check_bag(a, &a->bags[i]);
      }
    }
    // Claim bags
    for (int i = 0; i < NUM_BAGS; i++) {
      if (a->bags[i].status == BAGGAGE_CLAIM) {
        claim_bag(a, &a->bags[i]);
      }
    }
  }
}

// Main function
int main() {
  airport a;
  airport_init(&a);
  run_airport(&a);
  return 0;
}