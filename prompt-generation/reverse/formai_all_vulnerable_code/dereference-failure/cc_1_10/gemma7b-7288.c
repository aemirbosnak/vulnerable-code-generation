//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID_AMOUNT 10000

struct Bid {
  char name[50];
  int amount;
  struct Bid* next;
};

struct Auction {
  char item_name[50];
  int starting_price;
  struct Bid* bids;
  struct Auction* next;
};

void add_bid(struct Auction* auction, char* name, int amount) {
  struct Bid* new_bid = malloc(sizeof(struct Bid));
  strcpy(new_bid->name, name);
  new_bid->amount = amount;
  new_bid->next = NULL;

  if (auction->bids == NULL) {
    auction->bids = new_bid;
  } else {
    struct Bid* current_bid = auction->bids;
    while (current_bid->next) {
      current_bid = current_bid->next;
    }
    current_bid->next = new_bid;
  }
}

void print_auction(struct Auction* auction) {
  printf("Item name: %s\n", auction->item_name);
  printf("Starting price: %d\n", auction->starting_price);
  printf("Bids:\n");
  struct Bid* current_bid = auction->bids;
  while (current_bid) {
    printf("%s bidded %d\n", current_bid->name, current_bid->amount);
    current_bid = current_bid->next;
  }
}

int main() {
  struct Auction* auction = malloc(sizeof(struct Auction));
  strcpy(auction->item_name, "iPhone 14");
  auction->starting_price = 500;
  auction->bids = NULL;

  add_bid(auction, "John Doe", 700);
  add_bid(auction, "Jane Doe", 600);
  add_bid(auction, "Peter Pan", 800);

  print_auction(auction);

  return 0;
}