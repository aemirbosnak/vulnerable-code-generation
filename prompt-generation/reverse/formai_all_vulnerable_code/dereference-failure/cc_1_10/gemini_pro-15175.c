//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item structure
typedef struct Item {
    char name[50];
    float price;
} Item;

// Bidder structure
typedef struct Bidder {
    char name[50];
    float bid;
} Bidder;

// Auction structure
typedef struct Auction {
    Item item;
    Bidder* bidders;
    int num_bidders;
} Auction;

// Create a new auction
Auction* create_auction(Item item) {
    Auction* auction = malloc(sizeof(Auction));
    auction->item = item;
    auction->bidders = NULL;
    auction->num_bidders = 0;
    return auction;
}

// Destroy an auction
void destroy_auction(Auction* auction) {
    if (auction->bidders != NULL) {
        free(auction->bidders);
    }
    free(auction);
}

// Add a bidder to an auction
void add_bidder(Auction* auction, Bidder bidder) {
    auction->bidders = realloc(auction->bidders, (auction->num_bidders + 1) * sizeof(Bidder));
    auction->bidders[auction->num_bidders] = bidder;
    auction->num_bidders++;
}

// Get the highest bid for an auction
float get_highest_bid(Auction* auction) {
    float highest_bid = 0;
    for (int i = 0; i < auction->num_bidders; i++) {
        if (auction->bidders[i].bid > highest_bid) {
            highest_bid = auction->bidders[i].bid;
        }
    }
    return highest_bid;
}

// Get the winning bidder for an auction
Bidder* get_winning_bidder(Auction* auction) {
    float highest_bid = 0;
    Bidder* winning_bidder = NULL;
    for (int i = 0; i < auction->num_bidders; i++) {
        if (auction->bidders[i].bid > highest_bid) {
            highest_bid = auction->bidders[i].bid;
            winning_bidder = &auction->bidders[i];
        }
    }
    return winning_bidder;
}

// Run an auction
void run_auction(Auction* auction) {
    // Print the auction information
    printf("Item: %s\n", auction->item.name);
    printf("Starting price: $%.2f\n", auction->item.price);

    // Get bids from bidders
    while (1) {
        char name[50];
        float bid;
        printf("Enter your name: ");
        scanf("%s", name);
        printf("Enter your bid: ");
        scanf("%f", &bid);

        // Add the bidder to the auction
        Bidder bidder = { .name = name, .bid = bid };
        add_bidder(auction, bidder);

        // Check if the user wants to continue bidding
        char choice;
        printf("Do you want to continue bidding (y/n)? ");
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    // Get the highest bid and winning bidder
    float highest_bid = get_highest_bid(auction);
    Bidder* winning_bidder = get_winning_bidder(auction);

    // Print the results of the auction
    printf("The highest bid was $%.2f from %s.\n", highest_bid, winning_bidder->name);
}

int main() {
    // Create an item
    Item item = { .name = "Mona Lisa", .price = 1000000 };

    // Create an auction
    Auction* auction = create_auction(item);

    // Run the auction
    run_auction(auction);

    // Destroy the auction
    destroy_auction(auction);

    return 0;
}