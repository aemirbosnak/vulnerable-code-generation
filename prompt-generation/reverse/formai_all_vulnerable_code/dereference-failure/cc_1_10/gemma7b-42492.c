//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

struct Bid {
    int bidder_id;
    int amount;
    struct Bid* next;
};

void insert_bid(struct Bid** head, int bidder_id, int amount) {
    struct Bid* new_bid = malloc(sizeof(struct Bid));
    new_bid->bidder_id = bidder_id;
    new_bid->amount = amount;
    new_bid->next = NULL;

    if (*head == NULL) {
        *head = new_bid;
    } else {
        (*head)->next = new_bid;
    }
}

void print_bids(struct Bid* head) {
    while (head) {
        printf("Bidder ID: %d, Amount: %d\n", head->bidder_id, head->amount);
        head = head->next;
    }
}

int main() {
    struct Bid* head = NULL;

    // Insert bids
    insert_bid(&head, 1, 5000);
    insert_bid(&head, 2, 6000);
    insert_bid(&head, 3, 7000);
    insert_bid(&head, 4, 8000);

    // Print bids
    print_bids(head);

    // Find the winner
    struct Bid* winner = head;
    while (winner->next) {
        if (winner->amount < winner->next->amount) {
            winner = winner->next;
        }
    }

    // Announce the winner
    printf("The winner is: Bidder ID: %d, Amount: %d\n", winner->bidder_id, winner->amount);

    return 0;
}