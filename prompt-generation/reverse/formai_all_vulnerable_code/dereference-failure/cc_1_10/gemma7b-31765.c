//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_BID 1000

struct Bidder {
  char name[20];
  int bid;
  struct Bidder* next;
};

struct Item {
  char name[20];
  int startingPrice;
  struct Bidder* highestBidder;
  struct Item* next;
};

void insertBidder(struct Bidder** head, char* name, int bid) {
  struct Bidder* newBidder = (struct Bidder*)malloc(sizeof(struct Bidder));
  strcpy(newBidder->name, name);
  newBidder->bid = bid;
  newBidder->next = NULL;

  if (*head == NULL) {
    *head = newBidder;
  } else {
    (*head)->next = newBidder;
  }
}

void insertItem(struct Item** head, char* name, int startingPrice) {
  struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
  strcpy(newItem->name, name);
  newItem->startingPrice = startingPrice;
  newItem->highestBidder = NULL;
  newItem->next = NULL;

  if (*head == NULL) {
    *head = newItem;
  } else {
    (*head)->next = newItem;
  }
}

int main() {
  struct Bidder* head = NULL;
  struct Item* items = NULL;

  insertBidder(&head, "John Doe", 500);
  insertBidder(&head, "Jane Doe", 600);
  insertBidder(&head, "Bill Smith", 700);

  insertItem(&items, "Car", 10000);
  insertItem(&items, "Laptop", 8000);
  insertItem(&items, "Phone", 6000);

  int highestBid = 0;
  struct Item* currentItem = items;

  while (currentItem) {
    for (struct Bidder* bidder = head; bidder; bidder) {
      if (bidder->bid > highestBid) {
        highestBid = bidder->bid;
      }
    }

    printf("Item: %s, Highest Bid: %d\n", currentItem->name, highestBid);

    highestBid = 0;
    currentItem = currentItem->next;
  }

  return 0;
}