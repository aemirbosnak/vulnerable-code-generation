//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

typedef struct Bid {
    int bidder_id;
    int bid_amount;
    struct Bid* next;
} Bid;

Bid* insert_bid(Bid* head, int bidder_id, int bid_amount) {
    Bid* new_bid = (Bid*)malloc(sizeof(Bid));
    new_bid->bidder_id = bidder_id;
    new_bid->bid_amount = bid_amount;
    new_bid->next = NULL;

    if (head == NULL) {
        head = new_bid;
    } else {
        head->next = new_bid;
    }

    return head;
}

void print_bids(Bid* head) {
    while (head) {
        printf("Bidder ID: %d, Bid Amount: %d\n", head->bidder_id, head->bid_amount);
        head = head->next;
    }
}

int main() {
    Bid* bids = NULL;

    // Simulate some bids
    insert_bid(bids, 1, 500);
    insert_bid(bids, 2, 600);
    insert_bid(bids, 3, 700);
    insert_bid(bids, 4, 800);

    print_bids(bids);

    // Get the highest bid
    Bid* highest_bid = bids;
    while (highest_bid->next) {
        highest_bid = highest_bid->next;
    }

    printf("The highest bid is: %d\n", highest_bid->bid_amount);

    return 0;
}