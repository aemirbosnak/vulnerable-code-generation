//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an auction item
typedef struct {
    char name[50];
    int quantity;
    float price;
} AuctionItem;

// Define the structure for an auction
typedef struct {
    AuctionItem items[10];
    int num_items;
} Auction;

// Define the function to initialize an auction
Auction* init_auction(int num_items) {
    Auction* auction = (Auction*) malloc(sizeof(Auction));
    auction->num_items = num_items;
    return auction;
}

// Define the function to add an item to the auction
void add_item(Auction* auction, const char* name, int quantity, float price) {
    AuctionItem* item = &auction->items[auction->num_items];
    strcpy(item->name, name);
    item->quantity = quantity;
    item->price = price;
    auction->num_items++;
}

// Define the function to display the items in the auction
void display_items(Auction* auction) {
    for (int i = 0; i < auction->num_items; i++) {
        printf("%s: %d units @ $%.2f\n", auction->items[i].name, auction->items[i].quantity, auction->items[i].price);
    }
}

// Define the function to sell an item in the auction
void sell_item(Auction* auction, const char* name, int quantity, float price) {
    for (int i = 0; i < auction->num_items; i++) {
        if (strcmp(auction->items[i].name, name) == 0) {
            AuctionItem* item = &auction->items[i];
            if (item->quantity > quantity) {
                item->quantity -= quantity;
            } else {
                printf("Sorry, only %d units of %s are available.\n", item->quantity, name);
            }
            printf("Sold %d units of %s at $%.2f.\n", quantity, name, price);
            return;
        }
    }
    printf("Sorry, we don't have any %s in stock.\n", name);
}

// Define the main function
int main() {
    // Initialize the auction
    Auction* auction = init_auction(5);

    // Add items to the auction
    add_item(auction, "Widget", 10, 20.99);
    add_item(auction, "Gadget", 5, 12.49);
    add_item(auction, "Thingamajig", 3, 7.99);
    add_item(auction, "Whatchamacallit", 1, 4.99);
    add_item(auction, "Doo-hickey", 2, 2.99);

    // Display the items in the auction
    display_items(auction);

    // Sell some items
    sell_item(auction, "Widget", 2, 20.99);
    sell_item(auction, "Gadget", 1, 12.49);
    sell_item(auction, "Whatchamacallit", 1, 4.99);

    // Display the updated items in the auction
    display_items(auction);

    return 0;
}