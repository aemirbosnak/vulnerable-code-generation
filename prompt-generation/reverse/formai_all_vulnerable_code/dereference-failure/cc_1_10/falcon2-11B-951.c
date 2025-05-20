//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 1000
#define MAX_ITEMS 10

typedef struct {
    char name[100];
    int bid;
} Bidder;

typedef struct {
    char name[100];
    int bid;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
    Bidder bidders[MAX_ITEMS];
    int num_bidders;
} Auction;

void read_items(Auction* auction) {
    int i, j;
    printf("Enter the name and bid for each item: \n");
    for (i = 0; i < auction->num_items; i++) {
        for (j = 0; j < MAX_ITEMS; j++) {
            if (j == i) {
                fgets(auction->items[i].name, sizeof(auction->items[i].name), stdin);
                fgets(auction->items[i].bid, sizeof(auction->items[i].bid), stdin);
                auction->items[i].bid = atoi(auction->items[i].bid);
                if (auction->items[i].bid > MAX_BID) {
                    auction->items[i].bid = MAX_BID;
                }
            }
        }
    }
}

void read_bidders(Auction* auction) {
    int i, j;
    printf("Enter the name and bid for each bidder: \n");
    for (i = 0; i < auction->num_items; i++) {
        for (j = 0; j < MAX_ITEMS; j++) {
            if (j == i) {
                fgets(auction->bidders[i].name, sizeof(auction->bidders[i].name), stdin);
                fgets(auction->bidders[i].bid, sizeof(auction->bidders[i].bid), stdin);
                auction->bidders[i].bid = atoi(auction->bidders[i].bid);
            }
        }
    }
}

int find_highest_bid(Auction* auction) {
    int highest_bid = 0, i;
    for (i = 0; i < auction->num_items; i++) {
        if (auction->items[i].bid > highest_bid) {
            highest_bid = auction->items[i].bid;
        }
    }
    return highest_bid;
}

void print_auction(Auction* auction) {
    int i;
    printf("Auction: \n");
    for (i = 0; i < auction->num_items; i++) {
        printf("Item %d: %s, Bid: %d \n", i, auction->items[i].name, auction->items[i].bid);
    }
}

void main() {
    Auction auction;
    read_items(&auction);
    read_bidders(&auction);
    printf("Highest Bid: %d \n", find_highest_bid(&auction));
    print_auction(&auction);
}