//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_AUCTIONS 10
#define MAX_BIDS 5

typedef struct Auction {
  char title[50];
  int starting_bid;
  int reserve_price;
  int num_bids;
  struct Bid *bids;
} Auction;

typedef struct Bid {
  int amount;
  char bidder[50];
  struct Bid *next;
} Bid;

void create_auction(Auction *auction) {
  auction->num_bids = 0;
  auction->bids = NULL;
  auction->reserve_price = 0;
  auction->starting_bid = 0;
  auction->title[0] = '\0';
}

void add_bid(Auction *auction, int amount, char *bidder) {
  Bid *new_bid = (Bid *)malloc(sizeof(Bid));
  new_bid->amount = amount;
  strcpy(new_bid->bidder, bidder);
  new_bid->next = NULL;

  if (auction->num_bids == 0) {
    auction->bids = new_bid;
  } else {
    auction->bids->next = new_bid;
  }

  auction->num_bids++;
}

void print_auction(Auction *auction) {
  printf("Title: %s\n", auction->title);
  printf("Starting Bid: %d\n", auction->starting_bid);
  printf("Reserve Price: %d\n", auction->reserve_price);
  printf("Number of Bids: %d\n", auction->num_bids);
  printf("Bids:\n");

  Bid *bid = auction->bids;
  while (bid) {
    printf("  - Amount: %d, Bidder: %s\n", bid->amount, bid->bidder);
    bid = bid->next;
  }
}

int main() {
  Auction auctions[MAX_AUCTIONS];

  for (int i = 0; i < MAX_AUCTIONS; i++) {
    create_auction(&auctions[i]);
  }

  // Add bids to the auctions
  add_bid(&auctions[0], 10, "John Doe");
  add_bid(&auctions[0], 12, "Jane Doe");
  add_bid(&auctions[0], 14, "Peter Pan");

  add_bid(&auctions[1], 20, "Alice White");
  add_bid(&auctions[1], 22, "Bob White");

  // Print the auctions
  for (int i = 0; i < MAX_AUCTIONS; i++) {
    print_auction(&auctions[i]);
  }

  return 0;
}