//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create an array to store items
    int items[100];

    // Define the starting price for each item
    int startingPrice = 10;

    // Prompt the user to enter the number of items
    int numItems;
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    // Prompt the user to enter the prices for each item
    for (int i = 0; i < numItems; i++) {
        printf("Enter the price for item %d: ", i+1);
        scanf("%d", &items[i]);
    }

    // Define the starting bid
    int startingBid = 1;

    // Prompt the user to enter the number of bids
    int numBids;
    printf("Enter the number of bids: ");
    scanf("%d", &numBids);

    // Prompt the user to enter the bids
    int bids[numBids];
    for (int i = 0; i < numBids; i++) {
        printf("Enter bid %d: ", i+1);
        scanf("%d", &bids[i]);
    }

    // Print the starting prices and bids
    printf("Starting prices: ");
    for (int i = 0; i < numItems; i++) {
        printf("%d ", items[i]);
    }
    printf("\nBids: ");
    for (int i = 0; i < numBids; i++) {
        printf("%d ", bids[i]);
    }
    printf("\n");

    // Sort the bids in descending order
    for (int i = 0; i < numBids; i++) {
        for (int j = i+1; j < numBids; j++) {
            if (bids[i] < bids[j]) {
                int temp = bids[i];
                bids[i] = bids[j];
                bids[j] = temp;
            }
        }
    }

    // Print the sorted bids
    printf("Sorted bids: ");
    for (int i = 0; i < numBids; i++) {
        printf("%d ", bids[i]);
    }
    printf("\n");

    // Find the highest bid
    int maxBid = 0;
    for (int i = 0; i < numBids; i++) {
        if (bids[i] > maxBid) {
            maxBid = bids[i];
        }
    }

    // Print the highest bid
    printf("Highest bid: %d\n", maxBid);

    // Print the winning bidder
    int winningBidder = 0;
    for (int i = 0; i < numBids; i++) {
        if (bids[i] == maxBid) {
            winningBidder = i+1;
        }
    }
    printf("Winning bidder: %d\n", winningBidder);

    return 0;
}