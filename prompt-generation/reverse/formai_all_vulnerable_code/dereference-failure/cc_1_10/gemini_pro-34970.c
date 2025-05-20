//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items and bids
#define MAX_ITEMS 100
#define MAX_BIDS 1000

// Define the item structure
typedef struct item {
    int id;
    char name[100];
    float reserve_price;
    float current_bid;
    int num_bids;
} item;

// Define the bid structure
typedef struct bid {
    int id;
    int item_id;
    float amount;
} bid;

// Define the auction structure
typedef struct auction {
    int num_items;
    item items[MAX_ITEMS];
    int num_bids;
    bid bids[MAX_BIDS];
} auction;

// Create a new auction
auction *create_auction() {
    auction *auction = malloc(sizeof(auction));
    auction->num_items = 0;
    auction->num_bids = 0;
    return auction;
}

// Add an item to the auction
void add_item(auction *auction, item item) {
    auction->items[auction->num_items] = item;
    auction->num_items++;
}

// Add a bid to the auction
void add_bid(auction *auction, bid bid) {
    auction->bids[auction->num_bids] = bid;
    auction->num_bids++;
}

// Get the current bid for an item
float get_current_bid(auction *auction, int item_id) {
    for (int i = 0; i < auction->num_bids; i++) {
        if (auction->bids[i].item_id == item_id) {
            return auction->bids[i].amount;
        }
    }
    return 0.0;
}

// Get the winner of an item
int get_winner(auction *auction, int item_id) {
    float highest_bid = 0.0;
    int winner_id = -1;
    for (int i = 0; i < auction->num_bids; i++) {
        if (auction->bids[i].item_id == item_id && auction->bids[i].amount > highest_bid) {
            highest_bid = auction->bids[i].amount;
            winner_id = auction->bids[i].id;
        }
    }
    return winner_id;
}

// Print the auction results
void print_results(auction *auction) {
    for (int i = 0; i < auction->num_items; i++) {
        item item = auction->items[i];
        float current_bid = get_current_bid(auction, item.id);
        int winner_id = get_winner(auction, item.id);
        printf("Item: %s\n", item.name);
        printf("Reserve price: %.2f\n", item.reserve_price);
        printf("Current bid: %.2f\n", current_bid);
        if (winner_id != -1) {
            printf("Winner: %d\n", winner_id);
        } else {
            printf("No winner (reserve price not met)\n");
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new auction
    auction *auction = create_auction();

    // Add some items to the auction
    item item1 = {1, "iPhone 13", 1000.0, 0.0, 0};
    add_item(auction, item1);
    item item2 = {2, "Macbook Air", 1200.0, 0.0, 0};
    add_item(auction, item2);
    item item3 = {3, "iPad Pro", 800.0, 0.0, 0};
    add_item(auction, item3);

    // Add some bids to the auction
    bid bid1 = {1, 1, 1100.0};
    add_bid(auction, bid1);
    bid bid2 = {2, 2, 1300.0};
    add_bid(auction, bid2);
    bid bid3 = {3, 2, 1400.0};
    add_bid(auction, bid3);
    bid bid4 = {4, 3, 900.0};
    add_bid(auction, bid4);

    // Print the auction results
    print_results(auction);

    return 0;
}