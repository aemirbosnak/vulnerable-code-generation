//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item structure
typedef struct Item {
  int id;
  char *name;
  float price;
} Item;

// Bidder structure
typedef struct Bidder {
  int id;
  char *name;
  float max_bid;
} Bidder;

// Auction structure
typedef struct Auction {
  Item *item;
  Bidder *bidder;
  float current_bid;
  float reserve_price;
} Auction;

// Create a new item
Item *create_item(int id, char *name, float price) {
  Item *item = malloc(sizeof(Item));
  item->id = id;
  item->name = strdup(name);
  item->price = price;
  return item;
}

// Create a new bidder
Bidder *create_bidder(int id, char *name, float max_bid) {
  Bidder *bidder = malloc(sizeof(Bidder));
  bidder->id = id;
  bidder->name = strdup(name);
  bidder->max_bid = max_bid;
  return bidder;
}

// Create a new auction
Auction *create_auction(Item *item, Bidder *bidder, float reserve_price) {
  Auction *auction = malloc(sizeof(Auction));
  auction->item = item;
  auction->bidder = bidder;
  auction->current_bid = 0;
  auction->reserve_price = reserve_price;
  return auction;
}

// Print the details of an item
void print_item(Item *item) {
  printf("Item ID: %d\n", item->id);
  printf("Item name: %s\n", item->name);
  printf("Item price: %.2f\n", item->price);
}

// Print the details of a bidder
void print_bidder(Bidder *bidder) {
  printf("Bidder ID: %d\n", bidder->id);
  printf("Bidder name: %s\n", bidder->name);
  printf("Bidder max bid: %.2f\n", bidder->max_bid);
}

// Print the details of an auction
void print_auction(Auction *auction) {
  printf("Item ID: %d\n", auction->item->id);
  printf("Item name: %s\n", auction->item->name);
  printf("Item price: %.2f\n", auction->item->price);
  printf("Bidder ID: %d\n", auction->bidder->id);
  printf("Bidder name: %s\n", auction->bidder->name);
  printf("Bidder max bid: %.2f\n", auction->bidder->max_bid);
  printf("Current bid: %.2f\n", auction->current_bid);
  printf("Reserve price: %.2f\n", auction->reserve_price);
}

// Get the highest bid for an auction
float get_highest_bid(Auction *auction) {
  return auction->current_bid;
}

// Place a bid for an auction
void place_bid(Auction *auction, float bid) {
  if (bid > auction->current_bid && bid <= auction->bidder->max_bid) {
    auction->current_bid = bid;
  }
}

// End the auction and determine the winner
Bidder *end_auction(Auction *auction) {
  if (auction->current_bid >= auction->reserve_price) {
    return auction->bidder;
  } else {
    return NULL;
  }
}

int main() {
  // Create an item
  Item *item = create_item(1, "Mona Lisa", 1000000);

  // Create a bidder
  Bidder *bidder = create_bidder(1, "John Smith", 1200000);

  // Create an auction
  Auction *auction = create_auction(item, bidder, 800000);

  // Print the details of the auction
  print_auction(auction);

  // Place a bid
  place_bid(auction, 1100000);

  // Print the highest bid
  printf("Highest bid: %.2f\n", get_highest_bid(auction));

  // End the auction
  Bidder *winner = end_auction(auction);

  // Print the winner
  if (winner != NULL) {
    printf("Winner: %s\n", winner->name);
  } else {
    printf("No winner.\n");
  }

  // Free the memory allocated for the item, bidder, and auction
  free(item->name);
  free(item);
  free(bidder->name);
  free(bidder);
  free(auction);

  return 0;
}