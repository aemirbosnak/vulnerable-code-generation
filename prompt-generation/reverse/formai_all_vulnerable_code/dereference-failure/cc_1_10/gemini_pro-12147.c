//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an item in the auction
typedef struct item {
    int id;
    char* name;
    int starting_price;
    int current_price;
    int highest_bidder;
} item;

// Structure to represent an auction
typedef struct auction {
    item* items;
    int num_items;
    int current_item;
} auction;

// Function to create a new item
item* create_item(int id, char* name, int starting_price) {
    item* new_item = (item*) malloc(sizeof(item));
    new_item->id = id;
    new_item->name = strdup(name);
    new_item->starting_price = starting_price;
    new_item->current_price = starting_price;
    new_item->highest_bidder = -1;
    return new_item;
}

// Function to create a new auction
auction* create_auction(item* items, int num_items) {
    auction* new_auction = (auction*) malloc(sizeof(auction));
    new_auction->items = items;
    new_auction->num_items = num_items;
    new_auction->current_item = 0;
    return new_auction;
}

// Function to start the auction
void start_auction(auction* auction) {
    printf("Welcome to the auction! Let the bidding begin!\n");
    while (auction->current_item < auction->num_items) {
        item* current_item = &auction->items[auction->current_item];
        printf("Current item: %s (ID: %d)\n", current_item->name, current_item->id);
        printf("Starting price: $%d\n", current_item->starting_price);
        int bid = 0;
        while (bid >= current_item->current_price) {
            printf("Enter your bid (or 0 to pass): $");
            scanf("%d", &bid);
            if (bid >= current_item->current_price) {
                current_item->current_price = bid;
                current_item->highest_bidder = auction->current_item;
            }
        }
        printf("Item %s sold to bidder %d for $%d!\n", current_item->name, current_item->highest_bidder, current_item->current_price);
        auction->current_item++;
    }
    printf("Auction complete! Thank you for participating.\n");
}

// Main function
int main() {
    // Create some items
    item* items[] = {
        create_item(1, "Painting", 100),
        create_item(2, "Sculpture", 200),
        create_item(3, "Vase", 50),
        create_item(4, "Clock", 75),
        create_item(5, "Lamp", 25)
    };

    // Create an auction
    auction* auction = create_auction(items, 5);

    // Start the auction
    start_auction(auction);

    // Free the memory allocated for the items and the auction
    for (int i = 0; i < auction->num_items; i++) {
        free(auction->items[i].name);
        free(&auction->items[i]);
    }
    free(auction->items);
    free(auction);

    return 0;
}