//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define an auction struct
struct auction {
    int id;
    char* name;
    int startingPrice;
    int currentPrice;
    int bidderId;
};

// Function to create a new auction
struct auction* createAuction(int id, char* name, int startingPrice) {
    struct auction* auction = malloc(sizeof(struct auction));
    auction->id = id;
    auction->name = strdup(name);
    auction->startingPrice = startingPrice;
    auction->currentPrice = startingPrice;
    auction->bidderId = -1;

    return auction;
}

// Function to add a bidder to an auction
void addBidder(struct auction* auction, int bidderId) {
    if (auction->bidderId == -1) {
        auction->bidderId = bidderId;
    } else {
        printf("Auction is already closed.\n");
    }
}

// Function to bid on an auction
void bid(struct auction* auction, int bidAmount) {
    if (auction->currentPrice == auction->startingPrice) {
        printf("Bid must be higher than the starting price.\n");
        return;
    }
    if (auction->bidderId!= -1) {
        printf("Auction is already closed.\n");
        return;
    }
    if (bidAmount > auction->currentPrice) {
        auction->currentPrice = bidAmount;
    } else {
        printf("Invalid bid amount.\n");
        return;
    }
}

// Function to check if an auction is over
int isAuctionOver(struct auction* auction) {
    return auction->currentPrice == auction->startingPrice;
}

// Function to print an auction
void printAuction(struct auction* auction) {
    printf("ID: %d\n", auction->id);
    printf("Name: %s\n", auction->name);
    printf("Starting Price: %d\n", auction->startingPrice);
    printf("Current Price: %d\n", auction->currentPrice);
    printf("Bidder ID: %d\n", auction->bidderId);
}

int main() {
    // Create a new auction
    struct auction* auction = createAuction(1, "Example Auction", 10);
    printf("Auction created successfully.\n");

    // Add a bidder
    addBidder(auction, 1);
    printf("Bidder added successfully.\n");

    // Bid on the auction
    bid(auction, 20);
    printf("Bid placed successfully.\n");

    // Check if the auction is over
    if (isAuctionOver(auction)) {
        printf("Auction is over.\n");
    } else {
        printf("Auction is not over.\n");
    }

    // Print the auction details
    printAuction(auction);

    return 0;
}