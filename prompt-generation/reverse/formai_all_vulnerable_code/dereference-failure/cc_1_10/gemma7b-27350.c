//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

typedef struct Bid {
    int bidder_id;
    int bid_amount;
    struct Bid* next;
} Bid;

void insert_bid(Bid** head, int bidder_id, int bid_amount) {
    Bid* new_bid = malloc(sizeof(Bid));
    new_bid->bid_amount = bid_amount;
    new_bid->bidder_id = bidder_id;
    new_bid->next = NULL;

    if (*head == NULL) {
        *head = new_bid;
    } else {
        (*head)->next = new_bid;
    }
}

int find_highest_bid(Bid* head) {
    int highest_bid = 0;

    while (head) {
        if (head->bid_amount > highest_bid) {
            highest_bid = head->bid_amount;
        }
        head = head->next;
    }

    return highest_bid;
}

int main() {
    Bid* bids = NULL;

    // Simulate some bids
    insert_bid(&bids, 1, 500);
    insert_bid(&bids, 2, 600);
    insert_bid(&bids, 3, 700);
    insert_bid(&bids, 4, 800);

    // Find the highest bid
    int highest_bid = find_highest_bid(bids);

    // Print the highest bid
    printf("The highest bid is: %d", highest_bid);

    return 0;
}