//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

struct Bidder {
    char name[20];
    int bid;
    struct Bidder *next;
};

struct Auction {
    char item_name[50];
    int starting_price;
    struct Bidder *highest_bidder;
    struct Auction *next;
};

void place_bid(struct Auction *auction, char *bidder_name, int bid) {
    struct Bidder *new_bidder = (struct Bidder *)malloc(sizeof(struct Bidder));
    strcpy(new_bidder->name, bidder_name);
    new_bidder->bid = bid;
    new_bidder->next = NULL;

    if (auction->highest_bidder) {
        struct Bidder *current_bidder = auction->highest_bidder;
        while (current_bidder->next) {
            current_bidder = current_bidder->next;
        }
        current_bidder->next = new_bidder;
    } else {
        auction->highest_bidder = new_bidder;
    }

    if (new_bidder->bid > auction->starting_price) {
        auction->starting_price = new_bidder->bid;
    }
}

void print_auction(struct Auction *auction) {
    printf("Item name: %s\n", auction->item_name);
    printf("Starting price: %d\n", auction->starting_price);
    printf("Highest bidder: %s\n", auction->highest_bidder->name);
    printf("Highest bid: %d\n", auction->highest_bidder->bid);
}

int main() {
    struct Auction *auction = (struct Auction *)malloc(sizeof(struct Auction));
    strcpy(auction->item_name, "Diamond ring");
    auction->starting_price = 1000;
    auction->highest_bidder = NULL;

    place_bid(auction, "John Doe", 1500);
    place_bid(auction, "Jane Doe", 1200);
    place_bid(auction, "Bill Smith", 1300);

    print_auction(auction);

    return 0;
}