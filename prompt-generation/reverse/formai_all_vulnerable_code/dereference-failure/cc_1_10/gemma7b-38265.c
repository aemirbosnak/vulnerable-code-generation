//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store auction items
typedef struct item {
    char name[20];
    int starting_bid;
    int reserve_price;
    struct item* next;
} item;

// Create a linked list of auction items
item* item_head = NULL;

// Function to add an item to the linked list
void add_item(char* name, int starting_bid, int reserve_price) {
    item* new_item = (item*)malloc(sizeof(item));
    strcpy(new_item->name, name);
    new_item->starting_bid = starting_bid;
    new_item->reserve_price = reserve_price;
    new_item->next = NULL;

    if (item_head == NULL) {
        item_head = new_item;
    } else {
        item* temp = item_head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_item;
    }
}

// Function to start the auction
void start_auction() {
    item* current_item = item_head;

    // Iterate over the items and print their details
    while (current_item) {
        printf("Item: %s\n", current_item->name);
        printf("Starting Bid: %d\n", current_item->starting_bid);
        printf("Reserve Price: %d\n", current_item->reserve_price);
        printf("\n");
        current_item = current_item->next;
    }

    // Prompt the user to place a bid
    printf("Please enter your bid: ");
    int bid;
    scanf("%d", &bid);

    // Check if the bid is valid
    if (bid < item_head->starting_bid) {
        printf("Error: your bid is too low.\n");
    } else if (bid > item_head->reserve_price) {
        printf("Error: your bid is too high.\n");
    } else {
        // Award the item to the user
        printf("Congratulations! You have won the item: %s.\n", item_head->name);
        printf("Your total cost is: %d.\n", bid);
    }
}

int main() {
    // Add some items to the auction
    add_item("Laptop", 500, 1000);
    add_item("Smartphone", 200, 500);
    add_item("Watch", 100, 200);

    // Start the auction
    start_auction();

    return 0;
}