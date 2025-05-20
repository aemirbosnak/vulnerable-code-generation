//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines the maximum number of items in the auction
#define MAX_ITEMS 10

// Defines the structure of an item in the auction
typedef struct {
    int id;             // The unique identifier of the item
    char* name;         // The name of the item
    float reserve_price; // The reserve price of the item
    float current_bid;   // The current highest bid on the item
    int bidder_id;      // The ID of the current highest bidder
} Item;

// Defines the structure of a bid on an item
typedef struct {
    int item_id;     // The ID of the item being bid on
    int bidder_id;    // The ID of the bidder
    float amount;     // The amount of the bid
} Bid;

// Defines the structure of the auction system
typedef struct {
    Item items[MAX_ITEMS]; // The array of items in the auction
    int num_items;         // The number of items in the auction
    Bid bids[MAX_ITEMS];   // The array of bids on the items
    int num_bids;          // The number of bids on the items
} AuctionSystem;

// Creates a new auction system
AuctionSystem* create_auction_system() {
    AuctionSystem* system = malloc(sizeof(AuctionSystem));
    system->num_items = 0;
    system->num_bids = 0;
    return system;
}

// Adds an item to the auction system
void add_item(AuctionSystem* system, Item item) {
    if (system->num_items < MAX_ITEMS) {
        system->items[system->num_items] = item;
        system->num_items++;
    }
}

// Adds a bid to the auction system
void add_bid(AuctionSystem* system, Bid bid) {
    if (system->num_bids < MAX_ITEMS) {
        system->bids[system->num_bids] = bid;
        system->num_bids++;
    }
}

// Gets the current highest bid for an item
float get_current_bid(AuctionSystem* system, int item_id) {
    float highest_bid = 0.0;
    for (int i = 0; i < system->num_bids; i++) {
        if (system->bids[i].item_id == item_id && system->bids[i].amount > highest_bid) {
            highest_bid = system->bids[i].amount;
        }
    }
    return highest_bid;
}

// Gets the current highest bidder for an item
int get_current_bidder(AuctionSystem* system, int item_id) {
    int highest_bidder = 0;
    float highest_bid = 0.0;
    for (int i = 0; i < system->num_bids; i++) {
        if (system->bids[i].item_id == item_id && system->bids[i].amount > highest_bid) {
            highest_bid = system->bids[i].amount;
            highest_bidder = system->bids[i].bidder_id;
        }
    }
    return highest_bidder;
}

// Prints the details of the auction system
void print_auction_system(AuctionSystem* system) {
    printf("Items:\n");
    for (int i = 0; i < system->num_items; i++) {
        printf("  - %s (ID: %d, Reserve Price: %.2f, Current Bid: %.2f, Current Bidder: %d)\n",
            system->items[i].name, system->items[i].id, system->items[i].reserve_price,
            system->items[i].current_bid, system->items[i].bidder_id);
    }
    printf("Bids:\n");
    for (int i = 0; i < system->num_bids; i++) {
        printf("  - Item ID: %d, Bidder ID: %d, Amount: %.2f\n",
            system->bids[i].item_id, system->bids[i].bidder_id, system->bids[i].amount);
    }
}

// Frees the memory allocated for the auction system
void free_auction_system(AuctionSystem* system) {
    for (int i = 0; i < system->num_items; i++) {
        free(system->items[i].name);
    }
    free(system);
}

// Main function
int main() {
    // Creates a new auction system
    AuctionSystem* system = create_auction_system();

    // Adds some items to the auction system
    Item item1 = {1, "Painting", 100.0, 0.0, 0};
    Item item2 = {2, "Sculpture", 200.0, 0.0, 0};
    Item item3 = {3, "Vase", 50.0, 0.0, 0};
    add_item(system, item1);
    add_item(system, item2);
    add_item(system, item3);

    // Adds some bids to the auction system
    Bid bid1 = {1, 1, 110.0};
    Bid bid2 = {2, 2, 210.0};
    Bid bid3 = {3, 3, 60.0};
    add_bid(system, bid1);
    add_bid(system, bid2);
    add_bid(system, bid3);

    // Prints the details of the auction system
    print_auction_system(system);

    // Frees the memory allocated for the auction system
    free_auction_system(system);

    return 0;
}