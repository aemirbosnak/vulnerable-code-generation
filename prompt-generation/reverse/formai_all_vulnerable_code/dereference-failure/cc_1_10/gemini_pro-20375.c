//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the item struct
typedef struct item {
  int id;
  char *name;
  float price;
} item;

// Define the bid struct
typedef struct bid {
  int id;
  int item_id;
  float amount;
} bid;

// Define the user struct
typedef struct user {
  int id;
  char *name;
  float balance;
} user;

// Function to create a new item
item *create_item(int id, char *name, float price) {
  item *new_item = malloc(sizeof(item));
  new_item->id = id;
  new_item->name = strdup(name);
  new_item->price = price;
  return new_item;
}

// Function to create a new bid
bid *create_bid(int id, int item_id, float amount) {
  bid *new_bid = malloc(sizeof(bid));
  new_bid->id = id;
  new_bid->item_id = item_id;
  new_bid->amount = amount;
  return new_bid;
}

// Function to create a new user
user *create_user(int id, char *name, float balance) {
  user *new_user = malloc(sizeof(user));
  new_user->id = id;
  new_user->name = strdup(name);
  new_user->balance = balance;
  return new_user;
}

// Function to print an item
void print_item(item *item) {
  printf("Item: %s, Price: %f\n", item->name, item->price);
}

// Function to print a bid
void print_bid(bid *bid) {
  printf("Bid: %f, Item ID: %d\n", bid->amount, bid->item_id);
}

// Function to print a user
void print_user(user *user) {
  printf("User: %s, Balance: %f\n", user->name, user->balance);
}

// Function to start the auction
void start_auction(item *items[], int num_items, user *users[], int num_users) {
  // Print the items
  for (int i = 0; i < num_items; i++) {
    print_item(items[i]);
  }

  // Get the bids from the users
  for (int i = 0; i < num_users; i++) {
    for (int j = 0; j < num_items; j++) {
      // Get the bid amount from the user
      float bid_amount;
      printf("Enter your bid for %s: ", items[j]->name);
      scanf("%f", &bid_amount);

      // Create a new bid
      bid *new_bid = create_bid(i, items[j]->id, bid_amount);

      // Check if the bid is valid
      if (new_bid->amount > users[i]->balance) {
        printf("Your bid is too high. Please enter a lower bid.\n");
        continue;
      }

      // Add the bid to the list of bids
      users[i]->balance -= new_bid->amount;
      items[j]->price = new_bid->amount;
    }
  }

  // Print the winning bids
  for (int i = 0; i < num_items; i++) {
    printf("Winning bid for %s: %f\n", items[i]->name, items[i]->price);
  }
}

int main() {
  // Create the items
  item *items[] = {
    create_item(1, "iPhone 13 Pro Max", 1000.00),
    create_item(2, "MacBook Pro 14-inch", 2000.00),
    create_item(3, "Apple Watch Series 7", 400.00),
  };
  int num_items = sizeof(items) / sizeof(items[0]);

  // Create the users
  user *users[] = {
    create_user(1, "Alice", 10000.00),
    create_user(2, "Bob", 5000.00),
    create_user(3, "Carol", 3000.00),
  };
  int num_users = sizeof(users) / sizeof(users[0]);

  // Start the auction
  start_auction(items, num_items, users, num_users);

  return 0;
}