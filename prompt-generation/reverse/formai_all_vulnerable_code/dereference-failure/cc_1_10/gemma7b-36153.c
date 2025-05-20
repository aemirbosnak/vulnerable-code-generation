//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

struct Bidder {
    char name[50];
    int bid;
    struct Bidder* next;
};

struct Auction {
    char item_name[50];
    int starting_price;
    struct Bidder* bidders;
    struct Auction* next;
};

void add_bidder(struct Auction* auction, char* name, int bid) {
    struct Bidder* new_bidder = malloc(sizeof(struct Bidder));
    strcpy(new_bidder->name, name);
    new_bidder->bid = bid;
    new_bidder->next = NULL;

    if (auction->bidders == NULL) {
        auction->bidders = new_bidder;
    } else {
        auction->bidders->next = new_bidder;
        auction->bidders = new_bidder;
    }
}

void start_auction(struct Auction* auction) {
    printf("Auction for item: %s\n", auction->item_name);
    printf("Starting price: %d\n", auction->starting_price);

    struct Bidder* bidder = auction->bidders;
    while (bidder) {
        printf("Bidder: %s, Bid: %d\n", bidder->name, bidder->bid);
        bidder = bidder->next;
    }

    printf("Enter your bid: ");
    int your_bid = atoi(stdin);

    if (your_bid > MAX_BID) {
        printf("Error: Your bid is too high.\n");
    } else if (your_bid < auction->starting_price) {
        printf("Error: Your bid is too low.\n");
    } else {
        add_bidder(auction, "John Doe", your_bid);
        printf("Your bid has been added.\n");
    }
}

int main() {
    struct Auction* auction = malloc(sizeof(struct Auction));
    strcpy(auction->item_name, "Laptop");
    auction->starting_price = 500;
    auction->bidders = NULL;
    auction->next = NULL;

    start_auction(auction);

    return 0;
}