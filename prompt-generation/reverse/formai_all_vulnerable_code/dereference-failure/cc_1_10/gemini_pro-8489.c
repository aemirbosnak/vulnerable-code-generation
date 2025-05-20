//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the item struct
typedef struct {
    int id;
    char* name;
    float price;
} Item;

// Define the auction struct
typedef struct {
    Item* items;
    int num_items;
    int current_bidder;
    float current_bid;
} Auction;

// Create a new auction
Auction* create_auction(int num_items) {
    Auction* auction = (Auction*)malloc(sizeof(Auction));
    auction->items = (Item*)malloc(num_items * sizeof(Item));
    auction->num_items = num_items;
    auction->current_bidder = -1;
    auction->current_bid = 0;
    return auction;
}

// Destroy an auction
void destroy_auction(Auction* auction) {
    free(auction->items);
    free(auction);
}

// Add an item to an auction
void add_item(Auction* auction, Item item) {
    auction->items[auction->num_items] = item;
    auction->num_items++;
}

// Get the current highest bid for an item
float get_current_bid(Auction* auction, int item_id) {
    for (int i = 0; i < auction->num_items; i++) {
        if (auction->items[i].id == item_id) {
            return auction->items[i].price;
        }
    }
    return 0;
}

// Place a bid on an item
void place_bid(Auction* auction, int item_id, float bid) {
    for (int i = 0; i < auction->num_items; i++) {
        if (auction->items[i].id == item_id) {
            if (bid > auction->items[i].price) {
                auction->items[i].price = bid;
                auction->current_bidder = auction->items[i].id;
                auction->current_bid = bid;
            }
        }
    }
}

// Get the current highest bidder for an item
int get_current_bidder(Auction* auction, int item_id) {
    for (int i = 0; i < auction->num_items; i++) {
        if (auction->items[i].id == item_id) {
            return auction->current_bidder;
        }
    }
    return -1;
}

// Print the current state of an auction
void print_auction(Auction* auction) {
    printf("Current auction:\n");
    for (int i = 0; i < auction->num_items; i++) {
        printf("Item %d: %s, Current bid: $%.2f, Current bidder: %d\n",
            auction->items[i].id,
            auction->items[i].name,
            auction->items[i].price,
            auction->current_bidder);
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new auction
    Auction* auction = create_auction(5);

    // Add some items to the auction
    Item item1 = {1, "Painting", 100.0};
    add_item(auction, item1);
    Item item2 = {2, "Sculpture", 200.0};
    add_item(auction, item2);
    Item item3 = {3, "Vase", 300.0};
    add_item(auction, item3);
    Item item4 = {4, "Rug", 400.0};
    add_item(auction, item4);
    Item item5 = {5, "Chair", 500.0};
    add_item(auction, item5);

    // Print the current state of the auction
    print_auction(auction);

    // Place some bids on the items
    place_bid(auction, 1, 110.0);
    place_bid(auction, 2, 210.0);
    place_bid(auction, 3, 310.0);
    place_bid(auction, 4, 410.0);
    place_bid(auction, 5, 510.0);

    // Print the current state of the auction
    print_auction(auction);

    // Destroy the auction
    destroy_auction(auction);

    return 0;
}