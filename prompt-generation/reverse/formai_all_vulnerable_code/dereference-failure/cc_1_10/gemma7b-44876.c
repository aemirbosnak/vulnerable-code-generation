//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 1000

struct Bid {
    char name[50];
    int bid;
    struct Bid* next;
};

struct Item {
    char name[50];
    int startPrice;
    struct Bid* highestBid;
    struct Item* next;
};

void insertBid(struct Bid** head, char* name, int bid) {
    struct Bid* newBid = (struct Bid*)malloc(sizeof(struct Bid));
    strcpy(newBid->name, name);
    newBid->bid = bid;
    newBid->next = NULL;

    if (*head == NULL) {
        *head = newBid;
    } else {
        (*head)->next = newBid;
    }
}

void insertItem(struct Item** head, char* name, int startPrice) {
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
    strcpy(newItem->name, name);
    newItem->startPrice = startPrice;
    newItem->highestBid = NULL;
    newItem->next = NULL;

    if (*head == NULL) {
        *head = newItem;
    } else {
        (*head)->next = newItem;
    }
}

void auction(struct Item* item) {
    int highestBid = item->startPrice;
    struct Bid* currentBid = item->highestBid;

    while (currentBid) {
        if (currentBid->bid > highestBid) {
            highestBid = currentBid->bid;
        }
        currentBid = currentBid->next;
    }

    printf("The highest bid for item '%s' is %d.\n", item->name, highestBid);
}

int main() {
    struct Item* items = NULL;
    insertItem(&items, "Laptop", 500);
    insertItem(&items, "Smartphone", 300);
    insertItem(&items, "Watch", 200);

    auction(items->next);

    return 0;
}