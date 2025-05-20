//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item structure
typedef struct {
  int id;
  char name[50];
  double reserve_price;
  double current_bid;
  int highest_bidder;
} Item;

// Bid structure
typedef struct {
  int bidder_id;
  double bid_amount;
} Bid;

// Function to create a new item
Item *create_item(int id, char *name, double reserve_price) {
  Item *item = malloc(sizeof(Item));
  item->id = id;
  strcpy(item->name, name);
  item->reserve_price = reserve_price;
  item->current_bid = 0.0;
  item->highest_bidder = -1;
  return item;
}

// Function to create a new bid
Bid *create_bid(int bidder_id, double bid_amount) {
  Bid *bid = malloc(sizeof(Bid));
  bid->bidder_id = bidder_id;
  bid->bid_amount = bid_amount;
  return bid;
}

// Function to place a bid on an item
void place_bid(Item *item, Bid *bid) {
  // Check if the bid meets the reserve price
  if (bid->bid_amount < item->reserve_price) {
    printf("Bid does not meet reserve price.\n");
    return;
  }

  // Check if the bid is higher than the current highest bid
  if (bid->bid_amount > item->current_bid) {
    item->current_bid = bid->bid_amount;
    item->highest_bidder = bid->bidder_id;
  }
}

// Function to print the details of an item
void print_item(Item *item) {
  printf("Item ID: %d\n", item->id);
  printf("Item Name: %s\n", item->name);
  printf("Reserve Price: %.2f\n", item->reserve_price);
  printf("Current Bid: %.2f\n", item->current_bid);
  if (item->highest_bidder == -1) {
    printf("No bids placed yet.\n");
  } else {
    printf("Highest Bidder: %d\n", item->highest_bidder);
  }
  printf("\n");
}

// Function to print the details of a bid
void print_bid(Bid *bid) {
  printf("Bidder ID: %d\n", bid->bidder_id);
  printf("Bid Amount: %.2f\n", bid->bid_amount);
  printf("\n");
}

// Main function
int main() {
  // Create some items
  Item *item1 = create_item(1, "Painting", 100.0);
  Item *item2 = create_item(2, "Sculpture", 200.0);
  Item *item3 = create_item(3, "Vase", 50.0);

  // Print the details of each item
  printf("Items:\n");
  print_item(item1);
  print_item(item2);
  print_item(item3);

  // Create some bids
  Bid *bid1 = create_bid(1, 120.0);
  Bid *bid2 = create_bid(2, 220.0);
  Bid *bid3 = create_bid(3, 60.0);

  // Place the bids on the items
  place_bid(item1, bid1);
  place_bid(item2, bid2);
  place_bid(item3, bid3);

  // Print the details of each item after the bids have been placed
  printf("Items After Bids:\n");
  print_item(item1);
  print_item(item2);
  print_item(item3);

  return 0;
}