//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

typedef struct Bid {
  char name[20];
  int bid;
  struct Bid* next;
} Bid;

void insertBid(Bid** head, char* name, int bid) {
  Bid* newBid = malloc(sizeof(Bid));
  strcpy(newBid->name, name);
  newBid->bid = bid;
  newBid->next = NULL;

  if (*head == NULL) {
    *head = newBid;
  } else {
    (*head)->next = newBid;
  }
}

int main() {

  Bid* head = NULL;

  // Simulate some bids
  insertBid(&head, "John Doe", 5000);
  insertBid(&head, "Jane Doe", 6000);
  insertBid(&head, "Bill Smith", 7000);

  // Auction starts!

  // Generate a random number between 1 and MAX_BID
  int minBid = rand() % MAX_BID + 1;

  // Iterate over the bids and find the highest one
  for (Bid* currentBid = head; currentBid; currentBid) {
    if (currentBid->bid > minBid) {
      minBid = currentBid->bid;
    }
  }

  // Announce the winner
  printf("The winner is: %s with a bid of %d.\n", head->name, minBid);

  return 0;
}