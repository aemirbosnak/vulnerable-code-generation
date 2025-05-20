//FormAI DATASET v1.0 Category: Digital Auction System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a bid
typedef struct Bid {
    char bidderName[50];
    int bidAmount;
} Bid;

// Define the structure for an item
typedef struct Item {
    char itemName[50];
    Bid currentBid;
    Bid *allBids;
    int numBids;
} Item;

// Define the structure for the auction
typedef struct Auction {
    Item *items;
    int numItems;
} Auction;

// Function to create a new item
Item createItem(char *itemName) {
    Item newItem;
    strcpy(newItem.itemName, itemName);
    newItem.currentBid.bidAmount = 0;
    newItem.numBids = 0;
    newItem.allBids = NULL;
    return newItem;
}

// Function to create a new bid
Bid createBid(char *bidderName, int bidAmount) {
    Bid newBid;
    strcpy(newBid.bidderName, bidderName);
    newBid.bidAmount = bidAmount;
    return newBid;
}

// Function to add a bid to an item
void addBid(Auction *auction, int itemIndex, Bid newBid) {
    Item *item = &(auction->items[itemIndex]);
    item->numBids++;
    item->allBids = realloc(item->allBids, sizeof(Bid) * item->numBids);
    item->allBids[item->numBids - 1] = newBid;
    if (newBid.bidAmount > item->currentBid.bidAmount) {
        item->currentBid = newBid;
    }
}

// Main function to run the auction
int main() {
    // Initialize the auction with 3 items
    Auction auction;
    auction.numItems = 3;
    auction.items = malloc(sizeof(Item) * auction.numItems);

    // Create the items for auction
    auction.items[0] = createItem("Painting");
    auction.items[1] = createItem("Jewelry");
    auction.items[2] = createItem("Antique Vase");

    // Run the auction for each item
    for (int i = 0; i < auction.numItems; i++) {
        Item item = auction.items[i];
        printf("Auctioning item: %s\n", item.itemName);

        // Allow bidders to place bids
        int bidPlaced = 0;
        while (!bidPlaced) {
            printf("Enter your name or 'quit' to exit bidding: ");
            char bidderName[50];
            scanf("%s", bidderName);
            if (strcmp(bidderName, "quit") == 0) {
                break;
            }
            printf("Enter your bid amount: ");
            int bidAmount;
            scanf("%d", &bidAmount);
            Bid newBid = createBid(bidderName, bidAmount);
            addBid(&auction, i, newBid);
            printf("%s placed a bid of %d\n", bidderName, bidAmount);
        }

        // Print the winning bid
        printf("%s won the %s with a bid of %d\n", item.currentBid.bidderName, item.itemName, item.currentBid.bidAmount);

        // Print all bids for the item
        printf("All bids for the %s:\n", item.itemName);
        for (int j = 0; j < item.numBids; j++) {
            Bid bid = item.allBids[j];
            printf("%s bid %d\n", bid.bidderName, bid.bidAmount);
        }

        // Free the memory used by the bids array
        free(item.allBids);
    }

    // Free the memory used by the items array
    free(auction.items);

    return 0;
}