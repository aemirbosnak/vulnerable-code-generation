//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Item struct
typedef struct {
    int id;
    char *name;
    float starting_price;
    float current_price;
    float seller_id;
    int num_bids;
} Item;

// Bid struct
typedef struct {
    int id;
    float bid_amount;
    int bidder_id;
    int item_id;
} Bid;

// User struct
typedef struct {
    int id;
    char *name;
    float balance;
} User;

// List of items
Item *items = NULL;
int num_items = 0;

// List of bids
Bid *bids = NULL;
int num_bids = 0;

// List of users
User *users = NULL;
int num_users = 0;

// Initialize the system
void init_system() {
    // Create the first item
    Item item;
    item.id = 1;
    item.name = "iPhone 12";
    item.starting_price = 1000.0f;
    item.current_price = 1000.0f;
    item.seller_id = 1;
    item.num_bids = 0;
    items = &item;
    num_items = 1;

    // Create the first bid
    Bid bid;
    bid.id = 1;
    bid.bid_amount = 1100.0f;
    bid.bidder_id = 2;
    bid.item_id = 1;
    bids = &bid;
    num_bids = 1;

    // Create the first user
    User user;
    user.id = 1;
    user.name = "John Doe";
    user.balance = 10000.0f;
    users = &user;
    num_users = 1;
}

// Get the current time
time_t get_current_time() {
    return time(NULL);
}

// Get the item by ID
Item *get_item_by_id(int id) {
    for (int i = 0; i < num_items; i++) {
        if (items[i].id == id) {
            return &items[i];
        }
    }
    return NULL;
}

// Get the bid by ID
Bid *get_bid_by_id(int id) {
    for (int i = 0; i < num_bids; i++) {
        if (bids[i].id == id) {
            return &bids[i];
        }
    }
    return NULL;
}

// Get the user by ID
User *get_user_by_id(int id) {
    for (int i = 0; i < num_users; i++) {
        if (users[i].id == id) {
            return &users[i];
        }
    }
    return NULL;
}

// Place a bid
void place_bid(int bidder_id, int item_id, float bid_amount) {
    // Get the item
    Item *item = get_item_by_id(item_id);
    if (item == NULL) {
        printf("Item not found.\n");
        return;
    }

    // Get the user
    User *user = get_user_by_id(bidder_id);
    if (user == NULL) {
        printf("User not found.\n");
        return;
    }

    // Check if the bid is valid
    if (bid_amount <= item->current_price) {
        printf("Bid amount must be greater than the current price.\n");
        return;
    }
    if (bid_amount > user->balance) {
        printf("Insufficient balance.\n");
        return;
    }

    // Create the bid
    Bid bid;
    bid.id = num_bids + 1;
    bid.bid_amount = bid_amount;
    bid.bidder_id = bidder_id;
    bid.item_id = item_id;

    // Add the bid to the list of bids
    bids = realloc(bids, (num_bids + 1) * sizeof(Bid));
    bids[num_bids] = bid;
    num_bids++;

    // Update the item's current price
    item->current_price = bid_amount;

    // Update the user's balance
    user->balance -= bid_amount;

    // Print a message
    printf("Bid placed successfully.\n");
}

// End the auction
void end_auction(int item_id) {
    // Get the item
    Item *item = get_item_by_id(item_id);
    if (item == NULL) {
        printf("Item not found.\n");
        return;
    }

    // Get the highest bid
    Bid *highest_bid = NULL;
    for (int i = 0; i < num_bids; i++) {
        if (bids[i].item_id == item_id && (highest_bid == NULL || bids[i].bid_amount > highest_bid->bid_amount)) {
            highest_bid = &bids[i];
        }
    }

    // If there is no highest bid, then the auction ends without a winner.
    if (highest_bid == NULL) {
        printf("Auction ended without a winner.\n");
        return;
    }

    // Get the winner
    User *winner = get_user_by_id(highest_bid->bidder_id);
    if (winner == NULL) {
        printf("Winner not found.\n");
        return;
    }

    // Transfer the money from the winner to the seller
    User *seller = get_user_by_id(item->seller_id);
    if (seller == NULL) {
        printf("Seller not found.\n");
        return;
    }
    seller->balance += highest_bid->bid_amount;

    // Print a message
    printf("Auction ended. The winner is %s with a bid of %f.\n", winner->name, highest_bid->bid_amount);
}

// Main function
int main() {
    // Initialize the system
    init_system();

    // Place a bid
    place_bid(2, 1, 1200.0f);

    // End the auction
    end_auction(1);

    return 0;
}