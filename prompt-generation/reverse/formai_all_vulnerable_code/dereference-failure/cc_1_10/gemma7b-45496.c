//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID_AMOUNT 10000

struct Bid {
    int bidder_id;
    int bid_amount;
    struct Bid* next;
};

struct Auction {
    char item_name[20];
    int reserve_price;
    struct Bid* head;
    struct Bid* current_bid;
};

void initializeAuction(struct Auction* auction) {
    auction->item_name[0] = '\0';
    auction->reserve_price = 0;
    auction->head = NULL;
    auction->current_bid = NULL;
}

void placeBid(struct Auction* auction, int bidder_id, int bid_amount) {
    struct Bid* new_bid = (struct Bid*)malloc(sizeof(struct Bid));
    new_bid->bidder_id = bidder_id;
    new_bid->bid_amount = bid_amount;
    new_bid->next = NULL;

    if (auction->head == NULL) {
        auction->head = new_bid;
    } else {
        auction->current_bid->next = new_bid;
    }

    auction->current_bid = new_bid;
}

int checkIfBidWon(struct Auction* auction, int bidder_id) {
    struct Bid* current_bid = auction->head;

    while (current_bid) {
        if (current_bid->bidder_id == bidder_id && current_bid->bid_amount > auction->reserve_price) {
            return 1;
        }
        current_bid = current_bid->next;
    }

    return 0;
}

int main() {
    struct Auction* auction = (struct Auction*)malloc(sizeof(struct Auction));
    initializeAuction(auction);

    placeBid(auction, 1, 5000);
    placeBid(auction, 2, 6000);
    placeBid(auction, 3, 7000);

    if (checkIfBidWon(auction, 2)) {
        printf("Congratulations, bidder 2, you won the auction!\n");
    }

    return 0;
}