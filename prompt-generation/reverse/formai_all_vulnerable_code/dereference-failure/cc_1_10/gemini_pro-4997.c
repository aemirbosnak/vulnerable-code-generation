//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Type definition for a bid
typedef struct {
    char *name;  // Name of the bidder
    int amount;  // Amount of the bid
} bid_t;

// Type definition for an auction
typedef struct {
    char *name;     // Name of the auction
    char *desc;     // Description of the auction
    int start_time; // Start time of the auction (epoch time)
    int end_time;   // End time of the auction (epoch time)
    bid_t *bids;    // Array of bids
    int num_bids;   // Number of bids
} auction_t;

// Function to create a new auction
auction_t *create_auction(char *name, char *desc, int start_time, int end_time) {
    auction_t *auction = malloc(sizeof(auction_t));
    auction->name = strdup(name);
    auction->desc = strdup(desc);
    auction->start_time = start_time;
    auction->end_time = end_time;
    auction->bids = NULL;
    auction->num_bids = 0;
    return auction;
}

// Function to add a bid to an auction
void add_bid(auction_t *auction, char *name, int amount) {
    auction->bids = realloc(auction->bids, (auction->num_bids + 1) * sizeof(bid_t));
    auction->bids[auction->num_bids].name = strdup(name);
    auction->bids[auction->num_bids].amount = amount;
    auction->num_bids++;
}

// Function to get the highest bid for an auction
bid_t *get_highest_bid(auction_t *auction) {
    if (auction->num_bids == 0) {
        return NULL;
    }
    bid_t *highest_bid = &auction->bids[0];
    for (int i = 1; i < auction->num_bids; i++) {
        if (auction->bids[i].amount > highest_bid->amount) {
            highest_bid = &auction->bids[i];
        }
    }
    return highest_bid;
}

// Function to print the details of an auction
void print_auction(auction_t *auction) {
    printf("Name: %s\n", auction->name);
    printf("Description: %s\n", auction->desc);
    printf("Start time: %d\n", auction->start_time);
    printf("End time: %d\n", auction->end_time);
    printf("Number of bids: %d\n", auction->num_bids);
    for (int i = 0; i < auction->num_bids; i++) {
        printf("Bid %d:\n", i + 1);
        printf("Name: %s\n", auction->bids[i].name);
        printf("Amount: %d\n", auction->bids[i].amount);
    }
}

// Function to free the memory allocated for an auction
void free_auction(auction_t *auction) {
    free(auction->name);
    free(auction->desc);
    for (int i = 0; i < auction->num_bids; i++) {
        free(auction->bids[i].name);
    }
    free(auction->bids);
    free(auction);
}

int main() {
    // Create an array of auctions
    auction_t *auctions[] = {
        create_auction("Mona Lisa", "The famous painting by Leonardo da Vinci", 1625097600, 1625184000),
        create_auction("Starry Night", "The iconic painting by Vincent van Gogh", 1625184000, 1625270400),
        create_auction("The Scream", "The expressionist masterpiece by Edvard Munch", 1625270400, 1625356800),
    };

    // Add bids to the auctions
    add_bid(auctions[0], "Alice", 10000);
    add_bid(auctions[0], "Bob", 12000);
    add_bid(auctions[1], "Carol", 15000);
    add_bid(auctions[1], "Dave", 18000);
    add_bid(auctions[2], "Eve", 20000);
    add_bid(auctions[2], "Frank", 22000);

    // Get the current time
    time_t current_time = time(NULL);

    // Print the details of each auction
    for (int i = 0; i < 3; i++) {
        if (current_time >= auctions[i]->start_time && current_time <= auctions[i]->end_time) {
            printf("Current auction: %s\n", auctions[i]->name);
            print_auction(auctions[i]);
            bid_t *highest_bid = get_highest_bid(auctions[i]);
            if (highest_bid != NULL) {
                printf("Highest bid: %s %d\n", highest_bid->name, highest_bid->amount);
            } else {
                printf("No bids yet.\n");
            }
        }
    }

    // Free the memory allocated for the auctions
    for (int i = 0; i < 3; i++) {
        free_auction(auctions[i]);
    }

    return 0;
}