//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10
#define MAX_BIDDERS 20

typedef struct Auction {
    char name[20];
    int start_price;
    int reserve_price;
    int current_bid;
    struct Bidder *bidders;
} Auction;

typedef struct Bidder {
    char name[20];
    int bid;
    struct Bidder *next;
} Bidder;

void create_auction(Auction **auction) {
    *auction = malloc(sizeof(Auction));
    (*auction)->name[0] = '\0';
    (*auction)->start_price = 0;
    (*auction)->reserve_price = 0;
    (*auction)->current_bid = 0;
    (*auction)->bidders = NULL;
}

void add_bidder(Auction *auction, Bidder **bidder) {
    *bidder = malloc(sizeof(Bidder));
    (*bidder)->name[0] = '\0';
    (*bidder)->bid = 0;
    (*bidder)->next = NULL;

    if (auction->bidders == NULL) {
        auction->bidders = *bidder;
    } else {
        auction->bidders->next = *bidder;
        auction->bidders = *bidder;
    }
}

void place_bid(Auction *auction, Bidder *bidder, int bid) {
    if (bid > auction->current_bid) {
        auction->current_bid = bid;
        bidder->bid = bid;
    }
}

void auction_end(Auction *auction) {
    if (auction->current_bid >= auction->reserve_price) {
        printf("Congratulations, %s, you won the auction for %s at %d.\n", auction->bidders->name, auction->name, auction->current_bid);
    } else {
        printf("Sorry, %s, you were not successful in the auction for %s.\n", auction->bidders->name, auction->name);
    }
    free(auction);
}

int main() {
    Auction *auction;
    Bidder *bidder;

    create_auction(&auction);
    add_bidder(auction, &bidder);
    add_bidder(auction, &bidder);
    place_bid(auction, bidder, 10);
    place_bid(auction, bidder, 12);
    place_bid(auction, bidder, 14);
    auction_end(auction);

    return 0;
}