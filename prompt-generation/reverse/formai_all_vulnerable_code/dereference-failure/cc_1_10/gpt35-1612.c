//FormAI DATASET v1.0 Category: Digital Auction System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct Bid {
    char *bidder_name;
    float amount;
} Bid;

typedef struct Auction {
    char *item_name;
    float starting_amount;
    Bid *current_bid;
    int bids_count;
    Bid **bids;
} Auction;

Auction *create_auction(char *item_name, float starting_amount) {
    Auction *auction = malloc(sizeof(Auction));
    auction->item_name = item_name;
    auction->starting_amount = starting_amount;
    auction->current_bid = malloc(sizeof(Bid));
    auction->current_bid->bidder_name = "No bids yet";
    auction->current_bid->amount = starting_amount;
    auction->bids = calloc(5, sizeof(Bid*));
    auction->bids_count = 0;
    return auction;
}

void place_bid(Auction *auction, char *bidder_name, float new_amount) {
    if (new_amount > auction->current_bid->amount) {
        Bid *new_bid = malloc(sizeof(Bid));
        new_bid->bidder_name = bidder_name;
        new_bid->amount = new_amount;
        auction->bids[auction->bids_count] = new_bid;
        auction->bids_count++;
        auction->current_bid = new_bid;
    } else {
        printf("Your bid must be higher than the current bid of %.2f\n", auction->current_bid->amount);
    }
}

void print_auction(Auction *auction) {
    printf("Item: %s\nStarting Amount: $%.2f\nCurrent Bid: $%.2f by %s\n\n", 
            auction->item_name, auction->starting_amount, auction->current_bid->amount, auction->current_bid->bidder_name);
}

int main() {
    Auction *bicycle_auction = create_auction("Bicycle", 50.00);
    print_auction(bicycle_auction);

    place_bid(bicycle_auction, "Alice", 70.00);
    place_bid(bicycle_auction, "Bob", 75.00);
    place_bid(bicycle_auction, "Charlie", 60.00);
    place_bid(bicycle_auction, "Dave", 100.00);
    place_bid(bicycle_auction, "Eve", 95.00);
    place_bid(bicycle_auction, "Frank", 80.00);

    print_auction(bicycle_auction);

    return 0;
}