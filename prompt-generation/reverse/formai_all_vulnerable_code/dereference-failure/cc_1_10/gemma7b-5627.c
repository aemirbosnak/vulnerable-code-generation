//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an array of structures to store auction items
typedef struct Item {
    char name[20];
    int starting_price;
    int current_price;
    int num_bids;
    struct Item* next;
} Item;

// Define a function to insert an item into the auction
void insert_item(Item** head) {
    Item* new_item = (Item*)malloc(sizeof(Item));
    printf("Enter item name: ");
    scanf("%s", new_item->name);
    printf("Enter starting price: ");
    scanf("%d", &new_item->starting_price);
    new_item->current_price = new_item->starting_price;
    new_item->num_bids = 0;
    new_item->next = NULL;

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

// Define a function to display all items
void display_items(Item* head) {
    printf("List of items:\n");
    while (head) {
        printf("Item name: %s\n", head->name);
        printf("Starting price: %d\n", head->starting_price);
        printf("Current price: %d\n", head->current_price);
        printf("Number of bids: %d\n", head->num_bids);
        printf("\n");
        head = head->next;
    }
}

// Define a function to handle bids
void handle_bid(Item* head) {
    printf("Enter your bid: ");
    int bid;
    scanf("%d", &bid);

    Item* current_item = head;
    while (current_item) {
        if (strcmp(current_item->name, "Item name") == 0) {
            if (bid > current_item->current_price) {
                current_item->current_price = bid;
                current_item->num_bids++;
                printf("Your bid has been accepted.\n");
            } else {
                printf("Your bid is not high enough.\n");
            }
        }
        current_item = current_item->next;
    }
}

// Main function
int main() {
    Item* head = NULL;

    // Insert items into the auction
    insert_item(&head);
    insert_item(&head);
    insert_item(&head);

    // Display all items
    display_items(head);

    // Handle bids
    handle_bid(head);

    // Display all items again after bids
    display_items(head);

    return 0;
}