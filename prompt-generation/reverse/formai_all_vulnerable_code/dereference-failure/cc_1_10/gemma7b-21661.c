//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: dynamic
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

Item* insert_item(Item* head) {
    Item* new_item = (Item*)malloc(sizeof(Item));
    printf("Enter item name: ");
    scanf("%s", new_item->name);
    printf("Enter starting bid: ");
    scanf("%d", &new_item->starting_bid);
    new_item->current_bid = new_item->starting_bid;
    new_item->next = NULL;

    if (head == NULL) {
        head = new_item;
    } else {
        head->next = new_item;
    }

    return head;
}

void print_items(Item* head) {
    Item* current_item = head;
    while (current_item) {
        printf("%s: %d\n", current_item->name, current_item->current_bid);
        current_item = current_item->next;
    }
}

void bid(Item* head) {
    printf("Enter item you want to bid on: ");
    char item_name[20];
    scanf("%s", item_name);

    Item* current_item = head;
    while (current_item) {
        if (strcmp(current_item->name, item_name) == 0) {
            printf("Enter your bid: ");
            int your_bid;
            scanf("%d", &your_bid);

            if (your_bid > current_item->current_bid) {
                current_item->current_bid = your_bid;
                printf("Your bid has been accepted.\n");
            } else {
                printf("Your bid is not higher than the current bid.\n");
            }
        }
        current_item = current_item->next;
    }
}

int main() {
    Item* head = NULL;
    head = insert_item(head);
    head = insert_item(head);
    head = insert_item(head);

    print_items(head);

    bid(head);

    print_items(head);

    return 0;
}