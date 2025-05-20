//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Define the maximum number of bids
#define MAX_BIDS 10

// Define the structure of a bid
typedef struct bid {
  char name[20];
  double amount;
} Bid;

// Define the structure of an auction
typedef struct auction {
  char name[20];
  char description[100];
  double starting_price;
  double current_price;
  int num_bids;
  Bid bids[MAX_BIDS];
} Auction;

// Create a new auction
Auction *create_auction(char *name, char *description, double starting_price) {
  Auction *auction = malloc(sizeof(Auction));
  strcpy(auction->name, name);
  strcpy(auction->description, description);
  auction->starting_price = starting_price;
  auction->current_price = starting_price;
  auction->num_bids = 0;
  return auction;
}

// Add a bid to an auction
void add_bid(Auction *auction, Bid bid) {
  if (auction->num_bids < MAX_BIDS) {
    auction->bids[auction->num_bids] = bid;
    auction->num_bids++;
  }
}

// Get the highest bid for an auction
Bid get_highest_bid(Auction *auction) {
  Bid highest_bid;
  highest_bid.amount = 0;
  for (int i = 0; i < auction->num_bids; i++) {
    if (auction->bids[i].amount > highest_bid.amount) {
      highest_bid = auction->bids[i];
    }
  }
  return highest_bid;
}

// Print the details of an auction
void print_auction(Auction *auction) {
  printf("Name: %s\n", auction->name);
  printf("Description: %s\n", auction->description);
  printf("Starting price: %.2f\n", auction->starting_price);
  printf("Current price: %.2f\n", auction->current_price);
  printf("Number of bids: %d\n", auction->num_bids);
  for (int i = 0; i < auction->num_bids; i++) {
    printf("  Bid %d: %s %.2f\n", i + 1, auction->bids[i].name, auction->bids[i].amount);
  }
}

// Main function
int main() {
  // Create a new auction
  Auction *auction = create_auction("My Auction", "This is a sample auction.", 10.0);

  // Add some bids to the auction
  Bid bid1 = {"John Doe", 12.0};
  add_bid(auction, bid1);
  Bid bid2 = {"Jane Doe", 15.0};
  add_bid(auction, bid2);
  Bid bid3 = {"Bill Smith", 18.0};
  add_bid(auction, bid3);

  // Print the details of the auction
  print_auction(auction);

  // Get the highest bid for the auction
  Bid highest_bid = get_highest_bid(auction);

  // Print the winning bid
  printf("Winning bid: %s %.2f\n", highest_bid.name, highest_bid.amount);

  return 0;
}