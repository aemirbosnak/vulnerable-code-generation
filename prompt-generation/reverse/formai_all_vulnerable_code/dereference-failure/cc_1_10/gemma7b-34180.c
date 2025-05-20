//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000

struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
};

struct Item {
    char name[20];
    int startPrice;
    int reservePrice;
    struct Bidder* bidders;
    struct Item* next;
};

void insertBidder(struct Bidder** head, char* name, int bid) {
    struct Bidder* newNode = malloc(sizeof(struct Bidder));
    strcpy(newNode->name, name);
    newNode->bid = bid;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void insertItem(struct Item** head, char* name, int startPrice, int reservePrice) {
    struct Item* newNode = malloc(sizeof(struct Item));
    strcpy(newNode->name, name);
    newNode->startPrice = startPrice;
    newNode->reservePrice = reservePrice;
    newNode->bidders = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void auction(struct Item* item) {
    struct Bidder* currentBidder = item->bidders;
    int highestBid = item->startPrice;

    while (currentBidder) {
        if (currentBidder->bid > highestBid) {
            highestBid = currentBidder->bid;
        }
        currentBidder = currentBidder->next;
    }

    if (highestBid >= item->reservePrice) {
        printf("Congratulations, %s! You won the auction for %s with a bid of %d.\n", currentBidder->name, item->name, highestBid);
    } else {
        printf("No bids met the reserve price for %s.\n", item->name);
    }
}

int main() {
    struct Item* items = NULL;

    insertItem(&items, "Apple", 50, 70);
    insertItem(&items, "Banana", 20, 40);
    insertItem(&items, "Orange", 30, 60);

    struct Bidder* bidders = NULL;

    insertBidder(&bidders, "John Doe", 40);
    insertBidder(&bidders, "Jane Doe", 30);
    insertBidder(&bidders, "Bill Smith", 20);

    auction(items);

    return 0;
}