//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a bid
typedef struct bid {
    int amount;
    int bidder;
} Bid;

// Define the structure for a digital auction
typedef struct auction {
    int currentBid;
    int maxBid;
    int endTime;
} Auction;

// Function to initialize an auction
Auction* initAuction(int endTime) {
    Auction* auction = (Auction*) malloc(sizeof(Auction));
    auction->currentBid = 0;
    auction->maxBid = 0;
    auction->endTime = endTime;
    return auction;
}

// Function to add a bid to the auction
void addBid(Auction* auction, int amount, int bidder) {
    if (auction->endTime!= 0 && auction->endTime <= getTime()) {
        printf("Auction ended, cannot add bids.\n");
        return;
    }

    if (auction->currentBid < amount) {
        auction->currentBid = amount;
        auction->maxBid = amount;
        printf("New highest bid: %d\n", amount);
    } else {
        printf("Invalid bid, current highest bid is %d.\n", auction->currentBid);
    }
}

// Function to get the current time
int getTime() {
    return 0;
}

int main() {
    Auction* auction = initAuction(60);

    addBid(auction, 10, 1);
    addBid(auction, 20, 2);
    addBid(auction, 30, 3);

    printf("Ending time: %d\n", auction->endTime);
    printf("Current highest bid: %d\n", auction->currentBid);
    printf("Max bid: %d\n", auction->maxBid);

    return 0;
}