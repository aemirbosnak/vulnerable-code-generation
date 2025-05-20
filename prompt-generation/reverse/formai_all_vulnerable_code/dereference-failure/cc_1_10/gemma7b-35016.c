//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: multivariable
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

void insert_item(Item** head, char* name, int starting_bid) {
    Item* new_item = malloc(sizeof(Item));
    strcpy(new_item->name, name);
    new_item->starting_bid = starting_bid;
    new_item->current_bid = starting_bid;
    new_item->next = NULL;

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

void bid(Item* item) {
    int new_bid;

    printf("Enter your bid: ");
    scanf("%d", &new_bid);

    if (new_bid > item->current_bid) {
        item->current_bid = new_bid;
        printf("Your bid has been accepted. Current bid: $%d\n", item->current_bid);
    } else {
        printf("Your bid is not higher than the current bid. Please try again.\n");
    }
}

int main() {
    Item* head = NULL;

    insert_item(&head, "Apple", 100);
    insert_item(&head, "Banana", 200);
    insert_item(&head, "Orange", 300);

    bid(head->next);
    bid(head->next->next);

    return 0;
}