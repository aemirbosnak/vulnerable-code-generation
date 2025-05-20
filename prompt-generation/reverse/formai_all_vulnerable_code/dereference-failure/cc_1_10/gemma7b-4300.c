//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 10000

typedef struct Bidder {
    char name[50];
    int bid;
    struct Bidder* next;
} Bidder;

Bidder* addBidder(Bidder* head, char* name, int bid) {
    Bidder* newBidder = (Bidder*)malloc(sizeof(Bidder));
    strcpy(newBidder->name, name);
    newBidder->bid = bid;
    newBidder->next = NULL;

    if (head == NULL) {
        head = newBidder;
    } else {
        head->next = newBidder;
    }

    return head;
}

int main() {
    Bidder* head = NULL;

    // Simulate some bidders
    addBidder(head, "John Doe", 5000);
    addBidder(head, "Jane Doe", 6000);
    addBidder(head, "Bill Smith", 7000);
    addBidder(head, "Mary Johnson", 8000);

    // Start the auction
    printf("Welcome to the digital auction!\n");

    // Get the highest bid
    Bidder* highestBidder = head;
    for (Bidder* bidder = head; bidder; bidder = bidder->next) {
        if (highestBidder->bid < bidder->bid) {
            highestBidder = bidder;
        }
    }

    // Announce the winner
    printf("The winner of the auction is: %s with a bid of %d.\n", highestBidder->name, highestBidder->bid);

    return 0;
}