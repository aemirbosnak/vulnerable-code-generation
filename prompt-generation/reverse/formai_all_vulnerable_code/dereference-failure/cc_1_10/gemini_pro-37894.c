//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Item struct
typedef struct Item {
    char name[100];
    int reserve_price;
    int current_bid;
    int highest_bidder;  // -1 if no bids
    int closed;  // 0 if open, 1 if closed
} Item;

// User struct
typedef struct User {
    char name[100];
    int balance;
} User;

// Auction struct
typedef struct Auction {
    Item items[100];
    User users[100];
    int num_items;
    int num_users;
    int current_item;
} Auction;

// Function to create a new auction
Auction* create_auction() {
    Auction* auction = malloc(sizeof(Auction));
    auction->num_items = 0;
    auction->num_users = 0;
    auction->current_item = -1;
    return auction;
}

// Function to destroy an auction
void destroy_auction(Auction* auction) {
    free(auction);
}

// Function to add an item to an auction
void add_item(Auction* auction, char* name, int reserve_price) {
    Item item;
    strcpy(item.name, name);
    item.reserve_price = reserve_price;
    item.current_bid = 0;
    item.highest_bidder = -1;
    item.closed = 0;
    auction->items[auction->num_items++] = item;
}

// Function to add a user to an auction
void add_user(Auction* auction, char* name, int balance) {
    User user;
    strcpy(user.name, name);
    user.balance = balance;
    auction->users[auction->num_users++] = user;
}

// Function to start an auction
void start_auction(Auction* auction) {
    auction->current_item++;
}

// Function to close an auction
void close_auction(Auction* auction) {
    auction->items[auction->current_item].closed = 1;
}

// Function to bid on an item
int bid(Auction* auction, char* user_name, int amount) {
    int user_index = -1;
    int item_index = auction->current_item;

    // Find the user index
    for (int i = 0; i < auction->num_users; i++) {
        if (strcmp(auction->users[i].name, user_name) == 0) {
            user_index = i;
            break;
        }
    }

    // Check if the user exists
    if (user_index == -1) {
        return -1;
    }

    // Check if the item is closed
    if (auction->items[item_index].closed) {
        return -2;
    }

    // Check if the bid is high enough
    if (amount < auction->items[item_index].current_bid) {
        return -3;
    }

    // Check if the user has enough balance
    if (amount > auction->users[user_index].balance) {
        return -4;
    }

    // Place the bid
    auction->items[item_index].current_bid = amount;
    auction->items[item_index].highest_bidder = user_index;
    auction->users[user_index].balance -= amount;

    return 0;
}

// Function to get the current item
Item* get_current_item(Auction* auction) {
    return &auction->items[auction->current_item];
}

// Function to get the highest bidder
User* get_highest_bidder(Auction* auction) {
    int item_index = auction->current_item;
    int user_index = auction->items[item_index].highest_bidder;
    return &auction->users[user_index];
}

// Function to print the auction
void print_auction(Auction* auction) {
    printf("Current item: %s\n", auction->items[auction->current_item].name);
    printf("Reserve price: %d\n", auction->items[auction->current_item].reserve_price);
    printf("Current bid: %d\n", auction->items[auction->current_item].current_bid);
    printf("Highest bidder: %s\n", auction->users[auction->items[auction->current_item].highest_bidder].name);
    printf("Closed: %d\n", auction->items[auction->current_item].closed);
}

// Main function
int main() {
    // Create an auction
    Auction* auction = create_auction();

    // Add some items to the auction
    add_item(auction, "Mona Lisa", 1000000);
    add_item(auction, "Starry Night", 500000);
    add_item(auction, "The Last Supper", 1500000);

    // Add some users to the auction
    add_user(auction, "Alice", 1000000);
    add_user(auction, "Bob", 500000);
    add_user(auction, "Charlie", 1500000);

    // Start the auction
    start_auction(auction);

    // Print the auction
    print_auction(auction);

    // Get the current item
    Item* current_item = get_current_item(auction);

    // Place a bid
    int bid_amount = 1100000;
    int result = bid(auction, "Alice", bid_amount);

    // Print the auction
    print_auction(auction);

    // Get the highest bidder
    User* highest_bidder = get_highest_bidder(auction);

    // Print the highest bidder
    printf("Highest bidder: %s\n", highest_bidder->name);

    // Close the auction
    close_auction(auction);

    // Print the auction
    print_auction(auction);

    // Destroy the auction
    destroy_auction(auction);

    return 0;
}