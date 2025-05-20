//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 1000

struct Bid {
    char name[50];
    int bid_amount;
    struct Bid* next;
};

struct Item {
    char item_name[50];
    int reserve_price;
    struct Bid* bids;
    struct Item* next;
};

typedef struct Bid Bid;
typedef struct Item Item;

void insert_bid(Bid** head, int amount, char* name) {
    Bid* new_bid = malloc(sizeof(Bid));
    new_bid->bid_amount = amount;
    strcpy(new_bid->name, name);
    new_bid->next = NULL;

    if (*head == NULL) {
        *head = new_bid;
    } else {
        (*head)->next = new_bid;
    }
}

void insert_item(Item** head, char* name, int reserve_price) {
    Item* new_item = malloc(sizeof(Item));
    strcpy(new_item->item_name, name);
    new_item->reserve_price = reserve_price;
    new_item->bids = NULL;
    new_item->next = NULL;

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

void auction(Item* item) {
    Bid* highest_bid = item->bids;
    int current_price = item->reserve_price;

    while (highest_bid) {
        if (highest_bid->bid_amount > current_price) {
            current_price = highest_bid->bid_amount;
        }
        highest_bid = highest_bid->next;
    }

    printf("The highest bid for %s is %d.", item->item_name, current_price);
}

int main() {
    Item* head = NULL;
    insert_item(&head, "Laptop", 500);
    insert_item(&head, "Mobile Phone", 300);
    insert_item(&head, "Watch", 200);

    Bid* head_bid = NULL;
    insert_bid(&head_bid, 400, "John Doe");
    insert_bid(&head_bid, 250, "Jane Doe");
    insert_bid(&head_bid, 320, "Peter Pan");

    auction(head->next);

    return 0;
}