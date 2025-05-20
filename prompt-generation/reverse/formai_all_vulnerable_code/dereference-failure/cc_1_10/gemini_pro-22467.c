//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures

typedef struct {
    char *name;
    int bid;
} Bidder;

typedef struct {
    char *item;
    int reserve_price;
    Bidder **bidders;
    int num_bidders;
} AuctionItem;

// Function prototypes

void add_bidder(AuctionItem *item, Bidder *bidder);
void remove_bidder(AuctionItem *item, Bidder *bidder);
void place_bid(AuctionItem *item, Bidder *bidder, int bid);
void close_auction(AuctionItem *item);

// Main function

int main() {
    // Create an auction item
    AuctionItem item = {
        .item = "Rare baseball card",
        .reserve_price = 1000,
        .bidders = NULL,
        .num_bidders = 0
    };

    // Create some bidders
    Bidder bidder1 = {
        .name = "John Doe",
        .bid = 900
    };

    Bidder bidder2 = {
        .name = "Jane Doe",
        .bid = 1200
    };

    Bidder bidder3 = {
        .name = "Bob Smith",
        .bid = 1500
    };

    // Add the bidders to the auction item
    add_bidder(&item, &bidder1);
    add_bidder(&item, &bidder2);
    add_bidder(&item, &bidder3);

    // Place some bids
    place_bid(&item, &bidder1, 1000);
    place_bid(&item, &bidder2, 1300);
    place_bid(&item, &bidder3, 1600);

    // Close the auction
    close_auction(&item);

    // Print the winning bid
    printf("The winning bid is %d by %s\n", item.bidders[item.num_bidders - 1]->bid, item.bidders[item.num_bidders - 1]->name);

    return 0;
}

// Function definitions

void add_bidder(AuctionItem *item, Bidder *bidder) {
    // Reallocate the bidders array to make room for the new bidder
    item->bidders = realloc(item->bidders, (item->num_bidders + 1) * sizeof(Bidder *));

    // Add the new bidder to the array
    item->bidders[item->num_bidders] = bidder;

    // Increment the number of bidders
    item->num_bidders++;
}

void remove_bidder(AuctionItem *item, Bidder *bidder) {
    // Find the index of the bidder in the array
    int index = -1;
    for (int i = 0; i < item->num_bidders; i++) {
        if (item->bidders[i] == bidder) {
            index = i;
            break;
        }
    }

    // If the bidder was found, remove them from the array
    if (index != -1) {
        for (int i = index; i < item->num_bidders - 1; i++) {
            item->bidders[i] = item->bidders[i + 1];
        }

        // Decrement the number of bidders
        item->num_bidders--;
    }
}

void place_bid(AuctionItem *item, Bidder *bidder, int bid) {
    // If the bid is higher than the current bid, update the bid
    if (bid > item->bidders[item->num_bidders - 1]->bid) {
        bidder->bid = bid;
    }
}

void close_auction(AuctionItem *item) {
    // Find the winning bidder
    int winning_bid = -1;
    Bidder *winning_bidder = NULL;
    for (int i = 0; i < item->num_bidders; i++) {
        if (item->bidders[i]->bid > winning_bid) {
            winning_bid = item->bidders[i]->bid;
            winning_bidder = item->bidders[i];
        }
    }

    // If the winning bid is higher than the reserve price, sell the item
    if (winning_bid > item->reserve_price) {
        printf("The item has been sold to %s for %d\n", winning_bidder->name, winning_bid);
    } else {
        printf("The item has not been sold\n");
    }
}