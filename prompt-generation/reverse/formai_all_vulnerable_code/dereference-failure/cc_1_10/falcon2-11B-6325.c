//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

// Define structures for auction information
struct bidder {
    int id;
    char name[50];
    int bid;
};

struct auction {
    int id;
    char name[50];
    int startingPrice;
    int currentPrice;
};

struct auction *createAuction(int id, char name[50], int startingPrice) {
    struct auction *auction = (struct auction *)malloc(sizeof(struct auction));
    strcpy(auction->name, name);
    auction->id = id;
    auction->startingPrice = startingPrice;
    return auction;
}

void displayAuction(struct auction *auction) {
    printf("Auction ID: %d\n", auction->id);
    printf("Auction Name: %s\n", auction->name);
    printf("Starting Price: %d\n", auction->startingPrice);
    printf("Current Price: %d\n", auction->currentPrice);
}

void bidOnAuction(struct auction *auction, struct bidder *bidder) {
    if (auction->currentPrice >= auction->startingPrice * 2) {
        printf("Auction is closed. No more bids accepted.\n");
    } else {
        printf("Enter your bid: ");
        scanf("%d", &bidder->bid);
        if (bidder->bid > auction->currentPrice) {
            auction->currentPrice = bidder->bid;
            printf("Bid successful!\n");
        } else {
            printf("Invalid bid. Please try again.\n");
        }
    }
}

int main() {
    struct auction *auction1 = createAuction(1, "iPhone 12", 100);
    struct auction *auction2 = createAuction(2, "Samsung Galaxy S21", 200);

    struct bidder bidder1;
    strcpy(bidder1.name, "John Doe");
    bidder1.id = 1;

    struct bidder bidder2;
    strcpy(bidder2.name, "Jane Smith");
    bidder2.id = 2;

    displayAuction(auction1);
    bidOnAuction(auction1, &bidder1);
    displayAuction(auction1);
    bidOnAuction(auction2, &bidder2);
    displayAuction(auction2);

    return 0;
}