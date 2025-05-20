//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store auction items
typedef struct Item {
    char name[20];
    int startingBid;
    int currentBid;
    struct Item* nextItem;
} Item;

// Function to create a new item
Item* newItem() {
    Item* item = (Item*)malloc(sizeof(Item));
    item->nextItem = NULL;
    return item;
}

// Function to add an item to the auction
void addItem(Item* head, char* name, int startingBid) {
    Item* item = newItem();
    strcpy(item->name, name);
    item->startingBid = startingBid;
    item->currentBid = startingBid;

    if (head == NULL) {
        head = item;
    } else {
        head->nextItem = item;
    }
    head = item;
}

// Function to bid on an item
void bid(Item* item, int bid) {
    if (bid > item->currentBid) {
        item->currentBid = bid;
    }
}

// Function to print the auction items
void printItems(Item* head) {
    while (head) {
        printf("Item: %s, Starting Bid: %d, Current Bid: %d\n", head->name, head->startingBid, head->currentBid);
        head = head->nextItem;
    }
}

int main() {
    Item* head = NULL;

    // Add some items to the auction
    addItem(head, "Laptop", 1000);
    addItem(head, "Smartphone", 800);
    addItem(head, "Watch", 600);

    // Print the items
    printItems(head);

    // Bid on an item
    bid(head->nextItem, 900);

    // Print the items again after bidding
    printItems(head);

    return 0;
}