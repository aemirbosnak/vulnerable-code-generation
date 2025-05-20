//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000

typedef struct Bid {
    char name[255];
    int amount;
    struct Bid* next;
} Bid;

Bid* createBid(char* name, int amount) {
    Bid* newBid = malloc(sizeof(Bid));
    strcpy(newBid->name, name);
    newBid->amount = amount;
    newBid->next = NULL;
    return newBid;
}

void insertBid(Bid* head, Bid* newBid) {
    if (head == NULL) {
        head = newBid;
    } else {
        newBid->next = head;
        head = newBid;
    }
}

int main() {
    Bid* head = NULL;
    time_t start, end;

    // Start the timer
    start = time(NULL);

    // Simulate bidding
    insertBid(head, createBid("John Doe", 5000));
    insertBid(head, createBid("Jane Doe", 6000));
    insertBid(head, createBid("Bill Smith", 7000));
    insertBid(head, createBid("Mary Johnson", 8000));

    // End the timer
    end = time(NULL);

    // Print the results
    printf("Total time: %ld seconds\n", end - start);

    // Print the bids
    printf("Bids:\n");
    for (Bid* currentBid = head; currentBid; currentBid = currentBid->next) {
        printf("%s: %d\n", currentBid->name, currentBid->amount);
    }

    return 0;
}