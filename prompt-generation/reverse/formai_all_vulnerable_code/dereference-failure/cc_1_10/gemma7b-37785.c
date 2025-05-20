//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 100000
#define MAX_LOT 10

struct Bid {
    char name[50];
    int amount;
    struct Bid* next;
};

struct Lot {
    char name[50];
    int reservePrice;
    struct Bid* highestBid;
    struct Lot* next;
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

void insertLot(struct Lot** head, char* name, int reservePrice) {
    struct Lot* newLot = (struct Lot*)malloc(sizeof(struct Lot));
    strcpy(newLot->name, name);
    newLot->reservePrice = reservePrice;
    newLot->highestBid = NULL;
    newLot->next = NULL;

    if (*head == NULL) {
        *head = newLot;
    } else {
        (*head)->next = newLot;
    }
}

int main() {
    struct Bid* headBid = NULL;
    struct Lot* headLot = NULL;

    insertLot(&headLot, "Apple", 100);
    insertLot(&headLot, "Banana", 200);
    insertLot(&headLot, "Orange", 300);

    insertBid(&headBid, "John", 50);
    insertBid(&headBid, "Alice", 70);
    insertBid(&headBid, "Bob", 80);

    // Auction begins
    printf("Auction begins...\n");

    // Bidding ends
    printf("Bidding ends...\n");

    // Results
    printf("Results:\n");

    for (struct Lot* lot = headLot; lot; lot++) {
        printf("Lot: %s, Reserve Price: %d, Highest Bid: %s, Highest Bid Amount: %d\n", lot->name, lot->reservePrice, lot->highestBid->name, lot->highestBid->amount);
    }

    return 0;
}