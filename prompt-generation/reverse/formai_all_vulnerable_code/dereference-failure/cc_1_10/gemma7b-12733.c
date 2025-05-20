//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 10000

struct Bid {
  char bidder[20];
  int amount;
  struct Bid* next;
};

struct Item {
  char name[50];
  int starting_price;
  struct Bid* bids;
  struct Item* next;
};

void add_bid(struct Item* item, char* bidder, int amount) {
  struct Bid* new_bid = malloc(sizeof(struct Bid));
  strcpy(new_bid->bidder, bidder);
  new_bid->amount = amount;
  new_bid->next = item->bids;
  item->bids = new_bid;
}

void print_bids(struct Item* item) {
  struct Bid* current_bid = item->bids;
  while (current_bid) {
    printf("%s: %d\n", current_bid->bidder, current_bid->amount);
    current_bid = current_bid->next;
  }
}

int main() {
  struct Item* items = NULL;
  struct Item* new_item = malloc(sizeof(struct Item));
  strcpy(new_item->name, "Laptop");
  new_item->starting_price = 1000;
  new_item->bids = NULL;
  items = new_item;

  add_bid(items, "John Doe", 1200);
  add_bid(items, "Jane Doe", 1300);
  add_bid(items, "Bill Smith", 1400);

  print_bids(items);

  return 0;
}