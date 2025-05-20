//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 1000

struct Bid {
  char name[50];
  int bid;
  struct Bid* next;
} Bid;

struct Auction {
  char item_name[50];
  int reserve_price;
  struct Bid* head;
  struct Auction* next;
} Auction;

void insert_bid(struct Auction* auction, char* name, int bid) {
  struct Bid* new_bid = malloc(sizeof(struct Bid));
  strcpy(new_bid->name, name);
  new_bid->bid = bid;
  new_bid->next = NULL;

  if (auction->head == NULL) {
    auction->head = new_bid;
  } else {
    auction->head->next = new_bid;
  }
}

void print_bids(struct Auction* auction) {
  struct Bid* current_bid = auction->head;
  printf("Bids for item: %s\n", auction->item_name);
  while (current_bid) {
    printf("%s bid: %d\n", current_bid->name, current_bid->bid);
    current_bid = current_bid->next;
  }
}

void close_auction(struct Auction* auction) {
  struct Bid* current_bid = auction->head;
  while (current_bid) {
    struct Bid* next_bid = current_bid->next;
    free(current_bid);
    current_bid = next_bid;
  }
  free(auction);
}

int main() {
  struct Auction* my_auction = malloc(sizeof(struct Auction));
  strcpy(my_auction->item_name, "Gold Watch");
  my_auction->reserve_price = 500;
  my_auction->head = NULL;

  insert_bid(my_auction, "John Doe", 600);
  insert_bid(my_auction, "Jane Doe", 400);
  insert_bid(my_auction, "Peter Pan", 300);

  print_bids(my_auction);

  close_auction(my_auction);

  return 0;
}