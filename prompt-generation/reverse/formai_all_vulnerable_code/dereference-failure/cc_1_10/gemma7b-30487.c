//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 10
#define MAX_BID 1000

struct Item {
    char name[20];
    int startPrice;
    int reservePrice;
    int currentBid;
    struct Bidder *highestBidder;
};

struct Bidder {
    char name[20];
    int bidAmount;
    struct Bidder *next;
};

void initializeItems(struct Item *items) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].name[0] = '\0';
        items[i].startPrice = 0;
        items[i].reservePrice = 0;
        items[i].currentBid = 0;
        items[i].highestBidder = NULL;
    }
}

void addBidder(struct Bidder **head, char *name, int bidAmount) {
    struct Bidder *newBidder = malloc(sizeof(struct Bidder));
    newBidder->name[0] = '\0';
    newBidder->bidAmount = bidAmount;

    if (*head == NULL) {
        *head = newBidder;
    } else {
        (*head)->next = newBidder;
        *head = newBidder;
    }
}

int main() {
    struct Item items[MAX_ITEMS];
    initializeItems(items);

    struct Bidder *highestBidder = NULL;

    // Simulate bidding process
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].currentBid = 100;
        addBidder(&highestBidder, "John Doe", 200);
        addBidder(&highestBidder, "Jane Doe", 150);
        addBidder(&highestBidder, "Bob Smith", 120);

        // Find the highest bidder
        struct Bidder *currentBidder = highestBidder;
        while (currentBidder) {
            if (currentBidder->bidAmount > items[i].currentBid) {
                items[i].currentBid = currentBidder->bidAmount;
                items[i].highestBidder = currentBidder;
            }
            currentBidder = currentBidder->next;
        }
    }

    // Print the results
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("Item: %s, Highest Bid: %d, Highest Bidder: %s\n", items[i].name, items[i].currentBid, items[i].highestBidder->name);
    }

    return 0;
}