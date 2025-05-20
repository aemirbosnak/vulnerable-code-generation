//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int starting_bid;
    int current_bid;
    struct Item* next;
} Item;

Item* createItem(char* name, int starting_bid) {
    Item* item = (Item*)malloc(sizeof(Item));
    strcpy(item->name, name);
    item->starting_bid = starting_bid;
    item->current_bid = starting_bid;
    item->next = NULL;
    return item;
}

void displayItems(Item* head) {
    while (head) {
        printf("%s - Starting Bid: $%d, Current Bid: $%d\n", head->name, head->starting_bid, head->current_bid);
        head = head->next;
    }
}

void placeBid(Item* item, int bid) {
    if (bid < item->starting_bid) {
        printf("Error: Bid must be greater than the starting bid.\n");
        return;
    }

    if (item->current_bid < bid) {
        item->current_bid = bid;
        printf("Your bid has been placed successfully.\n");
    } else {
        printf("Error: Your bid is not higher than the current bid.\n");
    }
}

int main() {
    Item* head = NULL;

    // Create some items
    head = createItem("Laptop", 500);
    createItem("Smartphone", 300);
    createItem("Watch", 200);

    // Display the items
    displayItems(head);

    // Place a bid
    placeBid(head, 600);

    // Display the items again
    displayItems(head);

    return 0;
}