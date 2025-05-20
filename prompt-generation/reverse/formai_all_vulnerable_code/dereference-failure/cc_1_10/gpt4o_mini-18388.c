//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bid {
    char bidderName[50];
    float bidAmount;
    struct Bid* next;
} Bid;

typedef struct Auction {
    char itemName[100];
    float basePrice;
    Bid* bids;
    struct Auction* next;
} Auction;

Auction* createAuction(char* itemName, float basePrice) {
    Auction* newAuction = (Auction*)malloc(sizeof(Auction));
    strcpy(newAuction->itemName, itemName);
    newAuction->basePrice = basePrice;
    newAuction->bids = NULL;
    newAuction->next = NULL;
    return newAuction;
}

Bid* createBid(char* bidderName, float bidAmount) {
    Bid* newBid = (Bid*)malloc(sizeof(Bid));
    strcpy(newBid->bidderName, bidderName);
    newBid->bidAmount = bidAmount;
    newBid->next = NULL;
    return newBid;
}

void addAuction(Auction** auctionList, Auction* newAuction) {
    newAuction->next = *auctionList;
    *auctionList = newAuction;
}

void placeBid(Auction* auction, char* bidderName, float bidAmount) {
    if (bidAmount > auction->basePrice) {
        Bid* newBid = createBid(bidderName, bidAmount);
        newBid->next = auction->bids;
        auction->bids = newBid;
        printf("Bid of %.2f placed by %s on %s!\n", bidAmount, bidderName, auction->itemName);
    } else {
        printf("Bid amount must be greater than base price of %.2f!\n", auction->basePrice);
    }
}

void displayAuctions(Auction* auctionList) {
    Auction* current = auctionList;
    while (current != NULL) {
        printf("Auction Item: %s, Base Price: %.2f\n", current->itemName, current->basePrice);
        if (current->bids != NULL) {
            Bid* bidCurrent = current->bids;
            printf("Bids:\n");
            while (bidCurrent != NULL) {
                printf("  Bidder: %s, Amount: %.2f\n", bidCurrent->bidderName, bidCurrent->bidAmount);
                bidCurrent = bidCurrent->next;
            }
        } else {
            printf("  No bids yet.\n");
        }
        current = current->next;
    }
}

void freeMemory(Auction* auctionList) {
    while (auctionList != NULL) {
        Auction* tempAuction = auctionList;
        auctionList = auctionList->next;

        Bid* currentBid = tempAuction->bids;
        while (currentBid != NULL) {
            Bid* tempBid = currentBid;
            currentBid = currentBid->next;
            free(tempBid);
        }
        
        free(tempAuction);
    }
}

int main() {
    Auction* auctionList = NULL;
    int choice;
    
    do {
        printf("\nDigital Auction System\n");
        printf("1. Create Auction\n");
        printf("2. Place Bid\n");
        printf("3. Display Auctions\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char itemName[100];
                float basePrice;
                printf("Enter item name: ");
                scanf(" %[^\n]", itemName);
                printf("Enter base price: ");
                scanf("%f", &basePrice);
                Auction* newAuction = createAuction(itemName, basePrice);
                addAuction(&auctionList, newAuction);
                printf("Auction for %s created successfully!\n", itemName);
                break;
            }
            case 2: {
                char bidderName[50];
                float bidAmount;
                printf("Enter auction item name to bid on: ");
                char auctionItem[100];
                scanf(" %[^\n]", auctionItem);
                
                Auction* current = auctionList;
                while (current != NULL && strcmp(current->itemName, auctionItem) != 0) {
                    current = current->next;
                }
                
                if (current) {
                    printf("Enter your name: ");
                    scanf(" %[^\n]", bidderName);
                    printf("Enter bid amount: ");
                    scanf("%f", &bidAmount);
                    placeBid(current, bidderName, bidAmount);
                } else {
                    printf("Auction not found!\n");
                }
                break;
            }
            case 3:
                displayAuctions(auctionList);
                break;
            case 0:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    
    freeMemory(auctionList);
    return 0;
}