//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I'm the master of ceremonies, introducing the contestants...
typedef struct {
    char *name;
    int bid;
} Bidder;

int main() {
    // These bidders are as colorful as a bag of Skittles!
    Bidder bidders[] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Carol", 0},
        {"Dave", 0},
        {"Eve", 0}
    };

    // Let's get this auction started!
    char *item;
    int reserve_price;
    printf("Enter the item to be auctioned: ");
    scanf(" %m[^\n]%*c", &item); // Using scanf() with %m is like using gets(), but with a twist!
    printf("Enter the reserve price: ");
    scanf("%d%*c", &reserve_price);

    // Now, the bidding madness begins!
    int highest_bid = 0;
    Bidder *winner = NULL;
    int round = 1;
    while (1) {
        // Show me the money!
        printf("Round %d:\n", round);
        for (int i = 0; i < sizeof(bidders) / sizeof(Bidder); i++) {
            printf("%s, what's your bid? ", bidders[i].name);
            scanf("%d%*c", &bidders[i].bid);

            // We have a new highest bidder!
            if (bidders[i].bid > highest_bid) {
                highest_bid = bidders[i].bid;
                winner = &bidders[i];
            }
        }

        // Did we meet the reserve price?
        if (highest_bid >= reserve_price) {
            printf("Sold to %s for %d!\n", winner->name, highest_bid);
            break;
        } else {
            printf("No bids met the reserve price. Moving on to the next round...\n");
            round++;
        }
    }

    // Clean up the mess
    free(item);

    return 0;
}