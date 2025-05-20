//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
};

struct Item {
    char name[20];
    int reservePrice;
    struct Bidder* highestBidder;
    struct Item* next;
};

void placeBid(struct Item* item, struct Bidder* bidder, int bid) {
    struct Bidder* newBidder = (struct Bidder*)malloc(sizeof(struct Bidder));
    strcpy(newBidder->name, bidder->name);
    newBidder->bid = bid;
    newBidder->next = NULL;

    if (item->highestBidder) {
        struct Bidder* currentBidder = item->highestBidder;
        while (currentBidder->next) {
            currentBidder = currentBidder->next;
        }
        currentBidder->next = newBidder;
    } else {
        item->highestBidder = newBidder;
    }

    if (bid > item->reservePrice) {
        item->reservePrice = bid;
    }
}

int main() {
    struct Item* item = (struct Item*)malloc(sizeof(struct Item));
    strcpy(item->name, "iPhone");
    item->reservePrice = 500;
    item->highestBidder = NULL;

    struct Bidder* bidder = (struct Bidder*)malloc(sizeof(struct Bidder));
    strcpy(bidder->name, "John Doe");
    bidder->bid = 400;
    placeBid(item, bidder, 400);

    struct Bidder* newBidder = (struct Bidder*)malloc(sizeof(struct Bidder));
    strcpy(newBidder->name, "Jane Doe");
    newBidder->bid = 600;
    placeBid(item, newBidder, 600);

    struct Bidder* highestBidder = item->highestBidder;
    while (highestBidder) {
        printf("%s: %d\n", highestBidder->name, highestBidder->bid);
        highestBidder = highestBidder->next;
    }

    printf("The reserve price is: %d\n", item->reservePrice);

    return 0;
}