//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define an item structure
typedef struct Item {
    char name[20];
    int starting_bid;
    int current_bid;
    struct Item* next;
} Item;

// Define a linked list of items
typedef struct ItemList {
    Item* head;
    Item* tail;
} ItemList;

// Function to insert an item into the linked list
void insertItem(ItemList* list, Item* item) {
    if (list->head == NULL) {
        list->head = item;
        list->tail = item;
    } else {
        list->tail->next = item;
        list->tail = item;
    }
}

// Function to start the auction
void startAuction(ItemList* list) {
    // Print the items in the list
    Item* currentItem = list->head;
    while (currentItem) {
        printf("Item: %s, Starting Bid: %d, Current Bid: %d\n", currentItem->name, currentItem->starting_bid, currentItem->current_bid);
        currentItem = currentItem->next;
    }

    // Get the bids from the users
    for (int i = 0; i < 10; i++) {
        printf("Enter your bid for item %s: ", list->head->name);
        int bid = atoi(stdin);

        // Check if the bid is valid
        if (bid < list->head->starting_bid) {
            printf("Error: your bid is too low.\n");
        } else if (bid > list->head->current_bid) {
            printf("Error: your bid is too high.\n");
        } else {
            // Update the current bid for the item
            list->head->current_bid = bid;

            // Print the updated bid
            printf("Your bid for item %s has been updated to %d.\n", list->head->name, list->head->current_bid);
        }
    }

    // Print the winner of the auction
    Item* winner = list->head;
    for (Item* item = list->head; item; item = item->next) {
        if (item->current_bid > winner->current_bid) {
            winner = item;
        }
    }

    printf("The winner of the auction is: %s with a bid of %d.\n", winner->name, winner->current_bid);
}

int main() {
    // Create a linked list of items
    ItemList* list = malloc(sizeof(ItemList));
    list->head = NULL;
    list->tail = NULL;

    // Insert some items into the list
    Item* item1 = malloc(sizeof(Item));
    strcpy(item1->name, "Laptop");
    item1->starting_bid = 500;
    item1->current_bid = 200;
    insertItem(list, item1);

    Item* item2 = malloc(sizeof(Item));
    strcpy(item2->name, "Smartphone");
    item2->starting_bid = 300;
    item2->current_bid = 100;
    insertItem(list, item2);

    // Start the auction
    startAuction(list);

    return 0;
}