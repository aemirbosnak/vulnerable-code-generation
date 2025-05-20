//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store item details
typedef struct item {
  int id;
  char name[50];
  float price;
  int quantity;
} item;

// Structure to store bid details
typedef struct bid {
  int id;
  int item_id;
  float amount;
  char bidder_name[50];
} bid;

// Function to compare bids based on amount
int compare_bids(const void *a, const void *b) {
  bid *bid1 = (bid *)a;
  bid *bid2 = (bid *)b;
  return bid2->amount - bid1->amount;
}

// Function to print item details
void print_item(item *item) {
  printf("Item ID: %d\n", item->id);
  printf("Item Name: %s\n", item->name);
  printf("Item Price: %.2f\n", item->price);
  printf("Item Quantity: %d\n", item->quantity);
}

// Function to print bid details
void print_bid(bid *bid) {
  printf("Bid ID: %d\n", bid->id);
  printf("Item ID: %d\n", bid->item_id);
  printf("Bid Amount: %.2f\n", bid->amount);
  printf("Bidder Name: %s\n", bid->bidder_name);
}

int main() {
  // Create an array of items
  item items[] = {
    {1, "iPhone 13 Pro Max", 1299.99, 10},
    {2, "MacBook Air M2", 999.99, 15},
    {3, "iPad Pro 12.9-inch", 1099.99, 8},
    {4, "AirPods Pro", 249.99, 20},
  };

  // Create an array of bids
  bid bids[] = {
    {1, 1, 1350.00, "John Doe"},
    {2, 2, 1050.00, "Jane Smith"},
    {3, 3, 1150.00, "Michael Jones"},
    {4, 4, 260.00, "Sarah Wilson"},
  };

  // Sort the bids in descending order of amount
  qsort(bids, sizeof(bids) / sizeof(bid), sizeof(bid), compare_bids);

  // Iterate over the items and print the highest bid for each item
  for (int i = 0; i < sizeof(items) / sizeof(item); i++) {
    int highest_bid_id = -1;
    float highest_bid_amount = -1.0;
    for (int j = 0; j < sizeof(bids) / sizeof(bid); j++) {
      if (bids[j].item_id == items[i].id && bids[j].amount > highest_bid_amount) {
        highest_bid_id = bids[j].id;
        highest_bid_amount = bids[j].amount;
      }
    }

    if (highest_bid_id != -1) {
      printf("Highest Bid for Item %d:\n", items[i].id);
      print_bid(&bids[highest_bid_id]);
    } else {
      printf("No bids for Item %d.\n", items[i].id);
    }
    printf("\n");
  }

  return 0;
}