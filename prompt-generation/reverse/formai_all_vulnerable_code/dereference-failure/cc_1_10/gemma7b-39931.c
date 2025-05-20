//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_BID 10000

struct Bidder {
    char name[50];
    int bid;
    struct Bidder* next;
};

struct Item {
    char name[50];
    int reservePrice;
    struct Bidder* highestBidder;
    struct Item* next;
};

void insertBidder(struct Bidder** head, char* name, int bid) {
    struct Bidder* newNode = (struct Bidder*)malloc(sizeof(struct Bidder));
    strcpy(newNode->name, name);
    newNode->bid = bid;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void insertItem(struct Item** head, char* name, int reservePrice) {
    struct Item* newNode = (struct Item*)malloc(sizeof(struct Item));
    strcpy(newNode->name, name);
    newNode->reservePrice = reservePrice;
    newNode->highestBidder = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void startAuction(struct Item* item) {
    struct Bidder* highestBidder = item->highestBidder;
    int currentBid = highestBidder->bid;

    printf("Auction for item: %s\n", item->name);
    printf("Current bid: $%d\n", currentBid);

    // Get the new bid from the user
    int newBid = 0;
    printf("Enter your bid: ");
    scanf("%d", &newBid);

    // Check if the new bid is valid
    if (newBid < currentBid || newBid > MAX_BID) {
        printf("Invalid bid.\n");
    } else {
        // Update the highest bidder
        highestBidder->bid = newBid;

        // Check if the new bid is the highest bid
        if (newBid > currentBid) {
            printf("Congratulations, you are the highest bidder!\n");
            printf("Your bid: $%d\n", highestBidder->bid);
        }
    }
}

int main() {
    struct Item* itemHead = NULL;
    struct Bidder* bidderHead = NULL;

    insertItem(&itemHead, "Laptop", 1000);
    insertBidder(&bidderHead, "John Doe", 800);
    insertBidder(&bidderHead, "Jane Doe", 900);

    startAuction(itemHead);

    return 0;
}