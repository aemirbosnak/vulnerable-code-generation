//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10

struct Auction {
    char *name;
    int startPrice;
    int currentBid;
    int bidders;
    struct Auction *next;
};

void createAuction(struct Auction **head, char *name, int startPrice) {
    struct Auction *newAuction = malloc(sizeof(struct Auction));
    newAuction->name = strdup(name);
    newAuction->startPrice = startPrice;
    newAuction->currentBid = 0;
    newAuction->bidders = 0;
    newAuction->next = NULL;

    if (*head == NULL) {
        *head = newAuction;
    } else {
        (*head)->next = newAuction;
    }
}

void placeBid(struct Auction *auction, int bid) {
    if (bid > auction->currentBid) {
        auction->currentBid = bid;
        auction->bidders++;
    }
}

int main() {
    struct Auction *head = NULL;

    createAuction(&head, "iPhone", 1000);
    createAuction(&head, "Laptop", 2000);
    createAuction(&head, "Car", 3000);

    placeBid(head->next, 1500);
    placeBid(head->next, 1700);
    placeBid(head->next, 1800);

    printf("Auction name: %s, Current bid: %d, Number of bidders: %d\n", head->next->name, head->next->currentBid, head->next->bidders);

    return 0;
}