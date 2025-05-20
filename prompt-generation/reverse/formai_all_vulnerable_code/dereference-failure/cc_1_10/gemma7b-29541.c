//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 10000

struct Bid {
    char bidder[50];
    int bid_amount;
    struct Bid* next;
};

struct Item {
    char item_name[50];
    int reserve_price;
    struct Bid* highest_bid;
    struct Item* next;
};

void insert_bid(struct Bid** head, char* bidder, int bid_amount) {
    struct Bid* new_bid = (struct Bid*)malloc(sizeof(struct Bid));
    strcpy(new_bid->bidder, bidder);
    new_bid->bid_amount = bid_amount;
    new_bid->next = NULL;

    if (*head == NULL) {
        *head = new_bid;
    } else {
        (*head)->next = new_bid;
    }
}

void insert_item(struct Item** head, char* item_name, int reserve_price) {
    struct Item* new_item = (struct Item*)malloc(sizeof(struct Item));
    strcpy(new_item->item_name, item_name);
    new_item->reserve_price = reserve_price;
    new_item->highest_bid = NULL;
    new_item->next = NULL;

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

void display_bids(struct Bid* head) {
    struct Bid* current = head;
    while (current) {
        printf("%s: %d\n", current->bidder, current->bid_amount);
        current = current->next;
    }
}

void display_items(struct Item* head) {
    struct Item* current = head;
    while (current) {
        printf("%s: %d\n", current->item_name, current->reserve_price);
        current = current->next;
    }
}

int main() {
    struct Bid* bids = NULL;
    struct Item* items = NULL;

    insert_item(&items, "Laptop", 10000);
    insert_item(&items, "Phone", 8000);
    insert_item(&items, "Tablet", 6000);

    insert_bid(&bids, "John Doe", 9000);
    insert_bid(&bids, "Jane Doe", 8500);
    insert_bid(&bids, "Peter Pan", 7000);

    display_bids(bids);
    display_items(items);

    return 0;
}