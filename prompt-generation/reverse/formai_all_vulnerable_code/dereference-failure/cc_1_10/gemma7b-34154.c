//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BIDS 10

typedef struct Bid {
    char bidder[20];
    int bid_amount;
    struct Bid* next;
} Bid;

void insert_bid(Bid** head, char* bidder, int bid_amount) {
    Bid* new_bid = malloc(sizeof(Bid));
    strcpy(new_bid->bidder, bidder);
    new_bid->bid_amount = bid_amount;
    new_bid->next = NULL;

    if (*head == NULL) {
        *head = new_bid;
    } else {
        (*head)->next = new_bid;
    }
}

int compare_bids(Bid* a, Bid* b) {
    return b->bid_amount - a->bid_amount;
}

void print_auction_results(Bid* head) {
    printf("Auction Results:\n");
    while (head) {
        printf("%s: %d\n", head->bidder, head->bid_amount);
        head = head->next;
    }
}

int main() {
    Bid* head = NULL;
    insert_bid(&head, "John Doe", 100);
    insert_bid(&head, "Jane Doe", 120);
    insert_bid(&head, "Bill Smith", 110);
    insert_bid(&head, "Mary Johnson", 130);

    qsort(head, MAX_BIDS, sizeof(Bid), compare_bids);

    print_auction_results(head);

    return 0;
}