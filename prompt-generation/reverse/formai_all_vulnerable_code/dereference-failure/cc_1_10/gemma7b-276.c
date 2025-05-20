//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_BIDS 10

struct Bid {
    char name[20];
    int amount;
    struct Bid* next;
};

struct Item {
    char name[20];
    int starting_price;
    struct Bid* highest_bid;
    struct Item* next;
};

void insert_bid(struct Bid** head, char* name, int amount) {
    struct Bid* new_bid = (struct Bid*)malloc(sizeof(struct Bid));
    strcpy(new_bid->name, name);
    new_bid->amount = amount;
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
    insert_item(&items, "Apple", 100);
    insert_item(&items, "Banana", 200);
    insert_item(&items, "Orange", 300);

    struct Bid* bids = NULL;
    insert_bid(&bids, "John Doe", 50);
    insert_bid(&bids, "Jane Doe", 70);
    insert_bid(&bids, "Peter Pan", 80);

    // Auction process
    for (struct Item* item = items; item; item = item->next) {
        printf("Item: %s, Starting Price: %d\n", item->name, item->starting_price);

        for (struct Bid* bid = bids; bid; bid = bid->next) {
            printf("Bidder: %s, Amount: %d\n", bid->name, bid->amount);
        }

        // Determine highest bid
        struct Bid* highest_bid = NULL;
        for (struct Bid* bid = bids; bid; bid = bid->next) {
            if (highest_bid == NULL || bid->amount > highest_bid->amount) {
                highest_bid = bid;
            }
        }

        // Announce the winner
        if (highest_bid) {
            printf("The winner is: %s with a bid of %d\n", highest_bid->name, highest_bid->amount);
        } else {
            printf("No bids received.\n");
        }
    }

    return 0;
}