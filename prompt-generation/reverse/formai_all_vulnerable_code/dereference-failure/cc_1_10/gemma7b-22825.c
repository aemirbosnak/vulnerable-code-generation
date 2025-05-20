//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

typedef struct Bidder {
    char name[50];
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

void printBids(Bidder* head) {
    while (head) {
        printf("%s: %d\n", head->name, head->bid);
        head = head->next;
    }
}

int main() {
    Bidder* head = NULL;

    // Simulate some bids
    insertBidder(&head, "John Doe", 5000);
    insertBidder(&head, "Jane Doe", 6000);
    insertBidder(&head, "Bill Smith", 7000);

    // Print all bids
    printBids(head);

    // Find the highest bidder
    Bidder* highestBidder = head;
    while (highestBidder->next) {
        if (highestBidder->bid < highestBidder->next->bid) {
            highestBidder = highestBidder->next;
        }
    }

    // Print the highest bidder
    printf("The highest bidder is: %s with a bid of %d\n", highestBidder->name, highestBidder->bid);

    return 0;
}