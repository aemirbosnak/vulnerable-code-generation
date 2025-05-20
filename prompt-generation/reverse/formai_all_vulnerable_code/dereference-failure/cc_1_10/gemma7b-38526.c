//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

struct Bidder {
  char name[20];
  int bid;
  struct Bidder* next;
};

void insertBidder(struct Bidder** head, char* name, int bid) {
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

void printBids(struct Bidder* head) {
  struct Bidder* current = head;
  while (current) {
    printf("%s: %d\n", current->name, current->bid);
    current = current->next;
  }
}

int main() {
  struct Bidder* head = NULL;

  // Insert bidders
  insertBidder(&head, "John Doe", 5000);
  insertBidder(&head, "Jane Doe", 6000);
  insertBidder(&head, "Bob Smith", 7000);

  // Print bids
  printBids(head);

  // Bid auction
  printf("Enter your name: ");
  char name[20];
  scanf("%s", name);

  printf("Enter your bid: ");
  int bid;
  scanf("%d", &bid);

  insertBidder(&head, name, bid);

  printBids(head);

  return 0;
}