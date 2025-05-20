//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <time.h>

#define MAX_BID_AMOUNT 10000

typedef struct Bid {
    char *name;
    int amount;
    struct Bid *next;
} Bid;

typedef struct Auction {
    char *name;
    int startPrice;
    int reservePrice;
    Bid *highestBid;
    struct Auction *next;
} Auction;

Auction *auction_create(char *name, int startPrice, int reservePrice) {
    Auction *auction = malloc(sizeof(Auction));
    auction->name = strdup(name);
    auction->startPrice = startPrice;
    auction->reservePrice = reservePrice;
    auction->highestBid = NULL;
    auction->next = NULL;

    return auction;
}

void bid_add(Auction *auction, char *name, int amount) {
    Bid *newBid = malloc(sizeof(Bid));
    newBid->name = strdup(name);
    newBid->amount = amount;
    newBid->next = NULL;

    if (auction->highestBid == NULL) {
        auction->highestBid = newBid;
    } else {
        Bid *currentBid = auction->highestBid;
        while (currentBid->next) {
            currentBid = currentBid->next;
        }
        currentBid->next = newBid;
    }
}

int auction_close(Auction *auction) {
    if (auction->highestBid->amount < auction->reservePrice) {
        return 0;
    }

    printf("Congratulations, %s! You won the auction for %s with a bid of %d.\n", auction->highestBid->name, auction->name, auction->highestBid->amount);

    free(auction->highestBid);
    free(auction);

    return 1;
}

int main() {
    Auction *auction = auction_create("My Auction", 100, 50);

    bid_add(auction, "John Doe", 200);
    bid_add(auction, "Jane Doe", 150);
    bid_add(auction, "Bob Smith", 120);

    auction_close(auction);

    return 0;
}