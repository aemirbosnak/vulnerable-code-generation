//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a bid
typedef struct bid {
  char *bidder;  // Name of the bidder
  int amount;    // Amount of the bid
} bid;

// Define the structure of an auction
typedef struct auction {
  char *name;    // Name of the auction
  char *item;    // Item being auctioned
  int starting_price;  // Starting price of the auction
  int current_price;   // Current price of the auction
  int num_bids;   // Number of bids on the auction
  bid *bids;      // Array of bids on the auction
} auction;

// Create a new auction
auction *create_auction(char *name, char *item, int starting_price) {
  auction *a = malloc(sizeof(auction));
  a->name = strdup(name);
  a->item = strdup(item);
  a->starting_price = starting_price;
  a->current_price = starting_price;
  a->num_bids = 0;
  a->bids = NULL;
  return a;
}

// Destroy an auction
void destroy_auction(auction *a) {
  free(a->name);
  free(a->item);
  for (int i = 0; i < a->num_bids; i++) {
    free(a->bids[i].bidder);
  }
  free(a->bids);
  free(a);
}

// Add a bid to an auction
void add_bid(auction *a, char *bidder, int amount) {
  a->num_bids++;
  a->bids = realloc(a->bids, a->num_bids * sizeof(bid));
  a->bids[a->num_bids - 1].bidder = strdup(bidder);
  a->bids[a->num_bids - 1].amount = amount;
  if (amount > a->current_price) {
    a->current_price = amount;
  }
}

// Print the details of an auction
void print_auction(auction *a) {
  printf("Name: %s\n", a->name);
  printf("Item: %s\n", a->item);
  printf("Starting price: %d\n", a->starting_price);
  printf("Current price: %d\n", a->current_price);
  printf("Number of bids: %d\n", a->num_bids);
  for (int i = 0; i < a->num_bids; i++) {
    printf("  Bidder: %s\n", a->bids[i].bidder);
    printf("  Amount: %d\n", a->bids[i].amount);
  }
}

// Main function
int main() {
  // Create a new auction
  auction *a = create_auction("The Grand Auction", "A rare and valuable artifact", 100);

  // Add some bids to the auction
  add_bid(a, "Sir Reginald", 120);
  add_bid(a, "Lady Beatrice", 150);
  add_bid(a, "Lord Edmund", 180);

  // Print the details of the auction
  print_auction(a);

  // Destroy the auction
  destroy_auction(a);

  return 0;
}