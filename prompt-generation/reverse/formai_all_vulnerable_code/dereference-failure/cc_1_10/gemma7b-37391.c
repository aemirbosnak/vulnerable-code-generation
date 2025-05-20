//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 1000

// Define a structure for a bid
typedef struct Bid {
    char bidder[20];
    int amount;
    struct Bid* next;
} Bid;

// Function to insert a bid into the linked list
void insertBid(Bid** head, char* bidder, int amount) {
    Bid* newBid = (Bid*)malloc(sizeof(Bid));
    strcpy(newBid->bidder, bidder);
    newBid->amount = amount;
    newBid->next = NULL;

    if (*head == NULL) {
        *head = newBid;
    } else {
        (*head)->next = newBid;
    }
}

// Function to find the highest bid
int findHighestBid(Bid* head) {
    if (head == NULL) {
        return 0;
    }

    Bid* currentBid = head;
    int highestBid = currentBid->amount;

    while (currentBid->next) {
        currentBid = currentBid->next;
        if (currentBid->amount > highestBid) {
            highestBid = currentBid->amount;
        }
    }

    return highestBid;
}

int main() {
    // Create a linked list of bids
    Bid* bids = NULL;

    // Insert some bids
    insertBid(&bids, "John Doe", 500);
    insertBid(&bids, "Jane Doe", 600);
    insertBid(&bids, "Peter Pan", 700);

    // Find the highest bid
    int highestBid = findHighestBid(bids);

    // Print the highest bid
    printf("The highest bid is: %d", highestBid);

    return 0;
}