//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store item details
typedef struct {
    int id;
    char* name;
    float reserve_price;
    float current_bid;
    char* highest_bidder;
} Item;

// Structure to store auction details
typedef struct {
    int num_items;
    Item* items;
    int current_time;
    int end_time;
} Auction;

// Function to create a new item
Item* create_item(int id, char* name, float reserve_price) {
    Item* item = malloc(sizeof(Item));
    item->id = id;
    item->name = strdup(name);
    item->reserve_price = reserve_price;
    item->current_bid = 0.0;
    item->highest_bidder = NULL;
    return item;
}

// Function to create a new auction
Auction* create_auction(int num_items, Item* items, int current_time, int end_time) {
    Auction* auction = malloc(sizeof(Auction));
    auction->num_items = num_items;
    auction->items = items;
    auction->current_time = current_time;
    auction->end_time = end_time;
    return auction;
}

// Function to place a bid on an item
void place_bid(Auction* auction, int item_id, char* bidder, float bid_amount) {
    Item* item = &auction->items[item_id];

    // Check if the bid meets the reserve price
    if (bid_amount < item->reserve_price) {
        printf("Bid amount must meet the reserve price of %f\n", item->reserve_price);
        return;
    }

    // Check if the bid is higher than the current bid
    if (bid_amount <= item->current_bid) {
        printf("Bid amount must be higher than the current bid of %f\n", item->current_bid);
        return;
    }

    // Update the current bid and highest bidder
    item->current_bid = bid_amount;
    item->highest_bidder = strdup(bidder);
}

// Function to print the auction details
void print_auction(Auction* auction) {
    printf("Current time: %d\n", auction->current_time);
    printf("End time: %d\n", auction->end_time);

    for (int i = 0; i < auction->num_items; i++) {
        Item* item = &auction->items[i];
        printf("Item %d:\n", item->id);
        printf("Name: %s\n", item->name);
        printf("Reserve price: %f\n", item->reserve_price);
        printf("Current bid: %f\n", item->current_bid);
        printf("Highest bidder: %s\n\n", item->highest_bidder);
    }
}

// Function to run the auction
void run_auction(Auction* auction) {
    // Loop until the auction end time is reached
    while (auction->current_time < auction->end_time) {
        // Print the auction details
        print_auction(auction);

        // Get the next bid from the user
        int item_id;
        char bidder[256];
        float bid_amount;
        printf("Enter item ID, bidder name, and bid amount: ");
        scanf("%d %s %f", &item_id, &bidder, &bid_amount);

        // Place the bid
        place_bid(auction, item_id, bidder, bid_amount);

        // Increment the current time
        auction->current_time++;
    }

    // Print the auction results
    print_auction(auction);
}

// Main function
int main() {
    // Create some items
    Item* item1 = create_item(1, "Painting", 100.0);
    Item* item2 = create_item(2, "Sculpture", 200.0);
    Item* item3 = create_item(3, "Vase", 50.0);

    // Create an auction
    Auction* auction = create_auction(3, (Item*[]){item1, item2, item3}, 0, 10);

    // Run the auction
    run_auction(auction);

    // Free the memory allocated for the items and auction
    for (int i = 0; i < auction->num_items; i++) {
        free(auction->items[i].name);
        free(auction->items[i].highest_bidder);
    }
    free(auction->items);
    free(auction);

    return 0;
}