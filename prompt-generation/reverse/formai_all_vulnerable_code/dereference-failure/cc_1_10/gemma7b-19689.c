//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 10
#define MAX_BID 1000

typedef struct Item {
    char name[20];
    int start_price;
    int current_price;
    int num_bids;
    struct Bid *bids;
} Item;

typedef struct Bid {
    int bidder_id;
    int bid_amount;
    struct Bid *next;
} Bid;

Item items[MAX_ITEMS];

void initializeItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].name[0] = '\0';
        items[i].start_price = 0;
        items[i].current_price = 0;
        items[i].num_bids = 0;
        items[i].bids = NULL;
    }
}

void addBid(Item *item, int bidder_id, int bid_amount) {
    Bid *new_bid = malloc(sizeof(Bid));
    new_bid->bidder_id = bidder_id;
    new_bid->bid_amount = bid_amount;
    new_bid->next = NULL;

    if (item->bids == NULL) {
        item->bids = new_bid;
    } else {
        item->bids->next = new_bid;
        item->num_bids++;
    }
}

void startAuction() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%s is currently at %d. Bid now! (Max bid: %d)\n", items[i].name, items[i].current_price, MAX_BID);
        int bidder_id = rand() % MAX_BID;
        int bid_amount = rand() % MAX_BID;
        addBid(&items[i], bidder_id, bid_amount);
    }
}

int main() {
    initializeItems();
    startAuction();

    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%s has a total of %d bids.\n", items[i].name, items[i].num_bids);
    }

    return 0;
}