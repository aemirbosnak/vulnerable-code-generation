//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: Donald Knuth
/*
 * Digital Auction System: Knuthian Style
 *
 * This program demonstrates a simple digital auction system in the inimitable style of Dr. Donald E. Knuth.
 *
 * Usage:
 *   ./auction [initial_price] [maximum_price]
 *
 * Example:
 *   ./auction 100 1000
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the auction structure.
typedef struct {
    int initial_price;       // The initial price of the item.
    int maximum_price;       // The maximum price that the seller is willing to accept.
    int current_price;       // The current price of the item.
    int highest_bidder;      // The ID of the highest bidder.
    int num_bids;            // The number of bids that have been placed.
    int winning_bid;         // The winning bid.
} Auction;

// Initialize the auction.
void init_auction(Auction *auction, int initial_price, int maximum_price) {
    auction->initial_price = initial_price;
    auction->maximum_price = maximum_price;
    auction->current_price = initial_price;
    auction->highest_bidder = -1;
    auction->num_bids = 0;
    auction->winning_bid = -1;
}

// Get a random integer between two values.
int get_random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Place a bid on the item.
int place_bid(Auction *auction, int bidder_id, int bid) {
    // Check if the bid is valid.
    if (bid <= auction->current_price || bid > auction->maximum_price) {
        return -1;
    }

    // Update the auction state.
    auction->current_price = bid;
    auction->highest_bidder = bidder_id;
    auction->num_bids++;
    auction->winning_bid = bid;

    return 0;
}

// Conduct the auction.
void conduct_auction(Auction *auction) {
    // Initialize the random number generator.
    srand(time(NULL));

    // Generate a series of bids.
    int num_bids = get_random_int(1, 10);
    for (int i = 0; i < num_bids; i++) {
        // Get a random bidder ID.
        int bidder_id = get_random_int(0, 99);

        // Get a random bid.
        int bid = get_random_int(auction->current_price + 1, auction->maximum_price);

        // Place the bid.
        if (place_bid(auction, bidder_id, bid) == 0) {
            // The bid was successful.
            printf("Bidder %d placed a bid of %d.\n", bidder_id, bid);
        } else {
            // The bid was invalid.
            printf("Bidder %d placed an invalid bid of %d.\n", bidder_id, bid);
        }
    }
}

// Print the auction results.
void print_results(Auction *auction) {
    printf("The winning bid was %d, placed by bidder %d.\n", auction->winning_bid, auction->highest_bidder);
}

// Main function.
int main(int argc, char **argv) {
    // Check the command-line arguments.
    if (argc != 3) {
        printf("Usage: %s [initial_price] [maximum_price]\n", argv[0]);
        return -1;
    }

    // Parse the command-line arguments.
    int initial_price = atoi(argv[1]);
    int maximum_price = atoi(argv[2]);

    // Initialize the auction.
    Auction auction;
    init_auction(&auction, initial_price, maximum_price);

    // Conduct the auction.
    conduct_auction(&auction);

    // Print the auction results.
    print_results(&auction);

    return 0;
}