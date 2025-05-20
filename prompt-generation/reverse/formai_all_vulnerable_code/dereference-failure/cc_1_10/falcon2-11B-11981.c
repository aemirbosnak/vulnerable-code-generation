//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

struct bidder {
    int bid;
    char name[50];
};

struct auction {
    struct bidder* bidder;
    int num_bidders;
    int max_bid;
};

void print_auction(struct auction* auction) {
    printf("Auction with %d bidders\n", auction->num_bidders);
    printf("Max bid is %d\n", auction->max_bid);
    printf("Bidders:\n");
    for (int i = 0; i < auction->num_bidders; i++) {
        printf("Name: %s Bid: %d\n", auction->bidder[i].name, auction->bidder[i].bid);
    }
}

void add_bidder(struct auction* auction, char* name, int bid) {
    if (auction->num_bidders >= MAX_BID) {
        printf("No more bidders allowed\n");
        return;
    }

    struct bidder new_bidder = {.bid = bid,.name = name};

    auction->bidder = (struct bidder*)realloc(auction->bidder, (auction->num_bidders + 1) * sizeof(struct bidder));
    auction->bidder[auction->num_bidders] = new_bidder;
    auction->num_bidders++;
}

int main() {
    struct auction auction = {.bidder = NULL,.num_bidders = 0,.max_bid = 0};

    add_bidder(&auction, "Alice", 100);
    add_bidder(&auction, "Bob", 200);
    add_bidder(&auction, "Charlie", 300);

    print_auction(&auction);

    return 0;
}