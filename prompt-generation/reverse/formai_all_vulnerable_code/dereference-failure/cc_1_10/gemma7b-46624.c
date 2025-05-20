//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 1000

struct Bid {
    char name[20];
    int bid;
    struct Bid* next;
};

struct Auction {
    char item[20];
    int reservePrice;
    struct Bid* head;
};

void insertBid(struct Auction* auction, char* name, int bid) {
    struct Bid* newBid = (struct Bid*)malloc(sizeof(struct Bid));
    strcpy(newBid->name, name);
    newBid->bid = bid;
    newBid->next = NULL;

    if (auction->head == NULL) {
        auction->head = newBid;
    } else {
        struct Bid* currentBid = auction->head;
        while (currentBid->next) {
            currentBid = currentBid->next;
        }
        currentBid->next = newBid;
    }
}

int checkBid(struct Auction* auction, char* name) {
    struct Bid* currentBid = auction->head;
    while (currentBid) {
        if (strcmp(currentBid->name, name) == 0) {
            return currentBid->bid;
        }
        currentBid = currentBid->next;
    }
    return -1;
}

void printBids(struct Auction* auction) {
    struct Bid* currentBid = auction->head;
    printf("Bids for item: %s\n", auction->item);
    while (currentBid) {
        printf("%s bid: %d\n", currentBid->name, currentBid->bid);
        currentBid = currentBid->next;
    }
}

int main() {
    struct Auction* auction = (struct Auction*)malloc(sizeof(struct Auction));
    strcpy(auction->item, "Diamond Ring");
    auction->reservePrice = 500;
    auction->head = NULL;

    insertBid(auction, "John Doe", 600);
    insertBid(auction, "Jane Doe", 400);
    insertBid(auction, "Peter Pan", 300);

    printBids(auction);

    int bid = checkBid(auction, "John Doe");
    if (bid != -1) {
        printf("John Doe's bid: %d\n", bid);
    }

    return 0;
}