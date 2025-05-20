//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of items and bids
#define MAX_ITEMS 10
#define MAX_BIDS 100

// Define the structure of an item
typedef struct {
  int id;
  char name[50];
  float starting_price;
  float current_price;
  int num_bids;
  int highest_bidder;
} Item;

// Define the structure of a bid
typedef struct {
  int id;
  int item_id;
  float amount;
  int bidder_id;
  time_t timestamp;
} Bid;

// Define the structure of a bidder
typedef struct {
  int id;
  char name[50];
  float balance;
} Bidder;

// Initialize the system with some sample data
Item items[] = {
  {1, "Item 1", 10.0, 10.0, 0, -1},
  {2, "Item 2", 20.0, 20.0, 0, -1},
  {3, "Item 3", 30.0, 30.0, 0, -1},
};

Bidder bidders[] = {
  {1, "Bidder 1", 100.0},
  {2, "Bidder 2", 200.0},
  {3, "Bidder 3", 300.0},
};

// Function to print the welcome message
void print_welcome_message() {
  printf("Welcome to the Digital Auction System!\n");
  printf("-------------------------------------\n");
}

// Function to print the list of items
void print_items(Item items[], int num_items) {
  printf("Items:\n");
  for (int i = 0; i < num_items; i++) {
    printf("  - Item %d: %s (Starting price: %.2f, Current price: %.2f)\n",
      items[i].id, items[i].name, items[i].starting_price, items[i].current_price);
  }
}

// Function to print the list of bidders
void print_bidders(Bidder bidders[], int num_bidders) {
  printf("Bidders:\n");
  for (int i = 0; i < num_bidders; i++) {
    printf("  - Bidder %d: %s (Balance: %.2f)\n",
      bidders[i].id, bidders[i].name, bidders[i].balance);
  }
}

// Function to place a bid
Bid* place_bid(Item* item, Bidder* bidder, float amount) {
  // Check if the bid is valid
  if (amount <= item->current_price || amount > bidder->balance) {
    return NULL;
  }

  // Create a new bid
  Bid* bid = malloc(sizeof(Bid));
  bid->id = 1;
  bid->item_id = item->id;
  bid->amount = amount;
  bid->bidder_id = bidder->id;
  bid->timestamp = time(NULL);

  // Update the item's current price and highest bidder
  item->current_price = amount;
  item->highest_bidder = bidder->id;

  // Update the bidder's balance
  bidder->balance -= amount;

  // Return the bid
  return bid;
}

// Function to print the results of the auction
void print_results(Item items[], int num_items) {
  printf("Auction results:\n");
  for (int i = 0; i < num_items; i++) {
    if (items[i].highest_bidder == -1) {
      printf("  - Item %d: unsold\n", items[i].id);
    } else {
      printf("  - Item %d: sold to Bidder %d for %.2f\n",
        items[i].id, items[i].highest_bidder, items[i].current_price);
    }
  }
}

// Main function
int main() {
  // Print the welcome message
  print_welcome_message();

  // Print the list of items
  print_items(items, MAX_ITEMS);

  // Print the list of bidders
  print_bidders(bidders, 3);

  // Get the input from the user
  int item_id;
  float amount;
  int bidder_id;
  printf("Enter the ID of the item you want to bid on: ");
  scanf("%d", &item_id);
  printf("Enter the amount you want to bid: ");
  scanf("%f", &amount);
  printf("Enter your bidder ID: ");
  scanf("%d", &bidder_id);

  // Find the item and the bidder
  Item* item = NULL;
  Bidder* bidder = NULL;
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (items[i].id == item_id) {
      item = &items[i];
    }
  }
  for (int i = 0; i < 3; i++) {
    if (bidders[i].id == bidder_id) {
      bidder = &bidders[i];
    }
  }

  // Place the bid
  Bid* bid = place_bid(item, bidder, amount);

  // Check if the bid was successful
  if (bid == NULL) {
    printf("Error: Invalid bid.\n");
  } else {
    printf("Bid placed successfully.\n");
  }

  // Print the results of the auction
  print_results(items, MAX_ITEMS);

  return 0;
}