//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID_AMOUNT 1000
#define MAX_NUM_BIDDERS 10

struct Bidder {
    char name[20];
    int bidAmount;
    struct Bidder* next;
};

struct Item {
    char name[20];
    int reservePrice;
    struct Bidder* highestBidder;
    struct Item* next;
};

void createBidder(struct Bidder** head) {
    *head = (struct Bidder*)malloc(sizeof(struct Bidder));
    (*head)->name[0] = '\0';
    (*head)->bidAmount = 0;
    (*head)->next = NULL;
}

void createItem(struct Item** head) {
    *head = (struct Item*)malloc(sizeof(struct Item));
    (*head)->name[0] = '\0';
    (*head)->reservePrice = 0;
    (*head)->highestBidder = NULL;
    (*head)->next = NULL;
}

void addBidder(struct Bidder** head, char* name, int bidAmount) {
    struct Bidder* newBidder = (struct Bidder*)malloc(sizeof(struct Bidder));
    newBidder->name[0] = '\0';
    strcpy(newBidder->name, name);
    newBidder->bidAmount = bidAmount;
    newBidder->next = NULL;

    if (*head == NULL) {
        *head = newBidder;
    } else {
        (*head)->next = newBidder;
        *head = newBidder;
    }
}

void addItem(struct Item** head, char* name, int reservePrice) {
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
    newItem->name[0] = '\0';
    strcpy(newItem->name, name);
    newItem->reservePrice = reservePrice;
    newItem->highestBidder = NULL;
    newItem->next = NULL;

    if (*head == NULL) {
        *head = newItem;
    } else {
        (*head)->next = newItem;
        *head = newItem;
    }
}

void startAuction(struct Item* item) {
    struct Bidder* bidders = item->highestBidder;
    int highestBid = item->reservePrice;

    while (bidders) {
        if (bidders->bidAmount > highestBid) {
            highestBid = bidders->bidAmount;
        }
        bidders = bidders->next;
    }

    printf("The highest bid is: $%d\n", highestBid);
}

int main() {
    struct Item* itemHead = NULL;
    struct Bidder* bidderHead = NULL;

    addItem(&itemHead, "Car", 10000);
    addItem(&itemHead, "House", 20000);
    addItem(&itemHead, "Electronics", 5000);

    addBidder(&bidderHead, "John Doe", 8000);
    addBidder(&bidderHead, "Jane Doe", 9000);
    addBidder(&bidderHead, "Bill Smith", 7000);

    startAuction(itemHead->next);

    return 0;
}