//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 10000

struct Bidder {
  char name[20];
  int bid;
  struct Bidder* next;
};

struct Item {
  char name[20];
  int startingPrice;
  int currentPrice;
  struct Bidder* bidders;
};

void placeBid(struct Item* item, struct Bidder* bidder) {
  struct Bidder* newBidder = (struct Bidder*)malloc(sizeof(struct Bidder));
  strcpy(newBidder->name, bidder->name);
  newBidder->bid = bidder->bid;
  newBidder->next = item->bidders;
  item->bidders = newBidder;

  if (bidder->bid > item->currentPrice) {
    item->currentPrice = bidder->bid;
  }
}

int main() {
  struct Item item;
  strcpy(item.name, "Laptop");
  item.startingPrice = 500;
  item.currentPrice = item.startingPrice;
  item.bidders = NULL;

  struct Bidder bidder1;
  strcpy(bidder1.name, "John Doe");
  bidder1.bid = 600;

  struct Bidder bidder2;
  strcpy(bidder2.name, "Jane Doe");
  bidder2.bid = 700;

  placeBid(&item, &bidder1);
  placeBid(&item, &bidder2);

  printf("Current price: %d", item.currentPrice);

  return 0;
}