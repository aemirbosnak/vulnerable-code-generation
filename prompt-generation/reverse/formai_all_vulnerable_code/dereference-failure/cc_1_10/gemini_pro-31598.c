//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lots in the auction
#define MAX_LOTS 100

// Define the maximum length of a lot description
#define MAX_DESCRIPTION_LEN 100

// Define the maximum number of bids per lot
#define MAX_BIDS_PER_LOT 10

// Define the data structure for a lot
typedef struct {
    int lot_number;
    char description[MAX_DESCRIPTION_LEN];
    float reserve_price;
    float current_bid;
    int number_of_bids;
    int winning_bidder;
} Lot;

// Define the data structure for a bid
typedef struct {
    int lot_number;
    float amount;
    int bidder_id;
} Bid;

// Define the data structure for the auction
typedef struct {
    int number_of_lots;
    Lot lots[MAX_LOTS];
    int number_of_bids;
    Bid bids[MAX_LOTS * MAX_BIDS_PER_LOT];
} Auction;

// Create a new auction
Auction* create_auction() {
    Auction* auction = (Auction*)malloc(sizeof(Auction));
    auction->number_of_lots = 0;
    auction->number_of_bids = 0;
    return auction;
}

// Add a lot to the auction
void add_lot(Auction* auction, int lot_number, char* description, float reserve_price) {
    Lot lot;
    lot.lot_number = lot_number;
    strncpy(lot.description, description, MAX_DESCRIPTION_LEN);
    lot.reserve_price = reserve_price;
    lot.current_bid = 0.0;
    lot.number_of_bids = 0;
    lot.winning_bidder = -1;
    auction->lots[auction->number_of_lots++] = lot;
}

// Place a bid on a lot
void place_bid(Auction* auction, int lot_number, float amount, int bidder_id) {
    if (lot_number < 1 || lot_number > auction->number_of_lots) {
        printf("Invalid lot number.\n");
        return;
    }

    Lot* lot = &auction->lots[lot_number - 1];

    if (lot->current_bid >= amount) {
        printf("Bid amount must be greater than the current bid.\n");
        return;
    }

    if (lot->reserve_price > amount) {
        printf("Bid amount must be greater than the reserve price.\n");
        return;
    }

    Bid bid;
    bid.lot_number = lot_number;
    bid.amount = amount;
    bid.bidder_id = bidder_id;
    auction->bids[auction->number_of_bids++] = bid;

    lot->current_bid = amount;
    lot->number_of_bids++;
    lot->winning_bidder = bidder_id;
}

// Print the auction results
void print_results(Auction* auction) {
    for (int i = 0; i < auction->number_of_lots; i++) {
        Lot* lot = &auction->lots[i];
        printf("Lot %d: %s\n", lot->lot_number, lot->description);
        printf("Reserve price: $%.2f\n", lot->reserve_price);
        printf("Current bid: $%.2f\n", lot->current_bid);
        printf("Number of bids: %d\n", lot->number_of_bids);
        if (lot->winning_bidder != -1) {
            printf("Winning bidder: %d\n", lot->winning_bidder);
        }
        printf("\n");
    }
}

// Free the memory allocated for the auction
void free_auction(Auction* auction) {
    free(auction);
}

int main() {
    // Create a new auction
    Auction* auction = create_auction();

    // Add some lots to the auction
    add_lot(auction, 1, "Painting by Pablo Picasso", 10000.0);
    add_lot(auction, 2, "Sculpture by Michelangelo", 20000.0);
    add_lot(auction, 3, "Vase by Salvador Dali", 5000.0);

    // Place some bids on the lots
    place_bid(auction, 1, 11000.0, 1);
    place_bid(auction, 1, 12000.0, 2);
    place_bid(auction, 2, 21000.0, 3);
    place_bid(auction, 3, 5500.0, 4);

    // Print the auction results
    print_results(auction);

    // Free the memory allocated for the auction
    free_auction(auction);

    return 0;
}