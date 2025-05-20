//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 10000

struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
};

struct Item {
    char name[50];
    int startingPrice;
    struct Bidder* highestBidder;
    struct Item* next;
};

void insertBidder(struct Bidder* head, char* name, int bid) {
    struct Bidder* newBidder = malloc(sizeof(struct Bidder));
    strcpy(newBidder->name, name);
    newBidder->bid = bid;
    newBidder->next = NULL;

    if (head == NULL) {
        head = newBidder;
    } else {
        struct Bidder* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newBidder;
    }
}

void insertItem(struct Item* head, char* name, int startingPrice) {
    struct Item* newItem = malloc(sizeof(struct Item));
    strcpy(newItem->name, name);
    newItem->startingPrice = startingPrice;
    newItem->highestBidder = NULL;
    newItem->next = NULL;

    if (head == NULL) {
        head = newItem;
    } else {
        struct Item* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newItem;
    }
}

void auction() {
    struct Bidder* head = NULL;
    struct Item* headItem = NULL;

    insertItem(headItem, "Laptop", 1000);
    insertItem(headItem, "Smartphone", 500);
    insertItem(headItem, "Watch", 2000);

    insertBidder(head, "John Doe", 800);
    insertBidder(head, "Jane Doe", 700);
    insertBidder(head, "Bill Smith", 900);

    int highestBid = 0;
    struct Item* currentItem = headItem;
    while (currentItem) {
        struct Bidder* currentBidder = head;
        while (currentBidder) {
            if (currentBidder->bid > highestBid) {
                highestBid = currentBidder->bid;
                currentItem->highestBidder = currentBidder;
            }
            currentBidder = currentBidder->next;
        }
        currentItem = currentItem->next;
    }

    printf("The winner is: %s with a bid of %d.\n", currentItem->highestBidder->name, highestBid);
}

int main() {
    auction();

    return 0;
}