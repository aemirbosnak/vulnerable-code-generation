//FormAI DATASET v1.0 Category: Digital Auction System ; Style: modular
// Digital Auction System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants
#define MAX_USERS 10
#define MAX_ITEMS 5
#define MAX_BIDS 10

// Define User struct
typedef struct {
    char username[20];
    int balance;
} User;

// Define Item struct
typedef struct {
    char name[20];
    int current_bid;
    int highest_bid;
    User *highest_bidder;
} Item;

// Define Bid struct
typedef struct {
    int amount;
    User *bidder;
} Bid;

// Declare functions
void initialize_users(User *users[]);
void initialize_items(Item *items[]);
void print_users(User *users[]);
void print_items(Item *items[]);
void place_bid(Item *item, Bid *bids[], User *user);
void print_bids(Bid *bids[]);
void print_highest_bidder(Item *item);

// Main function
int main() {
    // Initialize users and items
    User *users[MAX_USERS];
    Item *items[MAX_ITEMS];
    initialize_users(users);
    initialize_items(items);
    // Print users and items
    print_users(users);
    print_items(items);
    // Place bids on items
    for (int i = 0; i < MAX_ITEMS; i++) {
        Bid *bids[MAX_BIDS];
        for (int j = 0; j < MAX_BIDS; j++) {
            bids[j] = NULL;
        }
        while (true) {
            printf("Enter your username to place a bid on %s (or 'q' to quit): ", items[i]->name);
            char username[20];
            scanf("%s", username);
            if (username[0] == 'q') {
                break;
            }
            User *user = NULL;
            for (int k = 0; k < MAX_USERS; k++) {
                if (users[k] != NULL && strcmp(users[k]->username, username) == 0) {
                    user = users[k];
                    break;
                }
            }
            if (user == NULL) {
                printf("User not found.\n");
                continue;
            }
            place_bid(items[i], bids, user);
        }
        printf("Bids for %s:\n", items[i]->name);
        print_bids(bids);
        print_highest_bidder(items[i]);
    }
    return 0;
}

// Initialize users
void initialize_users(User *users[]) {
    users[0] = (User *) malloc(sizeof(User));
    strcpy(users[0]->username, "Alice");
    users[0]->balance = 100;
    users[1] = (User *) malloc(sizeof(User));
    strcpy(users[1]->username, "Bob");
    users[1]->balance = 200;
    users[2] = (User *) malloc(sizeof(User));
    strcpy(users[2]->username, "Charlie");
    users[2]->balance = 300;
    for (int i = 3; i < MAX_USERS; i++) {
        users[i] = NULL;
    }
}

// Initialize items
void initialize_items(Item *items[]) {
    items[0] = (Item *) malloc(sizeof(Item));
    strcpy(items[0]->name, "Painting");
    items[0]->current_bid = 0;
    items[0]->highest_bid = 0;
    items[0]->highest_bidder = NULL;
    items[1] = (Item *) malloc(sizeof(Item));
    strcpy(items[1]->name, "Vase");
    items[1]->current_bid = 0;
    items[1]->highest_bid = 0;
    items[1]->highest_bidder = NULL;
    items[2] = (Item *) malloc(sizeof(Item));
    strcpy(items[2]->name, "Guitar");
    items[2]->current_bid = 0;
    items[2]->highest_bid = 0;
    items[2]->highest_bidder = NULL;
    items[3] = (Item *) malloc(sizeof(Item));
    strcpy(items[3]->name, "Ring");
    items[3]->current_bid = 0;
    items[3]->highest_bid = 0;
    items[3]->highest_bidder = NULL;
    items[4] = (Item *) malloc(sizeof(Item));
    strcpy(items[4]->name, "Watch");
    items[4]->current_bid = 0;
    items[4]->highest_bid = 0;
    items[4]->highest_bidder = NULL;
}

// Print users
void print_users(User *users[]) {
    printf("Users:\n");
    for (int i = 0; i < MAX_USERS; i++) {
        if (users[i] == NULL) {
            break;
        }
        printf("%s (balance: $%d)\n", users[i]->username, users[i]->balance);
    }
}

// Print items
void print_items(Item *items[]) {
    printf("Items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%s (current bid: $%d, highest bid: $%d)\n", items[i]->name, items[i]->current_bid, items[i]->highest_bid);
    }
}

// Place bid
void place_bid(Item *item, Bid *bids[], User *user) {
    printf("Enter your bid for %s (your balance: $%d): ", item->name, user->balance);
    int amount;
    scanf("%d", &amount);
    if (amount <= item->highest_bid) {
        printf("Your bid must be higher than the current highest bid.\n");
        return;
    }
    if (amount > user->balance) {
        printf("Your bid cannot exceed your current balance.\n");
        return;
    }
    for (int i = 0; i < MAX_BIDS; i++) {
        if (bids[i] == NULL) {
            Bid *bid = (Bid *) malloc(sizeof(Bid));
            bid->amount = amount;
            bid->bidder = user;
            bids[i] = bid;
            item->current_bid = amount;
            item->highest_bid = amount;
            item->highest_bidder = user;
            user->balance -= amount;
            printf("Bid placed!\n");
            return;
        }
    }
    printf("Maximum number of bids reached for %s.\n", item->name);
}

// Print bids
void print_bids(Bid *bids[]) {
    bool has_bids = false;
    for (int i = 0; i < MAX_BIDS; i++) {
        if (bids[i] != NULL) {
            has_bids = true;
            printf("%s: $%d\n", bids[i]->bidder->username, bids[i]->amount);
        }
    }
    if (!has_bids) {
        printf("No bids.\n");
    }
}

// Print highest bidder for item
void print_highest_bidder(Item *item) {
    if (item->highest_bidder == NULL) {
        printf("No bids for %s.\n", item->name);
    } else {
        printf("%s won %s for $%d!\n", item->highest_bidder->username, item->name, item->highest_bid);
    }
}