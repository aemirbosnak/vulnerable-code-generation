//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000
#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    int starting_bid;
    struct Bid *highest_bid;
} Item;

typedef struct Bid {
    int amount;
    struct Bid *next;
} Bid;

Item items[MAX_ITEMS] = {
    {"Laptop", 1, 500, NULL},
    {"Smartphone", 2, 300, NULL},
    {"Watch", 3, 200, NULL}
};

void place_bid(Item *item) {
    Bid *new_bid = malloc(sizeof(Bid));
    new_bid->amount = MAX_BID;

    if (item->highest_bid == NULL) {
        item->highest_bid = new_bid;
    } else {
        item->highest_bid->next = new_bid;
    }

    printf("Your bid has been placed. The current highest bid is $%d\n", item->highest_bid->amount);
}

void auction_close(Item *item) {
    Bid *highest_bid = item->highest_bid;

    if (highest_bid) {
        printf("The item has been sold to %s for $%d\n", highest_bid->amount, highest_bid->amount);
    } else {
        printf("No bids were placed for this item.\n");
    }
}

int main() {
    int i;

    for (i = 0; i < MAX_ITEMS; i++) {
        place_bid(&items[i]);
    }

    for (i = 0; i < MAX_ITEMS; i++) {
        auction_close(&items[i]);
    }

    return 0;
}