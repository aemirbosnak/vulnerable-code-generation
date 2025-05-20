//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

typedef struct Bidder {
    char name[50];
    int bid;
    struct Bidder* next;
} Bidder;

void placeBid(Bidder** head, int amount) {
    Bidder* newBidder = malloc(sizeof(Bidder));
    strcpy(newBidder->name, "Bob");
    newBidder->bid = amount;
    newBidder->next = NULL;

    if (*head == NULL) {
        *head = newBidder;
    } else {
        (*head)->next = newBidder;
    }
}

void printBids(Bidder* head) {
    while (head) {
        printf("%s: %d\n", head->name, head->bid);
        head = head->next;
    }
}

int main() {
    Bidder* head = NULL;

    // Simulate some bids
    placeBid(&head, 100);
    placeBid(&head, 200);
    placeBid(&head, 300);
    placeBid(&head, 400);
    placeBid(&head, 500);

    // Print all bids
    printBids(head);

    // Find the winner
    Bidder* winner = head;
    for (winner = head; winner->next; winner = winner->next) {
        if (winner->bid > winner->next->bid) {
            winner = winner->next;
        }
    }

    // Announce the winner
    printf("The winner is: %s with a bid of %d\n", winner->name, winner->bid);

    return 0;
}