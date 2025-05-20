//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Item struct
typedef struct Item {
  char name[50];
  int price;
} Item;

// Bid struct
typedef struct Bid {
  char bidder[50];
  int amount;
} Bid;

// Auction struct
typedef struct Auction {
  Item item;
  Bid winning_bid;
  int num_bids;
  Bid *bids;
} Auction;

// Create a new item
Item create_item(char *name, int price) {
  Item item;
  strcpy(item.name, name);
  item.price = price;
  return item;
}

// Create a new bid
Bid create_bid(char *bidder, int amount) {
  Bid bid;
  strcpy(bid.bidder, bidder);
  bid.amount = amount;
  return bid;
}

// Create a new auction
Auction create_auction(Item item) {
  Auction auction;
  auction.item = item;
  auction.num_bids = 0;
  auction.bids = NULL;
  return auction;
}

// Add a bid to an auction
void add_bid(Auction *auction, Bid bid) {
  auction->bids = realloc(auction->bids, (auction->num_bids + 1) * sizeof(Bid));
  auction->bids[auction->num_bids++] = bid;
}

// Get the highest bid for an auction
Bid get_highest_bid(Auction *auction) {
  Bid highest_bid;
  highest_bid.amount = -1;
  for (int i = 0; i < auction->num_bids; i++) {
    if (auction->bids[i].amount > highest_bid.amount) {
      highest_bid = auction->bids[i];
    }
  }
  return highest_bid;
}

// Close an auction
void close_auction(Auction *auction) {
  Bid highest_bid = get_highest_bid(auction);
  auction->winning_bid = highest_bid;
  printf("The auction for '%s' has ended. The winning bid is %d from %s.\n", auction->item.name, highest_bid.amount, highest_bid.bidder);
}

// Main function
int main() {
  // Create an item
  Item item = create_item("iPhone 13 Pro Max", 1000);

  // Create an auction
  Auction auction = create_auction(item);

  // Add some bids
  add_bid(&auction, create_bid("Alice", 1100));
  add_bid(&auction, create_bid("Bob", 1200));
  add_bid(&auction, create_bid("Carol", 1300));

  // Close the auction
  close_auction(&auction);

  return 0;
}