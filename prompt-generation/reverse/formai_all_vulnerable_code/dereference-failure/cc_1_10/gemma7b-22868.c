//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10

struct Auction {
  char name[20];
  int starting_bid;
  int current_bid;
  int num_bids;
  struct Auction* next;
};

struct Auction* create_auction(char* name, int starting_bid) {
  struct Auction* new_auction = (struct Auction*)malloc(sizeof(struct Auction));
  strcpy(new_auction->name, name);
  new_auction->starting_bid = starting_bid;
  new_auction->current_bid = starting_bid;
  new_auction->num_bids = 0;
  new_auction->next = NULL;
  return new_auction;
}

void add_bid(struct Auction* auction, int bid) {
  auction->num_bids++;
  if (bid > auction->current_bid) {
    auction->current_bid = bid;
  }
}

void print_auctions(struct Auction* auctions) {
  while (auctions) {
    printf("Name: %s, Starting Bid: %d, Current Bid: %d, Number of Bids: %d\n", auctions->name, auctions->starting_bid, auctions->current_bid, auctions->num_bids);
    auctions = auctions->next;
  }
}

int main() {
  struct Auction* auctions = NULL;

  auctions = create_auction("Apple", 100);
  add_bid(auctions, 120);
  add_bid(auctions, 130);
  add_bid(auctions, 140);

  auctions = create_auction("Banana", 200);
  add_bid(auctions, 220);
  add_bid(auctions, 230);
  add_bid(auctions, 240);

  print_auctions(auctions);

  return 0;
}