//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_BID 1000

struct Bid {
    char name[20];
    int bid;
    struct Bid* next;
};

struct Item {
    char name[20];
    int reservePrice;
    struct Bid* bids;
};

void addBid(struct Item* item, char* name, int bid) {
    struct Bid* newBid = malloc(sizeof(struct Bid));
    strcpy(newBid->name, name);
    newBid->bid = bid;
    newBid->next = NULL;

    if (item->bids == NULL) {
        item->bids = newBid;
    } else {
        struct Bid* currentBid = item->bids;
        while (currentBid->next) {
            currentBid = currentBid->next;
        }
        currentBid->next = newBid;
    }
}

int main() {
    struct Item* item = malloc(sizeof(struct Item));
    strcpy(item->name, "A priceless painting");
    item->reservePrice = 500;

    addBid(item, "John Doe", 200);
    addBid(item, "Jane Doe", 300);
    addBid(item, "Bill Gates", 400);

    struct Bid* currentBid = item->bids;
    while (currentBid) {
        printf("Name: %s, Bid: %d\n", currentBid->name, currentBid->bid);
        currentBid = currentBid->next;
    }

    return 0;
}