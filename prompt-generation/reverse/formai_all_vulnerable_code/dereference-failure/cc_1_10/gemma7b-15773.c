//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of bidders
#define MAX_BIDDERS 10

// Define the structure of a bidder
typedef struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
} Bidder;

// Function to create a new bidder
Bidder* createBidder(char* name, int bid) {
    Bidder* newBidder = (Bidder*)malloc(sizeof(Bidder));
    strcpy(newBidder->name, name);
    newBidder->bid = bid;
    newBidder->next = NULL;
    return newBidder;
}

// Function to compare two bidders
int compareBidders(Bidder* a, Bidder* b) {
    return a->bid - b->bid;
}

// Function to auction an item
void auctionItem(char* item) {
    // Create a list of bidders
    Bidder* bidders = NULL;

    // Get the bids from the bidders
    for (int i = 0; i < MAX_BIDDERS; i++) {
        char name[20];
        int bid;

        printf("Enter your name: ");
        scanf("%s", name);

        printf("Enter your bid: ");
        scanf("%d", &bid);

        // Create a new bidder
        Bidder* newBidder = createBidder(name, bid);

        // Add the new bidder to the list
        if (bidders == NULL) {
            bidders = newBidder;
        } else {
            newBidder->next = bidders;
            bidders = newBidder;
        }
    }

    // Sort the bidders by bid
    qsort(bidders, MAX_BIDDERS, sizeof(Bidder), compareBidders);

    // Print the winning bidder
    printf("The winner is: %s with a bid of %d\n", bidders->name, bidders->bid);
}

int main() {
    auctionItem("Car");
    return 0;
}