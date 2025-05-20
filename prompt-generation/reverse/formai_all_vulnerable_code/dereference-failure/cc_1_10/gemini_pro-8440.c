//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    int bid;
} Bidder;

int compare_bids(const void *a, const void *b) {
    return ((Bidder *)a)->bid - ((Bidder *)b)->bid;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s item_name starting_bid\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *item_name = argv[1];
    int starting_bid = atoi(argv[2]);
    int num_bidders = 0;
    Bidder *bidders = NULL;

    printf("Welcome to the Digital Auction System!\n");
    printf("Item for auction: %s\n", item_name);
    printf("Starting bid: %d\n", starting_bid);

    while (1) {
        char input[1024];
        printf("Enter your name and bid (or 'q' to quit): ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "q\n") == 0) {
            break;
        }

        // Parse the input.
        char *name = strtok(input, " ");
        char *bid_str = strtok(NULL, " ");
        if (name == NULL || bid_str == NULL) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        // Convert the bid to an integer.
        int bid = atoi(bid_str);
        if (bid <= starting_bid) {
            printf("Bid must be greater than the starting bid.\n");
            continue;
        }

        // Add the bidder to the list of bidders.
        bidders = realloc(bidders, sizeof(Bidder) * (num_bidders + 1));
        bidders[num_bidders].name = strdup(name);
        bidders[num_bidders].bid = bid;
        num_bidders++;
    }

    // Sort the bidders by their bids.
    qsort(bidders, num_bidders, sizeof(Bidder), compare_bids);

    // Determine the winning bidder.
    Bidder *winner = bidders + (num_bidders - 1);

    // Print the results of the auction.
    printf("The winner of the auction is %s with a bid of %d.\n", winner->name, winner->bid);

    // Free the memory allocated for the bidders.
    for (int i = 0; i < num_bidders; i++) {
        free(bidders[i].name);
    }
    free(bidders);

    return EXIT_SUCCESS;
}