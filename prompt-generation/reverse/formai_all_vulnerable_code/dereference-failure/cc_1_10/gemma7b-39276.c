//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_BIDS 10

typedef struct Bid {
    int bidder_id;
    int amount;
    struct Bid* next;
} Bid;

void insert_bid(Bid** head, int bidder_id, int amount) {
    Bid* new_bid = malloc(sizeof(Bid));
    new_bid->bidder_id = bidder_id;
    new_bid->amount = amount;
    new_bid->next = NULL;

    if (*head == NULL) {
        *head = new_bid;
    } else {
        (*head)->next = new_bid;
    }
}

int get_highest_bid(Bid* head) {
    if (head == NULL) {
        return 0;
    }

    Bid* current_bid = head;
    int highest_bid = current_bid->amount;

    while (current_bid->next) {
        current_bid = current_bid->next;
        if (current_bid->amount > highest_bid) {
            highest_bid = current_bid->amount;
        }
    }

    return highest_bid;
}

int main() {
    Bid* head = NULL;

    insert_bid(&head, 1, 10);
    insert_bid(&head, 2, 12);
    insert_bid(&head, 3, 14);
    insert_bid(&head, 4, 16);

    int highest_bid = get_highest_bid(head);

    printf("The highest bid is: %d\n", highest_bid);

    return 0;
}