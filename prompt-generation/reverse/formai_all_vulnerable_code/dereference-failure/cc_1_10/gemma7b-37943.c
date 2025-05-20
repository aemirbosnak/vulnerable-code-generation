//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Bidder {
  char name[20];
  int bid;
  struct Bidder *next;
};

struct Auction {
  char item_name[50];
  int reserve_price;
  struct Bidder *highest_bidder;
  struct Auction *next;
};

void place_bid(struct Auction *auction, char *bidder_name, int bid) {
  struct Bidder *new_bidder = malloc(sizeof(struct Bidder));
  strcpy(new_bidder->name, bidder_name);
  new_bidder->bid = bid;
  new_bidder->next = NULL;

  if (auction->highest_bidder) {
    struct Bidder *current_bidder = auction->highest_bidder;
    while (current_bidder->next) {
      current_bidder = current_bidder->next;
    }
    current_bidder->next = new_bidder;
  } else {
    auction->highest_bidder = new_bidder;
  }
}

void auction_end(struct Auction *auction) {
  struct Bidder *highest_bidder = auction->highest_bidder;
  if (highest_bidder) {
    printf("The winner is: %s with a bid of %d\n", highest_bidder->name, highest_bidder->bid);
  } else {
    printf("No bids were placed.\n");
  }
}

int main() {
  struct Auction *auction = malloc(sizeof(struct Auction));
  strcpy(auction->item_name, "A diamond ring");
  auction->reserve_price = 10000;

  place_bid(auction, "John Doe", 12000);
  place_bid(auction, "Jane Doe", 9000);
  place_bid(auction, "Bill Smith", 8000);

  auction_end(auction);

  return 0;
}