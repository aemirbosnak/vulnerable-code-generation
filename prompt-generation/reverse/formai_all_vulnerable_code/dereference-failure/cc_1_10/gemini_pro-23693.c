//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a bid
typedef struct bid {
  char *bidder_name;
  int bid_amount;
} bid_t;

// Structure to represent an auction item
typedef struct item {
  char *name;
  int starting_price;
  int current_price;
  int highest_bidder_index;
  bid_t *bids;
  int num_bids;
} item_t;

// Function to create a new bid
bid_t *create_bid(char *bidder_name, int bid_amount) {
  bid_t *bid = malloc(sizeof(bid_t));
  bid->bidder_name = strdup(bidder_name);
  bid->bid_amount = bid_amount;
  return bid;
}

// Function to create a new auction item
item_t *create_item(char *name, int starting_price) {
  item_t *item = malloc(sizeof(item_t));
  item->name = strdup(name);
  item->starting_price = starting_price;
  item->current_price = starting_price;
  item->highest_bidder_index = -1;
  item->bids = NULL;
  item->num_bids = 0;
  return item;
}

// Function to add a bid to an auction item
void add_bid(item_t *item, bid_t *bid) {
  item->bids = realloc(item->bids, (item->num_bids + 1) * sizeof(bid_t));
  item->bids[item->num_bids] = *bid;
  item->num_bids++;

  // Update the current price and highest bidder
  if (bid->bid_amount > item->current_price) {
    item->current_price = bid->bid_amount;
    item->highest_bidder_index = item->num_bids - 1;
  }
}

// Function to print the details of an auction item
void print_item(item_t *item) {
  printf("Name: %s\n", item->name);
  printf("Starting price: %d\n", item->starting_price);
  printf("Current price: %d\n", item->current_price);
  if (item->highest_bidder_index >= 0) {
    printf("Highest bidder: %s\n", item->bids[item->highest_bidder_index].bidder_name);
  } else {
    printf("No bids yet\n");
  }
  printf("Number of bids: %d\n", item->num_bids);
}

// Function to run the auction
void run_auction(item_t *items, int num_items) {
  // Loop through each item
  for (int i = 0; i < num_items; i++) {
    // Print the item details
    print_item(&items[i]);

    // Get bids for the item
    char bidder_name[100];
    int bid_amount;
    while (1) {
      printf("Enter your name: ");
      scanf("%s", bidder_name);

      printf("Enter your bid: ");
      scanf("%d", &bid_amount);

      // Create a new bid and add it to the item
      bid_t *bid = create_bid(bidder_name, bid_amount);
      add_bid(&items[i], bid);

      // Check if the user wants to continue bidding
      char continue_bidding;
      printf("Do you want to continue bidding? (y/n) ");
      scanf(" %c", &continue_bidding);
      if (continue_bidding == 'n') {
        break;
      }
    }

    // Print the winning bid
    if (items[i].highest_bidder_index >= 0) {
      printf("The winning bid is %d by %s\n", items[i].current_price, items[i].bids[items[i].highest_bidder_index].bidder_name);
    } else {
      printf("No bids were placed for this item.\n");
    }

    // Free the memory allocated for the item
    free(items[i].name);
    free(items[i].bids);
  }
}

int main() {
  // Create some auction items
  item_t items[] = {
    {"Painting", 100},
    {"Sculpture", 200},
    {"Vase", 50}
  };
  int num_items = sizeof(items) / sizeof(items[0]);

  // Run the auction
  run_auction(items, num_items);

  return 0;
}