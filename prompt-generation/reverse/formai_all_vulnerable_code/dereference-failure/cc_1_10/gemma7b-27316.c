//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000

typedef struct Bidder {
    char name[256];
    int bid;
    struct Bidder *next;
} Bidder;

Bidder *createBidder(char *name, int bid) {
    Bidder *newBidder = malloc(sizeof(Bidder));
    strcpy(newBidder->name, name);
    newBidder->bid = bid;
    newBidder->next = NULL;
    return newBidder;
}

void addBidder(Bidder *head, Bidder *newBidder) {
    if (head == NULL) {
        head = newBidder;
    } else {
        head->next = newBidder;
        head = newBidder;
    }
}

int main() {
    Bidder *head = NULL;
    time_t tStart, tEnd;
    int i, maxBid = 0, currentBid = 0, winner = -1;

    tStart = time(NULL);

    // Simulate bidders and bids
    for (i = 0; i < 10; i++) {
        addBidder(head, createBidder("Bidder", rand() % MAX_BID));
    }

    // Start the auction
    currentBid = 0;
    while (currentBid < maxBid) {
        printf("Current bid: $%d\n", currentBid);
        printf("Enter your bid: ");
        scanf("%d", &maxBid);

        if (maxBid > currentBid) {
            currentBid = maxBid;
            winner = -1;
            for (head = head->next; head; head = head->next) {
                if (head->bid == currentBid) {
                    winner = head->name;
                }
            }

            if (winner != -1) {
                printf("Winner: %s\n", winner);
                printf("Congratulations, you won!\n");
            } else {
                printf("Error: invalid bid.\n");
            }
        }
    }

    tEnd = time(NULL);
    printf("Time elapsed: %ld seconds\n", tEnd - tStart);

    return 0;
}