//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items and bids
#define MAX_ITEMS 100
#define MAX_BIDS 100

// Define the item struct
typedef struct {
    char name[100];
    double starting_price;
    double current_bid;
    int num_bids;
} Item;

// Define the bid struct
typedef struct {
    char bidder_name[100];
    double amount;
} Bid;

// Define the auction struct
typedef struct {
    Item items[MAX_ITEMS];
    Bid bids[MAX_BIDS];
    int num_items;
    int num_bids;
} Auction;

// Create a new auction
Auction *create_auction() {
    Auction *auction = malloc(sizeof(Auction));
    auction->num_items = 0;
    auction->num_bids = 0;
    return auction;
}

// Add an item to the auction
void add_item(Auction *auction, char *name, double starting_price) {
    strcpy(auction->items[auction->num_items].name, name);
    auction->items[auction->num_items].starting_price = starting_price;
    auction->items[auction->num_items].current_bid = starting_price;
    auction->items[auction->num_items].num_bids = 0;
    auction->num_items++;
}

// Add a bid to the auction
void add_bid(Auction *auction, char *item_name, char *bidder_name, double amount) {
    int item_index = -1;
    for (int i = 0; i < auction->num_items; i++) {
        if (strcmp(auction->items[i].name, item_name) == 0) {
            item_index = i;
            break;
        }
    }

    if (item_index == -1) {
        printf("Item not found\n");
        return;
    }

    if (amount <= auction->items[item_index].current_bid) {
        printf("Bid amount must be greater than the current bid\n");
        return;
    }

    strcpy(auction->bids[auction->num_bids].bidder_name, bidder_name);
    auction->bids[auction->num_bids].amount = amount;
    auction->items[item_index].current_bid = amount;
    auction->items[item_index].num_bids++;
    auction->num_bids++;
}

// Print the auction results
void print_results(Auction *auction) {
    for (int i = 0; i < auction->num_items; i++) {
        printf("Item: %s\n", auction->items[i].name);
        printf("Starting price: %.2f\n", auction->items[i].starting_price);
        printf("Current bid: %.2f\n", auction->items[i].current_bid);
        printf("Number of bids: %d\n", auction->items[i].num_bids);
        if (auction->items[i].num_bids > 0) {
            printf("Winning bidder: %s\n", auction->bids[auction->items[i].num_bids - 1].bidder_name);
        }
        printf("\n");
    }
}

// Free the memory allocated for the auction
void free_auction(Auction *auction) {
    free(auction);
}

int main() {
    // Create a new auction
    Auction *auction = create_auction();

    // Add some items to the auction
    add_item(auction, "Painting", 100.0);
    add_item(auction, "Sculpture", 200.0);
    add_item(auction, "Vase", 50.0);

    // Add some bids to the auction
    add_bid(auction, "Painting", "John Doe", 120.0);
    add_bid(auction, "Sculpture", "Jane Doe", 250.0);
    add_bid(auction, "Vase", "Bob Smith", 60.0);

    // Print the auction results
    print_results(auction);

    // Free the memory allocated for the auction
    free_auction(auction);

    return 0;
}