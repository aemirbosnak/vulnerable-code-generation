//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an auction item
typedef struct {
  int id;                // Unique identifier for the item
  char *name;             // Name of the item
  float reserve_price;    // Minimum price for the item to be sold
  float current_bid;     // Current highest bid for the item
  int highest_bidder;     // ID of the highest bidder
} auction_item;

// Structure to represent an auction
typedef struct {
  int num_items;          // Number of items in the auction
  auction_item *items;    // Array of auction items
  int num_bidders;        // Number of bidders in the auction
  int *bidders;           // Array of bidder IDs
} auction;

// Function to create a new auction
auction *create_auction(int num_items) {
  auction *a = malloc(sizeof(auction));
  a->num_items = num_items;
  a->items = malloc(sizeof(auction_item) * num_items);
  a->num_bidders = 0;
  a->bidders = NULL;
  return a;
}

// Function to add an item to an auction
void add_item(auction *a, auction_item item) {
  a->items[a->num_items++] = item;
}

// Function to add a bidder to an auction
void add_bidder(auction *a, int bidder_id) {
  a->bidders = realloc(a->bidders, sizeof(int) * (a->num_bidders + 1));
  a->bidders[a->num_bidders++] = bidder_id;
}

// Function to place a bid on an item
void place_bid(auction *a, int bidder_id, int item_id, float bid) {
  auction_item *item = &a->items[item_id];

  // Check if the bid is valid
  if (bid < item->reserve_price) {
    printf("Bid is too low.\n");
    return;
  }

  if (bid <= item->current_bid) {
    printf("Bid is not high enough.\n");
    return;
  }

  // Update the current bid and highest bidder
  item->current_bid = bid;
  item->highest_bidder = bidder_id;
}

// Function to get the current highest bid for an item
float get_current_bid(auction *a, int item_id) {
  return a->items[item_id].current_bid;
}

// Function to get the highest bidder for an item
int get_highest_bidder(auction *a, int item_id) {
  return a->items[item_id].highest_bidder;
}

// Function to print the details of an auction
void print_auction(auction *a) {
  printf("Auction details:\n");
  printf("Number of items: %d\n", a->num_items);
  printf("Items:\n");
  for (int i = 0; i < a->num_items; i++) {
    printf("  - ID: %d\n", a->items[i].id);
    printf("    Name: %s\n", a->items[i].name);
    printf("    Reserve price: %.2f\n", a->items[i].reserve_price);
    printf("    Current bid: %.2f\n", a->items[i].current_bid);
    printf("    Highest bidder: %d\n", a->items[i].highest_bidder);
  }
  printf("Number of bidders: %d\n", a->num_bidders);
  printf("Bidders:\n");
  for (int i = 0; i < a->num_bidders; i++) {
    printf("  - ID: %d\n", a->bidders[i]);
  }
}

// Main function
int main() {
  // Create a new auction
  auction *a = create_auction(3);

  // Add some items to the auction
  auction_item item1 = {1, "Painting", 100.0, 0.0, -1};
  add_item(a, item1);
  auction_item item2 = {2, "Sculpture", 200.0, 0.0, -1};
  add_item(a, item2);
  auction_item item3 = {3, "Vase", 50.0, 0.0, -1};
  add_item(a, item3);

  // Add some bidders to the auction
  add_bidder(a, 1);
  add_bidder(a, 2);
  add_bidder(a, 3);

  // Place some bids on the items
  place_bid(a, 1, 0, 110.0);
  place_bid(a, 2, 1, 210.0);
  place_bid(a, 3, 2, 60.0);

  // Print the details of the auction
  print_auction(a);

  return 0;
}