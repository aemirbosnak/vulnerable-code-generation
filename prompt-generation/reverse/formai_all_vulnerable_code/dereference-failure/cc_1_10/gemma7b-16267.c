//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 1000

struct Bidder {
    char name[50];
    int bid;
    struct Bidder *next;
};

struct AuctionItem {
    char name[50];
    int reservePrice;
    struct Bidder *highestBidder;
    struct AuctionItem *next;
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

void insertAuctionItem(struct AuctionItem **head, char *name, int reservePrice) {
    struct AuctionItem *newItem = (struct AuctionItem *)malloc(sizeof(struct AuctionItem));
    strcpy(newItem->name, name);
    newItem->reservePrice = reservePrice;
    newItem->highestBidder = NULL;
    newItem->next = NULL;

    if (*head == NULL) {
        *head = newItem;
    } else {
        (*head)->next = newItem;
    }
}

int main() {
    struct Bidder *headBidder = NULL;
    struct AuctionItem *headItem = NULL;

    insertBidder(&headBidder, "John Doe", 500);
    insertBidder(&headBidder, "Jane Doe", 600);
    insertBidder(&headBidder, "Peter Pan", 700);

    insertAuctionItem(&headItem, "Diamond Ring", 1000);
    insertAuctionItem(&headItem, "Gold Watch", 800);
    insertAuctionItem(&headItem, "Silver Chain", 900);

    // Auction begins
    printf("Enter your name: ");
    char bidderName[50];
    scanf("%s", bidderName);

    printf("Enter your bid: ");
    int bidAmount;
    scanf("%d", &bidAmount);

    struct Bidder *currentBidder = headBidder;
    struct AuctionItem *currentItem = headItem;

    while (currentBidder && currentItem) {
        if (strcmp(currentBidder->name, bidderName) == 0) {
            if (currentBidder->bid > bidAmount) {
                printf("Your bid is too low. Please try again.\n");
                return 0;
            }
        }

        if (currentItem->reservePrice > bidAmount) {
            printf("The item is not within your budget. Please try another item.\n");
            return 0;
        }

        currentBidder = currentBidder->next;
        currentItem = currentItem->next;
    }

    // Auction ends
    printf("Congratulations! You have won the auction.\n");

    return 0;
}