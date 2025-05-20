//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store item details
typedef struct item {
    int id;
    char name[50];
    float starting_price;
    float highest_bid;
    char highest_bidder[50];
    int status; // 0 for open, 1 for closed, 2 for sold
} item_t;

// Structure to store user details
typedef struct user {
    int id;
    char name[50];
    float balance;
} user_t;

// Function to create a new item
item_t* create_item(int id, char* name, float starting_price) {
    item_t* item = (item_t*)malloc(sizeof(item_t));
    item->id = id;
    strcpy(item->name, name);
    item->starting_price = starting_price;
    item->highest_bid = starting_price;
    item->highest_bidder[0] = '\0';
    item->status = 0;
    return item;
}

// Function to create a new user
user_t* create_user(int id, char* name, float balance) {
    user_t* user = (user_t*)malloc(sizeof(user_t));
    user->id = id;
    strcpy(user->name, name);
    user->balance = balance;
    return user;
}

// Function to start the auction
void start_auction(item_t* item) {
    item->status = 0;
    printf("Auction for item %s has started!\n", item->name);
}

// Function to place a bid
void place_bid(item_t* item, user_t* user, float bid_amount) {
    if(item->status == 0 && bid_amount > item->highest_bid && bid_amount <= user->balance) {
        item->highest_bid = bid_amount;
        strcpy(item->highest_bidder, user->name);
        user->balance -= bid_amount;
        printf("%s has placed a bid of $%.2f for item %s\n", user->name, bid_amount, item->name);
    } else {
        printf("Invalid bid. Please try again.\n");
    }
}

// Function to close the auction
void close_auction(item_t* item) {
    item->status = 1;
    printf("Auction for item %s has closed.\n", item->name);
    if(item->highest_bid > item->starting_price) {
        printf("The winner is %s with a bid of $%.2f\n", item->highest_bidder, item->highest_bid);
    } else {
        printf("The auction has ended without a winner.\n");
    }
}

// Function to sell the item to the winner
void sell_item(item_t* item) {
    item->status = 2;
    printf("Item %s has been sold to %s for $%.2f\n", item->name, item->highest_bidder, item->highest_bid);
}

// Function to print the status of an item
void print_item_status(item_t* item) {
    switch(item->status) {
        case 0:
            printf("Item %s is currently open for bidding.\n", item->name);
            break;
        case 1:
            printf("Item %s is currently closed for bidding.\n", item->name);
            break;
        case 2:
            printf("Item %s has been sold to %s for $%.2f\n", item->name, item->highest_bidder, item->highest_bid);
            break;
    }
}

// Main function
int main() {
    // Create some items
    item_t* item1 = create_item(1, "Painting", 100.00);
    item_t* item2 = create_item(2, "Sculpture", 200.00);
    item_t* item3 = create_item(3, "Vase", 50.00);

    // Create some users
    user_t* user1 = create_user(1, "John", 500.00);
    user_t* user2 = create_user(2, "Mary", 1000.00);
    user_t* user3 = create_user(3, "Bob", 200.00);

    // Start the auction for the first item
    start_auction(item1);

    // Place some bids
    place_bid(item1, user1, 120.00);
    place_bid(item1, user2, 150.00);
    place_bid(item1, user3, 100.00);

    // Close the auction for the first item
    close_auction(item1);

    // Sell the first item to the winner
    sell_item(item1);

    // Print the status of the first item
    print_item_status(item1);

    return 0;
}