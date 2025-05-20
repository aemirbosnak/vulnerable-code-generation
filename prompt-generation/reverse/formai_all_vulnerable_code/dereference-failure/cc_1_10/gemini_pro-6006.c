//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int bid;
} Bidder;

int compareBidders(const void *a, const void *b) {
    Bidder *bidder1 = (Bidder *)a;
    Bidder *bidder2 = (Bidder *)b;

    return bidder2->bid - bidder1->bid;
}

int main() {
    int numBidders, startingBid;
    scanf("%d %d", &numBidders, &startingBid);

    Bidder *bidders = (Bidder *)malloc(numBidders * sizeof(Bidder));

    for (int i = 0; i < numBidders; i++) {
        bidders[i].name = (char *)malloc(101 * sizeof(char));
        scanf("%s %d", bidders[i].name, &bidders[i].bid);
    }

    qsort(bidders, numBidders, sizeof(Bidder), compareBidders);

    int winningBid = bidders[0].bid;
    int numWinners = 0;

    for (int i = 0; i < numBidders; i++) {
        if (bidders[i].bid == winningBid) {
            numWinners++;
        }
    }

    printf("%d\n", winningBid);
    printf("%d\n", numWinners);

    for (int i = 0; i < numWinners; i++) {
        printf("%s\n", bidders[i].name);
    }

    for (int i = 0; i < numBidders; i++) {
        free(bidders[i].name);
    }
    free(bidders);

    return 0;
}