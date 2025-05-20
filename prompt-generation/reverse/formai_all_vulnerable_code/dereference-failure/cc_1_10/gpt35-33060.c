//FormAI DATASET v1.0 Category: Digital Auction System ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// Struct for Bidder node.
struct bidderNode {
    char name[50];
    int bidAmount;
    struct bidderNode* next;
};

// Struct for Item node.
struct itemNode {
    char name[50];
    int currentBid;
    struct bidderNode* topBidder;
    struct itemNode* next;
};

// Starting node for Item list.
struct itemNode* itemListHead = NULL;
// Current item being auctioned.
struct itemNode* currentItem = NULL;

// Function to print whole linked list of bidders.
void printBiddersList(struct bidderNode* curr) {
    printf("Bidders:\n");
    int count = 1;
    while(curr != NULL) {
        printf("%d. Bidder Name: %s, Bid Amount: %d\n", count, curr->name, curr->bidAmount);
        curr = curr->next;
        count++;
    }
}

// Function to print informatio about item being auctioned.
void printCurrentItem() {
    printf("\n---Current Auction---\nItem Name: %s\nCurrent Bid: %d\n", currentItem->name, currentItem->currentBid);
    printBiddersList(currentItem->topBidder);
}

// Function to find a Node in bidder list using name.
struct bidderNode* findBidderByName(char name[50], struct bidderNode* bids) {
    while(bids!=NULL) {
        if(strcmp(bids->name, name) == 0) {
            return bids;
        }
        bids = bids->next;
    }
    return NULL;
}

// Function to record a bid for current Auctioned item.
bool recordBid(char name[50], int bidAmount) {
    struct bidderNode* bidder = findBidderByName(name, currentItem->topBidder);
    if(bidder == NULL) {
        // Create new Bidder Node.
        struct bidderNode* newBidder = (struct bidderNode*)malloc(sizeof(struct bidderNode));
        strcpy(newBidder->name, name);
        newBidder->bidAmount = bidAmount;
        newBidder->next = currentItem->topBidder;
        currentItem->topBidder = newBidder;
        return true;
    }
    else {
        // Bidder already exists, update his bid.
        if(bidder->bidAmount > bidAmount) {
            return false;
        }
        else {
            bidder->bidAmount = bidAmount;  
            return true;
        }
    }
}

// Function to select a new item for auction from itemList.
bool selectNewItem() {
    if(itemListHead == NULL) {
        currentItem = NULL;
        return false;
    } else {
        currentItem = itemListHead;
        itemListHead = itemListHead->next;
        currentItem->next = NULL;
        currentItem->topBidder = NULL;
        return true;
    }
}

// Function to add a new item in itemList.
void addItem(char name[50], int price) {
    struct itemNode* newItem = (struct itemNode*)malloc(sizeof(struct itemNode));
    strcpy(newItem->name, name);
    newItem->currentBid = price;
    newItem->topBidder = NULL;
    if(itemListHead == NULL) {
        itemListHead = newItem;
        newItem->next = NULL;
    } else {
        struct itemNode* curr = itemListHead;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newItem;
        newItem->next = NULL;
    }
}

// Main function to run the auction system.
int main() {
    int choice;
    char name[50];
    int bidAmount;
    char itemName[50];
    int price;
    bool success;
    
    // Populate some initial entries in itemList.
    addItem("Ring", 500);
    addItem("Necklace", 800);
    addItem("Watch", 1500);
    
    do {
        printf("\n---Main Menu---\n1. Select New Item for Auction\n2. Add New Item in List\n3. Record Bid\n4. Print Current Auction Information\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                success = selectNewItem();
                if(success) {
                    printf("\nNew Item selected for auction!\n");
                    printCurrentItem();
                } else {
                    printf("\nOops! No more items in list for auction.\n");
                }
                break;
            case 2:
                printf("\nEnter Item Name: ");
                scanf("%s", itemName);
                printf("\nEnter Item Price: ");
                scanf("%d", &price);
                addItem(itemName, price);
                printf("\nNew Item added to the list!\n");
                break;
            case 3:
                if(currentItem == NULL) {
                    printf("\nOops! No item selected for auction.\n");
                } else {
                    printf("\nEnter Bidder Name: ");
                    scanf("%s", name);
                    printf("\nEnter Bid Amount: ");
                    scanf("%d", &bidAmount);
                    success = recordBid(name, bidAmount);
                    if(success) {
                        printf("\nBid Recorded Successfully!\n");
                    } else {
                        printf("\nOops! Your bid is less than current highest bid. Please bid again.\n");
                    }
                }
                break;
            case 4:
                if(currentItem == NULL) {
                    printf("\nOops! No item selected for auction.\n");
                } else {
                    printCurrentItem();
                }
                break;
            case 5:
                printf("\nThanks for using the program!\n");
                break;
            default:
                printf("\nOops! Invalid choice. Please try again.\n");
                break;
        }
    } while(choice!=5);
    
    return 0;
}