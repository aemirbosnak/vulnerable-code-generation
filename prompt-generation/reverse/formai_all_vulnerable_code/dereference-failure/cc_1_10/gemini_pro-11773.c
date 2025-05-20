//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100

struct item {
    char *name;
    int price;
};

struct bid {
    char *name;
    int price;
};

struct auction {
    struct item *items;
    int num_items;
    struct bid *bids;
    int num_bids;
};

void init_auction(struct auction *auction) {
    auction->items = malloc(sizeof(struct item) * MAX_ITEMS);
    auction->num_items = 0;
    auction->bids = malloc(sizeof(struct bid) * MAX_BIDS);
    auction->num_bids = 0;
}

void add_item(struct auction *auction, char *name, int price) {
    auction->items[auction->num_items].name = strdup(name);
    auction->items[auction->num_items].price = price;
    auction->num_items++;
}

void add_bid(struct auction *auction, char *name, int price) {
    auction->bids[auction->num_bids].name = strdup(name);
    auction->bids[auction->num_bids].price = price;
    auction->num_bids++;
}

void print_auction(struct auction *auction) {
    for (int i = 0; i < auction->num_items; i++) {
        printf("%s: %d\n", auction->items[i].name, auction->items[i].price);
    }
    for (int i = 0; i < auction->num_bids; i++) {
        printf("%s: %d\n", auction->bids[i].name, auction->bids[i].price);
    }
}

void free_auction(struct auction *auction) {
    for (int i = 0; i < auction->num_items; i++) {
        free(auction->items[i].name);
    }
    free(auction->items);
    for (int i = 0; i < auction->num_bids; i++) {
        free(auction->bids[i].name);
    }
    free(auction->bids);
}

int main() {
    struct auction auction;
    init_auction(&auction);

    add_item(&auction, "Item 1", 10);
    add_item(&auction, "Item 2", 20);
    add_item(&auction, "Item 3", 30);

    add_bid(&auction, "Bidder 1", 15);
    add_bid(&auction, "Bidder 2", 25);
    add_bid(&auction, "Bidder 3", 35);

    print_auction(&auction);

    free_auction(&auction);

    return 0;
}