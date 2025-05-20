//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_AUCTIONS 10

struct Auction {
    char name[20];
    int start_price;
    int current_price;
    int num_bids;
    struct Bidder *bidders;
};

struct Bidder {
    char name[20];
    int bid_amount;
    struct Bidder *next;
};

void create_auction(struct Auction **auction) {
    *auction = (struct Auction *)malloc(sizeof(struct Auction));
    (*auction)->name[0] = '\0';
    (*auction)->start_price = 0;
    (*auction)->current_price = 0;
    (*auction)->num_bids = 0;
    (*auction)->bidders = NULL;
}

void add_bidder(struct Auction *auction, struct Bidder **bidder) {
    *bidder = (struct Bidder *)malloc(sizeof(struct Bidder));
    (*bidder)->name[0] = '\0';
    (*bidder)->bid_amount = 0;
    (*bidder)->next = NULL;

    if (auction->bidders == NULL) {
        auction->bidders = *bidder;
    } else {
        auction->bidders->next = *bidder;
        auction->bidders = *bidder;
    }

    auction->num_bids++;
}

void bid(struct Auction *auction, struct Bidder *bidder, int amount) {
    if (amount > auction->current_price) {
        auction->current_price = amount;
        bidder->bid_amount = amount;
    }
}

int main() {
    struct Auction *auction = NULL;
    create_auction(&auction);

    struct Bidder *bidder = NULL;
    add_bidder(auction, &bidder);

    bid(auction, bidder, 20);
    bid(auction, bidder, 25);

    printf("Current price: %d\n", auction->current_price);
    printf("Winner: %s\n", bidder->name);

    return 0;
}