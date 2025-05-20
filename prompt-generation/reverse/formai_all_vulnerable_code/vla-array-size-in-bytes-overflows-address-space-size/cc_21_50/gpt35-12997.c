//FormAI DATASET v1.0 Category: Digital Auction System ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure for Auction Item
struct AuctionItem {
    char name[50];
    int startPrice;
    int currentBid;
    char bidder[50];
    int timeLeft;
};

int main() {
    int choice, numItems, auctionTime, i, j, maxBid, maxBidIndex;
    printf("Welcome to the Digital Auction System!\n\n");
    printf("Please enter the number of items up for auction: ");
    scanf("%d", &numItems);
    printf("Please enter the length of the auction in minutes: ");
    scanf("%d", &auctionTime);
    struct AuctionItem items[numItems];
    //Initialize all items to default values
    for(i=0;i<numItems;i++) {
        strcpy(items[i].name, "N/A");
        items[i].startPrice = 0;
        items[i].currentBid = 0;
        strcpy(items[i].bidder, "N/A");
        items[i].timeLeft = auctionTime;
    }
    //Menu-driven program for adding, bidding and displaying items
    do {
        printf("\nMain Menu\n");
        printf("1. Add item to auction\n");
        printf("2. Bid on item\n");
        printf("3. Display all items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                //Add new item to auction
                for(i=0;i<numItems;i++) {
                    if(strcmp(items[i].name, "N/A") == 0) {
                        printf("Enter name of item: ");
                        scanf("%s", items[i].name);
                        printf("Enter starting price: ");
                        scanf("%d", &items[i].startPrice);
                        items[i].currentBid = items[i].startPrice;
                        printf("Item added successfully!\n");
                        break;
                    }
                }
                if(i == numItems)
                    printf("Maximum items reached, cannot add anymore!\n");
                break;
            case 2:
                //Bid on an item
                printf("Enter name of item to bid for: ");
                char itemName[50];
                scanf("%s", itemName);
                for(i=0;i<numItems;i++) {
                    if(strcmp(items[i].name, itemName) == 0) {
                        if(items[i].timeLeft == 0) {
                            printf("Sorry, bidding for this item has closed!\n");
                            break;
                        }
                        printf("Current bid for %s is $%d\n", itemName, items[i].currentBid);
                        printf("Enter your bid: ");
                        scanf("%d", &maxBid);
                        if(maxBid > items[i].currentBid) {
                            strcpy(items[i].bidder, "You");
                            items[i].currentBid = maxBid;
                            printf("Your bid for %s was successful!\n", itemName);
                            for(j=0;j<numItems;j++) {
                                if(j!=i && strcmp(items[j].name, itemName) == 0) {
                                    items[j].currentBid = maxBid;
                                    strcpy(items[j].bidder, "Outbid");
                                }
                            }
                        }
                        else {
                            printf("Sorry, your bid was too low!\n");
                        }
                        break;
                    }
                }
                if(i == numItems)
                    printf("Invalid item name!\n");
                break;
            case 3:
                //Display all items and details
                printf("\nAuction Items\n");
                printf("%-20s %-20s %-20s %-20s %-20s\n", "Name", "Starting Price", "Current Bid", "Bidder", "Time Left");
                printf("============================================================================\n");
                for(i=0;i<numItems;i++) {
                    printf("%-20s %-20d %-20d %-20s %-20d\n", items[i].name, items[i].startPrice, items[i].currentBid, items[i].bidder, items[i].timeLeft);
                    if(items[i].timeLeft > 0)
                        items[i].timeLeft--;
                }
                break;
            case 4:
                //Exit program
                printf("Thank you for using the Digital Auction System! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        //Find the item with the highest bid
        maxBid = 0;
        maxBidIndex = -1;
        for(i=0;i<numItems;i++) {
            if(items[i].currentBid > maxBid) {
                maxBid = items[i].currentBid;
                maxBidIndex = i;
            }
        }
        if(maxBidIndex != -1)
            printf("Current highest bid is $%d for %s\n", maxBid, items[maxBidIndex].name);
    }while(choice != 4);
    return 0;
}