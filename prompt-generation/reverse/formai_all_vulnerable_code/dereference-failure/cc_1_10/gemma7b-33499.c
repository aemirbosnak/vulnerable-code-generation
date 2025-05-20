//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 10

typedef struct item {
    char name[20];
    int starting_price;
    int current_price;
    int num_bids;
    struct item* next;
} item_t;

item_t* insert_item(item_t* head, char* name, int starting_price) {
    item_t* new_item = malloc(sizeof(item_t));
    strcpy(new_item->name, name);
    new_item->starting_price = starting_price;
    new_item->current_price = starting_price;
    new_item->num_bids = 0;
    new_item->next = NULL;

    if (head == NULL) {
        head = new_item;
    } else {
        head->next = new_item;
    }

    return head;
}

void bid(item_t* item, int bid_price) {
    item->num_bids++;
    if (bid_price > item->current_price) {
        item->current_price = bid_price;
    }
}

void print_items(item_t* head) {
    item_t* current_item = head;
    while (current_item) {
        printf("%s - Current Price: %d, Bids: %d\n", current_item->name, current_item->current_price, current_item->num_bids);
        current_item = current_item->next;
    }
}

int main() {
    item_t* head = NULL;

    insert_item(head, "Apple", 10);
    insert_item(head, "Banana", 12);
    insert_item(head, "Orange", 14);

    bid(head->next, 13);
    bid(head, 11);
    bid(head->next, 15);

    print_items(head);

    return 0;
}