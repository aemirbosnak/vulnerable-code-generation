//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Struct to hold information about each bid */
typedef struct bid {
    char bidder_name[50];
    int amount;
} Bid;

/* Struct to hold information about the auction */
typedef struct auction {
    char item_name[50];
    Bid current_bid;
    Bid* all_bids;
    int num_bids;
    int max_bids;
} Auction;

/* Function to add a new bid to the auction */
void add_bid(Auction* auction, char* bidder_name, int amount) {
    /* Check if the amount is higher than the current bid */
    if (amount > auction->current_bid.amount) {
        /* Update the current bid */
        strcpy(auction->current_bid.bidder_name, bidder_name);
        auction->current_bid.amount = amount;
    }
    /* Add the bid to the list of all bids */
    if (auction->num_bids == auction->max_bids) {
        /* Allocate more memory if necessary */
        auction->all_bids = realloc(auction->all_bids, sizeof(Bid) * (auction->max_bids + 10));
        auction->max_bids += 10;
    }
    strcpy(auction->all_bids[auction->num_bids].bidder_name, bidder_name);
    auction->all_bids[auction->num_bids].amount = amount;
    auction->num_bids++;
}

/* Function to print out all of the bids in the auction */
void print_bids(Auction* auction) {
    printf("All Bids for %s:\n", auction->item_name);
    int i;
    for (i = 0; i < auction->num_bids; i++) {
        printf("%d: %s bid %d\n", i + 1, auction->all_bids[i].bidder_name, auction->all_bids[i].amount);
    }
}

/* Function to simulate the auction process */
void simulate_auction(Auction* auction) {
    int i;
    printf("Auction for %s starting...\n", auction->item_name);
    printf("Starting bid is 0\n");
    for (i = 0; i < 3; i++) {
        printf("Please enter your bid (in dollars): ");
        char bidder_name[50];
        int amount;
        scanf("%s %d", bidder_name, &amount);
        add_bid(auction, bidder_name, amount);
        printf("Current bid is %d\n", auction->current_bid.amount);
    }
    printf("Auction over!\n");
    printf("Winner is %s with a bid of %d\n", auction->current_bid.bidder_name, auction->current_bid.amount);
    print_bids(auction);
}

int main() {
    /* Seed the random number generator */
    srand(time(NULL));
    /* Create a new auction */
    Auction auction;
    strcpy(auction.item_name, "Baseball Card");
    auction.current_bid.amount = 0;
    auction.num_bids = 0;
    auction.max_bids = 10;
    auction.all_bids = (Bid*)malloc(sizeof(Bid) * auction.max_bids);
    /* Simulate the auction */
    simulate_auction(&auction);
    /* Clean up memory */
    free(auction.all_bids);
    return 0;
}