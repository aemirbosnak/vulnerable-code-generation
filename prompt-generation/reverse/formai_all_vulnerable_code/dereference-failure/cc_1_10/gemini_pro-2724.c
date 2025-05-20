//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of items that can be auctioned
#define MAX_ITEMS 10

// Define the maximum number of bids that can be placed on each item
#define MAX_BIDS 5

// Define the structure of an item
typedef struct item {
  int id;
  char *name;
  float reserve_price;
  float current_bid;
  int num_bids;
  struct bid *bids;
} item;

// Define the structure of a bid
typedef struct bid {
  int id;
  float amount;
  char *bidder;
} bid;

// Define the structure of the auction system
typedef struct auction_system {
  item items[MAX_ITEMS];
  int num_items;
  bid bids[MAX_BIDS * MAX_ITEMS];
  int num_bids;
} auction_system;

// Create a new auction system
auction_system *create_auction_system() {
  auction_system *system = malloc(sizeof(auction_system));
  system->num_items = 0;
  system->num_bids = 0;
  return system;
}

// Add an item to the auction system
void add_item(auction_system *system, char *name, float reserve_price) {
  if (system->num_items == MAX_ITEMS) {
    printf("Error: The maximum number of items has been reached.\n");
    return;
  }

  item *item = &system->items[system->num_items];
  item->id = system->num_items + 1;
  item->name = strdup(name);
  item->reserve_price = reserve_price;
  item->current_bid = 0.0;
  item->num_bids = 0;
  system->num_items++;
}

// Place a bid on an item
void place_bid(auction_system *system, int item_id, float amount, char *bidder) {
  if (item_id < 1 || item_id > system->num_items) {
    printf("Error: The item ID is invalid.\n");
    return;
  }

  item *item = &system->items[item_id - 1];

  if (amount < item->current_bid) {
    printf("Error: The bid amount must be greater than the current bid.\n");
    return;
  }

  bid *bid = &system->bids[system->num_bids];
  bid->id = system->num_bids + 1;
  bid->amount = amount;
  bid->bidder = strdup(bidder);
  item->num_bids++;
  system->num_bids++;
  item->current_bid = amount;
}

// Close the auction
void close_auction(auction_system *system) {
  for (int i = 0; i < system->num_items; i++) {
    item *item = &system->items[i];

    if (item->current_bid >= item->reserve_price) {
      printf("Item %s sold for $%.2f to %s.\n", item->name, item->current_bid,
             item->bids[item->num_bids - 1].bidder);
    } else {
      printf("Item %s did not meet its reserve price.\n", item->name);
    }
  }
}

// Free the memory allocated by the auction system
void free_auction_system(auction_system *system) {
  for (int i = 0; i < system->num_items; i++) {
    item *item = &system->items[i];
    free(item->name);
    for (int j = 0; j < item->num_bids; j++) {
      bid *bid = &item->bids[j];
      free(bid->bidder);
    }
  }
  free(system);
}

int main() {
  // Create a new auction system
  auction_system *system = create_auction_system();

  // Add some items to the auction system
  add_item(system, "Painting", 100.0);
  add_item(system, "Sculpture", 200.0);
  add_item(system, "Vase", 50.0);

  // Place some bids on the items
  place_bid(system, 1, 110.0, "John");
  place_bid(system, 2, 210.0, "Mary");
  place_bid(system, 3, 60.0, "Bob");

  // Close the auction
  close_auction(system);

  // Free the memory allocated by the auction system
  free_auction_system(system);

  return 0;
}