//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of bidders
#define MAX_BIDDERS 10

// Define the maximum number of items
#define MAX_ITEMS 5

// Define the structure of a bidder
typedef struct Bidder {
    char name[20];
    int bid;
    struct Bidder* next;
} Bidder;

// Define the structure of an item
typedef struct Item {
    char name[20];
    int starting_price;
    int current_price;
    struct Item* next;
} Item;

// Function to insert a bidder into the bidding list
void insert_bidder(Bidder** head) {
    Bidder* new_bidder = (Bidder*)malloc(sizeof(Bidder));
    printf("Enter your name: ");
    scanf("%s", new_bidder->name);
    new_bidder->bid = 0;
    new_bidder->next = NULL;

    if (*head == NULL) {
        *head = new_bidder;
    } else {
        (*head)->next = new_bidder;
    }
}

// Function to insert an item into the item list
void insert_item(Item** head) {
    Item* new_item = (Item*)malloc(sizeof(Item));
    printf("Enter the name of the item: ");
    scanf("%s", new_item->name);
    printf("Enter the starting price of the item: ");
    scanf("%d", &new_item->starting_price);
    new_item->current_price = new_item->starting_price;
    new_item->next = NULL;

    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
    }
}

// Function to start the auction
void start_auction(Item** head, Bidder** head_bidder) {
    // Iterate over the items
    Item* current_item = head;
    while (current_item) {
        // Iterate over the bidders
        Bidder* current_bidder = head_bidder;
        while (current_bidder) {
            // Place the bid
            int bid = current_bidder->bid;

            // Check if the bid is greater than the current price
            if (bid > current_item->current_price) {
                current_item->current_price = bid;
            }
        }

        // Print the current price of the item
        printf("The current price of %s is $%d.\n", current_item->name, current_item->current_price);
    }

    // Print the winner of the auction
    Item* winner = head;
    while (winner) {
        if (winner->current_price == winner->starting_price) {
            printf("The winner of the auction is %s.\n", winner->name);
        }
    }
}

int main() {
    // Create the head of the bidder list
    Bidder* head_bidder = NULL;

    // Create the head of the item list
    Item* head_item = NULL;

    // Insert bidders and items into the lists
    insert_bidder(&head_bidder);
    insert_item(&head_item);
    insert_item(&head_item);

    // Start the auction
    start_auction(&head_item, &head_bidder);

    return 0;
}