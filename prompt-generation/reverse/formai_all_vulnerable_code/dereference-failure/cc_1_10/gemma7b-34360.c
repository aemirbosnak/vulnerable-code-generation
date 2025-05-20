//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 10000

struct Bid {
    char name[20];
    int amount;
    struct Bid* next;
};

struct Item {
    char name[50];
    int startingPrice;
    struct Bid* bids;
    struct Item* next;
};

typedef struct Bid Bid;
typedef struct Item Item;

void insertBid(Bid** head, char* name, int amount) {
    Bid* newBid = malloc(sizeof(Bid));
    strcpy(newBid->name, name);
    newBid->amount = amount;
    newBid->next = NULL;

    if (*head == NULL) {
        *head = newBid;
    } else {
        (*head)->next = newBid;
    }
}

void insertItem(Item** head, char* name, int startingPrice) {
    Item* newItem = malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->startingPrice = startingPrice;
    newItem->bids = NULL;
    newItem->next = NULL;

    if (*head == NULL) {
        *head = newItem;
    } else {
        (*head)->next = newItem;
    }
}

void auction(Item* item) {
    Bid* currentBid = item->bids;
    int highestBid = item->startingPrice;

    printf("Auction for item: %s\n", item->name);
    printf("Starting price: %d\n", item->startingPrice);

    while (currentBid) {
        printf("Bidder: %s, Amount: %d\n", currentBid->name, currentBid->amount);

        if (currentBid->amount > highestBid) {
            highestBid = currentBid->amount;
        }
        currentBid = currentBid->next;
    }

    printf("The highest bid is: %d\n", highestBid);

    if (highestBid == item->startingPrice) {
        printf("No bids received.\n");
    } else {
        printf("The item has been sold to: %s\n", currentBid->name);
    }
}

int main() {
    Item* items = NULL;
    insertItem(&items, "iPhone", 500);
    insertItem(&items, "Laptop", 1000);
    insertItem(&items, "Car", 2000);

    auction(items->next);
    auction(items->next->next);

    return 0;
}