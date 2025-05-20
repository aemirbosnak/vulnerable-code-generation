//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of bidders
#define MAX_BIDDERS 10

// Define the maximum number of items
#define MAX_ITEMS 5

// Define the structure of a bidder
typedef struct bidder {
    char name[20];
    int bid;
    struct bidder* next;
} bidder;

// Define the structure of an item
typedef struct item {
    char name[20];
    int starting_price;
    int current_price;
    struct item* next;
} item;

// Function to insert a bidder into the bidding list
void insert_bidder(bidder** head) {
    // Allocate memory for the new bidder
    bidder* new_bidder = (bidder*)malloc(sizeof(bidder));

    // Get the bidder's name and bid
    printf("Enter bidder's name: ");
    scanf("%s", new_bidder->name);

    printf("Enter bidder's bid: ");
    scanf("%d", &new_bidder->bid);

    // Insert the new bidder into the list
    if (*head == NULL) {
        *head = new_bidder;
    } else {
        (*head)->next = new_bidder;
        *head = new_bidder;
    }
}

// Function to insert an item into the item list
void insert_item(item** head) {
    // Allocate memory for the new item
    item* new_item = (item*)malloc(sizeof(item));

    // Get the item's name and starting price
    printf("Enter item name: ");
    scanf("%s", new_item->name);

    printf("Enter item starting price: ");
    scanf("%d", &new_item->starting_price);

    // Insert the new item into the list
    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
        *head = new_item;
    }
}

// Function to conduct the auction
void conduct_auction(item** head, bidder** head_bidder) {
    // Iterate over the items
    item* current_item = *head;
    while (current_item) {
        // Print the item name and current price
        printf("Item: %s, Current Price: %d\n", current_item->name, current_item->current_price);

        // Iterate over the bidders
        bidder* current_bidder = *head_bidder;
        while (current_bidder) {
            // Print the bidder's name and bid
            printf("Bidder: %s, Bid: %d\n", current_bidder->name, current_bidder->bid);
        }

        // Get the highest bid
        int highest_bid = 0;
        current_bidder = *head_bidder;
        while (current_bidder) {
            if (current_bidder->bid > highest_bid) {
                highest_bid = current_bidder->bid;
            }
        }

        // Update the item's current price
        current_item->current_price = highest_bid;

        // Increment the item's current price by 10%
        current_item->current_price = (int)(current_item->current_price * 1.1);

        // Print the updated item current price
        printf("Updated Item Current Price: %d\n", current_item->current_price);
    }
}

int main() {
    // Create the bidding list
    bidder** head_bidder = NULL;

    // Create the item list
    item** head_item = NULL;

    // Insert bidders and items
    insert_bidder(head_bidder);
    insert_item(head_item);
    insert_bidder(head_bidder);
    insert_item(head_item);

    // Conduct the auction
    conduct_auction(head_item, head_bidder);

    return 0;
}