//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int bid;
} Bidder;

int main() {
    // Declare the auction items
    char items[5][50] = {"Painting", "Sculpture", "Vase", "Jewelry", "Furniture"};
    int prices[5] = {1000, 2000, 3000, 4000, 5000};

    // Get the number of bidders
    int numBidders;
    printf("Enter the number of bidders: ");
    scanf("%d", &numBidders);

    // Create an array of bidders
    Bidder bidders[numBidders];

    // Get the bidder information
    for (int i = 0; i < numBidders; i++) {
        printf("Enter the name of bidder %d: ", i + 1);
        scanf("%s", bidders[i].name);

        printf("Enter the bid amount for bidder %d: ", i + 1);
        scanf("%d", &bidders[i].bid);
    }

    // Find the winning bidder for each item
    int winningBidders[5];
    for (int i = 0; i < 5; i++) {
        int winningBid = 0;
        int winningBidderIndex = -1;

        for (int j = 0; j < numBidders; j++) {
            if (bidders[j].bid > winningBid && bidders[j].bid <= prices[i]) {
                winningBid = bidders[j].bid;
                winningBidderIndex = j;
            }
        }

        winningBidders[i] = winningBidderIndex;
    }

    // Print the results
    printf("\nThe winning bidders are:\n");
    for (int i = 0; i < 5; i++) {
        if (winningBidders[i] == -1) {
            printf("%s: No bids\n", items[i]);
        } else {
            printf("%s: %s ($%d)\n", items[i], bidders[winningBidders[i]].name, bidders[winningBidders[i]].bid);
        }
    }

    return 0;
}