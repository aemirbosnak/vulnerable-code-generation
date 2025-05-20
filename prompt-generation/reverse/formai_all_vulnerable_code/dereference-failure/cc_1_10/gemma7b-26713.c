//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_BID 100000
#define MAX_ITEM_NAME_LENGTH 255

typedef struct Bid {
    char *name;
    int amount;
    struct Bid *next;
} Bid;

typedef struct Item {
    char *name;
    int reserve_price;
    Bid *highest_bid;
} Item;

Item *create_item(char *name, int reserve_price) {
    Item *item = malloc(sizeof(Item));
    item->name = strdup(name);
    item->reserve_price = reserve_price;
    item->highest_bid = NULL;
    return item;
}

Bid *create_bid(char *name, int amount) {
    Bid *bid = malloc(sizeof(Bid));
    bid->name = strdup(name);
    bid->amount = amount;
    bid->next = NULL;
    return bid;
}

void place_bid(Item *item, Bid *new_bid) {
    if (item->highest_bid == NULL || new_bid->amount > item->highest_bid->amount) {
        item->highest_bid = new_bid;
    }
}

int main() {
    Item *item = create_item("Diamond Ring", 5000);
    Bid *highest_bid = create_bid("John Doe", 4000);
    place_bid(item, highest_bid);

    highest_bid = create_bid("Jane Doe", 4500);
    place_bid(item, highest_bid);

    highest_bid = create_bid("Bill Smith", 6000);
    place_bid(item, highest_bid);

    printf("The highest bid is: %s with an amount of %d\n", item->highest_bid->name, item->highest_bid->amount);

    return 0;
}