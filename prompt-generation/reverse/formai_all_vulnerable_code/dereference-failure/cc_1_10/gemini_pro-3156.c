//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the auction
#define MAX_ITEMS 100

// Define the structure of an auction item
typedef struct {
    int id;             // The unique ID of the item
    char *name;          // The name of the item
    float price;         // The current price of the item
    int highest_bidder;  // The ID of the highest bidder
} auction_item;

// Define the structure of an auction
typedef struct {
    int id;                // The unique ID of the auction
    char *name;             // The name of the auction
    auction_item *items;    // The array of auction items
    int num_items;         // The number of items in the auction
    int current_bidder;    // The ID of the current bidder
    float current_bid;     // The current bid amount
} auction;

// Create a new auction
auction *new_auction(char *name) {
    auction *a = malloc(sizeof(auction));
    a->id = rand();
    a->name = strdup(name);
    a->items = malloc(MAX_ITEMS * sizeof(auction_item));
    a->num_items = 0;
    a->current_bidder = -1;
    a->current_bid = 0.0;
    return a;
}

// Add an item to an auction
void add_item(auction *a, char *name, float price) {
    if (a->num_items < MAX_ITEMS) {
        a->items[a->num_items].id = rand();
        a->items[a->num_items].name = strdup(name);
        a->items[a->num_items].price = price;
        a->items[a->num_items].highest_bidder = -1;
        a->num_items++;
    } else {
        printf("Error: cannot add more items to auction.\n");
    }
}

// Start an auction
void start_auction(auction *a) {
    while (a->current_bidder == -1) {
        printf("Waiting for bidders...\n");
    }
    printf("Auction started!\n");
}

// Place a bid on an item
void bid(auction *a, int bidder_id, float bid) {
    if (bid > a->current_bid) {
        a->current_bid = bid;
        a->current_bidder = bidder_id;
    } else {
        printf("Error: bid must be higher than current bid.\n");
    }
}

// End an auction
void end_auction(auction *a) {
    for (int i = 0; i < a->num_items; i++) {
        if (a->items[i].highest_bidder == -1) {
            printf("Item %s did not sell.\n", a->items[i].name);
        } else {
            printf("Item %s sold to bidder %d for %.2f.\n", a->items[i].name, a->items[i].highest_bidder, a->items[i].price);
        }
    }
}

// Free the memory allocated for an auction
void free_auction(auction *a) {
    for (int i = 0; i < a->num_items; i++) {
        free(a->items[i].name);
    }
    free(a->items);
    free(a->name);
    free(a);
}

// Main function
int main() {
    // Create a new auction
    auction *a = new_auction("My Auction");

    // Add some items to the auction
    add_item(a, "Item 1", 10.0);
    add_item(a, "Item 2", 20.0);
    add_item(a, "Item 3", 30.0);

    // Start the auction
    start_auction(a);

    // Place some bids
    bid(a, 1, 15.0);
    bid(a, 2, 25.0);
    bid(a, 1, 30.0);

    // End the auction
    end_auction(a);

    // Free the memory allocated for the auction
    free_auction(a);

    return 0;
}