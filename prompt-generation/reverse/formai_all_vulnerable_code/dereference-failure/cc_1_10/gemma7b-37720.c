//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 100

typedef struct Auction {
    char name[256];
    int starting_price;
    int current_price;
    int num_bids;
    struct Bidder *bidders;
} Auction;

typedef struct Bidder {
    char name[256];
    int bid;
    struct Bidder *next;
} Bidder;

void create_auction(Auction **auction) {
    *auction = malloc(sizeof(Auction));
    (*auction)->name[0] = '\0';
    (*auction)->starting_price = 0;
    (*auction)->current_price = 0;
    (*auction)->num_bids = 0;
    (*auction)->bidders = NULL;
}

void add_bidder(Auction *auction, Bidder **bidder) {
    *bidder = malloc(sizeof(Bidder));
    (*bidder)->name[0] = '\0';
    (*bidder)->bid = 0;
    (*bidder)->next = NULL;

    if (auction->bidders == NULL) {
        auction->bidders = bidder;
    } else {
        auction->bidders->next = bidder;
        auction->bidders = bidder;
    }

    auction->num_bids++;
}

void bid(Auction *auction, Bidder *bidder, int new_bid) {
    if (new_bid > bidder->bid) {
        bidder->bid = new_bid;

        if (new_bid > auction->current_price) {
            auction->current_price = new_bid;
        }

        auction->num_bids++;
    }
}

int main() {
    Auction *auction = NULL;
    Bidder *bidder = NULL;

    create_auction(&auction);
    add_bidder(auction, &bidder);
    add_bidder(auction, &bidder);

    bid(auction, bidder, 10);
    bid(auction, bidder, 12);
    bid(auction, bidder, 14);

    printf("Current price: %d\n", auction->current_price);
    printf("Number of bids: %d\n", auction->num_bids);

    return 0;
}