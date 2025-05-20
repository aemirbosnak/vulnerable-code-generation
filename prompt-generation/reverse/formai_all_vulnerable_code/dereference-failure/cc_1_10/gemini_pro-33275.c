//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an item
typedef struct Item {
  int id;                  // Unique ID of the item
  char *name;              // Name of the item
  float reserve_price;     // Reserve price of the item
  float current_bid;       // Current highest bid for the item
  int num_bids;            // Number of bids received for the item
  char **bidders;          // Array of bidders for the item
} Item;

// Structure to represent an auction
typedef struct Auction {
  Item **items;            // Array of items in the auction
  int num_items;           // Number of items in the auction
  int num_bids;            // Number of bids received in the auction
  char **bidders;          // Array of unique bidders in the auction
} Auction;

// Function to create a new item
Item *create_item(int id, char *name, float reserve_price) {
  Item *item = malloc(sizeof(Item));
  item->id = id;
  item->name = strdup(name);
  item->reserve_price = reserve_price;
  item->current_bid = 0.0;
  item->num_bids = 0;
  item->bidders = NULL;
  return item;
}

// Function to create a new auction
Auction *create_auction() {
  Auction *auction = malloc(sizeof(Auction));
  auction->items = NULL;
  auction->num_items = 0;
  auction->num_bids = 0;
  auction->bidders = NULL;
  return auction;
}

// Function to add an item to an auction
void add_item_to_auction(Auction *auction, Item *item) {
  auction->items = realloc(auction->items, (auction->num_items + 1) * sizeof(Item *));
  auction->items[auction->num_items] = item;
  auction->num_items++;
}

// Function to place a bid on an item
void place_bid(Auction *auction, int item_id, char *bidder, float bid_amount) {
  Item *item = NULL;
  // Find the item by its ID
  for (int i = 0; i < auction->num_items; i++) {
    if (auction->items[i]->id == item_id) {
      item = auction->items[i];
      break;
    }
  }

  // Check if the bid amount is valid
  if (bid_amount < item->reserve_price) {
    printf("Bid amount must be greater than or equal to the reserve price.\n");
    return;
  }

  // Check if the bidder has already placed a bid on this item
  for (int i = 0; i < item->num_bids; i++) {
    if (strcmp(item->bidders[i], bidder) == 0) {
      printf("Bidder has already placed a bid on this item.\n");
      return;
    }
  }

  // Add the bid to the item
  item->bidders = realloc(item->bidders, (item->num_bids + 1) * sizeof(char *));
  item->bidders[item->num_bids] = strdup(bidder);
  item->num_bids++;

  // Update the current bid amount
  if (bid_amount > item->current_bid) {
    item->current_bid = bid_amount;
  }

  // Update the number of bids received in the auction
  auction->num_bids++;

  // Add the bidder to the list of unique bidders in the auction
  int found = 0;
  for (int i = 0; i < auction->num_bids; i++) {
    if (strcmp(auction->bidders[i], bidder) == 0) {
      found = 1;
      break;
    }
  }
  if (!found) {
    auction->bidders = realloc(auction->bidders, (auction->num_bids + 1) * sizeof(char *));
    auction->bidders[auction->num_bids] = strdup(bidder);
  }
}

// Function to print the details of an item
void print_item(Item *item) {
  printf("Item ID: %d\n", item->id);
  printf("Item Name: %s\n", item->name);
  printf("Reserve Price: %.2f\n", item->reserve_price);
  printf("Current Bid: %.2f\n", item->current_bid);
  printf("Number of Bids: %d\n", item->num_bids);
  printf("Bidders:\n");
  for (int i = 0; i < item->num_bids; i++) {
    printf("  %s\n", item->bidders[i]);
  }
}

// Function to print the details of an auction
void print_auction(Auction *auction) {
  printf("Number of Items: %d\n", auction->num_items);
  printf("Number of Bids: %d\n", auction->num_bids);
  printf("Bidders:\n");
  for (int i = 0; i < auction->num_bids; i++) {
    printf("  %s\n", auction->bidders[i]);
  }
  printf("Items:\n");
  for (int i = 0; i < auction->num_items; i++) {
    print_item(auction->items[i]);
  }
}

// Function to free the memory allocated for an item
void free_item(Item *item) {
  free(item->name);
  for (int i = 0; i < item->num_bids; i++) {
    free(item->bidders[i]);
  }
  free(item->bidders);
  free(item);
}

// Function to free the memory allocated for an auction
void free_auction(Auction *auction) {
  for (int i = 0; i < auction->num_items; i++) {
    free_item(auction->items[i]);
  }
  free(auction->items);
  for (int i = 0; i < auction->num_bids; i++) {
    free(auction->bidders[i]);
  }
  free(auction->bidders);
  free(auction);
}

// Main function
int main() {
  // Create a new auction
  Auction *auction = create_auction();

  // Add some items to the auction
  Item *item1 = create_item(1, "Painting", 100.0);
  add_item_to_auction(auction, item1);
  Item *item2 = create_item(2, "Sculpture", 200.0);
  add_item_to_auction(auction, item2);
  Item *item3 = create_item(3, "Vase", 300.0);
  add_item_to_auction(auction, item3);

  // Place some bids on the items
  place_bid(auction, 1, "Bidder1", 110.0);
  place_bid(auction, 1, "Bidder2", 120.0);
  place_bid(auction, 2, "Bidder3", 210.0);
  place_bid(auction, 2, "Bidder4", 220.0);
  place_bid(auction, 3, "Bidder5", 310.0);

  // Print the details of the auction
  print_auction(auction);

  // Free the memory allocated for the auction
  free_auction(auction);

  return 0;
}