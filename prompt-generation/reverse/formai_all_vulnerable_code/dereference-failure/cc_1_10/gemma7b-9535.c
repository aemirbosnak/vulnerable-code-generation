//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 10000

struct Bid {
    char name[50];
    int bid;
    struct Bid* next;
};

struct Item {
    char name[50];
    int startingPrice;
    struct Bid* highestBid;
    struct Item* next;
};

void insertBid(struct Bid** head, char* name, int bid) {
    struct Bid* newBid = malloc(sizeof(struct Bid));
    strcpy(newBid->name, name);
    newBid->bid = bid;
    newBid->next = NULL;

    if (*head == NULL) {
        *head = newBid;
    } else {
        (*head)->next = newBid;
    }
}

void insertItem(struct Item** head, char* name, int startingPrice) {
    struct Item* newItem = malloc(sizeof(struct Item));
    strcpy(newItem->name, name);
    newItem->startingPrice = startingPrice;
    newItem->highestBid = NULL;
    newItem->next = NULL;

    if (*head == NULL) {
        *head = newItem;
    } else {
        (*head)->next = newItem;
    }
}

int main() {
    struct Item* items = NULL;
    insertItem(&items, "Spaceship", 10000);
    insertItem(&items, "Flying Car", 5000);
    insertItem(&items, "Luxury Yacht", 20000);

    struct Bid* bids = NULL;
    insertBid(&bids, "John Doe", 8000);
    insertBid(&bids, "Jane Doe", 6000);
    insertBid(&bids, "Bill Smith", 7000);

    // Auction begins
    printf("Welcome to the future of bidding!\n");

    for (struct Item* item = items; item; item = item->next) {
        printf("Item: %s, Starting Price: %d\n", item->name, item->startingPrice);

        for (struct Bid* bid = bids; bid; bid = bid->next) {
            if (bid->bid >= item->startingPrice) {
                printf("Bidder: %s, Bid: %d\n", bid->name, bid->bid);
            }
        }

        printf("\n");
    }

    // Winner announcement
    for (struct Item* item = items; item; item = item->next) {
        struct Bid* highestBid = item->highestBid;
        if (highestBid) {
            printf("Congratulations, %s, you won the auction for the %s!\n", highestBid->name, item->name);
        } else {
            printf("No bids received for the %s.\n", item->name);
        }
    }

    return 0;
}