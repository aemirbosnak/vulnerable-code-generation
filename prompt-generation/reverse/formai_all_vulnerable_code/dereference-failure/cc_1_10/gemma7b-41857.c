//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_BIDS 10

typedef struct Bid {
    char name[20];
    int amount;
    struct Bid* next;
} Bid;

Bid* createBid(char* name, int amount) {
    Bid* newBid = (Bid*)malloc(sizeof(Bid));
    strcpy(newBid->name, name);
    newBid->amount = amount;
    newBid->next = NULL;
    return newBid;
}

void addBid(Bid* head, Bid* newBid) {
    if (head == NULL) {
        head = newBid;
    } else {
        newBid->next = head;
        head = newBid;
    }
}

int main() {
    Bid* head = NULL;
    char name[20];
    int amount;

    // Simulate a bidding process
    for (int i = 0; i < MAX_BIDS; i++) {
        printf("Enter your name: ");
        scanf("%s", name);

        printf("Enter your bid: ");
        scanf("%d", &amount);

        Bid* newBid = createBid(name, amount);
        addBid(head, newBid);
    }

    // Print the bids
    printf("Bids:\n");
    for (Bid* currentBid = head; currentBid; currentBid = currentBid->next) {
        printf("%s: %d\n", currentBid->name, currentBid->amount);
    }

    return 0;
}