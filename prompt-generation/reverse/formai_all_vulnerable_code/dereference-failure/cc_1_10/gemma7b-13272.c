//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the Item structure
typedef struct Item {
    char name[20];
    int quantity;
    float price;
    struct Item *next;
} Item;

// Define the Bid structure
typedef struct Bid {
    char bidder[20];
    int amount;
    struct Bid *next;
} Bid;

// Global variables
Item *head = NULL;
Bid *tail = NULL;

// Function to insert an item into the item list
void insertItem(char *name, int quantity, float price) {
    Item *newItem = (Item *)malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->price = price;
    newItem->next = NULL;

    if (head == NULL) {
        head = newItem;
    } else {
        tail->next = newItem;
        tail = newItem;
    }
}

// Function to insert a bid into the bid list
void insertBid(char *bidder, int amount) {
    Bid *newBid = (Bid *)malloc(sizeof(Bid));
    strcpy(newBid->bidder, bidder);
    newBid->amount = amount;
    newBid->next = NULL;

    if (tail == NULL) {
        tail = newBid;
    } else {
        tail->next = newBid;
        tail = newBid;
    }
}

// Function to start the auction
void startAuction() {
    // Display the items
    Item *currentItem = head;
    while (currentItem) {
        printf("Item: %s, Quantity: %d, Price: %.2f\n", currentItem->name, currentItem->quantity, currentItem->price);
        currentItem = currentItem->next;
    }

    // Get the bids
    Bid *currentBid = tail;
    printf("Bids:\n");
    while (currentBid) {
        printf("Bidder: %s, Amount: %d\n", currentBid->bidder, currentBid->amount);
        currentBid = currentBid->next;
    }

    // Calculate the winner
    float highestBid = 0;
    char winner[20] = "";
    Item *item = head;
    for (int i = 0; i < item->quantity; i++) {
        for (Bid *bid = tail; bid; bid) {
            if (bid->amount > highestBid) {
                highestBid = bid->amount;
                strcpy(winner, bid->bidder);
            }
        }
    }

    // Announce the winner
    printf("The winner is: %s with a bid of %.2f\n", winner, highestBid);
}

int main() {
    // Insert some items
    insertItem("iPhone", 10, 1000.0);
    insertItem("Samsung", 5, 800.0);
    insertItem("Google Pixel", 7, 900.0);

    // Insert some bids
    insertBid("John Doe", 1200);
    insertBid("Jane Doe", 1000);
    insertBid("Bill Smith", 900);

    // Start the auction
    startAuction();

    return 0;
}