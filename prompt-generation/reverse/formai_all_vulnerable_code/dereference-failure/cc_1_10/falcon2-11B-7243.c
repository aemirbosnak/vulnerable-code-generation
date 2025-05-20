//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* item;
    int price;
    char* description;
    int bidder;
    char* name;
} AuctionItem;

typedef struct {
    AuctionItem* items[100];
    int numItems;
} Auction;

void addAuctionItem(Auction* auction, char* item, int price, char* description, char* name) {
    AuctionItem* newItem = (AuctionItem*)malloc(sizeof(AuctionItem));
    newItem->item = strdup(item);
    newItem->price = price;
    newItem->description = strdup(description);
    newItem->bidder = 0;
    newItem->name = strdup(name);
    auction->items[auction->numItems++] = newItem;
}

void deleteAuctionItem(Auction* auction, int index) {
    free(auction->items[index]->item);
    free(auction->items[index]->description);
    free(auction->items[index]->name);
    free(auction->items[index]);
    for (int i = index; i < auction->numItems - 1; i++) {
        auction->items[i] = auction->items[i + 1];
    }
    auction->numItems--;
}

void displayAuction(Auction* auction) {
    for (int i = 0; i < auction->numItems; i++) {
        printf("Item: %s\n", auction->items[i]->item);
        printf("Price: %d\n", auction->items[i]->price);
        printf("Description: %s\n", auction->items[i]->description);
        printf("Bidder: %d\n", auction->items[i]->bidder);
        printf("Name: %s\n", auction->items[i]->name);
        printf("\n");
    }
}

int main() {
    Auction auction;
    auction.numItems = 0;

    addAuctionItem(&auction, "iPhone 12", 1000, "New and Unopened", "John");
    addAuctionItem(&auction, "MacBook Pro", 1500, "Used but in Great Condition", "Jane");
    addAuctionItem(&auction, "Sony PlayStation 5", 600, "Brand New", "Mike");

    displayAuction(&auction);

    deleteAuctionItem(&auction, 1);
    displayAuction(&auction);

    return 0;
}