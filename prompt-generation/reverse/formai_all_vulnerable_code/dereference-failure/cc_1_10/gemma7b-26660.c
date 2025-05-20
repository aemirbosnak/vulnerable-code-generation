//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 1000

struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
};

struct Item {
    char name[20];
    int startPrice;
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

void updateHighestBid(struct Item* item) {
    struct Bidder* currentBidder = item->highestBidder;
    int highestBid = currentBidder->bid;

    if (highestBid < item->reservePrice) {
        highestBid = item->reservePrice;
    }

    item->highestBidder = currentBidder;
    item->startPrice = highestBid;
}

int main() {
    struct Item item;
    strcpy(item.name, "Laptop");
    item.startPrice = 500;
    item.reservePrice = 700;
    item.highestBidder = NULL;

    struct Bidder* head = NULL;

    // Simulate bidders
    insertBidder(&head, "John Doe", 600);
    insertBidder(&head, "Jane Doe", 400);
    insertBidder(&head, "Peter Pan", 800);

    // Update highest bid
    updateHighestBid(&item);

    // Print highest bid
    printf("Highest bid: %d\n", item.startPrice);

    return 0;
}