//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store auction items
typedef struct Item {
    char name[20];
    int starting_bid;
    int current_bid;
    struct Item* next;
} Item;

// Function to insert an item into the auction
void insertItem(Item** head, char* name, int starting_bid) {
    Item* new_item = (Item*)malloc(sizeof(Item));
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

// Function to find the highest bidder for an item
Item* highestBidder(Item* item) {
    Item* highest_bidder = item;
    while (highest_bidder->next) {
        if (highest_bidder->current_bid > item->current_bid) {
            highest_bidder = highest_bidder->next;
        }
    }
    return highest_bidder;
}

// Function to place a bid on an item
void placeBid(Item* item, int bid) {
    item->current_bid = bid;
    item = highestBidder(item);
    printf("The highest bidder for %s is %s with a bid of %d.\n", item->name, item->name, item->current_bid);
}

int main() {
    Item* head = NULL;

    // Insert some items into the auction
    insertItem(&head, "iPhone", 1000);
    insertItem(&head, "Laptop", 800);
    insertItem(&head, "Watch", 600);

    // Place some bids on the items
    placeBid(head->next, 1200);
    placeBid(head, 900);
    placeBid(head->next, 1300);

    return 0;
}