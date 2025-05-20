//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be auctioned.
#define MAX_ITEMS 10

// Define the structure of an item.
typedef struct item {
    char name[50];        // The name of the item.
    int value;            // The value of the item.
    char description[100]; // A description of the item.
} item;

// Define the structure of an auction.
typedef struct auction {
    item items[MAX_ITEMS]; // The items that are being auctioned.
    int num_items;         // The number of items that are being auctioned.
    int highest_bid;       // The highest bid that has been placed on any item.
    char highest_bidder[50]; // The name of the highest bidder.
} auction;

// Create a new auction.
auction *create_auction() {
    auction *a = malloc(sizeof(auction));
    a->num_items = 0;
    a->highest_bid = 0;
    strcpy(a->highest_bidder, "");
    return a;
}

// Add an item to an auction.
void add_item(auction *a, item i) {
    a->items[a->num_items] = i;
    a->num_items++;
}

// Print the items in an auction.
void print_items(auction *a) {
    for (int i = 0; i < a->num_items; i++) {
        printf("%s - %d - %s\n", a->items[i].name, a->items[i].value, a->items[i].description);
    }
}

// Place a bid on an item.
void place_bid(auction *a, int item_index, int bid, char *bidder) {
    if (bid > a->items[item_index].value) {
        a->items[item_index].value = bid;
        strcpy(a->highest_bidder, bidder);
    }
}

// Find the highest bid for an item.
int get_highest_bid(auction *a, int item_index) {
    return a->items[item_index].value;
}

// Get the highest bidder for an item.
char *get_highest_bidder(auction *a, int item_index) {
    return a->highest_bidder;
}

// Close the auction.
void close_auction(auction *a) {
    for (int i = 0; i < a->num_items; i++) {
        printf("%s sold to %s for %d\n", a->items[i].name, a->highest_bidder, a->items[i].value);
    }
}

// Main function.
int main() {
    // Create an auction.
    auction *a = create_auction();

    // Add some items to the auction.
    item i1 = {"Leather jacket", 100, "A sturdy leather jacket that will protect you from the elements."};
    item i2 = {"Canned food", 50, "A case of canned food that will keep you from starving."};
    item i3 = {"Water purifier", 150, "A water purifier that will keep you from getting sick."};
    add_item(a, i1);
    add_item(a, i2);
    add_item(a, i3);

    // Print the items in the auction.
    printf("Items in the auction:\n");
    print_items(a);

    // Place some bids on the items.
    place_bid(a, 0, 120, "Scavenger");
    place_bid(a, 1, 60, "Trader");
    place_bid(a, 2, 160, "Doctor");

    // Close the auction.
    close_auction(a);

    return 0;
}