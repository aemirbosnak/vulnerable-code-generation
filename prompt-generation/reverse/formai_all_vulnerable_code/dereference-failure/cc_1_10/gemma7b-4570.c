//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

struct Bidder {
  char name[20];
  int bid;
  struct Bidder *next;
};

struct Item {
  char name[50];
  int startingPrice;
  int reservePrice;
  struct Bidder *highestBidder;
  struct Item *next;
};

void insertBidder(struct Bidder **head, char *name, int bid) {
  struct Bidder *newBidder = (struct Bidder *)malloc(sizeof(struct Bidder));
  strcpy(newBidder->name, name);
  newBidder->bid = bid;
  newBidder->next = NULL;

  if (*head == NULL) {
    *head = newBidder;
  } else {
    (*head)->next = newBidder;
  }
}

void insertItem(struct Item **head, char *name, int startingPrice, int reservePrice) {
  struct Item *newItem = (struct Item *)malloc(sizeof(struct Item));
  strcpy(newItem->name, name);
  newItem->startingPrice = startingPrice;
  newItem->reservePrice = reservePrice;
  newItem->highestBidder = NULL;
  newItem->next = NULL;

  if (*head == NULL) {
    *head = newItem;
  } else {
    (*head)->next = newItem;
  }
}

void startAuction(struct Item *item) {
  struct Bidder *highestBidder = item->highestBidder;
  int currentBid = item->startingPrice;

  while (highestBidder && currentBid < item->reservePrice) {
    printf("Current bid: $%d\n", currentBid);
    printf("Enter your bid: $");
    int newBid = atoi(stdin);

    if (newBid > currentBid && newBid <= MAX_BID) {
      insertBidder(&highestBidder, "John Doe", newBid);
      currentBid = newBid;
    } else {
      printf("Invalid bid.\n");
    }
  }

  printf("Auction complete.\n");
  printf("The highest bidder is: %s\n", highestBidder->name);
  printf("The winning bid is: $%d\n", highestBidder->bid);
}

int main() {
  struct Item *items = NULL;

  insertItem(&items, "Gold ring", 50, 100);
  insertItem(&items, "Diamond necklace", 100, 200);
  insertItem(&items, "Platinum watch", 200, 300);

  startAuction(items);

  return 0;
}