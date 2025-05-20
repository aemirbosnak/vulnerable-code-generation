//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000

struct Bid {
    char bidder[20];
    int amount;
    struct Bid* next;
};

struct Item {
    char name[20];
    int reserve_price;
    struct Bid* bids;
    struct Item* next;
};

void add_bid(struct Item* item, char* bidder, int amount) {
    struct Bid* new_bid = malloc(sizeof(struct Bid));
    strcpy(new_bid->bidder, bidder);
    new_bid->amount = amount;
    new_bid->next = NULL;

    if (item->bids == NULL) {
        item->bids = new_bid;
    } else {
        item->bids->next = new_bid;
    }
}

void print_bids(struct Item* item) {
    struct Bid* current_bid = item->bids;
    printf("Bids for item: %s\n", item->name);
    while (current_bid) {
        printf("Bidder: %s, Amount: %d\n", current_bid->bidder, current_bid->amount);
        current_bid = current_bid->next;
    }
}

int main() {
    struct Item* items = NULL;

    // Create a few items
    struct Item* item1 = malloc(sizeof(struct Item));
    strcpy(item1->name, "Laptop");
    item1->reserve_price = 5000;
    item1->bids = NULL;

    struct Item* item2 = malloc(sizeof(struct Item));
    strcpy(item2->name, "Smartphone");
    item2->reserve_price = 3000;
    item2->bids = NULL;

    items = item1;
    items->next = item2;

    // Add some bids
    add_bid(item1, "John Doe", 6000);
    add_bid(item1, "Jane Doe", 4000);
    add_bid(item2, "Peter Pan", 2000);
    add_bid(item2, "Mary Poppins", 1000);

    // Print the bids
    print_bids(item1);
    print_bids(item2);

    return 0;
}