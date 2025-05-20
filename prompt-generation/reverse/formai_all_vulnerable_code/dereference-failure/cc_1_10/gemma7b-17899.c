//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: multivariable
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
    int startingPrice;
    struct Bidder* highestBidder;
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

void insertItem(struct Item** head, char* name, int startingPrice) {
    struct Item* newNode = malloc(sizeof(struct Item));
    strcpy(newNode->name, name);
    newNode->startingPrice = startingPrice;
    newNode->highestBidder = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void startAuction(struct Item* item) {
    struct Bidder* highestBidder = item->highestBidder;
    int currentBid = item->startingPrice;

    while (highestBidder && currentBid < MAX_BID) {
        printf("Current Bid: $%d\n", currentBid);
        printf("Enter your name: ");
        char bidderName[20];
        scanf("%s", bidderName);

        printf("Enter your bid: $");
        int newBid;
        scanf("%d", &newBid);

        insertBidder(&highestBidder, bidderName, newBid);

        if (newBid > currentBid) {
            currentBid = newBid;
            highestBidder = NULL;
        }
    }

    printf("Congratulations, %s! You won the auction for %s!\n", highestBidder->name, item->name);
    printf("Your total bid: $%d\n", highestBidder->bid);
}

int main() {
    struct Item* itemHead = NULL;
    insertItem(&itemHead, "Diamond Ring", 500);
    insertItem(&itemHead, "Gold Watch", 200);
    insertItem(&itemHead, "Silver Chain", 300);

    startAuction(itemHead->next);

    return 0;
}