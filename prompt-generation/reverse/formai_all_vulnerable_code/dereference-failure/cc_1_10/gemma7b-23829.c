//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

typedef struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
} Bidder;

void insertBidder(Bidder** head, char* name, int bid) {
    Bidder* newBidder = (Bidder*)malloc(sizeof(Bidder));
    strcpy(newBidder->name, name);
    newBidder->bid = bid;
    newBidder->next = NULL;

    if (*head == NULL) {
        *head = newBidder;
    } else {
        (*head)->next = newBidder;
    }
}

void printBidders(Bidder* head) {
    while (head) {
        printf("%s: %d\n", head->name, head->bid);
        head = head->next;
    }
}

void auction(Bidder** head) {
    int highestBid = 0;
    Bidder* winner = NULL;

    for (Bidder* currentBidder = *head; currentBidder; currentBidder = currentBidder->next) {
        if (currentBidder->bid > highestBid) {
            highestBid = currentBidder->bid;
            winner = currentBidder;
        }
    }

    if (winner) {
        printf("Congratulations, %s! You won the auction with a bid of %d!\n", winner->name, winner->bid);
    } else {
        printf("No bidders. Please try again later.\n");
    }
}

int main() {
    Bidder* bidders = NULL;

    insertBidder(&bidders, "John Doe", 5000);
    insertBidder(&bidders, "Jane Doe", 3000);
    insertBidder(&bidders, "Bill Smith", 2000);
    insertBidder(&bidders, "Mary Johnson", 4000);

    auction(&bidders);

    printBidders(bidders);

    return 0;
}