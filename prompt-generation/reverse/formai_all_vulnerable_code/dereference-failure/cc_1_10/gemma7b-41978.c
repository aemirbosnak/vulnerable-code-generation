//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10

struct Auction {
  char *name;
  int starting_price;
  int reserve_price;
  int current_price;
  int num_bids;
  struct Bid *bids;
};

struct Bid {
  char *bidder_name;
  int bid_amount;
  struct Bid *next;
};

void create_auction(struct Auction **auction) {
  *auction = malloc(sizeof(struct Auction));
  (*auction)->name = malloc(20);
  (*auction)->starting_price = 0;
  (*auction)->reserve_price = 0;
  (*auction)->current_price = 0;
  (*auction)->num_bids = 0;
  (*auction)->bids = NULL;
}

void add_bid(struct Auction *auction, char *bidder_name, int bid_amount) {
  struct Bid *new_bid = malloc(sizeof(struct Bid));
  new_bid->bidder_name = malloc(20);
  new_bid->bid_amount = bid_amount;
  new_bid->next = NULL;

  if (auction->bids == NULL) {
    auction->bids = new_bid;
  } else {
    auction->bids->next = new_bid;
  }

  auction->num_bids++;
}

int main() {
  struct Auction *auction_list[MAX_AUCTIONS];

  for (int i = 0; i < MAX_AUCTIONS; i++) {
    create_auction(&auction_list[i]);
  }

  // Add bids to the auctions
  add_bid(auction_list[0], "John Doe", 100);
  add_bid(auction_list[0], "Jane Doe", 120);
  add_bid(auction_list[1], "Bill Smith", 150);
  add_bid(auction_list[1], "Mary Jones", 170);

  // Print the bids for each auction
  for (int i = 0; i < MAX_AUCTIONS; i++) {
    struct Auction *auction = auction_list[i];
    printf("Auction: %s\n", auction->name);
    printf("Number of bids: %d\n", auction->num_bids);
    printf("Bids:\n");
    struct Bid *bid = auction->bids;
    while (bid) {
      printf("  Bidder: %s, Bid amount: %d\n", bid->bidder_name, bid->bid_amount);
      bid = bid->next;
    }
    printf("\n");
  }

  return 0;
}