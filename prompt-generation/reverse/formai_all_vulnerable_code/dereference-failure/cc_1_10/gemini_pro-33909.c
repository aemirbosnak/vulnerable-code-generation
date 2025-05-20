//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent an item in the auction
typedef struct item {
    int id;             // Unique identifier for the item
    char *name;         // Name of the item
    float starting_price; // Starting price for the item
    float current_price;  // Current highest bid for the item
    int num_bids;       // Number of bids placed on the item
} item;

// Structure to represent a bid placed on an item
typedef struct bid {
    int item_id;     // ID of the item the bid is placed on
    float amount;    // Amount of the bid
    char *bidder;   // Name of the bidder
} bid;

// Structure to represent the auction system
typedef struct auction_system {
    int num_items;     // Number of items in the auction
    item *items;      // Array of items in the auction
    int num_bids;      // Number of bids placed in the auction
    bid *bids;        // Array of bids placed in the auction
} auction_system;

// Function to create a new auction system
auction_system *create_auction_system(int num_items) {
    auction_system *system = malloc(sizeof(auction_system));
    system->num_items = num_items;
    system->items = malloc(sizeof(item) * num_items);
    system->num_bids = 0;
    system->bids = NULL;
    return system;
}

// Function to add an item to the auction system
void add_item(auction_system *system, item *item) {
    system->items[system->num_items++] = *item;
}

// Function to place a bid on an item in the auction system
void place_bid(auction_system *system, bid *bid) {
    // Check if the bid is valid
    if (bid->amount <= system->items[bid->item_id].current_price) {
        printf("Invalid bid: bid amount must be greater than current price\n");
        return;
    }

    // Add the bid to the system
    system->bids[system->num_bids++] = *bid;

    // Update the current price of the item
    system->items[bid->item_id].current_price = bid->amount;
}

// Function to end the auction and determine the winners
void end_auction(auction_system *system) {
    // Iterate over each item in the auction
    for (int i = 0; i < system->num_items; i++) {
        // Get the highest bid for the item
        bid *highest_bid = NULL;
        for (int j = 0; j < system->num_bids; j++) {
            if (system->bids[j].item_id == system->items[i].id && (highest_bid == NULL || system->bids[j].amount > highest_bid->amount)) {
                highest_bid = &system->bids[j];
            }
        }

        // If there was a highest bid, print the winner
        if (highest_bid != NULL) {
            printf("Item %d: Won by %s for $%.2f\n", system->items[i].id, highest_bid->bidder, highest_bid->amount);
        } else {
            printf("Item %d: No bids placed\n", system->items[i].id);
        }
    }
}

// Main function
int main() {
    // Create a new auction system with 3 items
    auction_system *system = create_auction_system(3);

    // Add items to the auction system
    item item1 = {1, "Painting", 100.0, 100.0, 0};
    item item2 = {2, "Sculpture", 200.0, 200.0, 0};
    item item3 = {3, "Vase", 300.0, 300.0, 0};
    add_item(system, &item1);
    add_item(system, &item2);
    add_item(system, &item3);

    // Place bids on the items in the auction system
    bid bid1 = {1, 150.0, "John Doe"};
    bid bid2 = {2, 250.0, "Jane Doe"};
    bid bid3 = {3, 350.0, "Jack Doe"};
    place_bid(system, &bid1);
    place_bid(system, &bid2);
    place_bid(system, &bid3);

    // End the auction and determine the winners
    end_auction(system);

    return 0;
}