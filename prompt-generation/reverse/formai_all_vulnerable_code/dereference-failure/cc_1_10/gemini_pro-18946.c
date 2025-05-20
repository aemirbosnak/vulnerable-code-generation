//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 10

typedef struct {
    int item_id;
    char item_name[50];
    float reserve_price;
    float current_bid;
} Item;

typedef struct {
    int bid_id;
    int item_id;
    float bid_amount;
    char bidder_name[50];
} Bid;

// Function to create a new item
Item* create_item(int item_id, char* item_name, float reserve_price) {
    Item* item = (Item*)malloc(sizeof(Item));
    item->item_id = item_id;
    strcpy(item->item_name, item_name);
    item->reserve_price = reserve_price;
    item->current_bid = 0;
    return item;
}

// Function to create a new bid
Bid* create_bid(int bid_id, int item_id, float bid_amount, char* bidder_name) {
    Bid* bid = (Bid*)malloc(sizeof(Bid));
    bid->bid_id = bid_id;
    bid->item_id = item_id;
    bid->bid_amount = bid_amount;
    strcpy(bid->bidder_name, bidder_name);
    return bid;
}

// Function to add an item to the auction
void add_item(Item* items[], int* num_items, Item* item) {
    items[*num_items] = item;
    (*num_items)++;
}

// Function to add a bid to an item
void add_bid(Bid* bids[], int* num_bids, Bid* bid) {
    bids[*num_bids] = bid;
    (*num_bids)++;
}

// Function to print the details of an item
void print_item(Item* item) {
    printf("Item ID: %d\n", item->item_id);
    printf("Item Name: %s\n", item->item_name);
    printf("Reserve Price: %.2f\n", item->reserve_price);
    printf("Current Bid: %.2f\n", item->current_bid);
}

// Function to print the details of a bid
void print_bid(Bid* bid) {
    printf("Bid ID: %d\n", bid->bid_id);
    printf("Item ID: %d\n", bid->item_id);
    printf("Bid Amount: %.2f\n", bid->bid_amount);
    printf("Bidder Name: %s\n", bid->bidder_name);
}

// Function to find the highest bid for an item
Bid* find_highest_bid(Bid* bids[], int num_bids, int item_id) {
    Bid* highest_bid = NULL;
    for (int i = 0; i < num_bids; i++) {
        if (bids[i]->item_id == item_id && (highest_bid == NULL || bids[i]->bid_amount > highest_bid->bid_amount)) {
            highest_bid = bids[i];
        }
    }
    return highest_bid;
}

// Function to determine the winner of an auction
Bid* determine_winner(Item* items[], int num_items, Bid* bids[], int num_bids) {
    Bid* winner = NULL;
    for (int i = 0; i < num_items; i++) {
        Bid* highest_bid = find_highest_bid(bids, num_bids, items[i]->item_id);
        if (highest_bid != NULL && highest_bid->bid_amount >= items[i]->reserve_price) {
            winner = highest_bid;
        }
    }
    return winner;
}

// Main function
int main() {
    // Create an array of items
    Item* items[MAX_ITEMS];
    int num_items = 0;

    // Create an array of bids
    Bid* bids[MAX_BIDS];
    int num_bids = 0;

    // Add some items to the auction
    add_item(items, &num_items, create_item(1, "Painting", 1000.0));
    add_item(items, &num_items, create_item(2, "Sculpture", 500.0));
    add_item(items, &num_items, create_item(3, "Vase", 200.0));

    // Add some bids to the auction
    add_bid(bids, &num_bids, create_bid(1, 1, 1200.0, "John"));
    add_bid(bids, &num_bids, create_bid(2, 2, 600.0, "Mary"));
    add_bid(bids, &num_bids, create_bid(3, 3, 250.0, "Bob"));

    // Print the details of the items
    for (int i = 0; i < num_items; i++) {
        print_item(items[i]);
        printf("\n");
    }

    // Print the details of the bids
    for (int i = 0; i < num_bids; i++) {
        print_bid(bids[i]);
        printf("\n");
    }

    // Determine the winner of the auction
    Bid* winner = determine_winner(items, num_items, bids, num_bids);

    // Print the details of the winner
    if (winner != NULL) {
        printf("The winner of the auction is: %s\n", winner->bidder_name);
        printf("Winning bid: %.2f\n", winner->bid_amount);
    } else {
        printf("No winner: No bids met the reserve price.\n");
    }

    return 0;
}