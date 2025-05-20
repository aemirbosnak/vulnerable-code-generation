//FormAI DATASET v1.0 Category: Digital Auction System ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Bid {
    char bidder_name[25];
    int bid_amount;
    struct Bid *next_bid;
};

struct Item {
    int item_id;
    char item_name[25];
    int starting_bid_price;
    int current_bid_price;
    struct Bid *bids;
    struct Item *next_item;
};

struct Item *items = NULL;

void add_item(int item_id, char *item_name, int starting_bid_price) {
    struct Item *new_item = (struct Item *) malloc(sizeof(struct Item));
    new_item->item_id = item_id;
    strcpy(new_item->item_name, item_name);
    new_item->starting_bid_price = starting_bid_price;
    new_item->current_bid_price = starting_bid_price;
    new_item->bids = NULL;
    new_item->next_item = items;
    items = new_item;
}

void add_bid(int item_id, char *bidder_name, int bid_amount) {
    struct Item *current = items;
    while (current != NULL && current->item_id != item_id)
        current = current->next_item;
    if (current == NULL)
        printf("Item not found\n");
    else {
        struct Bid *new_bid = (struct Bid *) malloc(sizeof(struct Bid));
        strcpy(new_bid->bidder_name, bidder_name);
        new_bid->bid_amount = bid_amount;
        new_bid->next_bid = current->bids;
        current->bids = new_bid;
        current->current_bid_price = bid_amount;
    }
}

void display_items() {
    struct Item *current = items;
    while (current != NULL) {
        printf("Item ID: %d\n", current->item_id);
        printf("Item Name: %s\n", current->item_name);
        printf("Starting Bid Price: %d\n", current->starting_bid_price);
        printf("Current Bid Price: %d\n", current->current_bid_price);
        if (current->bids == NULL)
            printf("No bids yet\n");
        else {
            printf("Bids:\n");
            struct Bid *current_bid = current->bids;
            while (current_bid != NULL) {
                printf("Bidder Name: %s\n", current_bid->bidder_name);
                printf("Bid Amount: %d\n", current_bid->bid_amount);
                current_bid = current_bid->next_bid;
            }
        }
        current = current->next_item;
    }
}

int main() {
    add_item(1, "Ring", 100);
    add_bid(1, "John", 120);
    add_bid(1, "Mike", 150);
    add_item(2, "Necklace", 200);
    add_bid(2, "Sara", 220);
    add_bid(2, "Emma", 250);
    display_items();
    return 0;
}