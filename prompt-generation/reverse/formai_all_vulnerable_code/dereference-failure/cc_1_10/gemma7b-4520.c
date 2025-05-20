//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define an array of structures to store auction items
typedef struct item {
    char name[20];
    int starting_bid;
    int current_bid;
    struct item* next;
} item;

// Define a linked list of auction items
item* head = NULL;

// Function to insert a new item into the linked list
void insert_item(char* name, int starting_bid) {
    item* new_item = malloc(sizeof(item));
    strcpy(new_item->name, name);
    new_item->starting_bid = starting_bid;
    new_item->current_bid = starting_bid;
    new_item->next = NULL;

    if (head == NULL) {
        head = new_item;
    } else {
        item* current_item = head;
        while (current_item->next != NULL) {
            current_item = current_item->next;
        }
        current_item->next = new_item;
    }
}

// Function to bid on an item
void bid(char* item_name, int bid_amount) {
    item* item = head;
    while (item != NULL) {
        if (strcmp(item->name, item_name) == 0) {
            if (bid_amount > item->current_bid) {
                item->current_bid = bid_amount;
                printf("Your bid of %d for item %s has been accepted.\n", bid_amount, item_name);
            } else {
                printf("Your bid of %d for item %s is not acceptable. The current bid is %d.\n", bid_amount, item_name, item->current_bid);
            }
            break;
        }
        item = item->next;
    }

    if (item == NULL) {
        printf("Item %s not found.\n", item_name);
    }
}

// Function to start the auction
void start_auction() {
    int i = 0;
    item* current_item = head;
    while (current_item) {
        printf("Item: %s\n", current_item->name);
        printf("Starting Bid: $%d\n", current_item->starting_bid);
        printf("Current Bid: $%d\n", current_item->current_bid);
        printf("\n");
        i++;
        current_item = current_item->next;
    }

    printf("Total number of items: %d\n", i);
}

int main() {
    // Insert some items into the linked list
    insert_item("Laptop", 500);
    insert_item("Smartphone", 300);
    insert_item("Watch", 200);

    // Start the auction
    start_auction();

    // Bid on an item
    bid("Laptop", 600);

    // Start the auction again to show the updated list
    start_auction();

    return 0;
}