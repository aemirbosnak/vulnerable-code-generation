//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_AUCTIONS 10
#define MAX_BIDS 5

typedef struct Auction {
  char name[20];
  int start_price;
  int reserve_price;
  int current_bid;
  struct Bidder *bidders;
} Auction;

typedef struct Bidder {
  char name[20];
  int bid;
  struct Bidder *next;
} Bidder;

void create_auction(Auction **auction) {
  *auction = malloc(sizeof(Auction));
  (*auction)->name[0] = '\0';
  (*auction)->start_price = 0;
  (*auction)->reserve_price = 0;
  (*auction)->current_bid = 0;
  (*auction)->bidders = NULL;
}

void add_bidder(Auction *auction, Bidder **bidder) {
  *bidder = malloc(sizeof(Bidder));
  (*bidder)->name[0] = '\0';
  (*bidder)->bid = 0;
  (*bidder)->next = NULL;

  if (auction->bidders == NULL) {
    auction->bidders = bidder;
  } else {
    auction->bidders->next = bidder;
  }
}

void place_bid(Auction *auction, Bidder *bidder, int bid) {
  if (bid > auction->current_bid) {
    auction->current_bid = bid;
    bidder->bid = bid;
  }
}

void check_reserve_price(Auction *auction) {
  if (auction->current_bid >= auction->reserve_price) {
    printf("The auction has been won by %s for %d.\n", auction->bidders->name, auction->current_bid);
  } else {
    printf("The auction has not been won.\n");
  }
}

int main() {
  Auction *auction = NULL;
  Bidder *bidder = NULL;

  create_auction(&auction);
  add_bidder(auction, &bidder);
  add_bidder(auction, &bidder);
  add_bidder(auction, &bidder);

  place_bid(auction, bidder, 10);
  place_bid(auction, bidder, 12);
  place_bid(auction, bidder, 14);

  check_reserve_price(auction);

  return 0;
}