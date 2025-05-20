//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: shape shifting
// A kaleidoscopic canvas of digital desires and delights...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Metamorphosis: A dance of structs, each a prism of data.
typedef struct Item {
    char *name;
    double reserve;
    double bid;
} Item;

typedef struct Bidder {
    char *name;
    double funds;
} Bidder;

typedef struct Auction {
    Item item;
    Bidder *bidders;
    int numBidders;
} Auction;

// Prismatic hues of functions, illuminating the auction arena.

Auction *auction_create(char *item, double reserve) {
    Auction *auction = malloc(sizeof(Auction));
    auction->item.name = malloc(strlen(item) + 1);
    strcpy(auction->item.name, item);
    auction->item.reserve = reserve;
    auction->item.bid = 0;
    auction->bidders = NULL;
    auction->numBidders = 0;
    return auction;
}

void auction_destroy(Auction *auction) {
    free(auction->item.name);
    for (int i = 0; i < auction->numBidders; i++) {
        free(auction->bidders[i].name);
    }
    free(auction->bidders);
    free(auction);
}

Bidder *bidder_create(char *name, double funds) {
    Bidder *bidder = malloc(sizeof(Bidder));
    bidder->name = malloc(strlen(name) + 1);
    strcpy(bidder->name, name);
    bidder->funds = funds;
    return bidder;
}

void bidder_destroy(Bidder *bidder) {
    free(bidder->name);
    free(bidder);
}

void auction_add_bidder(Auction *auction, Bidder *bidder) {
    auction->bidders = realloc(auction->bidders, sizeof(Bidder) * (auction->numBidders + 1));
    auction->bidders[auction->numBidders++] = *bidder;
}

double auction_get_current_bid(Auction *auction) {
    return auction->item.bid;
}

Bidder *auction_get_current_winner(Auction *auction) {
    Bidder *winner = NULL;
    for (int i = 0; i < auction->numBidders; i++) {
        if (auction->bidders[i].funds >= auction->item.bid && (winner == NULL || auction->bidders[i].funds > winner->funds)) {
            winner = &auction->bidders[i];
        }
    }
    return winner;
}

void auction_place_bid(Auction *auction, Bidder *bidder, double amount) {
    if (amount > bidder->funds || amount < auction->item.reserve) {
        printf("Invalid bid: %s tries to bid $%.2f, but has only $%.2f and the reserve is $%.2f.\n", bidder->name, amount, bidder->funds, auction->item.reserve);
    } else {
        auction->item.bid = amount;
        printf("%s bids $%.2f on %s (current bid: $%.2f).\n", bidder->name, amount, auction->item.name, auction->item.bid);
    }
}

void auction_close(Auction *auction) {
    Bidder *winner = auction_get_current_winner(auction);
    if (winner == NULL) {
        printf("No bids placed on %s (reserve: $%.2f).\n", auction->item.name, auction->item.reserve);
    } else {
        printf("%s wins %s for $%.2f!\n", winner->name, auction->item.name, auction->item.bid);
    }
}

// The auction unfolds, a symphony of bids and desires...

int main() {
    Auction *auction = auction_create("Mona Lisa", 1000000.0);
    auction_add_bidder(auction, bidder_create("Alice", 500000.0));
    auction_add_bidder(auction, bidder_create("Bob", 750000.0));
    auction_add_bidder(auction, bidder_create("Carol", 1000000.0));

    auction_place_bid(auction, &auction->bidders[0], 600000.0);
    auction_place_bid(auction, &auction->bidders[1], 800000.0);
    auction_place_bid(auction, &auction->bidders[2], 1100000.0);

    auction_close(auction);
    auction_destroy(auction);

    return 0;
}