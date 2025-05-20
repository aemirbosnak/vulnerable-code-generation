//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure to store auction details
typedef struct {
    char name[50];
    int price;
    int bid;
    int highestBidder;
    int currentBidder;
} Auction;

// Function to initialize an auction
Auction* initAuction(char name[], int price, int bid, int highestBidder, int currentBidder) {
    Auction* auction = (Auction*) malloc(sizeof(Auction));
    strcpy(auction->name, name);
    auction->price = price;
    auction->bid = bid;
    auction->highestBidder = highestBidder;
    auction->currentBidder = currentBidder;
    return auction;
}

// Function to display auction details
void displayAuction(Auction* auction) {
    printf("Name: %s\n", auction->name);
    printf("Price: %d\n", auction->price);
    printf("Bid: %d\n", auction->bid);
    printf("Highest Bidder: %d\n", auction->highestBidder);
    printf("Current Bidder: %d\n", auction->currentBidder);
}

// Function to update the highest bidder
void updateHighestBidder(Auction* auction) {
    if (auction->bid > auction->price) {
        auction->highestBidder = auction->currentBidder;
        auction->price = auction->bid;
    }
}

// Function to update the current bidder
void updateCurrentBidder(Auction* auction) {
    if (auction->currentBidder!= auction->highestBidder) {
        auction->currentBidder = auction->highestBidder;
        updateHighestBidder(auction);
    }
}

// Function to simulate an auction
void simulateAuction(Auction* auction) {
    srand(time(NULL));

    while (auction->price > 0) {
        int bidder = rand() % 100;
        printf("Bidder %d: %d\n", bidder, auction->price);
        if (auction->bid < auction->price) {
            auction->bid = bidder;
            updateHighestBidder(auction);
            updateCurrentBidder(auction);
            printf("Highest Bidder: %d\n", auction->highestBidder);
            printf("Current Bidder: %d\n", auction->currentBidder);
        }
    }
}

// Function to print the winner of the auction
void printWinner(Auction* auction) {
    if (auction->currentBidder == auction->highestBidder) {
        printf("Winner: %s\n", auction->name);
    } else {
        printf("No winner.\n");
    }
}

int main() {
    char name[50];
    int price, bid, highestBidder, currentBidder;

    // Prompt the user for auction details
    printf("Enter auction details: \n");
    printf("Name: ");
    scanf("%s", name);
    printf("Price: ");
    scanf("%d", &price);
    printf("Bid: ");
    scanf("%d", &bid);
    printf("Highest Bidder: ");
    scanf("%d", &highestBidder);
    printf("Current Bidder: ");
    scanf("%d", &currentBidder);

    // Initialize the auction
    Auction* auction = initAuction(name, price, bid, highestBidder, currentBidder);

    // Simulate the auction
    simulateAuction(auction);

    // Print the winner of the auction
    printWinner(auction);

    // Free memory
    free(auction);

    return 0;
}