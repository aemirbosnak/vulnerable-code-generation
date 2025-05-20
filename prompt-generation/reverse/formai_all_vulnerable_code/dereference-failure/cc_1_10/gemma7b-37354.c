//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID_AMOUNT 10000
#define MAX_NUMBER_OF_BIDS 10

typedef struct Bid {
    char bidder_name[20];
    int bid_amount;
    struct Bid* next;
} Bid;

Bid* createBid(char* bidder_name, int bid_amount) {
    Bid* newBid = (Bid*)malloc(sizeof(Bid));
    strcpy(newBid->bidder_name, bidder_name);
    newBid->bid_amount = bid_amount;
    newBid->next = NULL;
    return newBid;
}

void addBid(Bid* head, char* bidder_name, int bid_amount) {
    Bid* newBid = createBid(bidder_name, bid_amount);
    if (head == NULL) {
        head = newBid;
    } else {
        newBid->next = head;
        head = newBid;
    }
}

int compareBids(Bid* bid1, Bid* bid2) {
    return bid1->bid_amount - bid2->bid_amount;
}

int main() {
    Bid* head = NULL;
    char bidder_name[20];
    int bid_amount;

    // Generate some bids
    addBid(head, "John Doe", 5000);
    addBid(head, "Jane Doe", 6000);
    addBid(head, "Bill Smith", 7000);
    addBid(head, "Alice White", 8000);

    // Sort the bids in descending order
    qsort(head, MAX_NUMBER_OF_BIDS, sizeof(Bid), compareBids);

    // Print the sorted bids
    printf("Sorted bids:\n");
    for (Bid* currentBid = head; currentBid; currentBid = currentBid->next) {
        printf("%s bidded %d\n", currentBid->bidder_name, currentBid->bid_amount);
    }

    return 0;
}