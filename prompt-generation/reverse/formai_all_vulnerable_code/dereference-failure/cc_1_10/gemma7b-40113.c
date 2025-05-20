//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 1000

struct Bid {
    char name[20];
    int bid;
    struct Bid* next;
};

struct Item {
    char name[20];
    int starting_price;
    struct Bid* highest_bid;
    struct Item* next;
};

void insert_bid(struct Bid** head, char* name, int bid) {
    struct Bid* new_bid = (struct Bid*)malloc(sizeof(struct Bid));
    strcpy(new_bid->name, name);
    new_bid->bid = bid;
    new_bid->next = NULL;

    if (*head == NULL) {
        *head = new_bid;
    } else {
        (*head)->next = new_bid;
    }
}

void insert_item(struct Item** head, char* name, int starting_price) {
    struct Item* new_item = (struct Item*)malloc(sizeof(struct Item));
    strcpy(new_item->name, name);
    new_item->starting_price = starting_price;
    new_item->highest_bid = NULL;
    new_item->next = NULL;

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

int main() {
    struct Item* items = NULL;
    insert_item(&items, "Laptop", 1000);
    insert_item(&items, "Phone", 800);
    insert_item(&items, "Watch", 600);

    struct Bid* bids = NULL;
    insert_bid(&bids, "John Doe", 900);
    insert_bid(&bids, "Jane Doe", 700);
    insert_bid(&bids, "Peter Pan", 500);

    int highest_bid = 0;
    for (struct Item* item = items; item; item++) {
        for (struct Bid* bid = bids; bid; bid++) {
            if (bid->bid > highest_bid && item->name == bid->name) {
                highest_bid = bid->bid;
            }
        }
    }

    printf("The highest bid is: $%d\n", highest_bid);

    return 0;
}