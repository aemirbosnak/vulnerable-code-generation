//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item data structure
typedef struct {
    int id;
    char *name;
    float reserve_price;
    float current_bid;
    int bidder;
} Item;

// Bidder data structure
typedef struct {
    int id;
    char *name;
    float balance;
} Bidder;

// Auction data structure
typedef struct {
    int num_items, num_bidders;
    Item *items;
    Bidder *bidders;
    int current_item;
} Auction;

// Initialize an auction with num_items items and num_bidders bidders
Auction *init_auction(int num_items, int num_bidders) {
    Auction *auction = malloc(sizeof(Auction));

    auction->num_items = num_items;
    auction->num_bidders = num_bidders;
    auction->items = malloc(sizeof(Item) * num_items);
    auction->bidders = malloc(sizeof(Bidder) * num_bidders);
    auction->current_item = 0;

    return auction;
}

// Add an item to the auction
void add_item(Auction *auction, int id, char *name, float reserve_price) {
    Item item = {
        .id = id,
        .name = name,
        .reserve_price = reserve_price,
        .current_bid = 0,
        .bidder = -1
    };

    auction->items[auction->num_items++] = item;
}

// Add a bidder to the auction
void add_bidder(Auction *auction, int id, char *name, float balance) {
    Bidder bidder = {
        .id = id,
        .name = name,
        .balance = balance
    };

    auction->bidders[auction->num_bidders++] = bidder;
}

// Start the auction
void start_auction(Auction *auction) {
    while (auction->current_item < auction->num_items) {
        Item *item = &auction->items[auction->current_item];

        printf("Current item: %s (ID: %d)\nReserve price: %.2f\n", item->name, item->id, item->reserve_price);

        // Get bids from bidders
        int highest_bidder = -1;
        float highest_bid = 0;
        for (int i = 0; i < auction->num_bidders; i++) {
            Bidder *bidder = &auction->bidders[i];

            float bid = 0;
            printf("%s, enter your bid: ", bidder->name);
            scanf("%f", &bid);

            // Check if the bid is valid
            if (bid >= item->current_bid && bid >= item->reserve_price && bid <= bidder->balance) {
                // Update the highest bid if this bid is higher
                if (bid > highest_bid) {
                    highest_bid = bid;
                    highest_bidder = i;
                }
            } else {
                printf("Invalid bid.\n");
            }
        }

        // Check if the highest bid meets the reserve price
        if (highest_bid >= item->reserve_price) {
            // Update the item's current bid and bidder
            item->current_bid = highest_bid;
            item->bidder = highest_bidder;

            // Print the successful bid
            Bidder *successful_bidder = &auction->bidders[highest_bidder];
            printf("Successful bid: %.2f by %s (ID: %d)\n", highest_bid, successful_bidder->name, successful_bidder->id);
        } else {
            // The reserve price was not met, so the item remains unsold
            printf("Reserve price not met. Item unsold.\n");
        }

        auction->current_item++;
    }
}

// Print the results of the auction
void print_results(Auction *auction) {
    printf("Auction results:\n");
    for (int i = 0; i < auction->num_items; i++) {
        Item *item = &auction->items[i];

        if (item->bidder != -1) {
            Bidder *bidder = &auction->bidders[item->bidder];
            printf("%s (ID: %d) sold for %.2f to %s (ID: %d)\n", item->name, item->id, item->current_bid, bidder->name, bidder->id);
        } else {
            printf("%s (ID: %d) unsold\n", item->name, item->id);
        }
    }
}

int main() {
    // Create an auction with 3 items and 4 bidders
    Auction *auction = init_auction(3, 4);

    // Add items to the auction
    add_item(auction, 1, "Painting", 1000);
    add_item(auction, 2, "Sculpture", 500);
    add_item(auction, 3, "Vase", 200);

    // Add bidders to the auction
    add_bidder(auction, 1, "John", 1500);
    add_bidder(auction, 2, "Mary", 1000);
    add_bidder(auction, 3, "Bob", 700);
    add_bidder(auction, 4, "Alice", 500);

    // Start the auction
    start_auction(auction);

    // Print the results of the auction
    print_results(auction);

    return 0;
}