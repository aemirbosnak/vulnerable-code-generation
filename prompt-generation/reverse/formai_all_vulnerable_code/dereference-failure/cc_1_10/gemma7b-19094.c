//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
};

struct Item {
    char name[50];
    int startPrice;
    int reservePrice;
    struct Bidder* bidders;
};

void addBidder(struct Item* item, char* name, int bid) {
    struct Bidder* newBidder = malloc(sizeof(struct Bidder));
    strcpy(newBidder->name, name);
    newBidder->bid = bid;
    newBidder->next = NULL;

    if (item->bidders == NULL) {
        item->bidders = newBidder;
    } else {
        struct Bidder* temp = item->bidders;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newBidder;
    }
}

void startAuction(struct Item* item) {
    int highestBid = item->startPrice;
    struct Bidder* currentBidder = item->bidders;

    while (currentBidder) {
        if (currentBidder->bid > highestBid) {
            highestBid = currentBidder->bid;
        }
        currentBidder = currentBidder->next;
    }

    if (highestBid >= item->reservePrice) {
        printf("Congratulations, %s, you won the auction for %s at %d!\n", item->bidders->name, item->name, highestBid);
    } else {
        printf("No bids met the reserve price for %s.\n", item->name);
    }
}

int main() {
    struct Item* item = malloc(sizeof(struct Item));
    strcpy(item->name, "Rare Diamond");
    item->startPrice = 5000;
    item->reservePrice = 6000;

    addBidder(item, "John Doe", 8000);
    addBidder(item, "Jane Doe", 6500);
    addBidder(item, "Bill Smith", 7000);

    startAuction(item);

    return 0;
}