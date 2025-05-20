//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

typedef struct Bid {
  char bidder[20];
  int bidAmount;
  struct Bid* next;
} Bid;

void insertBid(Bid** head, char* bidder, int bidAmount) {
  Bid* newBid = (Bid*)malloc(sizeof(Bid));
  strcpy(newBid->bidder, bidder);
  newBid->bidAmount = bidAmount;
  newBid->next = NULL;

  if (*head == NULL) {
    *head = newBid;
  } else {
    (*head)->next = newBid;
  }
}

void printBids(Bid* head) {
  while (head) {
    printf("%s: %d\n", head->bidder, head->bidAmount);
    head = head->next;
  }
}

int main() {
  Bid* head = NULL;

  // Simulate bidding
  insertBid(&head, "John Doe", 500);
  insertBid(&head, "Jane Doe", 600);
  insertBid(&head, "Bill Smith", 700);

  // Print bids
  printBids(head);

  // Find the highest bid
  Bid* highestBid = head;
  int highestBidAmount = 0;
  while (highestBid) {
    if (highestBid->bidAmount > highestBidAmount) {
      highestBidAmount = highestBid->bidAmount;
      highestBid = highestBid->next;
    } else {
      highestBid = highestBid->next;
    }
  }

  // Print the highest bid
  printf("The highest bid is: %d\n", highestBidAmount);

  return 0;
}