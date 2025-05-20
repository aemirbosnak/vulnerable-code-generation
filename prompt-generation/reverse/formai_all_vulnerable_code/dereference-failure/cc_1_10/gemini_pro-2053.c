//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lot {
    int id;
    char *description;
    float reserve_price;
    float current_bid;
    char *highest_bidder;
};

struct auction {
    int num_lots;
    struct lot *lots;
};

// Create a new auction
struct auction *create_auction(int num_lots) {
    struct auction *auction = malloc(sizeof(struct auction));
    auction->num_lots = num_lots;
    auction->lots = malloc(sizeof(struct lot) * num_lots);
    return auction;
}

// Add a lot to an auction
void add_lot(struct auction *auction, int id, char *description, float reserve_price) {
    struct lot *lot = &auction->lots[auction->num_lots++];
    lot->id = id;
    lot->description = description;
    lot->reserve_price = reserve_price;
    lot->current_bid = 0;
    lot->highest_bidder = NULL;
}

// Print the details of an auction
void print_auction(struct auction *auction) {
    printf("Auction:\n");
    for (int i = 0; i < auction->num_lots; i++) {
        struct lot *lot = &auction->lots[i];
        printf("Lot %d: %s\n", lot->id, lot->description);
        printf("Reserve price: %.2f\n", lot->reserve_price);
        printf("Current bid: %.2f\n", lot->current_bid);
        if (lot->highest_bidder) {
            printf("Highest bidder: %s\n", lot->highest_bidder);
        }
        printf("\n");
    }
}

// Handle a bid on a lot
void bid(struct auction *auction, int lot_id, char *bidder, float bid_amount) {
    struct lot *lot = &auction->lots[lot_id - 1];  // Lot IDs are 1-based
    if (bid_amount >= lot->reserve_price && bid_amount > lot->current_bid) {
        lot->current_bid = bid_amount;
        lot->highest_bidder = bidder;
    } else {
        printf("Invalid bid: reserve price not met or lower than current bid.\n");
    }
}

// Find the highest bid for an auction
struct lot *find_highest_bid(struct auction *auction) {
    struct lot *highest_bid_lot = NULL;
    float highest_bid = 0;
    for (int i = 0; i < auction->num_lots; i++) {
        struct lot *lot = &auction->lots[i];
        if (lot->current_bid > highest_bid) {
            highest_bid = lot->current_bid;
            highest_bid_lot = lot;
        }
    }
    return highest_bid_lot;
}

// Main function
int main() {
    // Create an auction with 3 lots
    struct auction *auction = create_auction(3);

    // Add lots to the auction
    add_lot(auction, 1, "Painting by Pablo Picasso", 10000);
    add_lot(auction, 2, "Statue by Michelangelo", 20000);
    add_lot(auction, 3, "Rare coin collection", 5000);

    // Print the details of the auction
    print_auction(auction);

    // Handle bids on the lots
    bid(auction, 1, "John Smith", 12000);
    bid(auction, 2, "Mary Johnson", 22000);
    bid(auction, 3, "Bill Jones", 6000);

    // Find the highest bid for the auction
    struct lot *highest_bid_lot = find_highest_bid(auction);

    // Print the details of the highest bid
    printf("Highest bid:\n");
    printf("Lot %d: %s\n", highest_bid_lot->id, highest_bid_lot->description);
    printf("Winning bid: %.2f\n", highest_bid_lot->current_bid);
    printf("Winning bidder: %s\n", highest_bid_lot->highest_bidder);

    return 0;
}