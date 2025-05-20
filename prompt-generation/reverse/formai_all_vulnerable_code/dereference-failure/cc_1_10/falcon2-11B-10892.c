//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int item_id;
    int bid_amount;
} bid_t;

typedef struct {
    bid_t *bids;
    int num_bids;
} auction_t;

void add_bid(auction_t *auction, int item_id, int bid_amount) {
    if (auction->num_bids == 0) {
        auction->bids = (bid_t *)malloc(sizeof(bid_t));
    } else {
        auction->bids = (bid_t *)realloc(auction->bids, (auction->num_bids + 1) * sizeof(bid_t));
    }

    auction->bids[auction->num_bids].item_id = item_id;
    auction->bids[auction->num_bids].bid_amount = bid_amount;

    auction->num_bids++;
}

void print_bids(auction_t *auction) {
    for (int i = 0; i < auction->num_bids; i++) {
        printf("Bid %d: item_id=%d, bid_amount=%d\n", i, auction->bids[i].item_id, auction->bids[i].bid_amount);
    }
}

int main() {
    srand(time(NULL));

    auction_t auction;
    auction.bids = NULL;
    auction.num_bids = 0;

    int item_id = rand() % 100;
    int bid_amount = rand() % 100;

    add_bid(&auction, item_id, bid_amount);
    add_bid(&auction, item_id, bid_amount + 10);

    print_bids(&auction);

    return 0;
}