//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

struct Bid {
    char bidder_name[50];
    int bid_amount;
    struct Bid *next;
};

struct Auction {
    char item_name[50];
    int reserve_price;
    struct Bid *highest_bid;
    struct Auction *next;
};

void place_bid(struct Auction *auction, char *bidder_name, int bid_amount) {
    struct Bid *new_bid = (struct Bid *)malloc(sizeof(struct Bid));
    strcpy(new_bid->bidder_name, bidder_name);
    new_bid->bid_amount = bid_amount;
    new_bid->next = NULL;

    if (auction->highest_bid) {
        struct Bid *current_bid = auction->highest_bid;
        while (current_bid->next) {
            current_bid = current_bid->next;
        }
        current_bid->next = new_bid;
    } else {
        auction->highest_bid = new_bid;
    }
}

void print_auction(struct Auction *auction) {
    printf("Item: %s\n", auction->item_name);
    printf("Reserve Price: %d\n", auction->reserve_price);
    printf("Highest Bid: %d\n", auction->highest_bid->bid_amount);
    printf("Bidders:\n");
    struct Bid *current_bid = auction->highest_bid;
    while (current_bid) {
        printf("- %s: %d\n", current_bid->bidder_name, current_bid->bid_amount);
        current_bid = current_bid->next;
    }
}

int main() {
    struct Auction *auction = (struct Auction *)malloc(sizeof(struct Auction));
    strcpy(auction->item_name, "Diamond Ring");
    auction->reserve_price = 5000;
    auction->highest_bid = NULL;

    place_bid(auction, "John Doe", 6000);
    place_bid(auction, "Jane Doe", 4000);
    place_bid(auction, "Bill Smith", 3000);

    print_auction(auction);

    return 0;
}