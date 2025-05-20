//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The item being auctioned.
struct Item {
  int id;
  char name[100];
  float current_bid;
};

// The list of items being auctioned.
struct ItemList {
  struct Item **items;
  int count;
};

// The user bidding on the item.
struct User {
  int id;
  char name[100];
  float balance;
};

// The list of users bidding on the item.
struct UserList {
  struct User **users;
  int count;
};

// The auction itself.
struct Auction {
  struct ItemList *items;
  struct UserList *users;
  int current_item;
};

// Create a new item.
struct Item *new_item(int id, char *name, float current_bid) {
  struct Item *item = malloc(sizeof(struct Item));
  item->id = id;
  strcpy(item->name, name);
  item->current_bid = current_bid;
  return item;
}

// Create a new item list.
struct ItemList *new_item_list() {
  struct ItemList *item_list = malloc(sizeof(struct ItemList));
  item_list->items = malloc(sizeof(struct Item *) * 100);
  item_list->count = 0;
  return item_list;
}

// Add an item to the item list.
void add_item(struct ItemList *item_list, struct Item *item) {
  item_list->items[item_list->count] = item;
  item_list->count++;
}

// Create a new user.
struct User *new_user(int id, char *name, float balance) {
  struct User *user = malloc(sizeof(struct User));
  user->id = id;
  strcpy(user->name, name);
  user->balance = balance;
  return user;
}

// Create a new user list.
struct UserList *new_user_list() {
  struct UserList *user_list = malloc(sizeof(struct UserList));
  user_list->users = malloc(sizeof(struct User *) * 100);
  user_list->count = 0;
  return user_list;
}

// Add a user to the user list.
void add_user(struct UserList *user_list, struct User *user) {
  user_list->users[user_list->count] = user;
  user_list->count++;
}

// Create a new auction.
struct Auction *new_auction(struct ItemList *items, struct UserList *users) {
  struct Auction *auction = malloc(sizeof(struct Auction));
  auction->items = items;
  auction->users = users;
  auction->current_item = 0;
  return auction;
}

// Start the auction.
void start_auction(struct Auction *auction) {
  while (auction->current_item < auction->items->count) {
    struct Item *item = auction->items->items[auction->current_item];
    printf("Current item: %s\n", item->name);
    printf("Current bid: %f\n", item->current_bid);
    for (int i = 0; i < auction->users->count; i++) {
      struct User *user = auction->users->users[i];
      printf("User %s: %f\n", user->name, user->balance);
    }
    printf("\n");
    char input[100];
    fgets(input, 100, stdin);
    float bid = atof(input);
    for (int i = 0; i < auction->users->count; i++) {
      struct User *user = auction->users->users[i];
      if (bid > user->balance) {
        printf("User %s does not have enough balance to bid.\n", user->name);
      } else {
        user->balance -= bid;
        item->current_bid = bid;
        printf("User %s has bid %f on item %s.\n", user->name, bid, item->name);
      }
    }
    auction->current_item++;
  }
}

// End the auction.
void end_auction(struct Auction *auction) {
  for (int i = 0; i < auction->items->count; i++) {
    struct Item *item = auction->items->items[i];
    printf("Item %s sold for %f.\n", item->name, item->current_bid);
  }
}

// Main function.
int main() {
  // Create the item list.
  struct ItemList *item_list = new_item_list();
  add_item(item_list, new_item(1, "Item 1", 10.0));
  add_item(item_list, new_item(2, "Item 2", 20.0));
  add_item(item_list, new_item(3, "Item 3", 30.0));

  // Create the user list.
  struct UserList *user_list = new_user_list();
  add_user(user_list, new_user(1, "User 1", 100.0));
  add_user(user_list, new_user(2, "User 2", 200.0));
  add_user(user_list, new_user(3, "User 3", 300.0));

  // Create the auction.
  struct Auction *auction = new_auction(item_list, user_list);

  // Start the auction.
  start_auction(auction);

  // End the auction.
  end_auction(auction);

  return 0;
}