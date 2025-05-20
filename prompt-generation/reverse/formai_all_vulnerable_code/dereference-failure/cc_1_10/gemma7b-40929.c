//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: peaceful
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
        auction->bidders = bidder;
    } else {
        auction->bidders->next = bidder;
        auction->bidders = bidder;
    }

    auction->num_bids++;
}

void bid(struct Auction *auction, struct Bidder *bidder, int amount) {
    if (amount > bidder->bid_amount) {
        bidder->bid_amount = amount;
    }
}

int main() {
    struct Auction *auction;
    create_auction(&auction);

    struct Bidder *bidder1, *bidder2, *bidder3;
    add_bidder(auction, &bidder1);
    add_bidder(auction, &bidder2);
    add_bidder(auction, &bidder3);

    bid(auction, bidder1, 10);
    bid(auction, bidder2, 12);
    bid(auction, bidder3, 15);

    printf("Auction name: %s\n", auction->name);
    printf("Start price: %d\n", auction->start_price);
    printf("Current price: %d\n", auction->current_price);
    printf("Number of bids: %d\n", auction->num_bids);

    printf("Bidders:\n");
    struct Bidder *current_bidder = auction->bidders;
    while (current_bidder) {
        printf("Name: %s\n", current_bidder->name);
        printf("Bid amount: %d\n", current_bidder->bid_amount);
        printf("\n");
        current_bidder = current_bidder->next;
    }

    return 0;
}