//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the auction
#define MAX_ITEMS 100

// Define the maximum length of an item name
#define MAX_NAME_LENGTH 50

// Define the structure of an auction item
typedef struct {
    char name[MAX_NAME_LENGTH];  // The name of the item
    float reserve_price;  // The reserve price of the item
    float current_bid;  // The current bid on the item
    int bidder;  // The ID of the current high bidder
} Item;

// Define the structure of the auction system
typedef struct {
    Item items[MAX_ITEMS];  // The array of auction items
    int num_items;  // The number of items in the auction
} AuctionSystem;

// Create a new auction system
AuctionSystem* create_auction_system() {
    AuctionSystem* auction_system = malloc(sizeof(AuctionSystem));
    auction_system->num_items = 0;
    return auction_system;
}

// Add an item to the auction system
void add_item(AuctionSystem* auction_system, char* name, float reserve_price) {
    if (auction_system->num_items >= MAX_ITEMS) {
        printf("Error: The auction system is full.\n");
        return;
    }

    strcpy(auction_system->items[auction_system->num_items].name, name);
    auction_system->items[auction_system->num_items].reserve_price = reserve_price;
    auction_system->items[auction_system->num_items].current_bid = 0.0;
    auction_system->items[auction_system->num_items].bidder = -1;
    auction_system->num_items++;
}

// Print the items in the auction system
void print_items(AuctionSystem* auction_system) {
    for (int i = 0; i < auction_system->num_items; i++) {
        printf("Item %d: %s (Reserve price: $%.2f, Current bid: $%.2f, Bidder: %d)\n",
               i + 1, auction_system->items[i].name, auction_system->items[i].reserve_price,
               auction_system->items[i].current_bid, auction_system->items[i].bidder);
    }
}

// Get the highest bid for an item
float get_highest_bid(Item* item) {
    return item->current_bid;
}

// Place a bid on an item
int place_bid(AuctionSystem* auction_system, int item_index, int bidder, float bid) {
    Item* item = &auction_system->items[item_index];

    // Check if the bid is higher than the current bid
    if (bid > item->current_bid) {
        // Check if the bid is higher than the reserve price
        if (bid >= item->reserve_price) {
            // Update the current bid and the bidder
            item->current_bid = bid;
            item->bidder = bidder;
            return 1;
        } else {
            printf("Error: The bid is lower than the reserve price.\n");
            return 0;
        }
    } else {
        printf("Error: The bid is lower than the current bid.\n");
        return 0;
    }
}

// Close the auction and determine the winners
void close_auction(AuctionSystem* auction_system) {
    for (int i = 0; i < auction_system->num_items; i++) {
        Item* item = &auction_system->items[i];

        // Check if the item has been sold
        if (item->current_bid >= item->reserve_price) {
            printf("Item %s sold to bidder %d for $%.2f.\n", item->name, item->bidder,
                   item->current_bid);
        } else {
            printf("Item %s not sold.\n", item->name);
        }
    }
}

// Free the memory used by the auction system
void free_auction_system(AuctionSystem* auction_system) {
    free(auction_system);
}

// Main function
int main() {
    // Create a new auction system
    AuctionSystem* auction_system = create_auction_system();

    // Add some items to the auction system
    add_item(auction_system, "Painting by Van Gogh", 10000.0);
    add_item(auction_system, "Sculpture by Michelangelo", 20000.0);
    add_item(auction_system, "Rare book by Shakespeare", 5000.0);

    // Print the items in the auction system
    print_items(auction_system);

    // Get a bid for the first item
    int bidder1 = 1;
    float bid1 = 11000.0;
    int success1 = place_bid(auction_system, 0, bidder1, bid1);

    // Get a bid for the second item
    int bidder2 = 2;
    float bid2 = 21000.0;
    int success2 = place_bid(auction_system, 1, bidder2, bid2);

    // Print the items in the auction system
    print_items(auction_system);

    // Close the auction and determine the winners
    close_auction(auction_system);

    // Free the memory used by the auction system
    free_auction_system(auction_system);
}