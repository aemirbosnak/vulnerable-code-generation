//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a bidder
typedef struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
} Bidder;

// Function to insert a bidder into the linked list
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

// Function to find the highest bidder
Bidder* findHighestBidder(Bidder* head) {
    Bidder* highestBidder = NULL;
    for (Bidder* currentBidder = head; currentBidder; currentBidder = currentBidder->next) {
        if (highestBidder == NULL || currentBidder->bid > highestBidder->bid) {
            highestBidder = currentBidder;
        }
    }
    return highestBidder;
}

int main() {
    // Create a linked list of bidders
    Bidder* bidders = NULL;

    // Insert some bidders
    insertBidder(&bidders, "John Doe", 100);
    insertBidder(&bidders, "Jane Doe", 200);
    insertBidder(&bidders, "Bill Smith", 300);

    // Find the highest bidder
    Bidder* highestBidder = findHighestBidder(bidders);

    // Print the highest bidder
    printf("The highest bidder is: %s with a bid of %d", highestBidder->name, highestBidder->bid);

    return 0;
}