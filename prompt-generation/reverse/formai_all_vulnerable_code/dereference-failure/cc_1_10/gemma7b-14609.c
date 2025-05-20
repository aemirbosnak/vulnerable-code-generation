//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10

struct auction {
    char name[20];
    int start_price;
    int current_price;
    int num_bids;
    struct bidder *bidders;
};

struct bidder {
    char name[20];
    int bid_amount;
    struct bidder *next;
};

void create_auction(struct auction *auction) {
    auction->name[0] = '\0';
    auction->start_price = 0;
    auction->current_price = 0;
    auction->num_bids = 0;
    auction->bidders = NULL;
}

void add_bidder(struct auction *auction, struct bidder *bidder) {
    auction->num_bids++;
    auction->bidders = bidder;
}

void place_bid(struct auction *auction, struct bidder *bidder, int bid_amount) {
    struct bidder *new_bidder = malloc(sizeof(struct bidder));
    new_bidder->name[0] = '\0';
    new_bidder->bid_amount = bid_amount;
    new_bidder->next = NULL;

    if (auction->bidders == NULL) {
        auction->bidders = new_bidder;
    } else {
        struct bidder *current_bidder = auction->bidders;
        while (current_bidder->next) {
            current_bidder = current_bidder->next;
        }
        current_bidder->next = new_bidder;
    }

    auction->current_price = bid_amount;
}

void print_auction(struct auction *auction) {
    printf("Auction Name: %s\n", auction->name);
    printf("Start Price: %d\n", auction->start_price);
    printf("Current Price: %d\n", auction->current_price);
    printf("Number of Bids: %d\n", auction->num_bids);
    printf("Bidders:\n");
    struct bidder *current_bidder = auction->bidders;
    while (current_bidder) {
        printf("  %s: %d\n", current_bidder->name, current_bidder->bid_amount);
        current_bidder = current_bidder->next;
    }
}

int main() {
    struct auction *auction = malloc(sizeof(struct auction));
    create_auction(auction);

    struct bidder *bidder = malloc(sizeof(struct bidder));
    add_bidder(auction, bidder);
    place_bid(auction, bidder, 10);

    struct bidder *new_bidder = malloc(sizeof(struct bidder));
    add_bidder(auction, new_bidder);
    place_bid(auction, new_bidder, 12);

    print_auction(auction);

    return 0;
}