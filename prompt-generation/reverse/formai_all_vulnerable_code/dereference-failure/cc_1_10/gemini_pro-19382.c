//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the auction
#define MAX_ITEMS 100

// Define the maximum number of bids per item
#define MAX_BIDS 10

// Define the structure of an item
typedef struct item {
    char name[50];
    float starting_price;
    float current_price;
    int num_bids;
    char bidders[MAX_BIDS][50];
    float bids[MAX_BIDS];
} item;

// Define the structure of the auction
typedef struct auction {
    char name[50];
    int num_items;
    item items[MAX_ITEMS];
} auction;

// Create a new auction
auction* create_auction(char* name) {
    auction* a = malloc(sizeof(auction));
    strcpy(a->name, name);
    a->num_items = 0;
    return a;
}

// Add an item to the auction
void add_item(auction* a, char* name, float starting_price) {
    item* i = &a->items[a->num_items];
    strcpy(i->name, name);
    i->starting_price = starting_price;
    i->current_price = starting_price;
    i->num_bids = 0;
    a->num_items++;
}

// Place a bid on an item
void place_bid(auction* a, char* item_name, char* bidder_name, float bid_amount) {
    item* i = NULL;
    for (int j = 0; j < a->num_items; j++) {
        if (strcmp(a->items[j].name, item_name) == 0) {
            i = &a->items[j];
            break;
        }
    }
    if (i == NULL) {
        printf("Item not found\n");
        return;
    }
    if (bid_amount < i->current_price) {
        printf("Bid amount must be greater than the current price\n");
        return;
    }
    i->bids[i->num_bids] = bid_amount;
    strcpy(i->bidders[i->num_bids], bidder_name);
    i->num_bids++;
    i->current_price = bid_amount;
}

// Print the details of the auction
void print_auction(auction* a) {
    printf("Auction: %s\n", a->name);
    for (int i = 0; i < a->num_items; i++) {
        item* item = &a->items[i];
        printf("Item: %s\n", item->name);
        printf("Starting price: %f\n", item->starting_price);
        printf("Current price: %f\n", item->current_price);
        printf("Number of bids: %d\n", item->num_bids);
        for (int j = 0; j < item->num_bids; j++) {
            printf("Bidder: %s\n", item->bidders[j]);
            printf("Bid amount: %f\n", item->bids[j]);
        }
    }
}

// Free the memory allocated for the auction
void free_auction(auction* a) {
    free(a);
}

int main() {
    // Create a new auction
    auction* a = create_auction("My Auction");

    // Add some items to the auction
    add_item(a, "Item 1", 10.0);
    add_item(a, "Item 2", 20.0);
    add_item(a, "Item 3", 30.0);

    // Place some bids on the items
    place_bid(a, "Item 1", "Bidder 1", 15.0);
    place_bid(a, "Item 2", "Bidder 2", 25.0);
    place_bid(a, "Item 3", "Bidder 3", 35.0);

    // Print the details of the auction
    print_auction(a);

    // Free the memory allocated for the auction
    free_auction(a);

    return 0;
}