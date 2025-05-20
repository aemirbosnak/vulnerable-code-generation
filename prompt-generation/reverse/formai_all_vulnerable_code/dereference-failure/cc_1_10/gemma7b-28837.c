//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

typedef struct Bidder {
  char name[20];
  int bid;
  struct Bidder* next;
} Bidder;

void addBidder(Bidder** head, char* name, int bid) {
  Bidder* newBidder = malloc(sizeof(Bidder));
  strcpy(newBidder->name, name);
  newBidder->bid = bid;
  newBidder->next = NULL;

  if (*head == NULL) {
    *head = newBidder;
  } else {
    (*head)->next = newBidder;
  }
}

void printBids(Bidder* head) {
  while (head) {
    printf("%s: %d\n", head->name, head->bid);
    head = head->next;
  }
}

int main() {
  Bidder* head = NULL;
  int auction_id = 1;
  int current_bid = 0;

  // Simulate bidding
  addBidder(&head, "John Doe", 500);
  addBidder(&head, "Jane Doe", 600);
  addBidder(&head, "Bill Smith", 700);

  // Increase current bid
  current_bid = 800;

  // Print bids
  printBids(head);

  // Check if current bid is highest
  if (current_bid > head->bid) {
    printf("Current bid is highest!\n");
  } else {
    printf("Current bid is not highest.\n");
  }

  return 0;
}