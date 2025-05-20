//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("Enter your bid: ");
    scanf("%d", &new_bidder->bid);
    new_bidder->next = *head;
    *head = new_bidder;
}

// Function to insert an item into the item list
void insert_item(Item** head) {
    Item* new_item = (Item*)malloc(sizeof(Item));
    printf("Enter the name of the item: ");
    scanf("%s", new_item->name);
    printf("Enter the starting price of the item: ");
    scanf("%d", &new_item->starting_price);
    new_item->current_price = new_item->starting_price;
    new_item->next = *head;
    *head = new_item;
}

// Function to start the auction
void start_auction(Item* item, Bidder* bidders) {
    // Calculate the highest bid
    int highest_bid = bidders->bid;
    for (Bidder* bidder = bidders->next; bidder; bidder) {
        if (bidder->bid > highest_bid) {
            highest_bid = bidder->bid;
        }
    }

    // Update the item's current price
    item->current_price = highest_bid;

    // Announce the winner
    printf("The winner of the auction is: %s\n", bidders->name);
    printf("The winning bid is: %d\n", highest_bid);
}

int main() {
    // Create the bidding list
    Bidder* bidders = NULL;

    // Create the item list
    Item* items = NULL;

    // Insert some bidders
    insert_bidder(&bidders);
    insert_bidder(&bidders);
    insert_bidder(&bidders);

    // Insert some items
    insert_item(&items);
    insert_item(&items);
    insert_item(&items);

    // Start the auction
    start_auction(items, bidders);

    return 0;
}