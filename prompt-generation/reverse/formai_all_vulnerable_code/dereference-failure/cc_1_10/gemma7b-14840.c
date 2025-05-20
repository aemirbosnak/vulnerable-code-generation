//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

typedef struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
} Bidder;

void createBidder(Bidder** head) {
    *head = malloc(sizeof(Bidder));
    (*head)->name[0] = '\0';
    (*head)->bid = 0;
    (*head)->next = NULL;
}

void addBidder(Bidder* head, char* name, int bid) {
    Bidder* newBidder = malloc(sizeof(Bidder));
    newBidder->name[0] = '\0';
    newBidder->bid = bid;
    newBidder->next = NULL;

    if (head == NULL) {
        head = newBidder;
    } else {
        head->next = newBidder;
        head = newBidder;
    }
}

void printBidders(Bidder* head) {
    while (head) {
        printf("%s: %d\n", head->name, head->bid);
        head = head->next;
    }
}

int main() {
    Bidder* bidders = NULL;

    // Create a few bidders
    createBidder(&bidders);
    addBidder(bidders, "John Doe", 5000);
    addBidder(bidders, "Jane Doe", 4000);
    addBidder(bidders, "Bill Smith", 3000);

    // Print the bidders
    printBidders(bidders);

    return 0;
}