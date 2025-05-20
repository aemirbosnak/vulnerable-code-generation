//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    int id;
    char *name;
    float reserve_price;
    float current_bid;
    int bidder_id;
};

struct Auction {
    int id;
    char *name;
    struct Item *items;
    int num_items;
    int current_item_index;
};

int main() {
    // Create an auction
    struct Auction auction;
    auction.id = 1;
    auction.name = "My Awesome Auction";
    auction.items = malloc(sizeof(struct Item) * 10);
    auction.num_items = 0;
    auction.current_item_index = -1;

    // Add some items to the auction
    struct Item item1;
    item1.id = 1;
    item1.name = "iPhone 13 Pro";
    item1.reserve_price = 999.00;
    item1.current_bid = 0.00;
    item1.bidder_id = -1;

    struct Item item2;
    item2.id = 2;
    item2.name = "MacBook Pro 16-inch";
    item2.reserve_price = 2499.00;
    item2.current_bid = 0.00;
    item2.bidder_id = -1;

    struct Item item3;
    item3.id = 3;
    item3.name = "Apple Watch Series 7";
    item3.reserve_price = 399.00;
    item3.current_bid = 0.00;
    item3.bidder_id = -1;

    auction.items[auction.num_items++] = item1;
    auction.items[auction.num_items++] = item2;
    auction.items[auction.num_items++] = item3;

    // Start the auction
    while (auction.current_item_index < auction.num_items) {
        // Get the current item
        struct Item *item = &auction.items[auction.current_item_index];

        // Print the item details
        printf("Item %d: %s\n", item->id, item->name);
        printf("Reserve price: $%.2f\n", item->reserve_price);
        printf("Current bid: $%.2f\n", item->current_bid);
        printf("Current bidder: %d\n", item->bidder_id);

        // Get a bid from the user
        float bid;
        printf("Enter your bid: ");
        scanf("%f", &bid);

        // Check if the bid is valid
        if (bid >= item->reserve_price && bid > item->current_bid) {
            // Update the current bid
            item->current_bid = bid;

            // Update the current bidder
            item->bidder_id = 1;
        } else {
            printf("Invalid bid. Please try again.\n");
        }

        // Move to the next item
        auction.current_item_index++;
    }

    // Print the results of the auction
    printf("Auction results:\n");
    for (int i = 0; i < auction.num_items; i++) {
        struct Item *item = &auction.items[i];
        printf("Item %d: %s\n", item->id, item->name);
        printf("Sold for: $%.2f\n", item->current_bid);
        printf("To bidder: %d\n", item->bidder_id);
    }

    return 0;
}