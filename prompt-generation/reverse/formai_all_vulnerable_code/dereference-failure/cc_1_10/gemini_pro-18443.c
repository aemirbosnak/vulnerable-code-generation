//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item struct to store item details
typedef struct Item {
    int id;
    char *name;
    float reserve_price;
    float current_bid;
} Item;

// Bidder struct to store bidder details
typedef struct Bidder {
    int id;
    char *name;
    float balance;
} Bidder;

// Auction struct to store auction details
typedef struct Auction {
    Item *item;
    Bidder **bidders;
    int num_bidders;
    float highest_bid;
} Auction;

// Function to create a new item
Item *create_item(int id, char *name, float reserve_price) {
    Item *item = malloc(sizeof(Item));
    item->id = id;
    item->name = strdup(name);
    item->reserve_price = reserve_price;
    item->current_bid = 0.0;
    return item;
}

// Function to create a new bidder
Bidder *create_bidder(int id, char *name, float balance) {
    Bidder *bidder = malloc(sizeof(Bidder));
    bidder->id = id;
    bidder->name = strdup(name);
    bidder->balance = balance;
    return bidder;
}

// Function to create a new auction
Auction *create_auction(Item *item, Bidder **bidders, int num_bidders) {
    Auction *auction = malloc(sizeof(Auction));
    auction->item = item;
    auction->bidders = bidders;
    auction->num_bidders = num_bidders;
    auction->highest_bid = 0.0;
    return auction;
}

// Function to start the auction
void start_auction(Auction *auction) {
    printf("Starting auction for item: %s\n", auction->item->name);
    printf("Reserve price: %.2f\n", auction->item->reserve_price);
    printf("Current bid: %.2f\n", auction->item->current_bid);

    // Loop until the reserve price is met or there are no more bidders
    while (auction->item->current_bid < auction->item->reserve_price && auction->num_bidders > 0) {
        // Get the next bid from the highest bidder
        float bid_amount;
        Bidder *highest_bidder = NULL;
        for (int i = 0; i < auction->num_bidders; i++) {
            if (auction->bidders[i]->balance > auction->item->current_bid) {
                bid_amount = auction->item->current_bid + 1.0;  // Increment the bid by $1
                highest_bidder = auction->bidders[i];
            }
        }

        // If there is no higher bid, end the auction
        if (highest_bidder == NULL) {
            printf("No higher bids received. Auction ended.\n");
            return;
        }

        // Update the current bid and the highest bidder
        auction->item->current_bid = bid_amount;
        auction->highest_bid = bid_amount;
        printf("%s bid %.2f\n", highest_bidder->name, bid_amount);

        // Remove the highest bidder from the list of bidders
        for (int i = 0; i < auction->num_bidders; i++) {
            if (auction->bidders[i] == highest_bidder) {
                auction->bidders[i] = auction->bidders[auction->num_bidders - 1];
                auction->num_bidders--;
                break;
            }
        }
    }

    // If the reserve price was met, declare the winner
    if (auction->item->current_bid >= auction->item->reserve_price) {
        printf("Reserve price met. ");
        for (int i = 0; i < auction->num_bidders; i++) {
            if (auction->bidders[i]->balance >= auction->item->current_bid) {
                printf("%s won the auction with a bid of %.2f\n", auction->bidders[i]->name, auction->item->current_bid);
                return;
            }
        }
    }

    // Otherwise, declare that the reserve price was not met
    printf("Reserve price not met. Auction ended.\n");
}

// Function to free the memory allocated for the auction
void free_auction(Auction *auction) {
    free(auction->item->name);
    free(auction->item);
    for (int i = 0; i < auction->num_bidders; i++) {
        free(auction->bidders[i]->name);
        free(auction->bidders[i]);
    }
    free(auction->bidders);
    free(auction);
}

int main() {
    // Create the item
    Item *item = create_item(1, "Painting", 100.0);

    // Create the bidders
    Bidder *bidder1 = create_bidder(1, "John", 150.0);
    Bidder *bidder2 = create_bidder(2, "Mary", 120.0);
    Bidder *bidder3 = create_bidder(3, "Bob", 100.0);

    // Create the auction
    Auction *auction = create_auction(item, (Bidder *[]){bidder1, bidder2, bidder3}, 3);

    // Start the auction
    start_auction(auction);

    // Free the memory allocated for the auction
    free_auction(auction);

    return 0;
}