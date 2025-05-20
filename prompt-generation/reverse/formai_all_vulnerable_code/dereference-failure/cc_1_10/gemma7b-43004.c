//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 10
#define MAX_BIDDERS 5

struct item {
  char name[20];
  int starting_bid;
  int current_bid;
  struct bidder *highest_bidder;
};

struct bidder {
  char name[20];
  int bids;
  int total_spent;
  struct bidder *next;
};

void auction_start(struct item *items, int num_items) {
  for (int i = 0; i < num_items; i++) {
    items[i].current_bid = items[i].starting_bid;
    items[i].highest_bidder = NULL;
  }

  int num_bidders = 0;
  struct bidder *bidders = NULL;

  while (num_bidders < MAX_BIDDERS) {
    struct bidder *new_bidder = malloc(sizeof(struct bidder));
    new_bidder->name[0] = '\0';
    new_bidder->bids = 0;
    new_bidder->total_spent = 0;
    new_bidder->next = bidders;
    bidders = new_bidder;
    num_bidders++;
  }

  srand(time(NULL));

  for (int round = 0; round < 10; round++) {
    for (int i = 0; i < num_items; i++) {
      struct bidder *highest_bidder = NULL;
      int highest_bid = items[i].starting_bid;

      for (struct bidder *bidder = bidders; bidder; bidder++) {
        if (bidder->bids > highest_bid) {
          highest_bidder = bidder;
          highest_bid = bidder->bids;
        }
      }

      if (highest_bidder) {
        items[i].highest_bidder = highest_bidder;
        items[i].current_bid = highest_bid;
      } else {
        items[i].current_bid = items[i].starting_bid;
      }
    }

    printf("Round %d:\n", round + 1);
    for (int i = 0; i < num_items; i++) {
      printf("Item: %s, Current Bid: %d, Highest Bidder: %s\n", items[i].name, items[i].current_bid, items[i].highest_bidder ? items[i].highest_bidder->name : "No bidder");
    }
  }

  printf("Auction Complete.\n");
  for (int i = 0; i < num_items; i++) {
    printf("Item: %s, Final Bid: %d, Highest Bidder: %s\n", items[i].name, items[i].current_bid, items[i].highest_bidder ? items[i].highest_bidder->name : "No bidder");
  }
}

int main() {
  struct item items[MAX_ITEMS] = {
    {"Laptop", 500, 0, NULL},
    {"Smartphone", 300, 0, NULL},
    {"Watch", 200, 0, NULL},
  };

  auction_start(items, 3);

  return 0;
}