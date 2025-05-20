//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 1000

typedef struct Bid {
    char name[20];
    int bid;
    struct Bid* next;
} Bid;

void createBid(Bid** head) {
    *head = (Bid*)malloc(sizeof(Bid));
    (*head)->name[0] = '\0';
    (*head)->bid = 0;
    (*head)->next = NULL;
}

void addBid(Bid** head, char* name, int bid) {
    Bid* newBid = (Bid*)malloc(sizeof(Bid));
    strcpy(newBid->name, name);
    newBid->bid = bid;
    newBid->next = NULL;

    if (*head == NULL) {
        *head = newBid;
    } else {
        (*head)->next = newBid;
        *head = newBid;
    }
}

void printBids(Bid* head) {
    while (head) {
        printf("%s: %d\n", head->name, head->bid);
        head = head->next;
    }
}

int main() {

    Bid* bids = NULL;

    // Simulate some bids
    addBid(&bids, "John Doe", 500);
    addBid(&bids, "Jane Doe", 600);
    addBid(&bids, "Bill Smith", 700);

    // Print the bids
    printBids(bids);

    // Find the highest bid
    Bid* highestBid = bids;
    while (highestBid->next) {
        if (highestBid->bid < highestBid->next->bid) {
            highestBid = highestBid->next;
        }
    }

    // Print the highest bid
    printf("The highest bid is: %s: %d\n", highestBid->name, highestBid->bid);

    return 0;
}