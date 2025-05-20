//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BID 10000

struct Bidder {
    char name[20];
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
    struct Bidder *newBidder = malloc(sizeof(struct Bidder));
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
    struct AuctionItem *newItem = malloc(sizeof(struct AuctionItem));
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
    struct Bidder *head = NULL;
    struct AuctionItem *items = NULL;

    insertBidder(&head, "John Doe", 5000);
    insertBidder(&head, "Jane Doe", 4000);
    insertBidder(&head, "Peter Pan", 3000);

    insertAuctionItem(&items, "Gold Coin", 1000);
    insertAuctionItem(&items, "Diamond Ring", 2000);
    insertAuctionItem(&items, "Silver Sword", 3000);

    // Auction begins
    printf("Welcome to the digital auction!\n");

    for (struct AuctionItem *item = items; item != NULL; item++) {
        printf("Item: %s, Reserve Price: %d\n", item->name, item->reservePrice);

        for (struct Bidder *bidder = head; bidder != NULL; bidder++) {
            if (bidder->bid > item->reservePrice) {
                printf("Bidder: %s, Bid: %d\n", bidder->name, bidder->bid);
            }
        }

        printf("\n");
    }

    return 0;
}