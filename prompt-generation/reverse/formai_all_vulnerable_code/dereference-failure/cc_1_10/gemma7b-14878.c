//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID_NUM 10
#define MAX_ITEM_NUM 10

typedef struct Bidder {
    char name[20];
    int bid_num;
    struct Bidder* next;
} Bidder;

typedef struct Item {
    char name[20];
    int start_price;
    int current_price;
    struct Item* next;
} Item;

void insert_bidder(Bidder** head, char* name, int bid_num) {
    Bidder* new_bidder = malloc(sizeof(Bidder));
    strcpy(new_bidder->name, name);
    new_bidder->bid_num = bid_num;
    new_bidder->next = NULL;

    if (*head == NULL) {
        *head = new_bidder;
    } else {
        (*head)->next = new_bidder;
    }
}

void insert_item(Item** head, char* name, int start_price) {
    Item* new_item = malloc(sizeof(Item));
    strcpy(new_item->name, name);
    new_item->start_price = start_price;
    new_item->current_price = start_price;
    new_item->next = NULL;

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

void bid(Bidder** head, Item** head_item) {
    Bidder* current_bidder = *head;
    Item* current_item = *head_item;

    printf("Enter your name: ");
    char name[20];
    scanf("%s", name);

    printf("Enter your bid: ");
    int bid_amount;
    scanf("%d", &bid_amount);

    insert_bidder(head, name, bid_amount);

    if (bid_amount > current_item->current_price) {
        current_item->current_price = bid_amount;
    }

    printf("Your bid has been placed.\n");
}

int main() {
    Bidder* head_bidder = NULL;
    Item* head_item = NULL;

    insert_item(&head_item, "Laptop", 500);
    insert_item(&head_item, "Phone", 300);
    insert_item(&head_item, "Watch", 200);

    insert_bidder(&head_bidder, "John Doe", 400);
    insert_bidder(&head_bidder, "Jane Doe", 350);
    insert_bidder(&head_bidder, "Peter Pan", 300);

    bid(&head_bidder, &head_item);

    printf("The current highest bid is: $%d", head_item->current_price);

    return 0;
}