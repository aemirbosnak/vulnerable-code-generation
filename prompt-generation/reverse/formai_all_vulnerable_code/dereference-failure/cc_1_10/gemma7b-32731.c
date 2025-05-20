//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

typedef struct Bid {
    int bidder_id;
    int amount;
    struct Bid* next;
} Bid;

Bid* create_bid(int bidder_id, int amount) {
    Bid* new_bid = malloc(sizeof(Bid));
    new_bid->bidder_id = bidder_id;
    new_bid->amount = amount;
    new_bid->next = NULL;
    return new_bid;
}

void add_bid(Bid* head, int bidder_id, int amount) {
    Bid* new_bid = create_bid(bidder_id, amount);
    if (head == NULL) {
        head = new_bid;
    } else {
        new_bid->next = head;
        head = new_bid;
    }
}

int main() {
    Bid* head = NULL;
    int i = 0;
    time_t t = time(NULL);

    // Simulate some bids
    for (i = 0; i < 10; i++) {
        add_bid(head, i, MAX_BID - i);
    }

    // Print the bids
    for (head = head; head; head = head->next) {
        printf("Bidder ID: %d, Amount: %d\n", head->bidder_id, head->amount);
    }

    // Calculate the winner
    Bid* winner = head;
    for (head = head->next; head; head = head->next) {
        if (winner->amount < head->amount) {
            winner = head;
        }
    }

    // Print the winner
    printf("Winner: Bidder ID: %d, Amount: %d\n", winner->bidder_id, winner->amount);

    return 0;
}