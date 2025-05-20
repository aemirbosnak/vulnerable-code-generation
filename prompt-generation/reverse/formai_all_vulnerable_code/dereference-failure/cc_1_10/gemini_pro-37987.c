//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items and bids
#define MAX_ITEMS 100
#define MAX_BIDS 10

// Define the item struct
typedef struct {
    int id;
    char *name;
    float starting_price;
    float current_price;
    int num_bids;
} Item;

// Define the bid struct
typedef struct {
    int id;
    int item_id;
    float amount;
} Bid;

// Define the auction struct
typedef struct {
    Item items[MAX_ITEMS];
    Bid bids[MAX_BIDS];
    int num_items;
    int num_bids;
} Auction;

// Create a new auction
Auction *create_auction() {
    Auction *auction = malloc(sizeof(Auction));
    auction->num_items = 0;
    auction->num_bids = 0;
    return auction;
}

// Add an item to the auction
void add_item(Auction *auction, Item item) {
    auction->items[auction->num_items] = item;
    auction->num_items++;
}

// Add a bid to the auction
void add_bid(Auction *auction, Bid bid) {
    auction->bids[auction->num_bids] = bid;
    auction->num_bids++;
}

// Get the current price of an item
float get_current_price(Auction *auction, int item_id) {
    for (int i = 0; i < auction->num_items; i++) {
        if (auction->items[i].id == item_id) {
            return auction->items[i].current_price;
        }
    }
    return -1;
}

// Place a bid on an item
int place_bid(Auction *auction, int item_id, float amount) {
    // Check if the item exists
    int item_index = -1;
    for (int i = 0; i < auction->num_items; i++) {
        if (auction->items[i].id == item_id) {
            item_index = i;
            break;
        }
    }
    if (item_index == -1) {
        return -1;
    }

    // Check if the bid is valid
    if (amount <= auction->items[item_index].current_price) {
        return -2;
    }

    // Place the bid
    Bid bid;
    bid.id = auction->num_bids;
    bid.item_id = item_id;
    bid.amount = amount;
    add_bid(auction, bid);

    // Update the item's current price
    auction->items[item_index].current_price = amount;

    return 0;
}

// Get the winner of an item
int get_winner(Auction *auction, int item_id) {
    // Find the bid with the highest amount for the item
    int winning_bid_index = -1;
    float winning_bid_amount = -1;
    for (int i = 0; i < auction->num_bids; i++) {
        if (auction->bids[i].item_id == item_id && auction->bids[i].amount > winning_bid_amount) {
            winning_bid_index = i;
            winning_bid_amount = auction->bids[i].amount;
        }
    }

    // Return the winner's ID
    if (winning_bid_index == -1) {
        return -1;
    }
    return auction->bids[winning_bid_index].id;
}

// Print the auction results
void print_results(Auction *auction) {
    printf("Auction Results\n");
    printf("===============\n");
    for (int i = 0; i < auction->num_items; i++) {
        printf("Item: %s\n", auction->items[i].name);
        printf("Starting Price: $%.2f\n", auction->items[i].starting_price);
        printf("Winning Bid: $%.2f\n", auction->items[i].current_price);
        printf("Winner: %d\n\n", get_winner(auction, auction->items[i].id));
    }
}

// Main function
int main() {
    // Create a new auction
    Auction *auction = create_auction();

    // Add some items to the auction
    Item item1;
    item1.id = 1;
    item1.name = "Painting";
    item1.starting_price = 100.00;
    item1.current_price = 100.00;
    item1.num_bids = 0;
    add_item(auction, item1);

    Item item2;
    item2.id = 2;
    item2.name = "Sculpture";
    item2.starting_price = 200.00;
    item2.current_price = 200.00;
    item2.num_bids = 0;
    add_item(auction, item2);

    Item item3;
    item3.id = 3;
    item3.name = "Vase";
    item3.starting_price = 50.00;
    item3.current_price = 50.00;
    item3.num_bids = 0;
    add_item(auction, item3);

    // Add some bids to the auction
    Bid bid1;
    bid1.id = 1;
    bid1.item_id = 1;
    bid1.amount = 110.00;
    add_bid(auction, bid1);

    Bid bid2;
    bid2.id = 2;
    bid2.item_id = 1;
    bid2.amount = 120.00;
    add_bid(auction, bid2);

    Bid bid3;
    bid3.id = 3;
    bid3.item_id = 2;
    bid3.amount = 210.00;
    add_bid(auction, bid3);

    Bid bid4;
    bid4.id = 4;
    bid4.item_id = 2;
    bid4.amount = 220.00;
    add_bid(auction, bid4);

    Bid bid5;
    bid5.id = 5;
    bid5.item_id = 3;
    bid5.amount = 60.00;
    add_bid(auction, bid5);

    // Print the auction results
    print_results(auction);

    return 0;
}