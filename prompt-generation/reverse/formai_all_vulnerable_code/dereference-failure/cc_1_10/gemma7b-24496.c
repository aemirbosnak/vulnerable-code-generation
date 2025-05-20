//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 1000

typedef struct Bidder {
    char name[50];
    int bid;
    struct Bidder* next;
} Bidder;

Bidder* insertBidder(Bidder* head, char* name, int bid) {
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

int findHighestBid(Bidder* head) {
    if (head == NULL) {
        return 0;
    }

    Bidder* current = head;
    int highestBid = current->bid;

    while (current->next) {
        current = current->next;
        if (current->bid > highestBid) {
            highestBid = current->bid;
        }
    }

    return highestBid;
}

int main() {
    Bidder* head = NULL;

    // Insert bidders
    insertBidder(head, "John Doe", 500);
    insertBidder(head, "Jane Doe", 600);
    insertBidder(head, "Bob Smith", 700);
    insertBidder(head, "Alice White", 800);

    // Find the highest bid
    int highestBid = findHighestBid(head);

    // Print the highest bid
    printf("The highest bid is: $%d", highestBid);

    return 0;
}