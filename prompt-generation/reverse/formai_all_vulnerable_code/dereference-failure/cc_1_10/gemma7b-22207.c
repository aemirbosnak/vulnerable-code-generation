//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

typedef struct Bidder {
    char name[20];
    int bid;
    struct Bidder *next;
} Bidder;

void addBidder(Bidder *head, char *name, int bid) {
    Bidder *newBidder = malloc(sizeof(Bidder));
    strcpy(newBidder->name, name);
    newBidder->bid = bid;
    newBidder->next = NULL;

    if (head == NULL) {
        head = newBidder;
    } else {
        head->next = newBidder;
    }
}

void printBids(Bidder *head) {
    Bidder *current = head;
    while (current) {
        printf("%s: %d\n", current->name, current->bid);
        current = current->next;
    }
}

int main() {
    Bidder *head = NULL;
    time_t tStart, tEnd;

    tStart = time(NULL);

    // Simulate bidding
    addBidder(head, "John Doe", 500);
    addBidder(head, "Jane Doe", 600);
    addBidder(head, "Bill Gates", 800);

    printBids(head);

    tEnd = time(NULL);

    printf("Time taken: %ld seconds\n", tEnd - tStart);

    return 0;
}