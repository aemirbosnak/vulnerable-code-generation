//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
  char *name;
  float price;
} item;

typedef struct bid {
  char *name;
  float amount;
} bid;

item *new_item(char *name, float price) {
  item *i = malloc(sizeof(item));
  i->name = strdup(name);
  i->price = price;
  return i;
}

bid *new_bid(char *name, float amount) {
  bid *b = malloc(sizeof(bid));
  b->name = strdup(name);
  b->amount = amount;
  return b;
}

void print_item(item *i) {
  printf("%s: $%.2f\n", i->name, i->price);
}

void print_bid(bid *b) {
  printf("%s: $%.2f\n", b->name, b->amount);
}

int main() {
  item *items[] = {
    new_item("Mona Lisa", 1000000000.00),
    new_item("Starry Night", 150000000.00),
    new_item("The Scream", 120000000.00),
    new_item("Guernica", 110000000.00),
    new_item("Water Lilies", 100000000.00),
  };

  bid *bids[] = {
    new_bid("Alice", 1000000001.00),
    new_bid("Bob", 1500000001.00),
    new_bid("Carol", 1200000001.00),
    new_bid("Dave", 1100000001.00),
    new_bid("Eve", 1000000001.00),
  };

  int num_items = sizeof(items) / sizeof(item *);
  int num_bids = sizeof(bids) / sizeof(bid *);

  // Find the highest bid for each item.
  for (int i = 0; i < num_items; i++) {
    bid *highest_bid = NULL;
    for (int j = 0; j < num_bids; j++) {
      if (bids[j]->amount > (highest_bid ? highest_bid->amount : 0.00)) {
        highest_bid = bids[j];
      }
    }

    // Print the item and the highest bid.
    print_item(items[i]);
    print_bid(highest_bid);

    // Free the memory allocated for the item and the bid.
    free(items[i]->name);
    free(items[i]);
    free(highest_bid->name);
    free(highest_bid);
  }

  return 0;
}