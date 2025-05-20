//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000

typedef struct Bid {
    char name[20];
    int bid;
    struct Bid* next;
} Bid;

void insertBid(Bid* head, char* name, int bid) {
    Bid* newBid = (Bid*)malloc(sizeof(Bid));
    strcpy(newBid->name, name);
    newBid->bid = bid;
    newBid->next = NULL;

    if (head == NULL) {
        head = newBid;
    } else {
        head->next = newBid;
    }
}

int main() {

    Bid* head = NULL;
    int i = 0;
    char name[20];
    int bid;

    // Simulate a list of bids
    for (i = 0; i < 10; i++) {
        printf("Enter your name: ");
        scanf("%s", name);
        printf("Enter your bid: ");
        scanf("%d", &bid);
        insertBid(head, name, bid);
    }

    // Print the bids
    printf("Bids:\n");
    for (head = head->next; head; head = head->next) {
        printf("%s: %d\n", head->name, head->bid);
    }

    return 0;
}