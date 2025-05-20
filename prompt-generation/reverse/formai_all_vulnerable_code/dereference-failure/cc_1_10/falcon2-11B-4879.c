//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

struct bid {
    int id;
    int amount;
    int bidder;
};

struct auction {
    int highest_bid;
    struct bid* bids;
    int num_bids;
};

void add_bid(struct auction* auction, int bid_id, int bid_amount, int bidder) {
    if (auction->num_bids == 0) {
        auction->highest_bid = bid_amount;
    } else if (bid_amount > auction->highest_bid) {
        auction->highest_bid = bid_amount;
    }

    struct bid* new_bid = malloc(sizeof(struct bid));
    new_bid->id = bid_id;
    new_bid->amount = bid_amount;
    new_bid->bidder = bidder;

    auction->bids = realloc(auction->bids, (auction->num_bids + 1) * sizeof(struct bid));
    auction->bids[auction->num_bids++] = *new_bid;
}

int main() {
    struct auction auction;

    auction.num_bids = 0;
    auction.highest_bid = 0;
    auction.bids = NULL;

    add_bid(&auction, 1, 100, 1);
    add_bid(&auction, 2, 150, 2);
    add_bid(&auction, 3, 200, 3);
    add_bid(&auction, 4, 120, 4);

    printf("Highest bid: %d\n", auction.highest_bid);
    printf("Bids:\n");
    for (int i = 0; i < auction.num_bids; i++) {
        printf("Bid %d: %d\n", auction.bids[i].id, auction.bids[i].amount);
    }

    return 0;
}