//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the auction
#define MAX_ITEMS 100

// Define the maximum length of an item's name
#define MAX_ITEM_NAME_LENGTH 50

// Define the initial starting price for each item
#define STARTING_PRICE 10

// Define the maximum number of bids per item
#define MAX_BIDS_PER_ITEM 10

// Define the data structure for an item
typedef struct item {
    char name[MAX_ITEM_NAME_LENGTH];
    float starting_price;
    float current_price;
    int num_bids;
    int bids[MAX_BIDS_PER_ITEM];
} item_t;

// Define the data structure for the auction
typedef struct auction {
    item_t items[MAX_ITEMS];
    int num_items;
} auction_t;

// Function to create a new auction
auction_t* create_auction() {
    auction_t* auction = malloc(sizeof(auction_t));
    auction->num_items = 0;
    return auction;
}

// Function to add an item to the auction
void add_item_to_auction(auction_t* auction, char* name, float starting_price) {
    strcpy(auction->items[auction->num_items].name, name);
    auction->items[auction->num_items].starting_price = starting_price;
    auction->items[auction->num_items].current_price = starting_price;
    auction->items[auction->num_items].num_bids = 0;
    auction->num_items++;
}

// Function to place a bid on an item
void place_bid(auction_t* auction, int item_index, float bid_amount) {
    if (bid_amount > auction->items[item_index].current_price) {
        auction->items[item_index].current_price = bid_amount;
        auction->items[item_index].bids[auction->items[item_index].num_bids++] = bid_amount;
    }
}

// Function to print the auction results
void print_auction_results(auction_t* auction) {
    for (int i = 0; i < auction->num_items; i++) {
        printf("Item: %s\n", auction->items[i].name);
        printf("Starting price: %.2f\n", auction->items[i].starting_price);
        printf("Current price: %.2f\n", auction->items[i].current_price);
        printf("Number of bids: %d\n", auction->items[i].num_bids);
        printf("Bids: ");
        for (int j = 0; j < auction->items[i].num_bids; j++) {
            printf("%.2f ", auction->items[i].bids[j]);
        }
        printf("\n\n");
    }
}

// Main function
int main() {
    // Create a new auction
    auction_t* auction = create_auction();

    // Add some items to the auction
    add_item_to_auction(auction, "Painting", 100.00);
    add_item_to_auction(auction, "Sculpture", 200.00);
    add_item_to_auction(auction, "Vase", 50.00);

    // Place some bids on the items
    place_bid(auction, 0, 110.00);
    place_bid(auction, 0, 120.00);
    place_bid(auction, 1, 210.00);
    place_bid(auction, 1, 220.00);
    place_bid(auction, 2, 60.00);

    // Print the auction results
    print_auction_results(auction);

    // Free the memory allocated for the auction
    free(auction);

    return 0;
}