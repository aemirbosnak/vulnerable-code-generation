//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[50];
    int starting_bid;
    int current_bid;
    struct Item* next;
} Item;

Item* create_item(char* name, int starting_bid) {
    Item* item = (Item*)malloc(sizeof(Item));
    strcpy(item->name, name);
    item->starting_bid = starting_bid;
    item->current_bid = starting_bid;
    item->next = NULL;
    return item;
}

void print_items(Item* head) {
    Item* current_item = head;
    while (current_item) {
        printf("%s (Starting Bid: %d, Current Bid: %d)\n", current_item->name, current_item->starting_bid, current_item->current_bid);
        current_item = current_item->next;
    }
}

void place_bid(Item* item, int bid) {
    if (bid < item->starting_bid) {
        printf("Bid too low.\n");
    } else if (bid > item->current_bid) {
        printf("Bid too high.\n");
    } else {
        item->current_bid = bid;
        printf("Bid placed successfully.\n");
    }
}

int main() {
    Item* head = create_item("Antique Clock", 100);
    create_item("Rare Book", 200);
    create_item("Diamond Necklace", 300);

    print_items(head);

    place_bid(head, 120);
    place_bid(head, 220);
    place_bid(head, 250);

    print_items(head);

    return 0;
}