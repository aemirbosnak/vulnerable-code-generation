//FormAI DATASET v1.0 Category: Digital Auction System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// structure for auction items
typedef struct AuctionItem {
    char name[50];
    int id;
    double currentBid;
    char bidderName[50];
    int timeLeft;
    struct AuctionItem* next;
} AuctionItem;

int itemCount;
AuctionItem* head;

// function to add new auction item
void addAuctionItem(char name[], int id, double startingBid, int timeLeft) {
    AuctionItem* newItem = (AuctionItem*)malloc(sizeof(AuctionItem));
    strcpy(newItem->name, name);
    newItem->id = id;
    newItem->currentBid = startingBid;
    strcpy(newItem->bidderName, "");
    newItem->timeLeft = timeLeft;
    newItem->next = NULL;
    
    if (head == NULL) {
        head = newItem;
    } else {
        AuctionItem* currentItem = head;
        while (currentItem->next != NULL) {
            currentItem = currentItem->next;
        }
        currentItem->next = newItem;
    }
    itemCount++;
}

// function to display all auction items on screen
void displayAuctionItems() {
    printf("Auction Items:\n\n");
    if (head == NULL) {
        printf("No items found.\n");
    } else {
        AuctionItem* currentItem = head;
        while (currentItem != NULL) {
            printf("%s (ID: %d) - Current Bid: $%.2f - Bidder Name: %s - Time Left: %d minutes\n", currentItem->name, currentItem->id, currentItem->currentBid, currentItem->bidderName, currentItem->timeLeft);
            currentItem = currentItem->next;
        }
    }
    printf("\n");
}

// function to get auction item by id
AuctionItem* getAuctionItem(int id) {
    AuctionItem* currentItem = head;
    while (currentItem != NULL) {
        if (currentItem->id == id) {
            return currentItem;
        }
        currentItem = currentItem->next;
    }
    return NULL;
}

// function to place bid on auction item
void placeBid(int id, double bidAmount, char bidderName[]) {
    AuctionItem* item = getAuctionItem(id);
    if (item == NULL) {
        printf("Item not found.\n");
    } else {
        if (bidAmount > item->currentBid) {
            item->currentBid = bidAmount;
            strcpy(item->bidderName, bidderName);
            printf("Bid accepted.\n");
        } else {
            printf("Your bid is too low.\n");
        }
    }
}

// function to remove auction item after auction ends
void removeAuctionItem(int id) {
    AuctionItem* currentItem = head;
    AuctionItem* prevItem = NULL;
    while (currentItem != NULL) {
        if (currentItem->id == id) {
            if (prevItem == NULL) {
                head = currentItem->next;
            } else {
                prevItem->next = currentItem->next;
            }
            free(currentItem);
            itemCount--;
            printf("Item removed.\n");
            break;
        }
        prevItem = currentItem;
        currentItem = currentItem->next;
    }
}

// function to check if auction item has ended
void checkAuctionItemEnds() {
    AuctionItem* currentItem = head;
    while (currentItem != NULL) {
        if (currentItem->timeLeft <= 0) {
            printf("\n%s (ID: %d) auction is over.\n", currentItem->name, currentItem->id);
            printf("Winner: %s (Bid: $%.2f)\n\n", currentItem->bidderName, currentItem->currentBid);
            removeAuctionItem(currentItem->id);
        } else {
            currentItem->timeLeft--;
        }
        currentItem = currentItem->next;
    }
}

int main() {
    itemCount = 0;
    head = NULL;
    srand(time(NULL)); // for generating random ids

    // add some sample auction items
    addAuctionItem("iPhone 12", rand() % 1000 + 1, 1000.00, 30);
    addAuctionItem("Nintendo Switch", rand() % 1000 + 1, 300.00, 20);
    
    // start the auction
    printf("\nWelcome to the Digital Auction System!\n\n");
    printf("Auction will start in 10 seconds...\n");
    sleep(10);
    
    int minutesLeft = 30;
    while (minutesLeft > 0) {
        printf("\nMinutes Left: %d\n", minutesLeft);
        displayAuctionItems();
        
        int itemId;
        double bidAmount;
        char bidderName[50];
        
        printf("Enter ID of the item you want to bid on (or 0 to skip): ");
        scanf("%d", &itemId);
        if (itemId != 0) {
            printf("Enter your bid amount: ");
            scanf("%lf", &bidAmount);
            printf("Enter your name: ");
            scanf("%s", bidderName);
            placeBid(itemId, bidAmount, bidderName);
        }
        
        checkAuctionItemEnds();
        sleep(60);
        minutesLeft--;
    }
    
    // end of auction
    printf("\nAuction is over.\n\n");
    displayAuctionItems();
    
    return 0;
}