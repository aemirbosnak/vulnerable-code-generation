//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct AuctionItem {
    char name[20];
    int startingBid;
    int currentBid;
    struct AuctionItem* nextItem;
};

struct AuctionItem* createItem(char* name, int startingBid) {
    struct AuctionItem* item = (struct AuctionItem*)malloc(sizeof(struct AuctionItem));
    strcpy(item->name, name);
    item->startingBid = startingBid;
    item->currentBid = startingBid;
    item->nextItem = NULL;
    return item;
}

void auction(struct AuctionItem* item) {
    int currentBid = item->currentBid;
    printf("Current bid: $%d\n", currentBid);

    printf("Enter your bid: $");
    int newBid = atoi(stdin);

    if (newBid < currentBid) {
        printf("Error: your bid is too low.\n");
    } else if (newBid > item->startingBid) {
        printf("Error: your bid is too high.\n");
    } else if (newBid == currentBid) {
        printf("Error: your bid is the same as the current bid.\n");
    } else {
        item->currentBid = newBid;
        printf("Your bid has been accepted. Current bid: $%d\n", item->currentBid);

        if (item->nextItem) {
            auction(item->nextItem);
        } else {
            printf("The auction is complete.\n");
        }
    }
}

int main() {
    struct AuctionItem* item = createItem("Painting", 100);
    auction(item);

    return 0;
}