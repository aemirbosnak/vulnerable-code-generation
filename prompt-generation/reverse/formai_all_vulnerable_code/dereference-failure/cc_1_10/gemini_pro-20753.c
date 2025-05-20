//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Item {
    char name[50];
    int price;
    int quantity;
};

struct Bid {
    char bidderName[50];
    int bidPrice;
};

struct Auction {
    struct Item item;
    struct Bid *bids;
    int numBids;
    time_t startTime;
    time_t endTime;
};

struct Auction *createAuction(struct Item item, time_t startTime, time_t endTime) {
    struct Auction *auction = (struct Auction *) malloc(sizeof(struct Auction));
    auction->item = item;
    auction->bids = NULL;
    auction->numBids = 0;
    auction->startTime = startTime;
    auction->endTime = endTime;
    return auction;
}

void destroyAuction(struct Auction *auction) {
    free(auction->bids);
    free(auction);
}

void addBid(struct Auction *auction, struct Bid bid) {
    auction->bids = (struct Bid *) realloc(auction->bids, (auction->numBids + 1) * sizeof(struct Bid));
    auction->bids[auction->numBids++] = bid;
}

int getHighestBid(struct Auction *auction) {
    int highestBid = 0;
    for (int i = 0; i < auction->numBids; i++) {
        if (auction->bids[i].bidPrice > highestBid) {
            highestBid = auction->bids[i].bidPrice;
        }
    }
    return highestBid;
}

void printAuction(struct Auction *auction) {
    printf("Item: %s\n", auction->item.name);
    printf("Price: %d\n", auction->item.price);
    printf("Quantity: %d\n", auction->item.quantity);
    printf("Start time: %s", ctime(&auction->startTime));
    printf("End time: %s", ctime(&auction->endTime));
    printf("Number of bids: %d\n", auction->numBids);
    for (int i = 0; i < auction->numBids; i++) {
        printf("Bidder: %s\n", auction->bids[i].bidderName);
        printf("Bid price: %d\n", auction->bids[i].bidPrice);
    }
}

int main() {
    struct Item item1 = {"iPhone 13", 1000, 10};
    time_t startTime = time(NULL);
    time_t endTime = startTime + 3600;
    struct Auction *auction1 = createAuction(item1, startTime, endTime);

    struct Bid bid1 = {"John Doe", 1100};
    addBid(auction1, bid1);

    struct Bid bid2 = {"Jane Doe", 1200};
    addBid(auction1, bid2);

    printAuction(auction1);

    int highestBid = getHighestBid(auction1);
    printf("Highest bid: %d\n", highestBid);

    destroyAuction(auction1);

    return 0;
}