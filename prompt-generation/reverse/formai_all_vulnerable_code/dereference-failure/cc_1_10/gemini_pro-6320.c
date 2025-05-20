//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an item in the auction
typedef struct Item {
    char name[50];
    float starting_bid;
    float current_bid;
    int bidder_id;
} Item;

// Structure to represent an auction
typedef struct Auction {
    char name[50];
    Item items[100];
    int num_items;
    int num_bidders;
    int current_bidder_id;
} Auction;

// Function to create a new auction
Auction* create_auction(char *name) {
    Auction *auction = (Auction*)malloc(sizeof(Auction));
    strcpy(auction->name, name);
    auction->num_items = 0;
    auction->num_bidders = 0;
    auction->current_bidder_id = 0;
    return auction;
}

// Function to add an item to an auction
void add_item(Auction *auction, char *name, float starting_bid) {
    Item item;
    strcpy(item.name, name);
    item.starting_bid = starting_bid;
    item.current_bid = starting_bid;
    item.bidder_id = 0;
    auction->items[auction->num_items++] = item;
}

// Function to register a bidder for an auction
int register_bidder(Auction *auction, char *name) {
    auction->num_bidders++;
    return auction->num_bidders;
}

// Function to place a bid on an item
void place_bid(Auction *auction, int bidder_id, int item_id, float bid) {
    Item *item = &auction->items[item_id];
    if (bid > item->current_bid) {
        item->current_bid = bid;
        item->bidder_id = bidder_id;
    }
}

// Function to print the current state of the auction
void print_auction(Auction *auction) {
    printf("Auction: %s\n", auction->name);
    printf("Items:\n");
    for (int i = 0; i < auction->num_items; i++) {
        Item *item = &auction->items[i];
        printf("    %s: %.2f (bidder: %d)\n", item->name, item->current_bid, item->bidder_id);
    }
    printf("Bidders:\n");
    for (int i = 1; i <= auction->num_bidders; i++) {
        printf("    Bidder %d\n", i);
    }
}

// Main function to run the auction
int main() {
    // Create a new auction
    Auction *auction = create_auction("My Awesome Auction");

    // Add some items to the auction
    add_item(auction, "iPhone 13 Pro", 1000.0);
    add_item(auction, "MacBook Pro", 1500.0);
    add_item(auction, "PlayStation 5", 500.0);

    // Register some bidders for the auction
    int bidder_id1 = register_bidder(auction, "John Doe");
    int bidder_id2 = register_bidder(auction, "Jane Smith");

    // Place some bids on the items
    place_bid(auction, bidder_id1, 0, 1100.0);
    place_bid(auction, bidder_id2, 1, 1600.0);
    place_bid(auction, bidder_id1, 2, 550.0);

    // Print the current state of the auction
    print_auction(auction);

    return 0;
}