//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10
#define MAX_BIDS 20

struct Auction {
    char name[50];
    int start_price;
    int reserve_price;
    int num_bids;
    struct Bid *bids;
};

struct Bid {
    char bidder_name[50];
    int bid_amount;
    struct Bid *next;
};

void create_auction(struct Auction **auction) {
    *auction = (struct Auction *)malloc(sizeof(struct Auction));
    (*auction)->num_bids = 0;
    (*auction)->bids = NULL;
}

void add_bid(struct Auction *auction, char *bidder_name, int bid_amount) {
    struct Bid *new_bid = (struct Bid *)malloc(sizeof(struct Bid));
    strcpy(new_bid->bidder_name, bidder_name);
    new_bid->bid_amount = bid_amount;
    new_bid->next = NULL;

    if (auction->num_bids == 0) {
        auction->bids = new_bid;
    } else {
        struct Bid *last_bid = auction->bids;
        while (last_bid->next) {
            last_bid = last_bid->next;
        }
        last_bid->next = new_bid;
    }

    auction->num_bids++;
}

int main() {
    struct Auction *auction = NULL;
    create_auction(&auction);

    add_bid(auction, "John Doe", 100);
    add_bid(auction, "Jane Doe", 120);
    add_bid(auction, "Bob Smith", 110);

    printf("Number of bids: %d\n", auction->num_bids);

    struct Bid *bid = auction->bids;
    while (bid) {
        printf("Bidder name: %s\n", bid->bidder_name);
        printf("Bid amount: %d\n", bid->bid_amount);
        printf("\n");
        bid = bid->next;
    }

    return 0;
}