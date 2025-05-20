//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

typedef struct Bidder {
  char name[50];
  int bid;
  struct Bidder* next;
} Bidder;

void placeBid(Bidder* head, int amount) {
  Bidder* newBidder = malloc(sizeof(Bidder));
  strcpy(newBidder->name, "Player");
  newBidder->bid = amount;
  newBidder->next = NULL;

  if (head == NULL) {
    head = newBidder;
  } else {
    head->next = newBidder;
  }
}

void printBids(Bidder* head) {
  Bidder* current = head;
  while (current) {
    printf("%s: %d\n", current->name, current->bid);
    current = current->next;
  }
}

int main() {
  Bidder* head = NULL;

  // Simulate some bids
  placeBid(head, 500);
  placeBid(head, 600);
  placeBid(head, 700);
  placeBid(head, 800);

  // Print all bids
  printBids(head);

  // Find the highest bidder
  Bidder* highestBidder = head;
  for (Bidder* current = head; current; current = current->next) {
    if (current->bid > highestBidder->bid) {
      highestBidder = current;
    }
  }

  // Announce the highest bidder
  printf("The highest bidder is: %s with a bid of %d\n", highestBidder->name, highestBidder->bid);

  return 0;
}