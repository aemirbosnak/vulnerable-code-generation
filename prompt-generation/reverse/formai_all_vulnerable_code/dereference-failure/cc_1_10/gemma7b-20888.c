//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
};

struct Auction {
    char item_name[50];
    int starting_price;
    struct Bidder* bidders;
    struct Auction* next;
};

void place_bid(struct Auction* auction, struct Bidder* bidder, int bid) {
    if (bid > MAX_BID) {
        return;
    }

    struct Bidder* new_bidder = malloc(sizeof(struct Bidder));
    strcpy(new_bidder->name, bidder->name);
    new_bidder->bid = bid;
    new_bidder->next = NULL;

    if (auction->bidders == NULL) {
        auction->bidders = new_bidder;
    } else {
        struct Bidder* current_bidder = auction->bidders;
        while (current_bidder->next) {
            current_bidder = current_bidder->next;
        }
        current_bidder->next = new_bidder;
    }
}

int main() {
    struct Auction* auction = malloc(sizeof(struct Auction));
    strcpy(auction->item_name, "A rare diamond ring");
    auction->starting_price = 1000;
    auction->bidders = NULL;

    struct Bidder* bidder = malloc(sizeof(struct Bidder));
    strcpy(bidder->name, "John Doe");
    bidder->bid = 800;

    place_bid(auction, bidder, 800);

    bidder = malloc(sizeof(struct Bidder));
    strcpy(bidder->name, "Jane Doe");
    bidder->bid = 900;

    place_bid(auction, bidder, 900);

    struct Bidder* current_bidder = auction->bidders;
    while (current_bidder) {
        printf("%s: %d\n", current_bidder->name, current_bidder->bid);
    }

    return 0;
}