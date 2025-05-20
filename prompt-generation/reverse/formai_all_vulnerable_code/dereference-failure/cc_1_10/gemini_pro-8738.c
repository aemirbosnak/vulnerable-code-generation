//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of an auction item
typedef struct {
    int id;                 // Unique ID of the item
    char *name;             // Name of the item
    char *description;       // Description of the item
    float reserve_price;     // Reserve price of the item
    float current_bid;      // Current bid on the item
    int highest_bidder;     // ID of the highest bidder
} auction_item;

// Define the structure of an auction
typedef struct {
    int id;                 // Unique ID of the auction
    char *name;             // Name of the auction
    char *description;       // Description of the auction
    auction_item *items;    // Array of auction items
    int num_items;          // Number of auction items
    int current_bidder;     // ID of the current highest bidder
    float current_bid;      // Current highest bid
} auction;

// Function to create a new auction
auction *create_auction(int id, char *name, char *description) {
    auction *a = malloc(sizeof(auction));
    a->id = id;
    a->name = strdup(name);
    a->description = strdup(description);
    a->items = NULL;
    a->num_items = 0;
    a->current_bidder = -1;
    a->current_bid = 0.0;
    return a;
}

// Function to add an item to an auction
void add_item_to_auction(auction *a, auction_item *item) {
    a->items = realloc(a->items, (a->num_items + 1) * sizeof(auction_item));
    a->items[a->num_items] = *item;
    a->num_items++;
}

// Function to print the details of an auction
void print_auction(auction *a) {
    printf("Auction ID: %d\n", a->id);
    printf("Auction Name: %s\n", a->name);
    printf("Auction Description: %s\n", a->description);
    printf("Number of Items: %d\n", a->num_items);
    for (int i = 0; i < a->num_items; i++) {
        printf("Item ID: %d\n", a->items[i].id);
        printf("Item Name: %s\n", a->items[i].name);
        printf("Item Description: %s\n", a->items[i].description);
        printf("Item Reserve Price: %f\n", a->items[i].reserve_price);
        printf("Item Current Bid: %f\n", a->items[i].current_bid);
        printf("Item Highest Bidder: %d\n", a->items[i].highest_bidder);
    }
}

// Function to start an auction
void start_auction(auction *a) {
    while (a->current_bid < a->items[0].reserve_price) {
        printf("Current bid: %f\n", a->current_bid);
        printf("Enter your bid: ");
        float bid;
        scanf("%f", &bid);
        if (bid > a->current_bid) {
            a->current_bid = bid;
            a->current_bidder = bid;
        }
    }
    printf("Auction over!\n");
    printf("Winning bid: %f\n", a->current_bid);
    printf("Winning bidder: %d\n", a->current_bidder);
}

// Main function
int main() {
    // Create a new auction
    auction *a = create_auction(1, "My Auction", "This is my auction.");

    // Add some items to the auction
    auction_item item1, item2, item3;
    item1.id = 1;
    item1.name = strdup("Item 1");
    item1.description = strdup("This is item 1.");
    item1.reserve_price = 10.0;
    item1.current_bid = 0.0;
    item1.highest_bidder = -1;
    add_item_to_auction(a, &item1);

    item2.id = 2;
    item2.name = strdup("Item 2");
    item2.description = strdup("This is item 2.");
    item2.reserve_price = 20.0;
    item2.current_bid = 0.0;
    item2.highest_bidder = -1;
    add_item_to_auction(a, &item2);

    item3.id = 3;
    item3.name = strdup("Item 3");
    item3.description = strdup("This is item 3.");
    item3.reserve_price = 30.0;
    item3.current_bid = 0.0;
    item3.highest_bidder = -1;
    add_item_to_auction(a, &item3);

    // Print the details of the auction
    print_auction(a);

    // Start the auction
    start_auction(a);

    return 0;
}