//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000

struct Bid {
    char name[50];
    int amount;
    struct Bid* next;
};

struct Item {
    char name[50];
    int startingPrice;
    int reservePrice;
    struct Bid* bids;
    struct Item* next;
};

void insertBid(struct Item* item, char* name, int amount) {
    struct Bid* newBid = malloc(sizeof(struct Bid));
    strcpy(newBid->name, name);
    newBid->amount = amount;
    newBid->next = NULL;

    if (item->bids == NULL) {
        item->bids = newBid;
    } else {
        struct Bid* currentBid = item->bids;
        while (currentBid->next != NULL) {
            currentBid = currentBid->next;
        }
        currentBid->next = newBid;
    }
}

int findHighestBid(struct Item* item) {
    if (item->bids == NULL) {
        return 0;
    } else {
        struct Bid* currentBid = item->bids;
        int highestBid = currentBid->amount;
        while (currentBid->next != NULL) {
            currentBid = currentBid->next;
            if (currentBid->amount > highestBid) {
                highestBid = currentBid->amount;
            }
        }
        return highestBid;
    }
}

int main() {
    struct Item* items = NULL;

    // Create a few items
    struct Item* item1 = malloc(sizeof(struct Item));
    strcpy(item1->name, "iPhone");
    item1->startingPrice = 500;
    item1->reservePrice = 700;
    item1->bids = NULL;

    struct Item* item2 = malloc(sizeof(struct Item));
    strcpy(item2->name, "Laptop");
    item2->startingPrice = 300;
    item2->reservePrice = 500;
    item2->bids = NULL;

    insertBid(item1, "John Doe", 600);
    insertBid(item1, "Jane Doe", 400);
    insertBid(item2, "Peter Pan", 200);
    insertBid(item2, "Mary Poppins", 350);

    // Find the highest bid for each item
    int highestBid1 = findHighestBid(item1);
    int highestBid2 = findHighestBid(item2);

    // Print the highest bid for each item
    printf("The highest bid for item1 is: %d\n", highestBid1);
    printf("The highest bid for item2 is: %d\n", highestBid2);

    return 0;
}