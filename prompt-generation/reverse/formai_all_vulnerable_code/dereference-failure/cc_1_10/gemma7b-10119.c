//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

typedef struct Bidder {
    char name[50];
    int bid;
    struct Bidder *next;
} Bidder;

void createBidder(Bidder **head) {
    *head = malloc(sizeof(Bidder));
    (*head)->name[0] = '\0';
    (*head)->bid = 0;
    (*head)->next = NULL;
}

void addBidder(Bidder *head, char *name, int bid) {
    Bidder *newBidder = malloc(sizeof(Bidder));
    newBidder->name[0] = '\0';
    newBidder->bid = 0;
    newBidder->next = NULL;

    strcpy(newBidder->name, name);
    newBidder->bid = bid;

    if (head == NULL) {
        head = newBidder;
    } else {
        head->next = newBidder;
        head = newBidder;
    }
}

void printBidders(Bidder *head) {
    while (head) {
        printf("%s: %d\n", head->name, head->bid);
        head = head->next;
    }
}

void auction(Bidder *head) {
    int highBid = 0;
    Bidder *winner = NULL;

    for (Bidder *bidder = head; bidder; bidder = bidder->next) {
        if (bidder->bid > highBid) {
            highBid = bidder->bid;
            winner = bidder;
        }
    }

    if (winner) {
        printf("Congratulations, %s! You won the auction with a bid of %d.\n", winner->name, winner->bid);
    } else {
        printf("No bids were received.\n");
    }
}

int main() {
    Bidder *head = NULL;

    createBidder(&head);
    addBidder(head, "John Doe", 500);
    addBidder(head, "Jane Doe", 600);
    addBidder(head, "Bill Smith", 700);

    auction(head);

    printBidders(head);

    return 0;
}