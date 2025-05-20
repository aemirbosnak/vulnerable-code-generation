//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BIDS 10

typedef struct Bid {
    int bidder_id;
    double bid_amount;
    struct Bid* next;
} Bid;

Bid* create_bid(int bidder_id, double bid_amount) {
    Bid* new_bid = malloc(sizeof(Bid));
    new_bid->bidder_id = bidder_id;
    new_bid->bid_amount = bid_amount;
    new_bid->next = NULL;
    return new_bid;
}

void add_bid(Bid* head, int bidder_id, double bid_amount) {
    Bid* new_bid = create_bid(bidder_id, bid_amount);
    if (head == NULL) {
        head = new_bid;
    } else {
        new_bid->next = head;
        head = new_bid;
    }
}

double get_highest_bid(Bid* head) {
    if (head == NULL) {
        return 0;
    }
    double highest_bid = head->bid_amount;
    for (Bid* current_bid = head->next; current_bid; current_bid) {
        if (current_bid->bid_amount > highest_bid) {
            highest_bid = current_bid->bid_amount;
        }
    }
    return highest_bid;
}

int main() {
    int i, num_bids;
    double highest_bid, current_bid;
    Bid* head = NULL;

    printf("Enter the number of bids: ");
    scanf("%d", &num_bids);

    for (i = 0; i < num_bids; i++) {
        printf("Enter the bidder ID: ");
        int bidder_id;
        scanf("%d", &bidder_id);

        printf("Enter the bid amount: ");
        double bid_amount;
        scanf("%lf", &bid_amount);

        add_bid(head, bidder_id, bid_amount);
    }

    highest_bid = get_highest_bid(head);

    printf("The highest bid is: $%.2lf", highest_bid);

    return 0;
}