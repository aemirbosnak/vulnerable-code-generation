//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the auction
#define MAX_ITEMS 100

// Define the structure of an item in the auction
typedef struct {
  char name[50]; // The name of the item
  float price; // The current price of the item
  int bidder; // The ID of the highest bidder
} Item;

// Define the structure of the auction system
typedef struct {
  Item items[MAX_ITEMS]; // The array of items in the auction
  int num_items; // The number of items in the auction
  int current_bidder; // The ID of the current highest bidder
  float current_bid; // The current highest bid
} AuctionSystem;

// Create a new auction system
AuctionSystem* create_auction_system() {
  AuctionSystem* auction_system = (AuctionSystem*)malloc(sizeof(AuctionSystem));
  auction_system->num_items = 0;
  auction_system->current_bidder = -1;
  auction_system->current_bid = 0.0;
  return auction_system;
}

// Add an item to the auction system
void add_item_to_auction_system(AuctionSystem* auction_system, char* name, float price) {
  if (auction_system->num_items < MAX_ITEMS) {
    strcpy(auction_system->items[auction_system->num_items].name, name);
    auction_system->items[auction_system->num_items].price = price;
    auction_system->items[auction_system->num_items].bidder = -1;
    auction_system->num_items++;
  } else {
    printf("Error: Maximum number of items reached.\n");
  }
}

// Place a bid on an item in the auction system
void place_bid(AuctionSystem* auction_system, int item_index, int bidder, float bid) {
  if (item_index >= 0 && item_index < auction_system->num_items) {
    if (bid > auction_system->items[item_index].price) {
      auction_system->items[item_index].price = bid;
      auction_system->items[item_index].bidder = bidder;
      auction_system->current_bidder = bidder;
      auction_system->current_bid = bid;
    } else {
      printf("Error: Bid must be higher than current price.\n");
    }
  } else {
    printf("Error: Invalid item index.\n");
  }
}

// Get the current highest bid for an item in the auction system
float get_current_bid(AuctionSystem* auction_system, int item_index) {
  if (item_index >= 0 && item_index < auction_system->num_items) {
    return auction_system->items[item_index].price;
  } else {
    return -1.0;
  }
}

// Get the ID of the current highest bidder for an item in the auction system
int get_current_bidder(AuctionSystem* auction_system, int item_index) {
  if (item_index >= 0 && item_index < auction_system->num_items) {
    return auction_system->items[item_index].bidder;
  } else {
    return -1;
  }
}

// Print the details of the auction system
void print_auction_system(AuctionSystem* auction_system) {
  printf("Current Auction Items:\n");
  for (int i = 0; i < auction_system->num_items; i++) {
    printf("Item %d: %s - Current Price: %.2f - Current Bidder: %d\n",
           i + 1, auction_system->items[i].name, auction_system->items[i].price, auction_system->items[i].bidder);
  }
  printf("Current Highest Bidder: %d\n", auction_system->current_bidder);
  printf("Current Highest Bid: %.2f\n", auction_system->current_bid);
}

// Main function
int main() {
  // Create a new auction system
  AuctionSystem* auction_system = create_auction_system();

  // Add some items to the auction system
  add_item_to_auction_system(auction_system, "Mona Lisa", 1000000.0);
  add_item_to_auction_system(auction_system, "Starry Night", 500000.0);
  add_item_to_auction_system(auction_system, "The Scream", 750000.0);

  // Print the details of the auction system
  print_auction_system(auction_system);

  // Place some bids on the items
  place_bid(auction_system, 0, 1, 1100000.0);
  place_bid(auction_system, 1, 2, 550000.0);
  place_bid(auction_system, 2, 3, 800000.0);

  // Print the updated details of the auction system
  print_auction_system(auction_system);

  return 0;
}