//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10

typedef struct Auction {
    char *name;
    int starting_bid;
    int current_bid;
    int num_bids;
} Auction;

Auction auctions[MAX_AUCTIONS];

void initialize_auctions() {
    for (int i = 0; i < MAX_AUCTIONS; i++) {
        auctions[i].name = NULL;
        auctions[i].starting_bid = 0;
        auctions[i].current_bid = 0;
        auctions[i].num_bids = 0;
    }
}

void add_auction(char *name, int starting_bid) {
    for (int i = 0; i < MAX_AUCTIONS; i++) {
        if (auctions[i].name == NULL) {
            auctions[i].name = strdup(name);
            auctions[i].starting_bid = starting_bid;
            auctions[i].current_bid = starting_bid;
            auctions[i].num_bids = 0;
            return;
        }
    }

    printf("Error: No more auctions can be added.\n");
}

void bid_on_auction(char *name, int bid) {
    for (int i = 0; i < MAX_AUCTIONS; i++) {
        if (auctions[i].name == name) {
            if (bid > auctions[i].current_bid) {
                auctions[i].current_bid = bid;
                auctions[i].num_bids++;
                printf("Your bid of %d has been accepted.\n", bid);
            } else {
                printf("Your bid of %d is not higher than the current bid of %d.\n", bid, auctions[i].current_bid);
            }
            return;
        }
    }

    printf("Error: No auction with that name was found.\n");
}

void list_auctions() {
    for (int i = 0; i < MAX_AUCTIONS; i++) {
        if (auctions[i].name) {
            printf("%s: Starting bid %d, Current bid %d, Number of bids %d\n", auctions[i].name, auctions[i].starting_bid, auctions[i].current_bid, auctions[i].num_bids);
        }
    }
}

int main() {
    initialize_auctions();

    add_auction("Car", 10000);
    add_auction("House", 20000);
    add_auction("Electronics", 5000);

    bid_on_auction("Car", 12000);
    bid_on_auction("House", 22000);
    bid_on_auction("Electronics", 6000);

    list_auctions();

    return 0;
}