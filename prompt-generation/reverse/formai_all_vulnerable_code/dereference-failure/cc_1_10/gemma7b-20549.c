//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID_AMOUNT 100000
#define MAX_NUMBER_OF_BIDS 10

typedef struct Bid {
    char *name;
    int amount;
    struct Bid *next;
} Bid;

Bid *insert_bid(Bid *head, char *name, int amount) {
    Bid *new_bid = malloc(sizeof(Bid));
    new_bid->name = strdup(name);
    new_bid->amount = amount;
    new_bid->next = NULL;

    if (head == NULL) {
        head = new_bid;
    } else {
        head->next = new_bid;
    }

    return head;
}

void print_bids(Bid *head) {
    while (head) {
        printf("%s: %d\n", head->name, head->amount);
        head = head->next;
    }
}

int main() {
    srand(time(NULL));

    Bid *head = NULL;

    // Simulate some bids
    insert_bid(head, "John Doe", rand() % MAX_BID_AMOUNT);
    insert_bid(head, "Jane Doe", rand() % MAX_BID_AMOUNT);
    insert_bid(head, "Bill Smith", rand() % MAX_BID_AMOUNT);

    // Print the bids
    print_bids(head);

    return 0;
}