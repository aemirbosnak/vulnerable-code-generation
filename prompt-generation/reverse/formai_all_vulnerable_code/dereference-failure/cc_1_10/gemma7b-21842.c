//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

struct Bidder {
  char name[50];
  int bid;
  struct Bidder* next;
};

void placeBid(struct Bidder* head, int amount) {
  struct Bidder* newBidder = malloc(sizeof(struct Bidder));
  newBidder->bid = amount;
  strcpy(newBidder->name, "Unknown");

  if (head == NULL) {
    head = newBidder;
  } else {
    struct Bidder* currentBidder = head;
    while (currentBidder->next) {
      currentBidder = currentBidder->next;
    }
    currentBidder->next = newBidder;
  }
}

void printBids(struct Bidder* head) {
  struct Bidder* currentBidder = head;
  while (currentBidder) {
    printf("%s: %d\n", currentBidder->name, currentBidder->bid);
    currentBidder = currentBidder->next;
  }
}

int main() {
  struct Bidder* head = NULL;

  // Simulate some bids
  placeBid(head, 500);
  placeBid(head, 700);
  placeBid(head, 600);
  placeBid(head, 800);

  // Print the bids
  printBids(head);

  // Find the highest bidder
  struct Bidder* highestBidder = head;
  while (highestBidder->next) {
    highestBidder = highestBidder->next;
  }

  // Announce the highest bidder
  printf("The highest bidder is: %s with a bid of %d\n", highestBidder->name, highestBidder->bid);

  return 0;
}