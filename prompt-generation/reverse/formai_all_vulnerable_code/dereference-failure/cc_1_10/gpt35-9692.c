//FormAI DATASET v1.0 Category: Digital Auction System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    float bid;
} Bidder;

Bidder **auction_winner(Bidder **bidders, int num_bidders) {
    Bidder **winners = malloc(sizeof(Bidder) * num_bidders);
    int i, j, k, winning_index = 0;
    float winning_bid = -1;
    for(i = 0; i < num_bidders; i++) {
        for(j = 0; j < num_bidders; j++) {
            if(bidders[j]->bid > winning_bid) {
                winning_bid = bidders[j]->bid;
                winning_index = j;
            }
        }
        winners[i] = bidders[winning_index];
        winners[i]->bid = winning_bid;
        bidders[winning_index] = NULL;
        winning_bid = -1;
    }
    return winners;
}

int main() {

    int num_bidders = 0, i, j;
    printf("Welcome to the Digital Auction System\n");
    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    Bidder **bidders = malloc(sizeof(Bidder) * num_bidders);

    for(i = 0; i < num_bidders; i++) {
        Bidder *bidder = malloc(sizeof(Bidder));
        printf("\nEnter Bidder %d name: ", i+1);
        scanf("%s", bidder->name);
        printf("Enter Bidder %d bid: ", i+1);
        scanf("%f", &bidder->bid);
        bidders[i] = bidder;
    }

    Bidder **winners = auction_winner(bidders, num_bidders);

    printf("\nWinning Bidders in Order:\n");

    for(i = 0; i < num_bidders; i++) {
        printf("%s - $%.2f\n", winners[i]->name, winners[i]->bid);
        free(winners[i]);
    }

    free(winners);
    free(bidders);

    return 0;
}