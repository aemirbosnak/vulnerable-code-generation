//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10

struct Auction {
  char name[20];
  int starting_bid;
  int current_bid;
  int num_bids;
  struct Bidder *bidders;
};

struct Bidder {
  char name[20];
  int bid;
  struct Bidder *next;
};

void create_auction(struct Auction **auction) {
  *auction = malloc(sizeof(struct Auction));
  (*auction)->name[0] = '\0';
  (*auction)->starting_bid = 0;
  (*auction)->current_bid = 0;
  (*auction)->num_bids = 0;
  (*auction)->bidders = NULL;
}

void add_bidder(struct Auction *auction, char *name, int bid) {
  struct Bidder *new_bidder = malloc(sizeof(struct Bidder));
  new_bidder->name[0] = '\0';
  strcpy(new_bidder->name, name);
  new_bidder->bid = bid;
  new_bidder->next = NULL;

  if (auction->bidders == NULL) {
    auction->bidders = new_bidder;
  } else {
    auction->bidders->next = new_bidder;
  }

  auction->num_bids++;
}

int main() {
  struct Auction *auction = NULL;
  create_auction(&auction);

  add_bidder(auction, "John Doe", 10);
  add_bidder(auction, "Jane Doe", 12);
  add_bidder(auction, "Bill Smith", 14);

  printf("Number of bids: %d\n", auction->num_bids);
  printf("Current bid: %d\n", auction->current_bid);

  return 0;
}