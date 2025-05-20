//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item structure
typedef struct {
  char* name;
  char* description;
  float starting_price;
  float current_bid;
  char* highest_bidder;
} Item;

// Bid structure
typedef struct {
  char* bidder_name;
  float bid_amount;
} Bid;

// Function to create a new item
Item* create_item(char* name, char* description, float starting_price) {
  Item* item = (Item*)malloc(sizeof(Item));
  item->name = strdup(name);
  item->description = strdup(description);
  item->starting_price = starting_price;
  item->current_bid = starting_price;
  item->highest_bidder = NULL;
  return item;
}

// Function to destroy an item
void destroy_item(Item* item) {
  free(item->name);
  free(item->description);
  free(item->highest_bidder);
  free(item);
}

// Function to create a new bid
Bid* create_bid(char* bidder_name, float bid_amount) {
  Bid* bid = (Bid*)malloc(sizeof(Bid));
  bid->bidder_name = strdup(bidder_name);
  bid->bid_amount = bid_amount;
  return bid;
}

// Function to destroy a bid
void destroy_bid(Bid* bid) {
  free(bid->bidder_name);
  free(bid);
}

// Function to compare two bids
int compare_bids(const void* a, const void* b) {
  Bid* bid1 = (Bid*)a;
  Bid* bid2 = (Bid*)b;
  return (bid2->bid_amount - bid1->bid_amount);
}

// Function to run the auction
void run_auction(Item* item) {
  // Get the number of bids
  int num_bids;
  printf("Enter the number of bids: ");
  scanf("%d", &num_bids);

  // Create an array of bids
  Bid** bids = (Bid**)malloc(sizeof(Bid*) * num_bids);

  // Get the bids
  for (int i = 0; i < num_bids; i++) {
    char bidder_name[100];
    float bid_amount;
    printf("Enter the bidder's name: ");
    scanf("%s", bidder_name);
    printf("Enter the bid amount: ");
    scanf("%f", &bid_amount);
    bids[i] = create_bid(bidder_name, bid_amount);
  }

  // Sort the bids in descending order
  qsort(bids, num_bids, sizeof(Bid*), compare_bids);

  // Find the highest bid
  Bid* highest_bid = bids[0];

  // Update the item's current bid and highest bidder
  item->current_bid = highest_bid->bid_amount;
  item->highest_bidder = highest_bid->bidder_name;

  // Destroy the bids
  for (int i = 0; i < num_bids; i++) {
    destroy_bid(bids[i]);
  }
  free(bids);
}

// Main function
int main() {
  // Create an item
  Item* item = create_item("iPhone 13 Pro Max", "The latest and greatest iPhone", 999.99);

  // Run the auction
  run_auction(item);

  // Print the results
  printf("The winning bid is: $%.2f\n", item->current_bid);
  printf("The winning bidder is: %s\n", item->highest_bidder);

  // Destroy the item
  destroy_item(item);

  return 0;
}