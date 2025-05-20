//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

struct Bidder {
    char name[20];
    int bid;
    struct Bidder *next;
};

struct Auction {
    char item[50];
    int reservePrice;
    struct Bidder *highestBidder;
    struct Auction *next;
};

void insertBidder(struct Bidder **head, char *name, int bid) {
    struct Bidder *newBidder = (struct Bidder *)malloc(sizeof(struct Bidder));
    strcpy(newBidder->name, name);
    newBidder->bid = bid;
    newBidder->next = NULL;

    if (*head == NULL) {
        *head = newBidder;
    } else {
        (*head)->next = newBidder;
    }
}

void insertAuction(struct Auction **head, char *item, int reservePrice) {
    struct Auction *newAuction = (struct Auction *)malloc(sizeof(struct Auction));
    strcpy(newAuction->item, item);
    newAuction->reservePrice = reservePrice;
    newAuction->highestBidder = NULL;
    newAuction->next = NULL;

    if (*head == NULL) {
        *head = newAuction;
    } else {
        (*head)->next = newAuction;
    }
}

int main() {
    struct Bidder *head = NULL;
    struct Auction *headA = NULL;

    insertBidder(&head, "John Doe", 500);
    insertBidder(&head, "Jane Doe", 400);
    insertBidder(&head, "Jack Doe", 300);

    insertAuction(&headA, "Car", 10000);
    insertAuction(&headA, "Bike", 8000);

    // Bidding starts
    printf("Enter your name: ");
    char name[20];
    scanf("%s", name);

    printf("Enter your bid: ");
    int bid;
    scanf("%d", &bid);

    insertBidder(&head, name, bid);

    // Auction ends

    // Display results
    printf("The highest bidder is: %s", head->name);
    printf("The highest bid is: %d", head->bid);

    return 0;
}