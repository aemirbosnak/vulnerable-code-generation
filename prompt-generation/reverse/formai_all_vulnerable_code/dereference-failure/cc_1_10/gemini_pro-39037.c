//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_BAGS 100
#define NUM_CHECKIN_COUNTERS 5
#define NUM_BAGGAGE_CLAIM_BELTS 5

typedef struct {
  int id;
  char *destination;
  int weight;
} Bag;

typedef struct {
  int id;
  Bag *bag;
} CheckinCounter;

typedef struct {
  int id;
  Bag *bag;
} BaggageClaimBelt;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int num_bags_checked_in = 0;
int num_bags_claimed = 0;

void *checkin_counter(void *arg) {
  CheckinCounter *checkin_counter = (CheckinCounter *)arg;

  while (1) {
    pthread_mutex_lock(&mutex);

    while (num_bags_checked_in == NUM_BAGS) {
      pthread_cond_wait(&cond, &mutex);
    }

    Bag *bag = malloc(sizeof(Bag));
    bag->id = checkin_counter->id;
    bag->destination = "LAX";
    bag->weight = rand() % 50 + 1;

    checkin_counter->bag = bag;
    num_bags_checked_in++;

    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);

    sleep(1);
  }

  return NULL;
}

void *baggage_claim_belt(void *arg) {
  BaggageClaimBelt *baggage_claim_belt = (BaggageClaimBelt *)arg;

  while (1) {
    pthread_mutex_lock(&mutex);

    while (num_bags_claimed == NUM_BAGS) {
      pthread_cond_wait(&cond, &mutex);
    }

    Bag *bag = baggage_claim_belt->bag;
    if (bag != NULL) {
      printf("Bag %d arrived at baggage claim belt %d\n", bag->id, baggage_claim_belt->id);

      free(bag);
      baggage_claim_belt->bag = NULL;
      num_bags_claimed++;

      pthread_cond_signal(&cond);
      pthread_mutex_unlock(&mutex);

      sleep(1);
    }
  }

  return NULL;
}

int main() {
  srand(time(NULL));

  pthread_t checkin_counter_threads[NUM_CHECKIN_COUNTERS];
  for (int i = 0; i < NUM_CHECKIN_COUNTERS; i++) {
    CheckinCounter *checkin_counter = malloc(sizeof(CheckinCounter));
    checkin_counter->id = i;
    pthread_create(&checkin_counter_threads[i], NULL, checkin_counter, checkin_counter);
  }

  pthread_t baggage_claim_belt_threads[NUM_BAGGAGE_CLAIM_BELTS];
  for (int i = 0; i < NUM_BAGGAGE_CLAIM_BELTS; i++) {
    BaggageClaimBelt *baggage_claim_belt = malloc(sizeof(BaggageClaimBelt));
    baggage_claim_belt->id = i;
    pthread_create(&baggage_claim_belt_threads[i], NULL, baggage_claim_belt, baggage_claim_belt);
  }

  for (int i = 0; i < NUM_CHECKIN_COUNTERS; i++) {
    pthread_join(checkin_counter_threads[i], NULL);
  }

  for (int i = 0; i < NUM_BAGGAGE_CLAIM_BELTS; i++) {
    pthread_join(baggage_claim_belt_threads[i], NULL);
  }

  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);

  return 0;
}