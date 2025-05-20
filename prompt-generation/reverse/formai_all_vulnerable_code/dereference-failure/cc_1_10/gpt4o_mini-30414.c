//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bidder {
    char name[100];
    float bidAmount;
    struct Bidder *next;
} Bidder;

typedef struct AuctionItem {
    char itemName[100];
    float startingBid;
    Bidder *bidders;
    struct AuctionItem *next;
} AuctionItem;

AuctionItem *createAuctionItem(const char *itemName, float startingBid) {
    AuctionItem *item = (AuctionItem *)malloc(sizeof(AuctionItem));
    strcpy(item->itemName, itemName);
    item->startingBid = startingBid;
    item->bidders = NULL;
    item->next = NULL;
    return item;
}

Bidder *createBidder(const char *name, float bidAmount) {
    Bidder *bidder = (Bidder *)malloc(sizeof(Bidder));
    strcpy(bidder->name, name);
    bidder->bidAmount = bidAmount;
    bidder->next = NULL;
    return bidder;
}

void addBid(AuctionItem *item, const char *bidderName, float bidAmount) {
    Bidder *newBidder = createBidder(bidderName, bidAmount);
    newBidder->next = item->bidders;
    item->bidders = newBidder;
}

void displayAuctionItem(AuctionItem *item) {
    printf("Item Name: %s\n", item->itemName);
    printf("Starting Bid: %.2f\n", item->startingBid);

    if (item->bidders != NULL) {
        printf("Bidders:\n");
        Bidder *current = item->bidders;
        while (current != NULL) {
            printf("Bidder: %s, Bid Amount: %.2f\n", current->name, current->bidAmount);
            current = current->next;
        }
    } else {
        printf("No bids placed yet.\n");
    }
    printf("\n");
}

void freeAuctionItems(AuctionItem *head) {
    AuctionItem *currentItem = head;
    while (currentItem != NULL) {
        Bidder *currentBidder = currentItem->bidders;
        while (currentBidder != NULL) {
            Bidder *tempBidder = currentBidder;
            currentBidder = currentBidder->next;
            free(tempBidder);
        }
        AuctionItem *tempItem = currentItem;
        currentItem = currentItem->next;
        free(tempItem);
    }
}

int main() {
    AuctionItem *auctionList = NULL;
    AuctionItem *lastItem = NULL;
    char itemName[100];
    float startingBid;
    char bidderName[100];
    float bidAmount;
    char choice;

    printf("Welcome to the Digital Auction System!\n");

    do {
        printf("Enter auction item name: ");
        scanf(" %[^\n]%*c", itemName);
        printf("Enter starting bid for %s: ", itemName);
        scanf("%f", &startingBid);

        AuctionItem *newItem = createAuctionItem(itemName, startingBid);
        if (auctionList == NULL) {
            auctionList = newItem;
        } else {
            lastItem->next = newItem;
        }
        lastItem = newItem;

        printf("Would you like to add a bid to this item? (y/n): ");
        scanf(" %c", &choice);
        while (choice == 'y') {
            printf("Enter your name: ");
            scanf(" %[^\n]%*c", bidderName);
            printf("Enter your bid amount: ");
            scanf("%f", &bidAmount);
            
            addBid(newItem, bidderName, bidAmount);

            printf("Would you like to add another bid? (y/n): ");
            scanf(" %c", &choice);
        }

        printf("Would you like to add another auction item? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    printf("\nAuction Items Summary:\n");
    AuctionItem *currentItem = auctionList;
    while (currentItem != NULL) {
        displayAuctionItem(currentItem);
        currentItem = currentItem->next;
    }

    freeAuctionItems(auctionList);
    
    printf("Thank you for using the Digital Auction System!\n");
    return 0;
}