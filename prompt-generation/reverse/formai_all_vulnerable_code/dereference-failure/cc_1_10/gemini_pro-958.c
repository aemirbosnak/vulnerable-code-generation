//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 1000

typedef struct {
  int id;
  char *name;
  float reserve_price;
  float current_bid;
  int num_bids;
} Item;

typedef struct {
  int id;
  char *name;
  float amount;
} Bid;

Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int num_items = 0;
int num_bids = 0;

void add_item(char *name, float reserve_price) {
  items[num_items].id = num_items + 1;
  items[num_items].name = malloc(strlen(name) + 1);
  strcpy(items[num_items].name, name);
  items[num_items].reserve_price = reserve_price;
  items[num_items].current_bid = 0;
  items[num_items].num_bids = 0;
  num_items++;
}

void add_bid(int item_id, char *name, float amount) {
  bids[num_bids].id = num_bids + 1;
  bids[num_bids].name = malloc(strlen(name) + 1);
  strcpy(bids[num_bids].name, name);
  bids[num_bids].amount = amount;
  num_bids++;

  Item *item = &items[item_id - 1];
  item->current_bid = amount;
  item->num_bids++;
}

void print_items() {
  printf("Items:\n");
  for (int i = 0; i < num_items; i++) {
    Item *item = &items[i];
    printf("  %d. %s (Reserve: %f, Current Bid: %f, Num Bids: %d)\n", item->id, item->name, item->reserve_price, item->current_bid, item->num_bids);
  }
}

void print_bids() {
  printf("Bids:\n");
  for (int i = 0; i < num_bids; i++) {
    Bid *bid = &bids[i];
    printf("  %d. %s (%f)\n", bid->id, bid->name, bid->amount);
  }
}

int main() {
  srand(time(NULL));

  // Add some items to the auction
  add_item("Mona Lisa", 1000000);
  add_item("Starry Night", 500000);
  add_item("Guernica", 800000);
  add_item("The Scream", 1200000);
  add_item("Water Lilies", 700000);

  // Add some bids to the auction
  add_bid(1, "Alice", 1100000);
  add_bid(2, "Bob", 550000);
  add_bid(3, "Carol", 850000);
  add_bid(4, "Dave", 1300000);
  add_bid(5, "Eve", 750000);

  // Print the items and bids
  print_items();
  print_bids();

  return 0;
}