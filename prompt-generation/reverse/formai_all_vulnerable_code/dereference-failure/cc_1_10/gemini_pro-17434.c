//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the Item struct
typedef struct Item {
    char *name;
    float price;
} Item;

// Declare the Auction struct
typedef struct Auction {
    Item *item;
    float current_bid;
    char *highest_bidder;
} Auction;

// Function to create a new item
Item *create_item(char *name, float price) {
    Item *item = malloc(sizeof(Item));
    item->name = strdup(name);
    item->price = price;
    return item;
}

// Function to create a new auction
Auction *create_auction(Item *item) {
    Auction *auction = malloc(sizeof(Auction));
    auction->item = item;
    auction->current_bid = item->price;
    auction->highest_bidder = NULL;
    return auction;
}

// Function to start the auction
void start_auction(Auction *auction) {
    printf("Starting auction for %s with a starting bid of $%.2f\n", auction->item->name, auction->current_bid);
    while (1) {
        float bid;
        char *bidder;
        printf("Enter your bid (or 'q' to quit): ");
        scanf("%f", &bid);
        if (bid == 'q') {
            break;
        }
        printf("Enter your name: ");
        scanf("%s", bidder);
        if (bid > auction->current_bid) {
            auction->current_bid = bid;
            auction->highest_bidder = strdup(bidder);
            printf("New highest bid: $%.2f by %s\n", auction->current_bid, auction->highest_bidder);
        } else {
            printf("Bid too low! Please enter a bid higher than $%.2f\n", auction->current_bid);
        }
    }
}

// Function to end the auction
void end_auction(Auction *auction) {
    printf("Auction for %s has ended!\n", auction->item->name);
    if (auction->highest_bidder == NULL) {
        printf("No bids were placed.\n");
    } else {
        printf("Highest bid: $%.2f by %s\n", auction->current_bid, auction->highest_bidder);
    }
}

// Main function
int main() {
    // Create a new item
    Item *item = create_item("Mona Lisa", 1000000.0);

    // Create a new auction
    Auction *auction = create_auction(item);

    // Start the auction
    start_auction(auction);

    // End the auction
    end_auction(auction);

    // Free the memory allocated for the item and auction
    free(item->name);
    free(item);
    free(auction->item);
    free(auction->highest_bidder);
    free(auction);

    return 0;
}