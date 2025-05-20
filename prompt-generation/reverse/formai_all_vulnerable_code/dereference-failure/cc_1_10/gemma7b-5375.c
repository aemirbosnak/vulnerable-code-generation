//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store auction items
typedef struct item {
    char name[20];
    int starting_price;
    int reserve_price;
    int current_bid;
    struct item* next;
} item;

// Function to create a new item
item* create_item(char* name, int starting_price, int reserve_price) {
    item* new_item = (item*)malloc(sizeof(item));
    strcpy(new_item->name, name);
    new_item->starting_price = starting_price;
    new_item->reserve_price = reserve_price;
    new_item->current_bid = 0;
    new_item->next = NULL;
    return new_item;
}

// Function to add an item to the auction
void add_item(item** head, char* name, int starting_price, int reserve_price) {
    item* new_item = create_item(name, starting_price, reserve_price);
    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
        *head = new_item;
    }
}

// Function to bid on an item
void bid(item* item, int bid_amount) {
    if (item->current_bid < bid_amount) {
        item->current_bid = bid_amount;
    }
}

// Function to auction the items
void auction(item** head) {
    // Iterates over the items
    item* current_item = *head;
    while (current_item) {
        // Prints the item name and current bid
        printf("Item: %s, Current Bid: %d\n", current_item->name, current_item->current_bid);

        // Allows bidders to place a bid
        int bid_amount;
        printf("Enter your bid: ");
        scanf("%d", &bid_amount);

        // Bids on the item
        bid(current_item, bid_amount);

        // Prints the updated current bid
        printf("Updated Current Bid: %d\n", current_item->current_bid);
    }

    // Prints the winner of each item
    printf("Winners:\n");
    current_item = *head;
    while (current_item) {
        printf("Item: %s, Winner: %d\n", current_item->name, current_item->current_bid);
    }
}

int main() {
    // Create a linked list of items
    item* head = NULL;

    // Add some items to the auction
    add_item(&head, "Laptop", 1000, 1500);
    add_item(&head, "Smartphone", 800, 1200);
    add_item(&head, "Watch", 600, 900);

    // Auction the items
    auction(&head);

    return 0;
}