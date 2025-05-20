//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item structure
typedef struct {
    char name[50];
    float reserve_price;
    float current_price;
    int highest_bidder;
} Item;

// Bid structure
typedef struct {
    int bidder_id;
    float amount;
} Bid;

// Function to create a new item
Item* create_item(char *name, float reserve_price) {
    Item *item = (Item*)malloc(sizeof(Item));
    strcpy(item->name, name);
    item->reserve_price = reserve_price;
    item->current_price = 0.0;
    item->highest_bidder = -1;

    return item;
}

// Function to place a bid
void place_bid(Item *item, int bidder_id, float amount) {
    if (amount >= item->current_price) {
        item->current_price = amount;
        item->highest_bidder = bidder_id;
    }
}

// Function to print the details of an item
void print_item(Item *item) {
    printf("Name: %s\n", item->name);
    printf("Reserve Price: %.2f\n", item->reserve_price);
    printf("Current Price: %.2f\n", item->current_price);
    if (item->highest_bidder != -1) {
        printf("Highest Bidder: %d\n", item->highest_bidder);
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new item
    Item *item1 = create_item("Painting", 100.0);
    Item *item2 = create_item("Sculpture", 200.0);

    // Place some bids
    place_bid(item1, 1, 110.0);
    place_bid(item2, 2, 210.0);
    place_bid(item1, 3, 120.0);

    // Print the details of the items
    print_item(item1);
    print_item(item2);

    return 0;
}