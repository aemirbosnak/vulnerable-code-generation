//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000

struct Bidder {
  char name[20];
  int bid;
  struct Bidder *next;
};

struct Item {
  char name[20];
  int reservePrice;
  struct Bidder *highestBidder;
  struct Item *next;
};

void placeBid(struct Item *item, struct Bidder *bidder, int bid) {
  struct Bidder *newBidder = malloc(sizeof(struct Bidder));
  strcpy(newBidder->name, bidder->name);
  newBidder->bid = bid;
  newBidder->next = NULL;

  if (item->highestBidder) {
    struct Bidder *currentBidder = item->highestBidder;
    while (currentBidder->next) {
      currentBidder = currentBidder->next;
    }
    currentBidder->next = newBidder;
  } else {
    item->highestBidder = newBidder;
  }

  if (bid > item->reservePrice) {
    item->reservePrice = bid;
  }
}

int main() {
  struct Item *item = malloc(sizeof(struct Item));
  strcpy(item->name, "Diamond Ring");
  item->reservePrice = 5000;

  struct Bidder *bidder1 = malloc(sizeof(struct Bidder));
  strcpy(bidder1->name, "John Doe");
  bidder1->bid = 4000;

  struct Bidder *bidder2 = malloc(sizeof(struct Bidder));
  strcpy(bidder2->name, "Jane Doe");
  bidder2->bid = 3000;

  placeBid(item, bidder1, 4500);
  placeBid(item, bidder2, 3500);

  printf("The highest bid is: %d", item->reservePrice);

  return 0;
}