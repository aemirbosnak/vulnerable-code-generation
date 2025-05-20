//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10

struct Bid {
    char bidder[20];
    int amount;
    struct Bid* next;
};

struct Item {
    char name[50];
    int startingPrice;
    struct Bid* bids;
};

void addBid(struct Item* item, char* bidder, int amount) {
    struct Bid* newBid = (struct Bid*)malloc(sizeof(struct Bid));
    strcpy(newBid->bidder, bidder);
    newBid->amount = amount;
    newBid->next = item->bids;
    item->bids = newBid;
}

int findHighestBid(struct Item* item) {
    struct Bid* currentBid = item->bids;
    int highestBid = 0;
    while (currentBid) {
        if (currentBid->amount > highestBid) {
            highestBid = currentBid->amount;
        }
        currentBid = currentBid->next;
    }
    return highestBid;
}

int main() {
    struct Item* item = (struct Item*)malloc(sizeof(struct Item));
    strcpy(item->name, "iPhone");
    item->startingPrice = 1000;
    item->bids = NULL;

    addBid(item, "John Doe", 1200);
    addBid(item, "Jane Doe", 1100);
    addBid(item, "Peter Pan", 1050);

    int highestBid = findHighestBid(item);
    printf("The highest bid is: %d", highestBid);

    return 0;
}