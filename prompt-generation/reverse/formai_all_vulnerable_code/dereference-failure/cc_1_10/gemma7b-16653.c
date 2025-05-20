//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 1000

struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
};

struct Item {
    char name[20];
    int startingPrice;
    int reservePrice;
    struct Bidder* highestBidder;
};

void insertBidder(struct Bidder** head, char* name, int bid) {
    struct Bidder* newBidder = malloc(sizeof(struct Bidder));
    strcpy(newBidder->name, name);
    newBidder->bid = bid;
    newBidder->next = NULL;

    if (*head == NULL) {
        *head = newBidder;
    } else {
        (*head)->next = newBidder;
    }
}

void updateHighestBid(struct Item* item, int newBid) {
    struct Bidder* highestBidder = item->highestBidder;
    if (highestBidder == NULL || newBid > highestBidder->bid) {
        highestBidder = NULL;
    }

    if (highestBidder) {
        highestBidder->bid = newBid;
    } else {
        insertBidder(&item->highestBidder, "New Bidder", newBid);
    }
}

int main() {
    struct Item item;
    strcpy(item.name, "Laptop");
    item.startingPrice = 500;
    item.reservePrice = 700;
    item.highestBidder = NULL;

    insertBidder(&item.highestBidder, "John Doe", 600);
    insertBidder(&item.highestBidder, "Jane Doe", 550);
    insertBidder(&item.highestBidder, "Bill Smith", 650);

    updateHighestBid(&item, 750);

    printf("Highest bidder: %s with bid %d\n", item.highestBidder->name, item.highestBidder->bid);

    return 0;
}