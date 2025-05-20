//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 10000

struct Bid {
    char *name;
    int amount;
    struct Bid *next;
};

void addBid(struct Bid **head, char *name, int amount) {
    struct Bid *newBid = malloc(sizeof(struct Bid));
    newBid->name = strdup(name);
    newBid->amount = amount;
    newBid->next = NULL;

    if (*head == NULL) {
        *head = newBid;
    } else {
        (*head)->next = newBid;
    }
}

int compareBids(struct Bid *bid1, struct Bid *bid2) {
    return bid1->amount - bid2->amount;
}

void printBids(struct Bid *head) {
    struct Bid *currentBid = head;
    while (currentBid) {
        printf("%s: %d\n", currentBid->name, currentBid->amount);
        currentBid = currentBid->next;
    }
}

int main() {
    struct Bid *head = NULL;

    // Add bids
    addBid(&head, "John Doe", 5000);
    addBid(&head, "Jane Doe", 6000);
    addBid(&head, "Peter Pan", 7000);

    // Print bids
    printBids(head);

    // Compare bids
    int comparisonResult = compareBids(head->next, head);
    printf("Comparison result: %d\n", comparisonResult);

    return 0;
}