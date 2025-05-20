//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items and bids
#define MAX_ITEMS 10
#define MAX_BIDS 100

// Define the structure of an item
typedef struct item {
  int id;
  char *name;
  float reserve_price;
  float current_bid;
  int num_bids;
} item_t;

// Define the structure of a bid
typedef struct bid {
  int id;
  int item_id;
  float amount;
  char *bidder_name;
} bid_t;

// Define the structure of the auction system
typedef struct auction_system {
  item_t items[MAX_ITEMS];
  bid_t bids[MAX_BIDS];
  int num_items;
  int num_bids;
} auction_system_t;

// Function to create an auction system
auction_system_t *create_auction_system() {
  auction_system_t *system = malloc(sizeof(auction_system_t));
  system->num_items = 0;
  system->num_bids = 0;
  return system;
}

// Function to add an item to the auction system
void add_item(auction_system_t *system, int id, char *name, float reserve_price) {
  if (system->num_items < MAX_ITEMS) {
    item_t item;
    item.id = id;
    item.name = strdup(name);
    item.reserve_price = reserve_price;
    item.current_bid = 0.0;
    item.num_bids = 0;
    system->items[system->num_items++] = item;
  }
}

// Function to add a bid to the auction system
void add_bid(auction_system_t *system, int id, int item_id, float amount, char *bidder_name) {
  if (system->num_bids < MAX_BIDS) {
    bid_t bid;
    bid.id = id;
    bid.item_id = item_id;
    bid.amount = amount;
    bid.bidder_name = strdup(bidder_name);
    system->bids[system->num_bids++] = bid;
  }
}

// Function to print the items in the auction system
void print_items(auction_system_t *system) {
  for (int i = 0; i < system->num_items; i++) {
    item_t item = system->items[i];
    printf("Item %d: %s (reserve price: $%.2f)\n", item.id, item.name, item.reserve_price);
  }
}

// Function to print the bids in the auction system
void print_bids(auction_system_t *system) {
  for (int i = 0; i < system->num_bids; i++) {
    bid_t bid = system->bids[i];
    printf("Bid %d: Item %d, $%.2f by %s\n", bid.id, bid.item_id, bid.amount, bid.bidder_name);
  }
}

// Function to process the bids in the auction system
void process_bids(auction_system_t *system) {
  for (int i = 0; i < system->num_bids; i++) {
    bid_t bid = system->bids[i];
    item_t *item = &system->items[bid.item_id - 1];
    if (bid.amount >= item->reserve_price) {
      if (bid.amount > item->current_bid) {
        item->current_bid = bid.amount;
        item->num_bids++;
      }
    }
  }
}

// Function to print the results of the auction
void print_results(auction_system_t *system) {
  for (int i = 0; i < system->num_items; i++) {
    item_t item = system->items[i];
    if (item.current_bid >= item.reserve_price) {
      printf("Item %d: %s sold for $%.2f\n", item.id, item.name, item.current_bid);
    } else {
      printf("Item %d: %s did not sell\n", item.id, item.name);
    }
  }
}

// Function to free the memory allocated by the auction system
void free_auction_system(auction_system_t *system) {
  for (int i = 0; i < system->num_items; i++) {
    free(system->items[i].name);
  }
  for (int i = 0; i < system->num_bids; i++) {
    free(system->bids[i].bidder_name);
  }
  free(system);
}

int main() {
  // Create an auction system
  auction_system_t *system = create_auction_system();

  // Add some items to the auction system
  add_item(system, 1, "Painting", 100.0);
  add_item(system, 2, "Sculpture", 200.0);
  add_item(system, 3, "Vase", 50.0);

  // Add some bids to the auction system
  add_bid(system, 1, 1, 110.0, "John Doe");
  add_bid(system, 2, 1, 120.0, "Jane Doe");
  add_bid(system, 3, 2, 210.0, "Jack Doe");
  add_bid(system, 4, 2, 220.0, "Jill Doe");
  add_bid(system, 5, 3, 40.0, "John Smith");
  add_bid(system, 6, 3, 45.0, "Jane Smith");

  // Print the items in the auction system
  printf("Items:\n");
  print_items(system);

  // Print the bids in the auction system
  printf("Bids:\n");
  print_bids(system);

  // Process the bids in the auction system
  process_bids(system);

  // Print the results of the auction
  printf("Results:\n");
  print_results(system);

  // Free the memory allocated by the auction system
  free_auction_system(system);

  return 0;
}