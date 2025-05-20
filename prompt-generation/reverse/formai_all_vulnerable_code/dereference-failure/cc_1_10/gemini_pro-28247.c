//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[50];
    int price;
    int quantity;
};

struct Auction {
    struct Item item;
    int max_price;
    int min_price;
    int current_price;
    int num_bids;
    char **bidders;
};

void add_item(struct Auction *auction, struct Item item) {
    auction->item = item;
    auction->max_price = item.price;
    auction->min_price = item.price;
    auction->current_price = item.price;
    auction->num_bids = 0;
    auction->bidders = NULL;
}

void bid(struct Auction *auction, char *bidder, int price) {
    if (price > auction->max_price) {
        auction->max_price = price;
        auction->current_price = price;
        if (auction->bidders) {
            free(auction->bidders);
            auction->bidders = (char **)malloc(sizeof(char *) * auction->num_bids);
        } else {
            auction->bidders = (char **)malloc(sizeof(char *));
        }
        auction->bidders[auction->num_bids++] = strdup(bidder);
    }
}

void end_auction(struct Auction *auction) {
    if (auction->num_bids > 0) {
        printf("The winner is %s with a bid of %d.\n", auction->bidders[auction->num_bids - 1], auction->current_price);
    } else {
        printf("No bids were received for this item.\n");
    }
}

int main() {
    struct Auction auction;

    struct Item item;
    strcpy(item.name, "iPhone 13");
    item.price = 1000;
    item.quantity = 1;

    add_item(&auction, item);

    bid(&auction, "John Doe", 1100);
    bid(&auction, "Jane Doe", 1200);
    bid(&auction, "John Doe", 1300);

    end_auction(&auction);

    return 0;
}