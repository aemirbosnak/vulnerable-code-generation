//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure for a bid
typedef struct bid {
    int bid_price;
    char* bidder;
} Bid;

// Define the structure for the auction
typedef struct auction {
    Bid* bids;
    int num_bids;
} Auction;

// Function to initialize an auction
Auction* init_auction(int num_bids) {
    Auction* auction = (Auction*)malloc(sizeof(Auction));
    auction->num_bids = num_bids;
    auction->bids = (Bid*)malloc(num_bids * sizeof(Bid));
    return auction;
}

// Function to add a bid to the auction
void add_bid(Auction* auction, int bid_price, char* bidder) {
    auction->bids[auction->num_bids].bid_price = bid_price;
    auction->bids[auction->num_bids].bidder = (char*)malloc((strlen(bidder) + 1) * sizeof(char));
    strcpy(auction->bids[auction->num_bids].bidder, bidder);
    auction->num_bids++;
}

// Function to get the highest bid from the auction
int get_highest_bid(Auction* auction) {
    int highest_bid = -1;
    for (int i = 0; i < auction->num_bids; i++) {
        if (auction->bids[i].bid_price > highest_bid) {
            highest_bid = auction->bids[i].bid_price;
        }
    }
    return highest_bid;
}

// Function to print the auction
void print_auction(Auction* auction) {
    printf("Auction: %s\n", auction->bids[0].bidder);
    for (int i = 1; i < auction->num_bids; i++) {
        printf("Bid: %s at $%d\n", auction->bids[i].bidder, auction->bids[i].bid_price);
    }
}

// Main function
int main() {
    // Initialize the auction
    Auction* auction = init_auction(10);
    
    // Add bids to the auction
    add_bid(auction, 100, "John Doe");
    add_bid(auction, 200, "Jane Smith");
    add_bid(auction, 150, "Bob Johnson");
    add_bid(auction, 300, "Alice Williams");
    add_bid(auction, 250, "Charlie Brown");
    add_bid(auction, 400, "David Lee");
    add_bid(auction, 500, "Emily Brown");
    add_bid(auction, 350, "George Washington");
    add_bid(auction, 450, "Mary Jane");
    add_bid(auction, 550, "John Smith");
    
    // Print the auction
    print_auction(auction);
    
    // Get the highest bid
    int highest_bid = get_highest_bid(auction);
    
    // Print the highest bid
    printf("Highest Bid: $%d\n", highest_bid);
    
    // Free the memory
    for (int i = 0; i < auction->num_bids; i++) {
        free(auction->bids[i].bidder);
    }
    free(auction->bids);
    free(auction);
    
    return 0;
}