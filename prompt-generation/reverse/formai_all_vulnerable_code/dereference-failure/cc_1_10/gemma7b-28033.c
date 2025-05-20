//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of bidders
#define MAX_BIDDERS 10

// Define the structure of a bidder
typedef struct Bidder {
    char name[20];
    int bid;
    struct Bidder *next;
} Bidder;

// Function to insert a bidder into the linked list
void insertBidder(Bidder **head, Bidder *newBidder) {
    if (*head == NULL) {
        *head = newBidder;
    } else {
        (*head)->next = newBidder;
        *head = newBidder;
    }
}

// Function to find the highest bidder
Bidder *findHighestBidder(Bidder *head) {
    Bidder *highestBidder = NULL;
    while (head) {
        if (highestBidder == NULL || head->bid > highestBidder->bid) {
            highestBidder = head;
        }
        head = head->next;
    }
    return highestBidder;
}

// Function to conduct the auction
void conductAuction(Bidder **head) {
    // Get the highest bidder
    Bidder *highestBidder = findHighestBidder(*head);

    // Announce the highest bidder
    printf("The highest bidder is: %s with a bid of %d\n", highestBidder->name, highestBidder->bid);
}

int main() {
    // Create a linked list of bidders
    Bidder *head = NULL;

    // Insert some bidders
    insertBidder(&head, malloc(sizeof(Bidder)));
    strcpy(head->name, "John Doe");
    head->bid = 100;

    insertBidder(&head, malloc(sizeof(Bidder)));
    strcpy(head->name, "Jane Doe");
    head->bid = 120;

    insertBidder(&head, malloc(sizeof(Bidder)));
    strcpy(head->name, "Peter Pan");
    head->bid = 140;

    // Conduct the auction
    conductAuction(&head);

    return 0;
}