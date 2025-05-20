//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_BID 10000

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

void insertBid(struct Item* item, char* name, int bid) {
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
    struct Item item;
    strcpy(item.name, "Diamond Ring");
    item.reservePrice = 5000;

    insertBid(&item, "John Doe", 4500);
    insertBid(&item, "Jane Doe", 4000);
    insertBid(&item, "Peter Pan", 3500);

    struct Bid* currentBid = item.bids;
    while (currentBid) {
        printf("Name: %s, Bid: %d\n", currentBid->name, currentBid->bid);
        currentBid = currentBid->next;
    }

    return 0;
}