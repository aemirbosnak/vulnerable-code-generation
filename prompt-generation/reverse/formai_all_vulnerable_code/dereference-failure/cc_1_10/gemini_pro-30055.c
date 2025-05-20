//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the maximum number of items in the auction
#define MAX_ITEMS 100

// Define the maximum length of an item's name
#define MAX_ITEM_NAME_LENGTH 50

// Define the maximum length of a bidder's name
#define MAX_BIDDER_NAME_LENGTH 50

// Define the minimum bid increment
#define MIN_BID_INCREMENT 1

// Define the auction status
typedef enum {
  AUCTION_OPEN,
  AUCTION_CLOSED
} auction_status;

// Define an item in the auction
typedef struct {
  int id;
  char name[MAX_ITEM_NAME_LENGTH];
  float current_bid;
  float reserve_price;
  int highest_bidder_id;
} item;

// Define a bidder in the auction
typedef struct {
  int id;
  char name[MAX_BIDDER_NAME_LENGTH];
} bidder;

// Define the auction
typedef struct {
  auction_status status;
  item items[MAX_ITEMS];
  int num_items;
  bidder bidders[MAX_ITEMS];
  int num_bidders;
} auction;

// Create a new auction
auction *create_auction() {
  auction *a = malloc(sizeof(auction));
  a->status = AUCTION_OPEN;
  a->num_items = 0;
  a->num_bidders = 0;
  return a;
}

// Add an item to the auction
void add_item(auction *a, item *i) {
  if (a->num_items < MAX_ITEMS) {
    a->items[a->num_items] = *i;
    a->num_items++;
  }
}

// Add a bidder to the auction
void add_bidder(auction *a, bidder *b) {
  if (a->num_bidders < MAX_ITEMS) {
    a->bidders[a->num_bidders] = *b;
    a->num_bidders++;
  }
}

// Place a bid on an item
void place_bid(auction *a, int item_id, int bidder_id, float bid) {
  if (a->status == AUCTION_OPEN) {
    item *i = &a->items[item_id];
    if (bid >= i->current_bid + MIN_BID_INCREMENT) {
      i->current_bid = bid;
      i->highest_bidder_id = bidder_id;
    }
  }
}

// Close the auction
void close_auction(auction *a) {
  a->status = AUCTION_CLOSED;
}

// Get the winning bidder for an item
bidder *get_winning_bidder(auction *a, int item_id) {
  if (a->status == AUCTION_CLOSED) {
    item *i = &a->items[item_id];
    return &a->bidders[i->highest_bidder_id];
  }
  return NULL;
}

// Print the auction results
void print_results(auction *a) {
  if (a->status == AUCTION_CLOSED) {
    for (int i = 0; i < a->num_items; i++) {
      item *item = &a->items[i];
      bidder *bidder = get_winning_bidder(a, i);
      printf("Item: %s\n", item->name);
      printf("Winning bid: %f\n", item->current_bid);
      printf("Winning bidder: %s\n\n", bidder->name);
    }
  }
}

// Main function
int main() {
  // Create a new auction
  auction *a = create_auction();

  // Add some items to the auction
  item item1 = {1, "Painting", 100.0, 150.0, -1};
  item item2 = {2, "Sculpture", 200.0, 250.0, -1};
  item item3 = {3, "Vase", 50.0, 75.0, -1};
  add_item(a, &item1);
  add_item(a, &item2);
  add_item(a, &item3);

  // Add some bidders to the auction
  bidder bidder1 = {1, "John"};
  bidder bidder2 = {2, "Mary"};
  bidder bidder3 = {3, "Bob"};
  add_bidder(a, &bidder1);
  add_bidder(a, &bidder2);
  add_bidder(a, &bidder3);

  // Place some bids
  place_bid(a, 0, 2, 120.0);
  place_bid(a, 1, 1, 225.0);
  place_bid(a, 2, 3, 60.0);

  // Close the auction
  close_auction(a);

  // Print the auction results
  print_results(a);

  // Free the auction
  free(a);

  return 0;
}