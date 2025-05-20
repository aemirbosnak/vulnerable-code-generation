//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int starting_bid;
    int current_bid;
    struct Item* next;
} Item;

Item* insert_item(Item* head) {
    Item* new_item = (Item*)malloc(sizeof(Item));
    printf("Enter item name: ");
    scanf("%s", new_item->name);
    printf("Enter starting bid: ");
    scanf("%d", &new_item->starting_bid);
    new_item->current_bid = new_item->starting_bid;
    new_item->next = head;
    return new_item;
}

void print_items(Item* head) {
    while (head) {
        printf("%s - Starting Bid: %d, Current Bid: %d\n", head->name, head->starting_bid, head->current_bid);
        head = head->next;
    }
}

void bid_on_item(Item* head) {
    printf("Enter item name: ");
    char item_name[20];
    scanf("%s", item_name);

    Item* item = head;
    while (item) {
        if (strcmp(item->name, item_name) == 0) {
            printf("Enter your bid: ");
            int bid;
            scanf("%d", &bid);

            if (bid > item->current_bid) {
                item->current_bid = bid;
                printf("Your bid has been accepted. Current bid: %d\n", item->current_bid);
            } else {
                printf("Your bid is not higher than the current bid. Please try again.\n");
            }
            break;
        }
        item = item->next;
    }

    if (item == NULL) {
        printf("Item not found.\n");
    }
}

int main() {
    Item* head = NULL;
    head = insert_item(head);
    insert_item(head);
    insert_item(head);

    print_items(head);

    bid_on_item(head);

    print_items(head);

    return 0;
}