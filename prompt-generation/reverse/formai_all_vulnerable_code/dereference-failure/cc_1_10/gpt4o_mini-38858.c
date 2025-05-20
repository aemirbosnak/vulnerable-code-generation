//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bid {
    char bidder[50];
    float amount;
    struct Bid *next;
} Bid;

typedef struct Auction {
    char item[100];
    float startingPrice;
    Bid *bids;
    float highestBid;
    char highestBidder[50];
    struct Auction *next;
} Auction;

Auction *auctionList = NULL;

Auction *createAuction(char *item, float startingPrice) {
    Auction *newAuction = (Auction *)malloc(sizeof(Auction));
    strcpy(newAuction->item, item);
    newAuction->startingPrice = startingPrice;
    newAuction->bids = NULL;
    newAuction->highestBid = startingPrice;
    strcpy(newAuction->highestBidder, "None");
    newAuction->next = NULL;
    return newAuction;
}

void addAuction(Auction *auction) {
    auction->next = auctionList;
    auctionList = auction;
}

void placeBid(char *item, char *bidder, float bidAmount) {
    Auction *current = auctionList;
    while (current != NULL) {
        if (strcmp(current->item, item) == 0) {
            if (bidAmount > current->highestBid) {
                Bid *newBid = (Bid *)malloc(sizeof(Bid));
                strcpy(newBid->bidder, bidder);
                newBid->amount = bidAmount;
                newBid->next = current->bids;
                current->bids = newBid;

                current->highestBid = bidAmount;
                strcpy(current->highestBidder, bidder);
                printf("Bid placed successfully!\n");
            } else {
                printf("Bid amount must be higher than the current highest bid of %.2f.\n", current->highestBid);
            }
            return;
        }
        current = current->next;
    }
    printf("Auction for item '%s' not found.\n", item);
}

void displayAuctions() {
    Auction *current = auctionList;
    printf("\n--- Current Auctions ---\n");
    while (current != NULL) {
        printf("Item: %s | Starting Price: %.2f | Highest Bid: %.2f by %s\n",
               current->item, current->startingPrice, current->highestBid, current->highestBidder);
        current = current->next;
    }
    printf("------------------------\n");
}

void deleteAuction(char *item) {
    Auction *current = auctionList;
    Auction *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->item, item) == 0) {
            if (previous == NULL) {
                auctionList = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Auction for item '%s' has been deleted.\n", item);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Auction for item '%s' not found.\n", item);
}

void freeAuctions() {
    Auction *current = auctionList;
    while (current != NULL) {
        Auction *temp = current;
        current = current->next;
        free(temp);
    }
    auctionList = NULL;
}

int main() {
    int choice;
    char item[100], bidder[50];
    float startingPrice, bidAmount;

    while (1) {
        printf("\n--- Digital Auction System ---\n");
        printf("1. Create Auction\n");
        printf("2. Place Bid\n");
        printf("3. Display Auctions\n");
        printf("4. Delete Auction\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                fgets(item, sizeof(item), stdin);
                item[strcspn(item, "\n")] = 0; // Remove newline
                printf("Enter starting price: ");
                scanf("%f", &startingPrice);
                addAuction(createAuction(item, startingPrice));
                break;
            case 2:
                printf("Enter item name for bidding: ");
                fgets(item, sizeof(item), stdin);
                item[strcspn(item, "\n")] = 0; // Remove newline
                printf("Enter your name: ");
                fgets(bidder, sizeof(bidder), stdin);
                bidder[strcspn(bidder, "\n")] = 0; // Remove newline
                printf("Enter your bid amount: ");
                scanf("%f", &bidAmount);
                placeBid(item, bidder, bidAmount);
                break;
            case 3:
                displayAuctions();
                break;
            case 4:
                printf("Enter item name to delete auction: ");
                fgets(item, sizeof(item), stdin);
                item[strcspn(item, "\n")] = 0; // Remove newline
                deleteAuction(item);
                break;
            case 5:
                freeAuctions();
                printf("Exiting the system.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}