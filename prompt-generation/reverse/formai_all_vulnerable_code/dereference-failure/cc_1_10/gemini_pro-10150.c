//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for storing auction items
typedef struct item {
    int id;
    char *name;
    double current_bid;
    int highest_bidder_id;
} Item;

// Node structure for storing bidders
typedef struct bidder {
    int id;
    char *name;
    double balance;
} Bidder;

// Array of auction items
Item items[100];

// Array of bidders
Bidder bidders[100];

// Number of auction items
int num_items = 0;

// Number of bidders
int num_bidders = 0;

// Current highest bid
double highest_bid = 0.0;

// Current highest bidder ID
int highest_bidder_id = -1;

// Function to add a new auction item
void add_item(int id, char *name, double starting_bid) {
    items[num_items].id = id;
    items[num_items].name = strdup(name);
    items[num_items].current_bid = starting_bid;
    items[num_items].highest_bidder_id = -1;
    num_items++;
}

// Function to add a new bidder
void add_bidder(int id, char *name, double balance) {
    bidders[num_bidders].id = id;
    bidders[num_bidders].name = strdup(name);
    bidders[num_bidders].balance = balance;
    num_bidders++;
}

// Function to place a bid
void place_bid(int bidder_id, int item_id, double bid_amount) {
    // Check if the bidder exists
    int bidder_index = -1;
    for (int i = 0; i < num_bidders; i++) {
        if (bidders[i].id == bidder_id) {
            bidder_index = i;
            break;
        }
    }
    if (bidder_index == -1) {
        printf("Bidder does not exist.\n");
        return;
    }

    // Check if the item exists
    int item_index = -1;
    for (int i = 0; i < num_items; i++) {
        if (items[i].id == item_id) {
            item_index = i;
            break;
        }
    }
    if (item_index == -1) {
        printf("Item does not exist.\n");
        return;
    }

    // Check if the bid amount is valid
    if (bid_amount <= items[item_index].current_bid) {
        printf("Bid amount must be greater than the current bid.\n");
        return;
    }

    // Check if the bidder has enough balance
    if (bid_amount > bidders[bidder_index].balance) {
        printf("Bidder does not have enough balance.\n");
        return;
    }

    // Place the bid
    items[item_index].current_bid = bid_amount;
    items[item_index].highest_bidder_id = bidder_id;
    highest_bid = bid_amount;
    highest_bidder_id = bidder_id;

    // Deduct the bid amount from the bidder's balance
    bidders[bidder_index].balance -= bid_amount;

    printf("Bid placed successfully.\n");
}

// Function to close the auction
void close_auction() {
    // Print the winning bids
    for (int i = 0; i < num_items; i++) {
        if (items[i].highest_bidder_id != -1) {
            printf("Item %s won by bidder %s for $%.2f.\n", items[i].name, bidders[items[i].highest_bidder_id].name, items[i].current_bid);
        } else {
            printf("Item %s did not receive any bids.\n", items[i].name);
        }
    }
}

// Main function
int main() {
    // Add some auction items
    add_item(1, "Painting", 100.0);
    add_item(2, "Sculpture", 200.0);
    add_item(3, "Vase", 50.0);

    // Add some bidders
    add_bidder(1, "John Doe", 1000.0);
    add_bidder(2, "Jane Smith", 500.0);
    add_bidder(3, "Bill Jones", 2000.0);

    // Place some bids
    place_bid(1, 1, 150.0);
    place_bid(2, 2, 250.0);
    place_bid(3, 3, 75.0);
    place_bid(1, 2, 300.0);
    place_bid(2, 3, 100.0);

    // Close the auction
    close_auction();

    return 0;
}