//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

struct Bidder {
  char name[20];
  int bid;
  struct Bidder* next;
};

void placeBid(struct Bidder** head, int bid, char* name) {
  struct Bidder* newBidder = malloc(sizeof(struct Bidder));
  strcpy(newBidder->name, name);
  newBidder->bid = bid;
  newBidder->next = NULL;

  if (*head == NULL) {
    *head = newBidder;
  } else {
    (*head)->next = newBidder;
  }
}

int main() {
  struct Bidder* head = NULL;

  // Simulate some bidders
  placeBid(&head, 500, "John Doe");
  placeBid(&head, 600, "Jane Doe");
  placeBid(&head, 700, "Peter Pan");

  // Print the bidders
  struct Bidder* currentBidder = head;
  while (currentBidder) {
    printf("%s bid is %d\n", currentBidder->name, currentBidder->bid);
    currentBidder = currentBidder->next;
  }

  // Find the highest bidder
  struct Bidder* highestBidder = head;
  int highestBid = 0;
  while (highestBidder) {
    if (highestBidder->bid > highestBid) {
      highestBid = highestBidder->bid;
    }
    highestBidder = highestBidder->next;
  }

  // Print the highest bidder
  printf("The highest bidder is %s with a bid of %d\n", highestBidder->name, highestBid);

  return 0;
}