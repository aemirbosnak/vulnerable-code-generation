//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the auction
#define MAX_ITEMS 100

// Define the maximum number of bids per item
#define MAX_BIDS 10

// Define the structure of an item
typedef struct item {
    char name[100];
    float starting_price;
    float current_bid;
    int number_of_bids;
    int highest_bidder;
} item;

// Define the structure of an auction
typedef struct auction {
    item items[MAX_ITEMS];
    int number_of_items;
    int current_item;
} auction;

// Create a new auction
auction* create_auction() {
    auction* a = (auction*)malloc(sizeof(auction));
    a->number_of_items = 0;
    a->current_item = 0;
    return a;
}

// Add an item to the auction
void add_item(auction* a, char* name, float starting_price) {
    a->items[a->number_of_items].starting_price = starting_price;
    strcpy(a->items[a->number_of_items].name, name);
    a->items[a->number_of_items].number_of_bids = 0;
    a->items[a->number_of_items].highest_bidder = -1;
    a->number_of_items++;
}

// Place a bid on an item
void place_bid(auction* a, int item_index, float bid, int bidder) {
    if (bid > a->items[item_index].current_bid) {
        a->items[item_index].current_bid = bid;
        a->items[item_index].highest_bidder = bidder;
    }
}

// Get the current highest bid for an item
float get_current_bid(auction* a, int item_index) {
    return a->items[item_index].current_bid;
}

// Get the highest bidder for an item
int get_highest_bidder(auction* a, int item_index) {
    return a->items[item_index].highest_bidder;
}

// Get the name of an item
char* get_item_name(auction* a, int item_index) {
    return a->items[item_index].name;
}

// Get the number of items in the auction
int get_number_of_items(auction* a) {
    return a->number_of_items;
}

// Get the current item index
int get_current_item(auction* a) {
    return a->current_item;
}

// Move to the next item in the auction
void next_item(auction* a) {
    a->current_item++;
}

// Print the auction details
void print_auction(auction* a) {
    for (int i = 0; i < a->number_of_items; i++) {
        printf("Item %d: %s\n", i + 1, a->items[i].name);
        printf("Starting price: %f\n", a->items[i].starting_price);
        printf("Current bid: %f\n", a->items[i].current_bid);
        printf("Number of bids: %d\n", a->items[i].number_of_bids);
        if (a->items[i].highest_bidder != -1) {
            printf("Highest bidder: %d\n", a->items[i].highest_bidder);
        }
        printf("\n");
    }
}

// Free the memory allocated for the auction
void free_auction(auction* a) {
    free(a);
}

int main() {
    // Create a new auction
    auction* a = create_auction();

    // Add some items to the auction
    add_item(a, "Painting", 100.0);
    add_item(a, "Sculpture", 200.0);
    add_item(a, "Vase", 50.0);

    // Print the auction details
    print_auction(a);

    // Start the auction
    while (a->current_item < a->number_of_items) {
        // Get the current item
        int item_index = a->current_item;

        // Place some bids on the item
        place_bid(a, item_index, 120.0, 1);
        place_bid(a, item_index, 150.0, 2);
        place_bid(a, item_index, 175.0, 3);

        // Print the current bid for the item
        printf("Current bid for %s: %f\n", get_item_name(a, item_index), get_current_bid(a, item_index));

        // Move to the next item
        next_item(a);
    }

    // Print the final results of the auction
    printf("Auction results:\n");
    for (int i = 0; i < a->number_of_items; i++) {
        printf("Item %d: %s\n", i + 1, get_item_name(a, i));
        printf("Final bid: %f\n", get_current_bid(a, i));
        printf("Highest bidder: %d\n", get_highest_bidder(a, i));
        printf("\n");
    }

    // Free the memory allocated for the auction
    free_auction(a);

    return 0;
}