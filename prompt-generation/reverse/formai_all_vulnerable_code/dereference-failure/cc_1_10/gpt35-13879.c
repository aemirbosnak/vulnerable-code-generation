//FormAI DATASET v1.0 Category: Digital Auction System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for an item in the auction
typedef struct AuctionItem {
    char *name;
    int startingBid;
    int currentBid;
    char *highestBidder;
} AuctionItem;

// Function to create a new auction item
AuctionItem *createAuctionItem(char *name, int startingBid) {
    AuctionItem *item = malloc(sizeof(AuctionItem));
    item->name = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(item->name, name);
    item->startingBid = startingBid;
    item->currentBid = 0;
    item->highestBidder = NULL;
    return item;
}

// Function to bid on an auction item
void bidOnItem(AuctionItem *item, int bidAmount, char *bidderName) {
    if (bidAmount > item->currentBid) {
        item->currentBid = bidAmount;
        if (item->highestBidder == NULL) {
            item->highestBidder = malloc(sizeof(char) * (strlen(bidderName) + 1));
            strcpy(item->highestBidder, bidderName);
        } else {
            item->highestBidder = realloc(item->highestBidder, sizeof(char) * (strlen(bidderName) + 1));
            strcpy(item->highestBidder, bidderName);
        }
        printf("Bid accepted! New highest bid is %d by %s\n", item->currentBid, item->highestBidder);
    } else {
        printf("Bid rejected. Current highest bid is %d by %s\n", item->currentBid, item->highestBidder);
    }
}

int main(void) {
    // Create some items for the auction
    AuctionItem *item1 = createAuctionItem("Baseball bat", 10);
    AuctionItem *item2 = createAuctionItem("Signed football", 20);
    AuctionItem *item3 = createAuctionItem("Game-worn jersey", 50);

    // Let's start the auction!
    printf("Welcome to our digital auction!\n");
    printf("The following items are up for bid:\n");
    printf("1. %s (starting bid: %d)\n", item1->name, item1->startingBid);
    printf("2. %s (starting bid: %d)\n", item2->name, item2->startingBid);
    printf("3. %s (starting bid: %d)\n", item3->name, item3->startingBid);

    // Bidding on an item
    bidOnItem(item1, 15, "Sam");
    bidOnItem(item1, 12, "Joe");
    bidOnItem(item2, 30, "Sarah");
    bidOnItem(item3, 60, "Mike");
    bidOnItem(item3, 55, "John");

    // Free allocated memory
    free(item1->name);
    free(item1->highestBidder);
    free(item1);
    free(item2->name);
    free(item2->highestBidder);
    free(item2);
    free(item3->name);
    free(item3->highestBidder);
    free(item3);

    return 0;
}