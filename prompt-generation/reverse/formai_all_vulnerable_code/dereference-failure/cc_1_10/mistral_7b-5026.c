//MISTRAL-7B DATASET v1.0 Category: Digital Auction System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bid {
    int bid_id;
    int bid_amount;
    struct Bid *next;
} Bid;

typedef struct Item {
    char name[50];
    int item_id;
    int highest_bid;
    int winner_id;
    Bid *bids;
    struct Item *next;
} Item;

void init_item(Item **items, int item_id, char *name) {
    Item *new_item = (Item *)malloc(sizeof(Item));
    strcpy(new_item->name, name);
    new_item->item_id = item_id;
    new_item->highest_bid = 0;
    new_item->winner_id = 0;
    new_item->bids = NULL;
    new_item->next = *items;
    *items = new_item;
}

void add_bid(Item *item, int bid_id, int bid_amount) {
    Bid *new_bid = (Bid *)malloc(sizeof(Bid));
    new_bid->bid_id = bid_id;
    new_bid->bid_amount = bid_amount;
    new_bid->next = item->bids;
    item->bids = new_bid;
    if (item->highest_bid < bid_amount) {
        item->highest_bid = bid_amount;
        item->winner_id = bid_id;
    }
}

void display_item(Item *item) {
    printf("\nItem %d: %s\n", item->item_id, item->name);
    printf("Highest Bid: %d by User %d\n", item->highest_bid, item->winner_id);
    printf("Bids:\n");
    Bid *current_bid = item->bids;
    while (current_bid != NULL) {
        printf("User %d bid %d\n", current_bid->bid_id, current_bid->bid_amount);
        current_bid = current_bid->next;
    }
}

int main() {
    Item *items = NULL;

    init_item(&items, 1, "Smartphone");
    init_item(&items, 2, "Tablet");

    int num_bids = 3;

    for (int i = 0; i < num_bids; ++i) {
        int item_id, bid_id, bid_amount;
        scanf("%d %d %d", &item_id, &bid_id, &bid_amount);

        Item *current_item = items;
        while (current_item != NULL && current_item->item_id != item_id) {
            current_item = current_item->next;
        }

        if (current_item == NULL) {
            printf("Invalid Item ID!\n");
            continue;
        }

        add_bid(current_item, bid_id, bid_amount);
    }

    Item *current_item = items;
    while (current_item != NULL) {
        display_item(current_item);
        current_item = current_item->next;
    }

    return 0;
}