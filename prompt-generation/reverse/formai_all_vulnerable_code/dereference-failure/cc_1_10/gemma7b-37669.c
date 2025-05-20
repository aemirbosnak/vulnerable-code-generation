//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10
#define MAX_BIDDERS 5

typedef struct Auction {
    char *name;
    int starting_price;
    int reserve_price;
    int current_bid;
    struct Bidder *highest_bidder;
} Auction;

typedef struct Bidder {
    char *name;
    int bid;
    struct Bidder *next;
} Bidder;

void initialize_auction(Auction *auction) {
    auction->name = malloc(20);
    auction->starting_price = 0;
    auction->reserve_price = 0;
    auction->current_bid = 0;
    auction->highest_bidder = NULL;
}

void add_bidder(Bidder **bidder_head, char *name, int bid) {
    Bidder *new_bidder = malloc(sizeof(Bidder));
    new_bidder->name = malloc(20);
    new_bidder->name = name;
    new_bidder->bid = bid;
    new_bidder->next = NULL;

    if (*bidder_head == NULL) {
        *bidder_head = new_bidder;
    } else {
        (*bidder_head)->next = new_bidder;
    }
}

void bid_on_auction(Auction *auction, char *bidder_name, int new_bid) {
    Bidder *highest_bidder = auction->highest_bidder;
    Bidder *new_highest_bidder = NULL;

    if (new_bid > auction->current_bid) {
        auction->current_bid = new_bid;
        highest_bidder = NULL;

        for (Bidder *bidder = auction->highest_bidder; bidder; bidder = bidder->next) {
            if (new_bid > bidder->bid) {
                new_highest_bidder = bidder;
            }
        }

        if (new_highest_bidder) {
            auction->highest_bidder = new_highest_bidder;
        }
    }
}

void print_auction(Auction *auction) {
    printf("Name: %s\n", auction->name);
    printf("Starting Price: %d\n", auction->starting_price);
    printf("Reserve Price: %d\n", auction->reserve_price);
    printf("Current Bid: %d\n", auction->current_bid);
    printf("Highest Bidder: %s\n", auction->highest_bidder->name);
}

int main() {
    Auction auctions[MAX_AUCTIONS];
    Bidder *bidders[MAX_BIDDERS];

    for (int i = 0; i < MAX_AUCTIONS; i++) {
        initialize_auction(&auctions[i]);
    }

    for (int i = 0; i < MAX_BIDDERS; i++) {
        bidders[i] = NULL;
    }

    // Add some auctions and bidders
    add_bidder(&bidders[0], "John Doe", 10);
    add_bidder(&bidders[0], "Jane Doe", 12);
    add_bidder(&bidders[0], "Bill Smith", 14);

    bid_on_auction(&auctions[0], "John Doe", 16);

    print_auction(&auctions[0]);

    return 0;
}