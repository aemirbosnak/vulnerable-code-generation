//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 10000

struct Bid {
    char *name;
    int amount;
    struct Bid *next;
};

struct Item {
    char *name;
    int startingPrice;
    struct Bid *highestBid;
    struct Item *next;
};

void addItem(struct Item **head, char *name, int startingPrice);
void placeBid(struct Item *item, char *name, int amount);
void printBids(struct Item *item);

int main() {
    struct Item *items = NULL;

    addItem(&items, "Apple", 100);
    addItem(&items, "Banana", 50);
    addItem(&items, "Orange", 75);

    placeBid(items, "John", 120);
    placeBid(items, "Mary", 60);
    placeBid(items, "Bob", 80);

    printBids(items);

    return 0;
}

void addItem(struct Item **head, char *name, int startingPrice) {
    struct Item *newItem = malloc(sizeof(struct Item));
    newItem->name = strdup(name);
    newItem->startingPrice = startingPrice;
    newItem->highestBid = NULL;
    newItem->next = NULL;

    if (*head == NULL) {
        *head = newItem;
    } else {
        (*head)->next = newItem;
    }
}

void placeBid(struct Item *item, char *name, int amount) {
    struct Bid *newBid = malloc(sizeof(struct Bid));
    newBid->name = strdup(name);
    newBid->amount = amount;
    newBid->next = NULL;

    if (item->highestBid == NULL) {
        item->highestBid = newBid;
    } else {
        item->highestBid->next = newBid;
    }
}

void printBids(struct Item *item) {
    struct Bid *bid = item->highestBid;

    printf("Bids for item: %s\n", item->name);
    while (bid) {
        printf("  %s: %d\n", bid->name, bid->amount);
        bid = bid->next;
    }
}