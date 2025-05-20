//FormAI DATASET v1.0 Category: Digital Auction System ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEM 10
#define MAX_BIDDER 5

// Struct for the item data
struct item {
    char name[50];
    int starting_price;
    int highest_bid;
    char highest_bidder[50];
};

// Struct for the bidder data
struct bidder {
    char name[50];
    int wallet;
    struct item *current_item;
};

// Array to store all the items
struct item itemList[MAX_ITEM];

// Array to store all the bidders
struct bidder bidderList[MAX_BIDDER];

// Function to add an item to the auction
void add_item(char *name, int starting_price) {
    int i;
    
    for (i=0; i<MAX_ITEM; i++) {
        if (itemList[i].name[0] == '\0') {
            strcpy(itemList[i].name, name);
            itemList[i].starting_price = starting_price;
            itemList[i].highest_bid = starting_price;
            strcpy(itemList[i].highest_bidder, "None");
            printf("Item added to the auction.\n");
            return;
        }
    }
    
    printf("Maximum items reached.\n");
}

// Function to add a bidder to the auction
void add_bidder(char *name, int wallet) {
    int i;
    
    for (i=0; i<MAX_BIDDER; i++) {
        if (bidderList[i].name[0] == '\0') {
            strcpy(bidderList[i].name, name);
            bidderList[i].wallet = wallet;
            bidderList[i].current_item = NULL;
            printf("Bidder added to the auction.\n");
            return;
        }
    }
    
    printf("Maximum bidders reached.\n");
}

// Function to list all the items in the auction
void list_items() {
    int i;
    
    printf("Items in the auction:\n");
    for (i=0; i<MAX_ITEM; i++) {
        if (itemList[i].name[0] != '\0') {
            printf("%d. %s\n", i+1, itemList[i].name);
        }
    }
}

// Function to list all the bidders in the auction
void list_bidders() {
    int i;
    
    printf("Bidders in the auction:\n");
    for (i=0; i<MAX_BIDDER; i++) {
        if (bidderList[i].name[0] != '\0') {
            printf("%d. %s\n", i+1, bidderList[i].name);
        }
    }
}

// Function to allow a bidder to bid on an item
void bid(char *bidderName, int itemNum, int amount) {
    int i;
    struct bidder *currentBidder = NULL;
    struct item *currentItem = NULL;
    
    // Find the bidder and item
    for (i=0; i<MAX_BIDDER; i++) {
        if (strcmp(bidderList[i].name, bidderName) == 0) {
            currentBidder = &bidderList[i];
            break;
        }
    }
    
    if (currentBidder == NULL) {
        printf("Bidder not found.\n");
        return;
    }
    
    for (i=0; i<MAX_ITEM; i++) {
        if (i == itemNum-1) {
            currentItem = &itemList[i];
            break;
        }
    }
    
    if (currentItem == NULL) {
        printf("Item not found.\n");
        return;
    }
    
    // Check if the bidder has enough money
    if (currentBidder->wallet < amount) {
        printf("Bidder does not have enough money.\n");
        return;
    }
    
    // Check if the bid is higher than the current highest bid
    if (currentItem->highest_bid >= amount) {
        printf("Bid is too low.\n");
        return;
    }
    
    // Remove the previous bid from the bidder's wallet
    if (currentItem->highest_bid != currentItem->starting_price && currentItem->highest_bidder[0] != '\0') {
        for (i=0; i<MAX_BIDDER; i++) {
            if (strcmp(bidderList[i].name, currentItem->highest_bidder) == 0) {
                bidderList[i].wallet += currentItem->highest_bid;
                break;
            }
        }
    }
    
    // Add the new bid to the bidder's wallet
    currentBidder->wallet -= amount;
    
    // Update the highest bid and highest bidder for the item
    currentItem->highest_bid = amount;
    strcpy(currentItem->highest_bidder, currentBidder->name);
    
    // Set the current item for the bidder
    currentBidder->current_item = currentItem;
    
    printf("Bid successful.\n");
}

// Function to end an auction and declare a winner
void end_auction() {
    int i;
    struct bidder *winner = NULL;
    struct item *itemSold = NULL;
    
    // Find the item that was sold
    for (i=0; i<MAX_ITEM; i++) {
        if (itemList[i].highest_bidder[0] != '\0') {
            itemSold = &itemList[i];
            break;
        }
    }
    
    if (itemSold == NULL) {
        printf("No items were sold.\n");
        return;
    }
    
    // Find the winner
    for (i=0; i<MAX_BIDDER; i++) {
        if (strcmp(bidderList[i].name, itemSold->highest_bidder) == 0) {
            winner = &bidderList[i];
            break;
        }
    }
    
    if (winner == NULL) {
        printf("No winner found.\n");
        return;
    }
    
    // Add the final bid to the bidder's wallet
    winner->wallet += itemSold->highest_bid;
    
    printf("%s won the auction for %s with a bid of %d.\n", winner->name, itemSold->name, itemSold->highest_bid);
}

int main() {
    char input[100];
    char *token;
    char *delim = " ";
    char *name;
    int starting_price;
    char *bidderName;
    int itemNum;
    int amount;
    
    printf("Welcome to the digital auction system!\n");
    
    while (1) {
        printf("> ");
        fgets(input, 100, stdin);
        
        token = strtok(input, delim);
        if (strcmp(token, "add_item") == 0) {
            name = strtok(NULL, delim);
            starting_price = atoi(strtok(NULL, delim));
            add_item(name, starting_price);
        }
        else if (strcmp(token, "add_bidder") == 0) {
            name = strtok(NULL, delim);
            starting_price = atoi(strtok(NULL, delim));
            add_bidder(name, starting_price);
        }
        else if (strcmp(token, "list_items") == 0) {
            list_items();
        }
        else if (strcmp(token, "list_bidders") == 0) {
            list_bidders();
        }
        else if (strcmp(token, "bid") == 0) {
            bidderName = strtok(NULL, delim);
            itemNum = atoi(strtok(NULL, delim));
            amount = atoi(strtok(NULL, delim));
            bid(bidderName, itemNum, amount);
        }
        else if (strcmp(token, "end_auction") == 0) {
            end_auction();
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }
    
    return 0;
}