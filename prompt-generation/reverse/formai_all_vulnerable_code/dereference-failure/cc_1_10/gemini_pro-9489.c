//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100

typedef struct {
  int id;
  char *name;
  double starting_bid;
} Item;

typedef struct {
  int id;
  int item_id;
  double amount;
} Bid;

// Function to create a new item
Item *create_item(int id, char *name, double starting_bid) {
  Item *item = malloc(sizeof(Item));
  item->id = id;
  item->name = strdup(name);
  item->starting_bid = starting_bid;
  return item;
}

// Function to create a new bid
Bid *create_bid(int id, int item_id, double amount) {
  Bid *bid = malloc(sizeof(Bid));
  bid->id = id;
  bid->item_id = item_id;
  bid->amount = amount;
  return bid;
}

// Function to print an item
void print_item(Item *item) {
  printf("Item %d: %s - Starting bid: %f\n", item->id, item->name, item->starting_bid);
}

// Function to print a bid
void print_bid(Bid *bid) {
  printf("Bid %d: Item %d - Amount: %f\n", bid->id, bid->item_id, bid->amount);
}

// Function to compare two bids
int compare_bids(const void *a, const void *b) {
  Bid *bid1 = (Bid *)a;
  Bid *bid2 = (Bid *)b;
  return bid2->amount - bid1->amount;
}

// Main function
int main() {
  // Create some items
  Item *items[MAX_ITEMS];
  items[0] = create_item(1, "Painting", 100.0);
  items[1] = create_item(2, "Sculpture", 200.0);
  items[2] = create_item(3, "Vase", 50.0);

  // Create some bids
  Bid *bids[MAX_BIDS];
  bids[0] = create_bid(1, 1, 110.0);
  bids[1] = create_bid(2, 2, 210.0);
  bids[2] = create_bid(3, 3, 60.0);

  // Print the items
  printf("Items:\n");
  for (int i = 0; i < 3; i++) {
    print_item(items[i]);
  }

  // Print the bids
  printf("\nBids:\n");
  for (int i = 0; i < 3; i++) {
    print_bid(bids[i]);
  }

  // Sort the bids in descending order
  qsort(bids, 3, sizeof(Bid), compare_bids);

  // Print the winning bids
  printf("\nWinning bids:\n");
  for (int i = 0; i < 3; i++) {
    print_bid(bids[i]);
  }

  return 0;
}