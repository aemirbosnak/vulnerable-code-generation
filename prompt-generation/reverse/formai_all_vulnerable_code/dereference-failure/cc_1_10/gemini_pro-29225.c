//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item struct to store item details
typedef struct Item {
    int id;
    char name[50];
    float starting_price;
    float current_bid;
    int highest_bidder_id;
} Item;

// Bidder struct to store bidder details
typedef struct Bidder {
    int id;
    char name[50];
    float balance;
} Bidder;

// Function to create a new item
Item *create_item(int id, char *name, float starting_price) {
    Item *item = (Item *)malloc(sizeof(Item));
    item->id = id;
    strcpy(item->name, name);
    item->starting_price = starting_price;
    item->current_bid = starting_price;
    item->highest_bidder_id = -1;
    return item;
}

// Function to create a new bidder
Bidder *create_bidder(int id, char *name, float balance) {
    Bidder *bidder = (Bidder *)malloc(sizeof(Bidder));
    bidder->id = id;
    strcpy(bidder->name, name);
    bidder->balance = balance;
    return bidder;
}

// Function to place a bid
void place_bid(Item *item, Bidder *bidder, float bid_amount) {
    if (bid_amount <= item->current_bid) {
        printf("Bid amount must be greater than the current bid.\n");
        return;
    }
    if (bidder->balance < bid_amount) {
        printf("Insufficient balance to place bid.\n");
        return;
    }
    item->current_bid = bid_amount;
    item->highest_bidder_id = bidder->id;
    bidder->balance -= bid_amount;
    printf("Bid placed successfully.\n");
}

// Function to close the auction
void close_auction(Item *item) {
    printf("Auction closed for item %s (ID: %d).\n", item->name, item->id);
    if (item->highest_bidder_id == -1) {
        printf("No bids placed.\n");
    } else {
        printf("Winning bid: %.2f by %s (ID: %d).\n", item->current_bid, item->name, item->highest_bidder_id);
    }
}

// Driver function
int main() {
    // Create some items
    Item *item1 = create_item(1, "Painting", 100.0);
    Item *item2 = create_item(2, "Sculpture", 200.0);
    Item *item3 = create_item(3, "Vase", 50.0);

    // Create some bidders
    Bidder *bidder1 = create_bidder(1, "Alice", 500.0);
    Bidder *bidder2 = create_bidder(2, "Bob", 1000.0);
    Bidder *bidder3 = create_bidder(3, "Carol", 1500.0);

    // Place some bids
    place_bid(item1, bidder1, 120.0);
    place_bid(item2, bidder2, 250.0);
    place_bid(item1, bidder2, 150.0);
    place_bid(item3, bidder3, 60.0);
    place_bid(item2, bidder1, 300.0);

    // Close the auction
    close_auction(item1);
    close_auction(item2);
    close_auction(item3);

    return 0;
}