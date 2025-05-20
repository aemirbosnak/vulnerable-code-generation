//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a bidder
typedef struct bidder {
    char name[20];
    int bid;
    struct bidder* next;
} bidder;

// Function to insert a bidder into a linked list
void insertBidder(bidder** head, char* name, int bid) {
    bidder* newBidder = (bidder*)malloc(sizeof(bidder));
    strcpy(newBidder->name, name);
    newBidder->bid = bid;
    newBidder->next = NULL;

    if (*head == NULL) {
        *head = newBidder;
    } else {
        (*head)->next = newBidder;
    }
}

// Function to find the highest bidder
bidder* findHighestBidder(bidder* head) {
    bidder* highestBidder = NULL;
    for (bidder* currentBidder = head; currentBidder; currentBidder = currentBidder->next) {
        if (highestBidder == NULL || currentBidder->bid > highestBidder->bid) {
            highestBidder = currentBidder;
        }
    }
    return highestBidder;
}

// Function to conduct the auction
void conductAuction(int item_id) {
    // Create a linked list of bidders
    bidder* head = NULL;

    // Get the bids from the bidders
    for (int i = 0; i < 10; i++) {
        char name[20];
        int bid;
        printf("Enter your name: ");
        scanf("%s", name);
        printf("Enter your bid: ");
        scanf("%d", &bid);
        insertBidder(&head, name, bid);
    }

    // Find the highest bidder
    bidder* highestBidder = findHighestBidder(head);

    // Announce the highest bidder
    printf("The highest bidder is: %s with a bid of %d", highestBidder->name, highestBidder->bid);

    // Award the item to the highest bidder
    printf("Item %d has been awarded to %s", item_id, highestBidder->name);
}

int main() {
    conductAuction(1);
    return 0;
}