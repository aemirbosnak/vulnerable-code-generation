//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int bid;
} Bidder;

typedef struct {
    char *item;
    int starting_price;
    int current_price;
    int highest_bid;
    Bidder *highest_bidder;
    Bidder **bidders;
    int num_bidders;
} AuctionItem;

int main() {
    // Create an auction item
    AuctionItem item = {"Painting", 100, 100, 0, NULL, NULL, 0};

    // Add some bidders
    Bidder *bidder1 = malloc(sizeof(Bidder));
    bidder1->name = "Alice";
    bidder1->bid = 150;

    Bidder *bidder2 = malloc(sizeof(Bidder));
    bidder2->name = "Bob";
    bidder2->bid = 200;

    item.bidders = malloc(sizeof(Bidder *) * 2);
    item.bidders[0] = bidder1;
    item.bidders[1] = bidder2;
    item.num_bidders = 2;

    // Run the auction
    while (1) {
        // Get the highest bid
        item.highest_bid = 0;
        for (int i = 0; i < item.num_bidders; i++) {
            if (item.bidders[i]->bid > item.highest_bid) {
                item.highest_bid = item.bidders[i]->bid;
                item.highest_bidder = item.bidders[i];
            }
        }

        // Check if the auction is over
        if (item.highest_bid >= item.starting_price) {
            // The auction is over
            printf("The auction is over!\n");
            printf("The winning bid is %d by %s\n", item.highest_bid, item.highest_bidder->name);
            break;
        }

        // Otherwise, increase the current price and continue
        item.current_price += 10;
        printf("The current price is %d\n", item.current_price);
    }

    // Free the memory
    free(bidder1);
    free(bidder2);
    free(item.bidders);

    return 0;
}