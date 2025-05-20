//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    int id;
    char *name;
    float reserve_price;
    float current_bid;
    int num_bids;
} Item;

typedef struct Bid {
    int item_id;
    float amount;
    char *bidder_name;
} Bid;

typedef struct Auction {
    Item *items;
    int num_items;
    Bid *bids;
    int num_bids;
} Auction;

// Function to create a new auction
Auction *create_auction() {
    Auction *auction = (Auction *)malloc(sizeof(Auction));
    auction->items = NULL;
    auction->num_items = 0;
    auction->bids = NULL;
    auction->num_bids = 0;
    return auction;
}

// Function to add an item to the auction
void add_item(Auction *auction, Item *item) {
    auction->items = (Item *)realloc(auction->items, (auction->num_items + 1) * sizeof(Item));
    auction->items[auction->num_items] = *item;
    auction->num_items++;
}

// Function to add a bid to the auction
void add_bid(Auction *auction, Bid *bid) {
    auction->bids = (Bid *)realloc(auction->bids, (auction->num_bids + 1) * sizeof(Bid));
    auction->bids[auction->num_bids] = *bid;
    auction->num_bids++;
}

// Function to print the auction details
void print_auction(Auction *auction) {
    printf("Items:\n");
    for (int i = 0; i < auction->num_items; i++) {
        printf("  %d. %s (Reserve Price: $%.2f)\n", auction->items[i].id, auction->items[i].name, auction->items[i].reserve_price);
    }

    printf("\nBids:\n");
    for (int i = 0; i < auction->num_bids; i++) {
        printf("  Item %d: $%.2f by %s\n", auction->bids[i].item_id, auction->bids[i].amount, auction->bids[i].bidder_name);
    }
}

// Function to free the memory allocated for the auction
void free_auction(Auction *auction) {
    for (int i = 0; i < auction->num_items; i++) {
        free(auction->items[i].name);
    }
    free(auction->items);

    for (int i = 0; i < auction->num_bids; i++) {
        free(auction->bids[i].bidder_name);
    }
    free(auction->bids);

    free(auction);
}

int main() {
    // Create a new auction
    Auction *auction = create_auction();

    // Add some items to the auction
    Item item1 = {1, "Painting", 100.00, 0.00, 0};
    Item item2 = {2, "Sculpture", 200.00, 0.00, 0};
    Item item3 = {3, "Vase", 50.00, 0.00, 0};
    add_item(auction, &item1);
    add_item(auction, &item2);
    add_item(auction, &item3);

    // Add some bids to the auction
    Bid bid1 = {1, 110.00, "John Doe"};
    Bid bid2 = {2, 210.00, "Jane Doe"};
    Bid bid3 = {3, 60.00, "Bob Smith"};
    add_bid(auction, &bid1);
    add_bid(auction, &bid2);
    add_bid(auction, &bid3);

    // Print the auction details
    print_auction(auction);

    // Free the memory allocated for the auction
    free_auction(auction);

    return 0;
}