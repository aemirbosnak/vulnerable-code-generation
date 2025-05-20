//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Define the maximum number of bids and bidders
#define MAX_BIDS 10
#define MAX_BIDDERS 5

// Define the structure of a bid
typedef struct bid {
  int amount;
  int bidder_id;
} bid_t;

// Define the structure of an auction
typedef struct auction {
  int item_id;
  char *item_name;
  int starting_price;
  int current_price;
  int highest_bidder_id;
  bid_t bids[MAX_BIDS];
  int num_bids;
} auction_t;

// Create a new auction
auction_t *create_auction(int item_id, char *item_name, int starting_price) {
  auction_t *auction = malloc(sizeof(auction_t));
  auction->item_id = item_id;
  auction->item_name = strdup(item_name);
  auction->starting_price = starting_price;
  auction->current_price = starting_price;
  auction->highest_bidder_id = -1;
  auction->num_bids = 0;
  return auction;
}

// Destroy an auction
void destroy_auction(auction_t *auction) {
  free(auction->item_name);
  free(auction);
}

// Add a bid to an auction
void add_bid(auction_t *auction, int bidder_id, int amount) {
  if (auction->num_bids < MAX_BIDS) {
    auction->bids[auction->num_bids].amount = amount;
    auction->bids[auction->num_bids].bidder_id = bidder_id;
    auction->num_bids++;

    if (amount > auction->current_price) {
      auction->current_price = amount;
      auction->highest_bidder_id = bidder_id;
    }
  }
}

// Get the highest bid for an auction
int get_highest_bid(auction_t *auction) {
  return auction->current_price;
}

// Get the highest bidder for an auction
int get_highest_bidder(auction_t *auction) {
  return auction->highest_bidder_id;
}

// Print the details of an auction
void print_auction(auction_t *auction) {
  printf("Item ID: %d\n", auction->item_id);
  printf("Item Name: %s\n", auction->item_name);
  printf("Starting Price: %d\n", auction->starting_price);
  printf("Current Price: %d\n", auction->current_price);
  printf("Highest Bidder: %d\n", auction->highest_bidder_id);
  printf("Number of Bids: %d\n", auction->num_bids);
  for (int i = 0; i < auction->num_bids; i++) {
    printf("Bid %d: %d from bidder %d\n", i + 1, auction->bids[i].amount, auction->bids[i].bidder_id);
  }
}

// Main function
int main() {
  // Create a new auction
  auction_t *auction = create_auction(1, "iPhone 13 Pro", 1000);

  // Add some bids to the auction
  add_bid(auction, 1, 1100);
  add_bid(auction, 2, 1200);
  add_bid(auction, 3, 1300);

  // Print the details of the auction
  print_auction(auction);

  // Get the highest bid and bidder
  int highest_bid = get_highest_bid(auction);
  int highest_bidder = get_highest_bidder(auction);

  // Print the results
  printf("Highest Bid: %d\n", highest_bid);
  printf("Highest Bidder: %d\n", highest_bidder);

  // Destroy the auction
  destroy_auction(auction);

  return 0;
}