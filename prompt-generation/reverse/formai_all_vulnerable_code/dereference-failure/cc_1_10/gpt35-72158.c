//FormAI DATASET v1.0 Category: Digital Auction System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 1000
#define MAX_LEN 50

typedef struct {
    char name[MAX_LEN];
    int bid_amount;
} Bidder;

int main() {
    char auction_item[MAX_LEN];
    int num_bidders, current_bid = 0, winning_bid, winner_index;
    Bidder *bidders;

    printf("Enter the name of the item for auction: ");
    scanf("%s", auction_item);

    printf("How many bidders are participating in the auction? ");
    scanf("%d", &num_bidders);

    bidders = (Bidder*) malloc(sizeof(Bidder) * num_bidders);

    for(int i = 0; i < num_bidders; i++) {
        printf("Enter the name of bidder #%d: ", i+1);
        scanf("%s", bidders[i].name);

        printf("Enter the bid amount for %s: $", bidders[i].name);
        scanf("%d", &bidders[i].bid_amount);

        if(bidders[i].bid_amount > current_bid) {
            current_bid = bidders[i].bid_amount;
            winner_index = i;
        }
    }

    printf("\nThe bidding for %s is now closed.\n", auction_item);

    printf("\nHere are the results:\n");

    printf("\nAuction item: %s", auction_item);
    printf("\nWinning Bid: $%d", current_bid);
    printf("\nWinner: %s\n", bidders[winner_index].name);

    printf("\nAll bidders:\n");

    for(int i = 0; i < num_bidders; i++) {
        printf("%s: $%d\n", bidders[i].name, bidders[i].bid_amount);
    }

    free(bidders);

    return 0;
}