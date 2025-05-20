//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000

struct Bid {
    char bidder[20];
    int bidAmount;
    struct Bid* next;
};

struct Item {
    char itemName[20];
    int startingPrice;
    struct Bid* highestBid;
    struct Item* next;
};

void insertBid(struct Bid** head, char* bidder, int bidAmount) {
    struct Bid* newBid = (struct Bid*)malloc(sizeof(struct Bid));
    strcpy(newBid->bidder, bidder);
    newBid->bidAmount = bidAmount;
    newBid->next = NULL;

    if (*head == NULL) {
        *head = newBid;
    } else {
        (*head)->next = newBid;
    }
}

void insertItem(struct Item** head, char* itemName, int startingPrice) {
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
    strcpy(newItem->itemName, itemName);
    newItem->startingPrice = startingPrice;
    newItem->highestBid = NULL;
    newItem->next = NULL;

    if (*head == NULL) {
        *head = newItem;
    } else {
        (*head)->next = newItem;
    }
}

void auction(struct Item* item) {
    printf("Auction for item: %s\n", item->itemName);
    printf("Starting price: $%d\n", item->startingPrice);

    struct Bid* highestBid = item->highestBid;
    if (highestBid) {
        printf("Current highest bid: $%d from %s\n", highestBid->bidAmount, highestBid->bidder);
    } else {
        printf("No bids yet.\n");
    }

    printf("Enter your bid: $");
    int bidAmount;
    scanf("%d", &bidAmount);

    if (bidAmount > item->startingPrice && bidAmount <= MAX_BID) {
        insertBid(&highestBid, "John Doe", bidAmount);
        printf("Your bid has been placed. Thank you for participating.\n");
    } else {
        printf("Invalid bid. Please try again.\n");
    }
}

int main() {
    struct Item* itemHead = NULL;
    insertItem(&itemHead, "Laptop", 500);
    insertItem(&itemHead, "Smartphone", 300);

    auction(itemHead->next);

    return 0;
}