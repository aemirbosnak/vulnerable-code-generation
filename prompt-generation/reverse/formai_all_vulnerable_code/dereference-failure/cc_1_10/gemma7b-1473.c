//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_BID 10000

struct Bidder {
  char name[50];
  int bid;
  struct Bidder* next;
};

struct Item {
  char name[50];
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
  struct Bidder* bidders = NULL;
  struct Item* items = NULL;

  insertBidder(&bidders, "John Doe", 5000);
  insertBidder(&bidders, "Jane Doe", 4000);
  insertBidder(&bidders, "Bill Smith", 3000);

  insertItem(&items, "Car", 10000);
  insertItem(&items, "House", 20000);
  insertItem(&items, "Laptop", 30000);

  // Auction begins
  for (struct Item* item = items; item != NULL; item++) {
    printf("Item: %s, Starting Price: %d\n", item->name, item->startingPrice);

    for (struct Bidder* bidder = bidders; bidder != NULL; bidder++) {
      printf("Bidder: %s, Bid: %d\n", bidder->name, bidder->bid);
    }

    // Bidding ends, highest bidder wins
    struct Bidder* highestBidder = item->highestBidder;
    if (highestBidder) {
      printf("Congratulations, %s, you won the auction for item %s!\n", highestBidder->name, item->name);
    } else {
      printf("No bids received for item %s.\n", item->name);
    }
  }

  return 0;
}