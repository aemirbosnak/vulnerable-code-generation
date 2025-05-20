//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of bidders and items
#define MAX_BIDDERS 10
#define MAX_ITEMS 10

// Define the structure of a bidder
typedef struct {
    char name[100];
    int bid;
} Bidder;

// Define the structure of an item
typedef struct {
    char name[100];
    int price;
} Item;

// Define the structure of the auction system
typedef struct {
    Bidder bidders[MAX_BIDDERS];
    Item items[MAX_ITEMS];
    int num_bidders;
    int num_items;
} AuctionSystem;

// Create a new auction system
AuctionSystem* create_auction_system() {
    AuctionSystem* auction_system = malloc(sizeof(AuctionSystem));
    auction_system->num_bidders = 0;
    auction_system->num_items = 0;
    return auction_system;
}

// Add a bidder to the auction system
void add_bidder(AuctionSystem* auction_system, Bidder bidder) {
    auction_system->bidders[auction_system->num_bidders] = bidder;
    auction_system->num_bidders++;
}

// Add an item to the auction system
void add_item(AuctionSystem* auction_system, Item item) {
    auction_system->items[auction_system->num_items] = item;
    auction_system->num_items++;
}

// Get the highest bid for an item
int get_highest_bid(AuctionSystem* auction_system, Item item) {
    int highest_bid = 0;
    for (int i = 0; i < auction_system->num_bidders; i++) {
        if (auction_system->bidders[i].bid > highest_bid) {
            highest_bid = auction_system->bidders[i].bid;
        }
    }
    return highest_bid;
}

// Get the winner of an auction
Bidder* get_winner(AuctionSystem* auction_system, Item item) {
    int highest_bid = get_highest_bid(auction_system, item);
    for (int i = 0; i < auction_system->num_bidders; i++) {
        if (auction_system->bidders[i].bid == highest_bid) {
            return &auction_system->bidders[i];
        }
    }
    return NULL;
}

// Print the results of the auction
void print_results(AuctionSystem* auction_system) {
    for (int i = 0; i < auction_system->num_items; i++) {
        Item item = auction_system->items[i];
        Bidder* winner = get_winner(auction_system, item);
        printf("Item: %s, Price: %d, Winner: %s\n", item.name, item.price, winner->name);
    }
}

// Main function
int main() {
    // Create a new auction system
    AuctionSystem* auction_system = create_auction_system();

    // Add some bidders to the auction system
    Bidder bidder1 = {"Alice", 100};
    Bidder bidder2 = {"Bob", 120};
    Bidder bidder3 = {"Carol", 150};
    add_bidder(auction_system, bidder1);
    add_bidder(auction_system, bidder2);
    add_bidder(auction_system, bidder3);

    // Add some items to the auction system
    Item item1 = {"Painting", 1000};
    Item item2 = {"Sculpture", 1500};
    Item item3 = {"Jewelry", 2000};
    add_item(auction_system, item1);
    add_item(auction_system, item2);
    add_item(auction_system, item3);

    // Print the results of the auction
    print_results(auction_system);

    return 0;
}