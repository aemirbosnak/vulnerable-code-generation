//FormAI DATASET v1.0 Category: Digital Auction System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of users
#define MAX_USERS 100

// Define maximum number of items up for auction
#define MAX_ITEMS 50

// Define structure for user
struct User {
    char username[20];
    float balance;
};

// Define structure for item
struct Item {
    char name[20];
    float starting_bid;
    float current_bid;
    char highest_bidder[20];
    int time_left;
};

// Declare array for users and items
struct User users[MAX_USERS];
struct Item items[MAX_ITEMS];

// Initialize number of users and items
int num_users = 0;
int num_items = 0;

// Function to add a user
void add_user(char *username, float balance) {
    // Allocate memory for new user
    struct User *new_user = malloc(sizeof(struct User));
    
    // Copy username and balance into new user
    strcpy(new_user->username, username);
    new_user->balance = balance;
    
    // Add new user to array and increment number of users
    users[num_users] = *new_user;
    num_users++;
}

// Function to add an item
void add_item(char *name, float starting_bid, int time_left) {
    // Allocate memory for new item
    struct Item *new_item = malloc(sizeof(struct Item));
    
    // Copy name, starting bid, and time left into new item
    strcpy(new_item->name, name);
    new_item->starting_bid = starting_bid;
    new_item->current_bid = starting_bid;
    strcpy(new_item->highest_bidder, "None");
    new_item->time_left = time_left;
    
    // Add new item to array and increment number of items
    items[num_items] = *new_item;
    num_items++;
}

// Function to display all items currently up for auction
void display_items() {
    printf("Items up for auction:\n");
    printf("======================\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s\n", i+1, items[i].name);
        printf("Starting bid: $%.2f\n", items[i].starting_bid);
        printf("Current bid: $%.2f\n", items[i].current_bid);
        printf("Highest bidder: %s\n", items[i].highest_bidder);
        printf("Time left: %d hours\n", items[i].time_left);
        printf("\n");
    }
}

// Function to place a bid on an item
void place_bid(int item_num, float bid_amount, char *username) {
    // Check if bid amount is greater than or equal to current bid
    if (bid_amount < items[item_num-1].current_bid) {
        printf("Your bid must be higher than the current bid.\n");
        return;
    }
    
    // Check if user has enough balance to make bid
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (bid_amount > users[i].balance) {
                printf("Insufficient funds.\n");
                return;
            }
            else {
                users[i].balance -= bid_amount;
            }
            break;
        }
    }
    
    // Update item with new bid information
    items[item_num-1].current_bid = bid_amount;
    strcpy(items[item_num-1].highest_bidder, username);
    
    printf("Bid placed successfully.\n");
}

int main() {
    // Add some users
    add_user("JohnDoe", 1000);
    add_user("JaneDoe", 2500);
    
    // Add some items
    add_item("Baseball", 10.00, 24);
    add_item("Guitar", 100.00, 48);
    
    // Display all items currently up for auction
    display_items();
    
    // Place a bid on an item
    place_bid(1, 15.00, "JaneDoe");
    
    // Display all items currently up for auction again to see updated bid information
    display_items();
    
    return 0;
}