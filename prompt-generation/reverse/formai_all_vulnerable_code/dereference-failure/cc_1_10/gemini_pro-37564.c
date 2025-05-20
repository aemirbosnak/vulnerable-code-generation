//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item structure
typedef struct Item {
    int id;
    char *name;
    float price;
} Item;

// Bidder structure
typedef struct Bidder {
    int id;
    char *name;
    float max_bid;
} Bidder;

// Auction structure
typedef struct Auction {
    int id;
    char *name;
    Item *item;
    Bidder *highest_bidder;
    float highest_bid;
    int status; // 0 = open, 1 = closed
} Auction;

// Create a new item
Item *create_item(int id, char *name, float price) {
    Item *item = malloc(sizeof(Item));
    item->id = id;
    item->name = strdup(name);
    item->price = price;
    return item;
}

// Create a new bidder
Bidder *create_bidder(int id, char *name, float max_bid) {
    Bidder *bidder = malloc(sizeof(Bidder));
    bidder->id = id;
    bidder->name = strdup(name);
    bidder->max_bid = max_bid;
    return bidder;
}

// Create a new auction
Auction *create_auction(int id, char *name, Item *item, Bidder *highest_bidder, float highest_bid, int status) {
    Auction *auction = malloc(sizeof(Auction));
    auction->id = id;
    auction->name = strdup(name);
    auction->item = item;
    auction->highest_bidder = highest_bidder;
    auction->highest_bid = highest_bid;
    auction->status = status;
    return auction;
}

// Open an auction
void open_auction(Auction *auction) {
    if (auction->status == 0) {
        printf("Auction %s is now open.\n", auction->name);
    } else {
        printf("Auction %s is already open.\n", auction->name);
    }
}

// Close an auction
void close_auction(Auction *auction) {
    if (auction->status == 1) {
        printf("Auction %s is now closed.\n", auction->name);
        printf("The highest bidder is %s with a bid of %f.\n", auction->highest_bidder->name, auction->highest_bid);
    } else {
        printf("Auction %s is already closed.\n", auction->name);
    }
}

// Place a bid on an auction
void place_bid(Auction *auction, Bidder *bidder, float bid) {
    if (auction->status == 0) {
        if (bid > auction->highest_bid) {
            auction->highest_bidder = bidder;
            auction->highest_bid = bid;
            printf("Bid placed successfully.\n");
        } else {
            printf("Bid is too low.\n");
        }
    } else {
        printf("Auction is closed. No bids can be placed.\n");
    }
}

// Print the details of an auction
void print_auction(Auction *auction) {
    printf("Auction ID: %d\n", auction->id);
    printf("Auction Name: %s\n", auction->name);
    printf("Item: %s\n", auction->item->name);
    printf("Highest Bidder: %s\n", auction->highest_bidder->name);
    printf("Highest Bid: %f\n", auction->highest_bid);
    printf("Status: %s\n", auction->status == 0 ? "Open" : "Closed");
}

// Main function
int main() {
    // Create an item
    Item *item = create_item(1, "iPhone 13 Pro Max", 1000.0);

    // Create a bidder
    Bidder *bidder1 = create_bidder(1, "John Doe", 1200.0);
    Bidder *bidder2 = create_bidder(2, "Jane Doe", 1100.0);

    // Create an auction
    Auction *auction = create_auction(1, "iPhone 13 Pro Max Auction", item, NULL, 0.0, 0);

    // Open the auction
    open_auction(auction);

    // Place a bid
    place_bid(auction, bidder1, 1150.0);

    // Place another bid
    place_bid(auction, bidder2, 1250.0);

    // Print the details of the auction
    print_auction(auction);

    // Close the auction
    close_auction(auction);

    return 0;
}