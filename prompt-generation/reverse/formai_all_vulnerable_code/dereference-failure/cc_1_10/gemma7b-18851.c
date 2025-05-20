//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: protected
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_BID 10000

typedef struct Bidder {
    char name[20];
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

int main() {
    Bidder* head = NULL;
    int i = 0;
    char name[20];
    int bid;

    // Simulate bidders
    for (i = 0; i < 5; i++) {
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter bid: ");
        scanf("%d", &bid);
        insertBidder(&head, name, bid);
    }

    // Print bidders
    printf("Bidders:");
    for (Bidder* current = head; current; current = current->next) {
        printf("\nName: %s", current->name);
        printf("Bid: %d", current->bid);
    }

    return 0;
}