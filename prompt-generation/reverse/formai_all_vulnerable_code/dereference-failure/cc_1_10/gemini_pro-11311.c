//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an item in the auction
struct Item {
    char name[100];
    float reserve_price;
    float current_bid;
    char highest_bidder[100];
};

// Structure to represent the auction itself
struct Auction {
    char name[100];
    int num_items;
    struct Item *items;
};

// Function to create a new auction
struct Auction *create_auction(char *name, int num_items) {
    struct Auction *auction = (struct Auction *)malloc(sizeof(struct Auction));
    strcpy(auction->name, name);
    auction->num_items = num_items;
    auction->items = (struct Item *)malloc(sizeof(struct Item) * num_items);
    return auction;
}

// Function to add an item to an auction
void add_item(struct Auction *auction, char *name, float reserve_price) {
    struct Item *item = &auction->items[auction->num_items];
    strcpy(item->name, name);
    item->reserve_price = reserve_price;
    item->current_bid = 0;
    strcpy(item->highest_bidder, "");
    auction->num_items++;
}

// Function to start the auction
void start_auction(struct Auction *auction) {
    printf("Welcome to the %s auction!\n", auction->name);
    for (int i = 0; i < auction->num_items; i++) {
        struct Item *item = &auction->items[i];
        printf("Item %d: %s\n", i + 1, item->name);
        printf("Reserve price: $%.2f\n", item->reserve_price);
    }
    printf("\n");
}

// Function to place a bid on an item
void place_bid(struct Auction *auction, int item_number, float bid_amount, char *bidder_name) {
    struct Item *item = &auction->items[item_number - 1];
    if (bid_amount < item->reserve_price) {
        printf("Bid amount is below the reserve price.\n");
        return;
    }
    if (bid_amount > item->current_bid) {
        item->current_bid = bid_amount;
        strcpy(item->highest_bidder, bidder_name);
    } else {
        printf("Bid amount is not higher than the current bid.\n");
    }
}

// Function to end the auction
void end_auction(struct Auction *auction) {
    printf("The auction has ended.\n");
    for (int i = 0; i < auction->num_items; i++) {
        struct Item *item = &auction->items[i];
        if (item->current_bid >= item->reserve_price) {
            printf("Item %s sold to %s for $%.2f.\n", item->name, item->highest_bidder, item->current_bid);
        } else {
            printf("Item %s did not sell.\n", item->name);
        }
    }
}

// Main function
int main() {
    // Create a new auction
    struct Auction *auction = create_auction("My Awesome Auction", 3);

    // Add items to the auction
    add_item(auction, "Painting", 100.00);
    add_item(auction, "Sculpture", 200.00);
    add_item(auction, "Vase", 50.00);

    // Start the auction
    start_auction(auction);

    // Place bids on items
    place_bid(auction, 1, 110.00, "John Doe");
    place_bid(auction, 2, 210.00, "Jane Doe");
    place_bid(auction, 3, 60.00, "Bob Smith");

    // End the auction
    end_auction(auction);

    return 0;
}