//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
  char *name;
  int price;
};

struct bid {
  char *name;
  int price;
};

struct auction {
  struct item *item;
  struct bid *bids;
  int num_bids;
};

struct auction *new_auction(struct item *item) {
  struct auction *auction = malloc(sizeof(struct auction));
  auction->item = item;
  auction->bids = NULL;
  auction->num_bids = 0;
  return auction;
}

void add_bid(struct auction *auction, struct bid *bid) {
  auction->bids = realloc(auction->bids, (auction->num_bids + 1) * sizeof(struct bid));
  auction->bids[auction->num_bids++] = *bid;
}

struct bid *get_highest_bid(struct auction *auction) {
  int highest_bid = -1;
  struct bid *highest_bidder = NULL;
  for (int i = 0; i < auction->num_bids; i++) {
    if (auction->bids[i].price > highest_bid) {
      highest_bid = auction->bids[i].price;
      highest_bidder = &auction->bids[i];
    }
  }
  return highest_bidder;
}

void print_auction(struct auction *auction) {
  printf("Item: %s\n", auction->item->name);
  printf("Current price: %d\n", auction->item->price);
  printf("Number of bids: %d\n", auction->num_bids);
  for (int i = 0; i < auction->num_bids; i++) {
    printf("Bidder: %s\n", auction->bids[i].name);
    printf("Bid: %d\n", auction->bids[i].price);
  }
}

int main() {
  struct item *item = malloc(sizeof(struct item));
  item->name = "Mona Lisa";
  item->price = 1000000;

  struct auction *auction = new_auction(item);

  struct bid *bid1 = malloc(sizeof(struct bid));
  bid1->name = "Alice";
  bid1->price = 1100000;

  struct bid *bid2 = malloc(sizeof(struct bid));
  bid2->name = "Bob";
  bid2->price = 1200000;

  add_bid(auction, bid1);
  add_bid(auction, bid2);

  print_auction(auction);

  struct bid *highest_bidder = get_highest_bid(auction);

  printf("The highest bidder is %s with a bid of %d\n", highest_bidder->name, highest_bidder->price);

  return 0;
}