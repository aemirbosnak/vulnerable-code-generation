//FormAI DATASET v1.0 Category: Digital Auction System ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct auction {
    int auctionID;
    char itemName[50];
    int initialBid;
    int currentBid;
    char bidderName[50];
};

// Function to generate unique auction ID
int generateAuctionID() {
    srand(time(0));
    return rand() % 10000 + 1;
}

// Function to check if there are any existing bids on the auction
int checkBids(struct auction auctions[], int n, int auctionID) {
    for(int i=0; i<n; i++) {
        if(auctions[i].auctionID == auctionID) {
            if(auctions[i].currentBid == 0)
                return 0;
            else
                return 1;
        }
    }
    return 0;
}

// Function to display the current bid status of an auction
void displayBidStatus(struct auction auctions[], int n, int auctionID) {
    printf("Current Bid Status:\n");
    for(int i=0; i<n; i++) {
        if(auctions[i].auctionID == auctionID) {
            printf("Item: %s\n", auctions[i].itemName);
            printf("Current Bid: %d\n", auctions[i].currentBid);
            printf("Bidder: %s\n", auctions[i].bidderName);
            break;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of auctions: ");
    scanf("%d", &n);
    struct auction auctions[n];

    // Initialize auction details
    for(int i=0; i<n; i++) {
        auctions[i].auctionID = generateAuctionID();
        printf("\nEnter details for auction #%d:\n", i+1);
        printf("Item Name: ");
        scanf("%s", auctions[i].itemName);
        printf("Initial Bid: ");
        scanf("%d", &auctions[i].initialBid);
        auctions[i].currentBid = auctions[i].initialBid;
        auctions[i].bidderName[0] = '\0';
    }

    // Auction loop
    int choice, id, bidAmount;
    char bidderName[50];
    do {
        printf("\n\nAUCTION MENU\n");
        printf("1. Display all auctions\n");
        printf("2. Display bid status for an auction\n");
        printf("3. Place a bid\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Display all auctions
                printf("\nAuctions:\n");
                for(int i=0; i<n; i++) {
                    printf("Auction #%d | ID: %d | Item: %s | Current Bid: %d\n", i+1, auctions[i].auctionID, auctions[i].itemName, auctions[i].currentBid);
                }
                break;
            case 2: // Display bid status for an auction
                printf("\nEnter Auction ID: ");
                scanf("%d", &id);
                if(checkBids(auctions, n, id))
                    displayBidStatus(auctions, n, id);
                else
                    printf("No bids on this auction yet.\n");
                break;
            case 3: // Place a bid
                printf("\nEnter Auction ID: ");
                scanf("%d", &id);
                if(checkBids(auctions, n, id)) {
                    printf("Enter Bid Amount: ");
                    scanf("%d", &bidAmount);
                    if(bidAmount > auctions[id-1].currentBid) {
                        printf("Enter Bidder Name: ");
                        scanf("%s", bidderName);
                        auctions[id-1].currentBid = bidAmount;
                        strcpy(auctions[id-1].bidderName, bidderName);
                        printf("Bid Placed Successfully!\n");
                    }
                    else {
                        printf("Bid amount must be higher than current bid.\n");
                    }
                }
                else {
                    printf("Invalid Auction ID.\n");
                }
                break;
            case 4: // Exit
                break;
            default:
                printf("Invalid choice. Try Again.\n");
        }
    } while(choice != 4);

    printf("\nTHANK YOU FOR USING OUR AUCTION SYSTEM!");
    return 0;
}