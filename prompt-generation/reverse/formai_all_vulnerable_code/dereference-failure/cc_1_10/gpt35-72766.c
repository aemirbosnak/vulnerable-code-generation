//FormAI DATASET v1.0 Category: Digital Auction System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numBidders, i, j, maxBid, winner, bid;
    printf("Welcome to the Digital Auction System\n\n");
    printf("Enter the number of bidders: ");
    scanf("%d", &numBidders);

    // Dynamically allocate memory for the bidder names
    char** bidderNames = (char**)malloc(numBidders * sizeof(char*));
    for (i = 0; i < numBidders; i++)
    {
        bidderNames[i] = (char*)malloc(50 * sizeof(char));
        printf("Enter the name of bidder %d: ", i+1);
        scanf("%s", bidderNames[i]);
    }

    // Generate random bids for each bidder between 1 to 100
    int* bids = (int*)malloc(numBidders * sizeof(int));
    srand(time(0));
    for (i = 0; i < numBidders; i++)
    {
        bids[i] = (rand() % 100) + 1;
    }

    // Find the highest bidder
    maxBid = bids[0];
    winner = 0;
    for (i = 1; i < numBidders; i++)
    {
        if (bids[i] > maxBid)
        {
            maxBid = bids[i];
            winner = i;
        }
    }

    // Print the results
    printf("\n\nBid Results:\n");
    for (i = 0; i < numBidders; i++)
    {
        printf("%s bid $%d\n", bidderNames[i], bids[i]);
    }
    printf("\nThe highest bid was $%d by %s\n", maxBid, bidderNames[winner]);

    // Free the dynamically allocated memory
    for (i = 0; i < numBidders; i++)
    {
        free(bidderNames[i]);
    }
    free(bidderNames);
    free(bids);

    return 0;
}