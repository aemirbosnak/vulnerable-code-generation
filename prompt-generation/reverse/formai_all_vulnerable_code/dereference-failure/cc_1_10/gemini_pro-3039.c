//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store an item
typedef struct Item {
    char name[50];
    float starting_price;
    float current_price;
    int num_bids;
} Item;

// Data structure to store a bid
typedef struct Bid {
    char bidder_name[50];
    float amount;
} Bid;

// Function to create a new item
Item *create_item(char *name, float starting_price) {
    Item *item = (Item *)malloc(sizeof(Item));
    strcpy(item->name, name);
    item->starting_price = starting_price;
    item->current_price = starting_price;
    item->num_bids = 0;
    return item;
}

// Function to create a new bid
Bid *create_bid(char *bidder_name, float amount) {
    Bid *bid = (Bid *)malloc(sizeof(Bid));
    strcpy(bid->bidder_name, bidder_name);
    bid->amount = amount;
    return bid;
}

// Function to add a bid to an item
void add_bid(Item *item, Bid *bid) {
    item->current_price = bid->amount;
    item->num_bids++;
}

// Function to print the details of an item
void print_item(Item *item) {
    printf("Item Name: %s\n", item->name);
    printf("Starting Price: %.2f\n", item->starting_price);
    printf("Current Price: %.2f\n", item->current_price);
    printf("Number of Bids: %d\n", item->num_bids);
}

// Function to print the details of a bid
void print_bid(Bid *bid) {
    printf("Bidder Name: %s\n", bid->bidder_name);
    printf("Bid Amount: %.2f\n", bid->amount);
}

// Main function
int main() {
    // Create two items
    Item *item1 = create_item("Painting", 100.0);
    Item *item2 = create_item("Sculpture", 200.0);

    // Create three bids for the first item
    Bid *bid1 = create_bid("Alice", 120.0);
    Bid *bid2 = create_bid("Bob", 130.0);
    Bid *bid3 = create_bid("Carol", 140.0);

    // Create two bids for the second item
    Bid *bid4 = create_bid("Dave", 220.0);
    Bid *bid5 = create_bid("Eve", 230.0);

    // Add the bids to the items
    add_bid(item1, bid1);
    add_bid(item1, bid2);
    add_bid(item1, bid3);
    add_bid(item2, bid4);
    add_bid(item2, bid5);

    // Print the details of the items and their bids
    printf("Item 1:\n");
    print_item(item1);
    printf("Bids:\n");
    print_bid(bid1);
    print_bid(bid2);
    print_bid(bid3);

    printf("\nItem 2:\n");
    print_item(item2);
    printf("Bids:\n");
    print_bid(bid4);
    print_bid(bid5);

    return 0;
}