//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID_AMOUNT 10000

typedef struct Bidder {
  char name[20];
  int bid_amount;
  struct Bidder* next;
} Bidder;

Bidder* insertBidder(Bidder* head) {
  Bidder* newBidder = (Bidder*)malloc(sizeof(Bidder));
  newBidder->bid_amount = 0;
  newBidder->next = NULL;

  if (head == NULL) {
    head = newBidder;
  } else {
    head->next = newBidder;
  }

  return head;
}

void printBidders(Bidder* head) {
  while (head) {
    printf("%s: %d\n", head->name, head->bid_amount);
    head = head->next;
  }
}

void startAuction() {
  Bidder* head = NULL;

  // Simulate some bidders
  insertBidder(head);
  insertBidder(head);
  insertBidder(head);

  // Print bidders
  printBidders(head);

  // Start the auction
  printf("Enter your bid: ");
  int bidAmount = 0;
  scanf("%d", &bidAmount);

  // Check if the bid is valid
  if (bidAmount > MAX_BID_AMOUNT) {
    printf("Error: bid amount is too high.\n");
  } else {
    // Insert the bidder into the auction
    insertBidder(head);

    // Print the updated bidders
    printBidders(head);

    // Auction ends
    printf("Auction ended.\n");
  }
}

int main() {
  startAuction();

  return 0;
}