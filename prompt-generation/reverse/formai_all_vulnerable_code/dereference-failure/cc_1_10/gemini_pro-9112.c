//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the auction
#define MAX_ITEMS 100

// Define the maximum length of an item name
#define MAX_NAME_LENGTH 50

// Define the maximum length of a bidder name
#define MAX_BIDDER_NAME_LENGTH 50

// Define the minimum bid increment
#define MIN_BID_INCREMENT 10

// Define the auction status
enum auction_status {
  AUCTION_OPEN,
  AUCTION_CLOSED
};

// Define the item struct
typedef struct item {
  char name[MAX_NAME_LENGTH];
  float current_bid;
  char current_bidder[MAX_BIDDER_NAME_LENGTH];
} item_t;

// Define the bidder struct
typedef struct bidder {
  char name[MAX_BIDDER_NAME_LENGTH];
  float balance;
} bidder_t;

// Define the auction struct
typedef struct auction {
  item_t items[MAX_ITEMS];
  int num_items;
  bidder_t bidders[MAX_ITEMS];
  int num_bidders;
  enum auction_status status;
} auction_t;

// Create a new auction
auction_t *create_auction() {
  auction_t *auction = malloc(sizeof(auction_t));
  auction->num_items = 0;
  auction->num_bidders = 0;
  auction->status = AUCTION_OPEN;
  return auction;
}

// Add an item to the auction
void add_item(auction_t *auction, char *name, float starting_bid) {
  if (auction->num_items >= MAX_ITEMS) {
    printf("Error: Maximum number of items reached.\n");
    return;
  }

  strcpy(auction->items[auction->num_items].name, name);
  auction->items[auction->num_items].current_bid = starting_bid;
  auction->items[auction->num_items].current_bidder[0] = '\0';
  auction->num_items++;
}

// Add a bidder to the auction
void add_bidder(auction_t *auction, char *name, float balance) {
  if (auction->num_bidders >= MAX_ITEMS) {
    printf("Error: Maximum number of bidders reached.\n");
    return;
  }

  strcpy(auction->bidders[auction->num_bidders].name, name);
  auction->bidders[auction->num_bidders].balance = balance;
  auction->num_bidders++;
}

// Place a bid on an item
void place_bid(auction_t *auction, char *item_name, char *bidder_name, float bid) {
  // Find the item
  int item_index = -1;
  for (int i = 0; i < auction->num_items; i++) {
    if (strcmp(auction->items[i].name, item_name) == 0) {
      item_index = i;
      break;
    }
  }

  // Check if the item was found
  if (item_index == -1) {
    printf("Error: Item not found.\n");
    return;
  }

  // Find the bidder
  int bidder_index = -1;
  for (int i = 0; i < auction->num_bidders; i++) {
    if (strcmp(auction->bidders[i].name, bidder_name) == 0) {
      bidder_index = i;
      break;
    }
  }

  // Check if the bidder was found
  if (bidder_index == -1) {
    printf("Error: Bidder not found.\n");
    return;
  }

  // Check if the bid is valid
  if (bid <= auction->items[item_index].current_bid + MIN_BID_INCREMENT || bid > auction->bidders[bidder_index].balance) {
    printf("Error: Invalid bid.\n");
    return;
  }

  // Place the bid
  auction->items[item_index].current_bid = bid;
  strcpy(auction->items[item_index].current_bidder, bidder_name);
}

// Close the auction
void close_auction(auction_t *auction) {
  auction->status = AUCTION_CLOSED;

  // Print the results
  printf("Auction results:\n");
  for (int i = 0; i < auction->num_items; i++) {
    printf("%s: %f (%s)\n", auction->items[i].name, auction->items[i].current_bid, auction->items[i].current_bidder);
  }
}

// Main function
int main() {
  // Create a new auction
  auction_t *auction = create_auction();

  // Add some items to the auction
  add_item(auction, "Item 1", 100.0);
  add_item(auction, "Item 2", 200.0);
  add_item(auction, "Item 3", 300.0);

  // Add some bidders to the auction
  add_bidder(auction, "Bidder 1", 1000.0);
  add_bidder(auction, "Bidder 2", 2000.0);
  add_bidder(auction, "Bidder 3", 3000.0);

  // Place some bids
  place_bid(auction, "Item 1", "Bidder 1", 110.0);
  place_bid(auction, "Item 2", "Bidder 2", 210.0);
  place_bid(auction, "Item 3", "Bidder 3", 310.0);
  place_bid(auction, "Item 1", "Bidder 2", 120.0);
  place_bid(auction, "Item 2", "Bidder 3", 220.0);
  place_bid(auction, "Item 3", "Bidder 1", 320.0);

  // Close the auction
  close_auction(auction);

  // Free the auction
  free(auction);

  return 0;
}