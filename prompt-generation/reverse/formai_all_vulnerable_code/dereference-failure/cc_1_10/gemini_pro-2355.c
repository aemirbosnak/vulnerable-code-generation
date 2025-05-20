//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an item in the auction
typedef struct item {
    char name[50];
    float current_bid;
    float reserve_price;
    int highest_bidder;
} item;

// Structure to represent the auction system
typedef struct auction_system {
    item items[100];
    int num_items;
    int current_bidder;
    float highest_bid;
} auction_system;

// Function to create a new auction system
auction_system* create_auction_system() {
    auction_system* system = malloc(sizeof(auction_system));
    system->num_items = 0;
    system->current_bidder = -1;
    system->highest_bid = 0.0;
    return system;
}

// Function to add an item to the auction system
void add_item(auction_system* system, char* name, float reserve_price) {
    strcpy(system->items[system->num_items].name, name);
    system->items[system->num_items].current_bid = 0.0;
    system->items[system->num_items].reserve_price = reserve_price;
    system->items[system->num_items].highest_bidder = -1;
    system->num_items++;
}

// Function to place a bid on an item
void place_bid(auction_system* system, int item_index, float bid) {
    if (bid > system->items[item_index].current_bid && bid >= system->items[item_index].reserve_price) {
        system->items[item_index].current_bid = bid;
        system->items[item_index].highest_bidder = system->current_bidder;
        system->highest_bid = bid;
    }
}

// Function to get the current highest bid for an item
float get_highest_bid(auction_system* system, int item_index) {
    return system->items[item_index].current_bid;
}

// Function to get the highest bidder for an item
int get_highest_bidder(auction_system* system, int item_index) {
    return system->items[item_index].highest_bidder;
}

// Function to close the auction
void close_auction(auction_system* system) {
    for (int i = 0; i < system->num_items; i++) {
        if (system->items[i].current_bid >= system->items[i].reserve_price) {
            printf("Item %s sold for $%.2f to bidder %d\n", system->items[i].name, system->items[i].current_bid, system->items[i].highest_bidder);
        } else {
            printf("Item %s did not meet reserve price\n", system->items[i].name);
        }
    }
}

// Main function
int main() {
    // Create a new auction system
    auction_system* system = create_auction_system();

    // Add some items to the auction
    add_item(system, "Painting", 1000.0);
    add_item(system, "Sculpture", 500.0);
    add_item(system, "Vase", 200.0);

    // Place some bids
    place_bid(system, 0, 1200.0);
    place_bid(system, 1, 600.0);
    place_bid(system, 2, 250.0);

    // Close the auction
    close_auction(system);

    return 0;
}