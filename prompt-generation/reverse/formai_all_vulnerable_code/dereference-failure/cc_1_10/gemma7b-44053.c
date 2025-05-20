//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 10000

typedef struct Bidder {
  char name[20];
  int bid;
  struct Bidder* next;
} Bidder;

Bidder* insertBidder(Bidder* head, char* name, int bid) {
  Bidder* newBidder = malloc(sizeof(Bidder));
  strcpy(newBidder->name, name);
  newBidder->bid = bid;
  newBidder->next = NULL;

  if (head == NULL) {
    head = newBidder;
  } else {
    head->next = newBidder;
  }

  return head;
}

int main() {

  Bidder* head = NULL;

  // Insert bidders
  insertBidder(head, "John Doe", 5000);
  insertBidder(head, "Jane Doe", 4000);
  insertBidder(head, "Bill Smith", 3000);
  insertBidder(head, "Mary Johnson", 2000);

  // Start the auction
  printf("Enter your bid: ");
  int bid;
  scanf("%d", &bid);

  // Find the highest bidder
  Bidder* highestBidder = head;
  while (highestBidder->next) {
    if (highestBidder->bid > bid) {
      highestBidder = highestBidder->next;
    }
  }

  // Announce the winner
  printf("The winner is: %s with a bid of %d\n", highestBidder->name, highestBidder->bid);

  return 0;
}