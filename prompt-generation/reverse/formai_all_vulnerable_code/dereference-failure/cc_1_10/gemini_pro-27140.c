//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the auction
#define MAX_ITEMS 100

// Define the maximum length of an item name
#define MAX_NAME_LENGTH 100

// Define the maximum length of a bidder name
#define MAX_BIDDER_NAME_LENGTH 50

// Define the maximum number of bids per item
#define MAX_BIDS_PER_ITEM 10

// Define the data structure for an item
typedef struct item {
    char name[MAX_NAME_LENGTH];
    float current_bid;
    int number_of_bids;
    char highest_bidder[MAX_BIDDER_NAME_LENGTH];
} item;

// Define the data structure for an auction
typedef struct auction {
    item items[MAX_ITEMS];
    int number_of_items;
} auction;

// Create a new auction
auction *create_auction() {
    auction *new_auction = malloc(sizeof(auction));
    new_auction->number_of_items = 0;
    return new_auction;
}

// Add an item to an auction
void add_item_to_auction(auction *auction, char *name, float starting_bid) {
    item new_item;
    strcpy(new_item.name, name);
    new_item.current_bid = starting_bid;
    new_item.number_of_bids = 0;
    auction->items[auction->number_of_items] = new_item;
    auction->number_of_items++;
}

// Place a bid on an item in an auction
void place_bid(auction *auction, char *item_name, char *bidder_name, float bid_amount) {
    for (int i = 0; i < auction->number_of_items; i++) {
        if (strcmp(auction->items[i].name, item_name) == 0) {
            if (bid_amount > auction->items[i].current_bid) {
                auction->items[i].current_bid = bid_amount;
                strcpy(auction->items[i].highest_bidder, bidder_name);
                auction->items[i].number_of_bids++;
            }
        }
    }
}

// Print the current state of an auction
void print_auction(auction *auction) {
    printf("Current auction items:\n");
    for (int i = 0; i < auction->number_of_items; i++) {
        printf(" - %s: Current bid: $%.2f, Highest bidder: %s, Number of bids: %d\n",
            auction->items[i].name, auction->items[i].current_bid,
            auction->items[i].highest_bidder, auction->items[i].number_of_bids);
    }
}

// Close an auction and determine the winners
void close_auction(auction *auction) {
    printf("Auction closed!\n");
    for (int i = 0; i < auction->number_of_items; i++) {
        printf(" - %s: Winner: %s, Winning bid: $%.2f\n",
            auction->items[i].name, auction->items[i].highest_bidder, auction->items[i].current_bid);
    }
}

// Free the memory allocated for an auction
void free_auction(auction *auction) {
    free(auction);
}

int main() {
    // Create a new auction
    auction *my_auction = create_auction();

    // Add some items to the auction
    add_item_to_auction(my_auction, "Painting", 100.00);
    add_item_to_auction(my_auction, "Sculpture", 500.00);
    add_item_to_auction(my_auction, "Vase", 200.00);

    // Print the current state of the auction
    print_auction(my_auction);

    // Place some bids on the items
    place_bid(my_auction, "Painting", "John Smith", 120.00);
    place_bid(my_auction, "Sculpture", "Jane Doe", 600.00);
    place_bid(my_auction, "Vase", "Bob Jones", 250.00);

    // Print the current state of the auction
    print_auction(my_auction);

    // Close the auction and determine the winners
    close_auction(my_auction);

    // Free the memory allocated for the auction
    free_auction(my_auction);

    return 0;
}