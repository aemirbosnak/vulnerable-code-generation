//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000

struct Bidder {
  char name[50];
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
  struct Bidder *newBidder = malloc(sizeof(struct Bidder));
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
  struct Item *newItem = malloc(sizeof(struct Item));
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

void auction(struct Item *item) {
  struct Bidder *highestBidder = item->highestBidder;
  int highestBid = highestBidder->bid;

  if (highestBid < item->reservePrice) {
    printf("No bids meet the reserve price.\n");
  } else {
    printf("Congratulations, %s! You won the auction for %s for %d.\n", highestBidder->name, item->name, highestBid);
  }
}

int main() {
  struct Item *items = NULL;
  struct Bidder *bidders = NULL;

  insertItem(&items, "iPhone", 500, 700);
  insertItem(&items, "Laptop", 300, 500);
  insertItem(&items, "Car", 1000, 1500);

  insertBidder(&bidders, "John Doe", 400);
  insertBidder(&bidders, "Jane Doe", 350);
  insertBidder(&bidders, "Peter Pan", 600);

  auction(items);

  return 0;
}