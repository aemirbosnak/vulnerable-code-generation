//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 10000

struct Bidder {
    char name[20];
    int bid;
    struct Bidder *next;
};

struct Item {
    char name[20];
    int reserve_price;
    struct Bidder *highest_bidder;
    struct Item *next;
};

void insert_bidder(struct Bidder **head, char *name, int bid) {
    struct Bidder *new_bidder = malloc(sizeof(struct Bidder));
    strcpy(new_bidder->name, name);
    new_bidder->bid = bid;
    new_bidder->next = NULL;

    if (*head == NULL) {
        *head = new_bidder;
    } else {
        (*head)->next = new_bidder;
    }
}

void insert_item(struct Item **head, char *name, int reserve_price) {
    struct Item *new_item = malloc(sizeof(struct Item));
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

int main() {
    struct Bidder *head_bidder = NULL;
    struct Item *head_item = NULL;

    insert_bidder(&head_bidder, "John Doe", 5000);
    insert_bidder(&head_bidder, "Jane Doe", 6000);
    insert_bidder(&head_bidder, "Mike Smith", 7000);

    insert_item(&head_item, "Car", 10000);
    insert_item(&head_item, "Computer", 8000);
    insert_item(&head_item, "Phone", 9000);

    int current_bid = 0;
    struct Bidder *current_bidder = NULL;

    while (current_bid < MAX_BID) {
        printf("Enter your name: ");
        char name[20];
        scanf("%s", name);

        printf("Enter your bid: ");
        int bid;
        scanf("%d", &bid);

        insert_bidder(&head_bidder, name, bid);

        current_bid = bid;
        current_bidder = head_bidder;
    }

    for (struct Item *item = head_item; item; item = item->next) {
        printf("Item: %s, Highest Bid: %d\n", item->name, item->highest_bidder->bid);
    }

    return 0;
}