//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct Bidder {
  char name[20];
  int bid;
  struct Bidder* next;
};

struct Item {
  char name[20];
  int starting_price;
  struct Bidder* highest_bidder;
  struct Item* next;
};

void place_bid(struct Item* item, struct Bidder* bidder, int bid) {
  struct Bidder* new_bidder = malloc(sizeof(struct Bidder));
  strcpy(new_bidder->name, bidder->name);
  new_bidder->bid = bid;
  new_bidder->next = NULL;

  if (item->highest_bidder == NULL) {
    item->highest_bidder = new_bidder;
  } else {
    struct Bidder* current_bidder = item->highest_bidder;
    while (current_bidder->next != NULL) {
      current_bidder = current_bidder->next;
    }
    current_bidder->next = new_bidder;
  }
}

void print_auction(struct Item* item) {
  printf("Item: %s\n", item->name);
  printf("Starting Price: %d\n", item->starting_price);
  printf("Highest Bid: %d\n", item->highest_bidder->bid);
  printf("Bidders:\n");
  struct Bidder* current_bidder = item->highest_bidder;
  while (current_bidder) {
    printf("  %s: %d\n", current_bidder->name, current_bidder->bid);
    current_bidder = current_bidder->next;
  }
  printf("\n");
}

int main() {
  struct Item* item = malloc(sizeof(struct Item));
  strcpy(item->name, "Laptop");
  item->starting_price = 1000;
  item->highest_bidder = NULL;

  struct Bidder* bidder = malloc(sizeof(struct Bidder));
  strcpy(bidder->name, "John Doe");
  bidder->bid = 800;

  place_bid(item, bidder, 800);

  print_auction(item);

  return 0;
}