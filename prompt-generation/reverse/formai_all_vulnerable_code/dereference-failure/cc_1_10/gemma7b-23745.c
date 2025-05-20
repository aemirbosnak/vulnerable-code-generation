//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID_AMOUNT 10000

struct Bidder {
    char name[20];
    int bid_amount;
    struct Bidder *next;
};

struct Item {
    char name[20];
    int reserve_price;
    struct Bidder *highest_bidder;
    struct Item *next;
};

void insert_bidder(struct Bidder **head, char *name, int bid_amount) {
    struct Bidder *new_bidder = (struct Bidder *)malloc(sizeof(struct Bidder));
    strcpy(new_bidder->name, name);
    new_bidder->bid_amount = bid_amount;
    new_bidder->next = NULL;

    if (*head == NULL) {
        *head = new_bidder;
    } else {
        (*head)->next = new_bidder;
    }
}

void insert_item(struct Item **head, char *name, int reserve_price) {
    struct Item *new_item = (struct Item *)malloc(sizeof(struct Item));
    strcpy(new_item->name, name);
    new_item->reserve_price = reserve_price;
    new_item->highest_bidder = NULL;
    new_item->next = NULL;

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

void auction(struct Item *item) {
    struct Bidder *highest_bidder = item->highest_bidder;
    if (highest_bidder) {
        printf("The highest bidder for item '%s' is %s with a bid amount of %d.\n", item->name, highest_bidder->name, highest_bidder->bid_amount);
    } else {
        printf("There has not been any bidding for item '%s' yet.\n", item->name);
    }
}

int main() {
    struct Item *item_head = NULL;
    struct Bidder *bidder_head = NULL;

    insert_item(&item_head, "Laptop", 1000);
    insert_item(&item_head, "Smartphone", 800);
    insert_item(&item_head, "Watch", 600);

    insert_bidder(&bidder_head, "John Doe", 700);
    insert_bidder(&bidder_head, "Jane Doe", 500);
    insert_bidder(&bidder_head, "Peter Pan", 650);

    auction(item_head->next);

    return 0;
}