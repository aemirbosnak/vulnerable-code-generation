//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the auction
#define MAX_ITEMS 100

// Define the maximum number of bids per item
#define MAX_BIDS_PER_ITEM 10

// Define the structure of an item
typedef struct item {
  int id;
  char name[100];
  float starting_price;
  float current_price;
  int num_bids;
  int bids[MAX_BIDS_PER_ITEM];
} item_t;

// Define the structure of an auction
typedef struct auction {
  int num_items;
  item_t items[MAX_ITEMS];
} auction_t;

// Create a new auction
auction_t *create_auction() {
  auction_t *auction = malloc(sizeof(auction_t));
  auction->num_items = 0;
  return auction;
}

// Add an item to an auction
void add_item_to_auction(auction_t *auction, item_t item) {
  auction->items[auction->num_items] = item;
  auction->num_items++;
}

// Get the current highest bid for an item
float get_current_highest_bid(item_t item) {
  float highest_bid = 0.0;
  for (int i = 0; i < item.num_bids; i++) {
    if (item.bids[i] > highest_bid) {
      highest_bid = item.bids[i];
    }
  }
  return highest_bid;
}

// Place a bid on an item
void place_bid(item_t *item, float bid) {
  if (bid > item->current_price) {
    item->bids[item->num_bids] = bid;
    item->num_bids++;
    item->current_price = bid;
  }
}

// Close the auction
void close_auction(auction_t *auction) {
  for (int i = 0; i < auction->num_items; i++) {
    printf("Item %d: %s\n", auction->items[i].id, auction->items[i].name);
    printf("  Starting price: %.2f\n", auction->items[i].starting_price);
    printf("  Current price: %.2f\n", auction->items[i].current_price);
    printf("  Number of bids: %d\n", auction->items[i].num_bids);
    printf("  Highest bid: %.2f\n", get_current_highest_bid(auction->items[i]));
    printf("\n");
  }
}

// Main function
int main() {
  // Create a new auction
  auction_t *auction = create_auction();

  // Add some items to the auction
  item_t item1 = {1, "Item 1", 10.0, 10.0, 0, {}};
  add_item_to_auction(auction, item1);
  item_t item2 = {2, "Item 2", 20.0, 20.0, 0, {}};
  add_item_to_auction(auction, item2);

  // Place some bids on the items
  place_bid(&item1, 12.0);
  place_bid(&item1, 15.0);
  place_bid(&item2, 22.0);
  place_bid(&item2, 25.0);

  // Close the auction
  close_auction(auction);

  return 0;
}