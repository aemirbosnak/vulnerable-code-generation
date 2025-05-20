//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 1000

struct Bid {
  char name[20];
  int bid;
  struct Bid* next;
} Bid;

void insertBid(struct Bid** head, char* name, int bid) {
  struct Bid* newBid = (struct Bid*)malloc(sizeof(struct Bid));
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

  struct Bid* head = NULL;

  // Simulate some bids
  insertBid(&head, "John Doe", 500);
  insertBid(&head, "Jane Doe", 600);
  insertBid(&head, "Bob Smith", 700);

  // Print the bids
  struct Bid* currentBid = head;
  while (currentBid) {
    printf("%s bid: %d\n", currentBid->name, currentBid->bid);
    currentBid = currentBid->next;
  }

  // Find the highest bid
  struct Bid* highestBid = head;
  int highestBidValue = 0;
  while (highestBid) {
    if (highestBid->bid > highestBidValue) {
      highestBidValue = highestBid->bid;
      highestBid = highestBid->next;
    }
  }

  // Print the highest bid
  printf("The highest bid is: %d\n", highestBidValue);

  return 0;
}