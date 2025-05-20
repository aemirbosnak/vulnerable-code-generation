//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000

struct Bid {
    char name[20];
    int amount;
    struct Bid* next;
};

struct Item {
    char name[20];
    int reservePrice;
    struct Bid* highestBid;
};

void insertBid(struct Bid** head, char* name, int amount) {
    struct Bid* newBid = (struct Bid*)malloc(sizeof(struct Bid));
    strcpy(newBid->name, name);
    newBid->amount = amount;
    newBid->next = NULL;

    if (*head == NULL) {
        *head = newBid;
    } else {
        (*head)->next = newBid;
    }
}

void findHighestBid(struct Item* item) {
    struct Bid* highestBid = item->highestBid;
    if (highestBid) {
        printf("The highest bid is: %s for %d\n", highestBid->name, highestBid->amount);
    } else {
        printf("No bids yet.\n");
    }
}

int main() {
    struct Item* item = (struct Item*)malloc(sizeof(struct Item));
    strcpy(item->name, "iPhone");
    item->reservePrice = 500;
    insertBid(&item->highestBid, "John Doe", 600);
    insertBid(&item->highestBid, "Jane Doe", 400);
    insertBid(&item->highestBid, "Peter Pan", 300);

    findHighestBid(item);

    return 0;
}