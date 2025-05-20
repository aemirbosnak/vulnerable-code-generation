//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store auction items
typedef struct Item {
    char name[20];
    int starting_price;
    int current_price;
    int num_bids;
    struct Item* next;
} Item;

// Function to insert a new item into the auction
void insert_item(Item** head, char* name, int starting_price) {
    Item* new_item = malloc(sizeof(Item));
    strcpy(new_item->name, name);
    new_item->starting_price = starting_price;
    new_item->current_price = starting_price;
    new_item->num_bids = 0;
    new_item->next = NULL;

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

// Function to place a bid on an item
void place_bid(Item* item, int bid) {
    item->num_bids++;
    if (item->current_price < bid) {
        item->current_price = bid;
    }
}

// Function to print the auction items
void print_items(Item* head) {
    while (head) {
        printf("Item: %s, Starting Price: %d, Current Price: %d, Number of Bids: %d\n", head->name, head->starting_price, head->current_price, head->num_bids);
        head = head->next;
    }
}

int main() {
    Item* head = NULL;

    // Insert some items into the auction
    insert_item(&head, "Laptop", 1000);
    insert_item(&head, "Smartphone", 800);
    insert_item(&head, "Watch", 600);

    // Place some bids on the items
    place_bid(head->next, 1200);
    place_bid(head, 900);
    place_bid(head->next, 1300);

    // Print the items
    print_items(head);

    return 0;
}