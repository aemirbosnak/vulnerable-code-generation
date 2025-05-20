//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int bid;
} Bidder;

int compare_bids(const void *a, const void *b) {
    Bidder *bidder_a = (Bidder *)a;
    Bidder *bidder_b = (Bidder *)b;
    return bidder_b->bid - bidder_a->bid;
}

int main() {
    // Initialize the auction system
    int num_bidders;
    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    Bidder *bidders = malloc(sizeof(Bidder) * num_bidders);

    for (int i = 0; i < num_bidders; i++) {
        char name[256];
        int bid;

        printf("Enter the name of bidder %d: ", i + 1);
        scanf("%s", name);

        printf("Enter the bid of bidder %d: ", i + 1);
        scanf("%d", &bid);

        bidders[i].name = strdup(name);
        bidders[i].bid = bid;
    }

    // Sort the bidders by their bids in descending order
    qsort(bidders, num_bidders, sizeof(Bidder), compare_bids);

    // Print the winner of the auction
    printf("The winner of the auction is: %s\n", bidders[0].name);
    printf("Winning bid: %d\n", bidders[0].bid);

    // Free the memory allocated for the bidders
    for (int i = 0; i < num_bidders; i++) {
        free(bidders[i].name);
    }
    free(bidders);

    return 0;
}