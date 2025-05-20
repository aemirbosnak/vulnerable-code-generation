//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 10000

typedef struct Bid {
    char bidder[20];
    int amount;
    struct Bid* next;
} Bid;

Bid* insertBid(Bid* head, char* bidder, int amount) {
    Bid* newBid = malloc(sizeof(Bid));
    strcpy(newBid->bidder, bidder);
    newBid->amount = amount;
    newBid->next = NULL;

    if (head == NULL) {
        head = newBid;
    } else {
        head->next = newBid;
    }

    return head;
}

void printBids(Bid* head) {
    while (head) {
        printf("%s: %d\n", head->bidder, head->amount);
        head = head->next;
    }
}

int main() {
    Bid* head = NULL;

    // Insert bids
    insertBid(head, "John Doe", 5000);
    insertBid(head, "Jane Doe", 6000);
    insertBid(head, "Bill Smith", 7000);

    // Print bids
    printBids(head);

    // Check for highest bid
    Bid* highestBid = head;
    for (Bid* currentBid = head; currentBid; currentBid = currentBid->next) {
        if (currentBid->amount > highestBid->amount) {
            highestBid = currentBid;
        }
    }

    // Print highest bid
    printf("Highest bid: %s: %d\n", highestBid->bidder, highestBid->amount);

    return 0;
}