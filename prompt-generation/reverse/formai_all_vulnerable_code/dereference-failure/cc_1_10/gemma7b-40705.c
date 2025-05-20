//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000

typedef struct Bid {
    char bidder[20];
    int bid_amount;
    struct Bid* next;
} Bid;

Bid* create_bid(char* bidder, int bid_amount) {
    Bid* new_bid = (Bid*)malloc(sizeof(Bid));
    strcpy(new_bid->bidder, bidder);
    new_bid->bid_amount = bid_amount;
    new_bid->next = NULL;
    return new_bid;
}

void add_bid(Bid* head, char* bidder, int bid_amount) {
    Bid* new_bid = create_bid(bidder, bid_amount);
    if (head == NULL) {
        head = new_bid;
    } else {
        head->next = new_bid;
        head = new_bid;
    }
}

int get_highest_bid(Bid* head) {
    if (head == NULL) {
        return 0;
    }
    int highest_bid = head->bid_amount;
    for (Bid* current = head->next; current; current) {
        if (current->bid_amount > highest_bid) {
            highest_bid = current->bid_amount;
        }
    }
    return highest_bid;
}

int main() {
    Bid* head = NULL;
    add_bid(head, "John Doe", 5000);
    add_bid(head, "Jane Doe", 6000);
    add_bid(head, "Bill Smith", 7000);
    add_bid(head, "Mary Johnson", 8000);

    int highest_bid = get_highest_bid(head);

    printf("The highest bid is: %d", highest_bid);

    return 0;
}