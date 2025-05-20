//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

typedef struct Bid {
    int bidder_id;
    double bid_amount;
    struct Bid* next;
} Bid;

Bid* insert_bid(Bid* head, int bidder_id, double bid_amount) {
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
        printf("Bidder ID: %d, Bid Amount: %.2lf\n", head->bidder_id, head->bid_amount);
        head = head->next;
    }
}

int main() {
    Bid* head = NULL;

    // Insert bids
    insert_bid(head, 1, 5000);
    insert_bid(head, 2, 4000);
    insert_bid(head, 3, 3000);
    insert_bid(head, 4, 2000);

    // Print bids
    print_bids(head);

    // Find the highest bid
    Bid* highest_bid = head;
    while (highest_bid->next) {
        if (highest_bid->bid_amount < highest_bid->next->bid_amount) {
            highest_bid = highest_bid->next;
        }
    }

    // Print the highest bid
    printf("The highest bid is: Bidder ID: %d, Bid Amount: %.2lf\n", highest_bid->bidder_id, highest_bid->bid_amount);

    return 0;
}