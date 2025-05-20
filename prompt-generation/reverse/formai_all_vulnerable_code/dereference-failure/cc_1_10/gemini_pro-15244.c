//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of bids
#define MAX_BIDS 10

// Define the structure of a bid
typedef struct {
    char *name;
    int amount;
} Bid;

// Define the structure of an auction
typedef struct {
    char *item;
    int starting_price;
    int current_price;
    int num_bids;
    Bid bids[MAX_BIDS];
} Auction;

// Create a new auction
Auction *create_auction(char *item, int starting_price) {
    Auction *auction = malloc(sizeof(Auction));
    auction->item = item;
    auction->starting_price = starting_price;
    auction->current_price = starting_price;
    auction->num_bids = 0;
    return auction;
}

// Add a bid to an auction
void add_bid(Auction *auction, char *name, int amount) {
    if (auction->num_bids < MAX_BIDS) {
        auction->bids[auction->num_bids].name = name;
        auction->bids[auction->num_bids].amount = amount;
        auction->num_bids++;
    }
}

// Get the current highest bid
int get_highest_bid(Auction *auction) {
    int highest_bid = 0;
    for (int i = 0; i < auction->num_bids; i++) {
        if (auction->bids[i].amount > highest_bid) {
            highest_bid = auction->bids[i].amount;
        }
    }
    return highest_bid;
}

// Get the winner of the auction
char *get_winner(Auction *auction) {
    int highest_bid = get_highest_bid(auction);
    for (int i = 0; i < auction->num_bids; i++) {
        if (auction->bids[i].amount == highest_bid) {
            return auction->bids[i].name;
        }
    }
    return NULL;
}

// Print the auction details
void print_auction(Auction *auction) {
    printf("Item: %s\n", auction->item);
    printf("Starting price: %d\n", auction->starting_price);
    printf("Current price: %d\n", auction->current_price);
    printf("Number of bids: %d\n", auction->num_bids);
    for (int i = 0; i < auction->num_bids; i++) {
        printf("Bid %d: %s %d\n", i + 1, auction->bids[i].name, auction->bids[i].amount);
    }
}

// Free the memory allocated for the auction
void free_auction(Auction *auction) {
    free(auction->item);
    for (int i = 0; i < auction->num_bids; i++) {
        free(auction->bids[i].name);
    }
    free(auction);
}

int main() {
    // Create a new auction for Juliet's hand in marriage
    Auction *auction = create_auction("Juliet's hand in marriage", 1000);

    // Add some bids to the auction
    add_bid(auction, "Romeo", 1200);
    add_bid(auction, "Paris", 1500);
    add_bid(auction, "Tybalt", 1800);

    // Print the auction details
    print_auction(auction);

    // Get the winner of the auction
    char *winner = get_winner(auction);

    // Print the winner
    printf("The winner of the auction is: %s\n", winner);

    // Free the memory allocated for the auction
    free_auction(auction);

    return 0;
}