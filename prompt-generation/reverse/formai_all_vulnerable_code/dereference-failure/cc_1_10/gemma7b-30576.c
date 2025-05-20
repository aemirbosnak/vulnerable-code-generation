//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int reserve_price;
    struct item* next;
} item;

// Function to insert a bidder into the list
void insert_bidder(bidder** head) {
    // Allocate memory for the new bidder
    bidder* new_bidder = (bidder*)malloc(sizeof(bidder));

    // Get the bidder's name and bid
    printf("Enter your name: ");
    scanf("%s", new_bidder->name);

    printf("Enter your bid: ");
    scanf("%d", &new_bidder->bid);

    // Insert the new bidder into the list
    if (*head == NULL) {
        *head = new_bidder;
    } else {
        (*head)->next = new_bidder;
        *head = new_bidder;
    }
}

// Function to insert an item into the list
void insert_item(item** head) {
    // Allocate memory for the new item
    item* new_item = (item*)malloc(sizeof(item));

    // Get the item's name, starting price, and reserve price
    printf("Enter the item name: ");
    scanf("%s", new_item->name);

    printf("Enter the starting price: ");
    scanf("%d", &new_item->starting_price);

    printf("Enter the reserve price: ");
    scanf("%d", &new_item->reserve_price);

    // Insert the new item into the list
    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
        *head = new_item;
    }
}

// Function to conduct the auction
void conduct_auction(item* item, bidder* bidders) {
    // Get the highest bid
    int highest_bid = bidders->bid;

    // Iterate over the bidders
    for (bidder* bidder = bidders; bidder != NULL; bidder = bidder->next) {
        // If the bidder's bid is higher than the highest bid, update the highest bid
        if (bidder->bid > highest_bid) {
            highest_bid = bidder->bid;
        }
    }

    // If the highest bid is greater than the item's reserve price, the item is sold
    if (highest_bid > item->reserve_price) {
        // Print the winning bidder's name and the item's name
        printf("Congratulations, %s! You have won the auction for %s.\n", bidders->name, item->name);

        // Print the final price of the item
        printf("The final price of the item is $%d.\n", highest_bid);
    } else {
        // Print an error message
        printf("Sorry, the item has not been sold.\n");
    }
}

int main() {
    // Create a list of bidders
    bidder* bidders = NULL;

    // Create a list of items
    item* items = NULL;

    // Insert bidders and items into the lists
    insert_bidder(&bidders);
    insert_item(&items);

    // Conduct the auction
    conduct_auction(items, bidders);

    return 0;
}