//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10

struct Bid {
    char bidder[20];
    int bid_amount;
    struct Bid* next;
};

struct Auction {
    struct Bid* head;
    int current_price;
    char item_name[20];
    int num_bids;
};

void add_bid(struct Auction* auction, char* bidder, int bid_amount) {
    struct Bid* new_bid = malloc(sizeof(struct Bid));
    strcpy(new_bid->bidder, bidder);
    new_bid->bid_amount = bid_amount;
    new_bid->next = NULL;

    if (auction->head == NULL) {
        auction->head = new_bid;
    } else {
        auction->head->next = new_bid;
    }

    auction->num_bids++;
}

void print_bids(struct Auction* auction) {
    struct Bid* current_bid = auction->head;
    while (current_bid) {
        printf("%s: %d\n", current_bid->bidder, current_bid->bid_amount);
        current_bid = current_bid->next;
    }
}

int main() {
    struct Auction* auction = malloc(sizeof(struct Auction));
    auction->head = NULL;
    auction->current_price = 0;
    auction->num_bids = 0;
    auction->item_name[0] = '\0';

    add_bid(auction, "John Doe", 100);
    add_bid(auction, "Jane Doe", 120);
    add_bid(auction, "Bill Smith", 110);

    print_bids(auction);

    return 0;
}