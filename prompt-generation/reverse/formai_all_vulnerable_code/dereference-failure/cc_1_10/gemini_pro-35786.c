//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Mutex to protect shared data
pthread_mutex_t mutex;

// Condition variable to signal when the auction is over
pthread_cond_t cond;

// The auction item
char *item;

// The current bid
double bid;

// The winning bidder
char *winner;

// Thread function for each bidder
void *bidder(void *arg) {
  char *name = (char *)arg;
  double my_bid;

  // Get a random bid
  my_bid = (rand() % 1000) / 100.0;

  // Lock the mutex
  pthread_mutex_lock(&mutex);

  // Check if the auction is over
  while (winner == NULL) {
    // If the auction is not over, check if my bid is higher than the current bid
    if (my_bid > bid) {
      // If my bid is higher, update the current bid and the winning bidder
      bid = my_bid;
      winner = name;
    }

    // Wait for the auction to be over
    pthread_cond_wait(&cond, &mutex);
  }

  // Unlock the mutex
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main() {
  int num_bidders;
  pthread_t *bidders;

  // Get the number of bidders
  printf("Enter the number of bidders: ");
  scanf("%d", &num_bidders);

  // Get the auction item
  printf("Enter the auction item: ");
  scanf(" %s", item);

  // Initialize the mutex and condition variable
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cond, NULL);

  // Create the bidder threads
  bidders = malloc(sizeof(pthread_t) * num_bidders);
  for (int i = 0; i < num_bidders; i++) {
    pthread_create(&bidders[i], NULL, bidder, (void *)"Bidder");
  }

  // Join the bidder threads
  for (int i = 0; i < num_bidders; i++) {
    pthread_join(bidders[i], NULL);
  }

  // Destroy the mutex and condition variable
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);

  // Print the winning bidder and the winning bid
  printf("The winning bidder is %s with a bid of %f\n", winner, bid);

  return 0;
}