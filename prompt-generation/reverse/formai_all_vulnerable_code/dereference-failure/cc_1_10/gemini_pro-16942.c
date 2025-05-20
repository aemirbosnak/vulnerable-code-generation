//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A mind-bending digital auction system based on the concept of time-warp bidding

// Structure to store a bid
typedef struct {
    char *item;         // Item being bid on
    int bid;            // Bid amount
    time_t time_placed; // Time bid was placed (in seconds since the epoch)
} Bid;

// Function to compare two bids
int compare_bids(const void *a, const void *b) {
    Bid *bid1 = (Bid *)a;
    Bid *bid2 = (Bid *)b;

    // Sort bids in descending order of bid amount, then in ascending order of time placed
    if (bid1->bid != bid2->bid) {
        return bid2->bid - bid1->bid;
    } else {
        return bid1->time_placed - bid2->time_placed;
    }
}

// Function to run the auction
void run_auction(int num_items, char **items) {
    // Create an array of bids
    Bid *bids = malloc(sizeof(Bid) * num_items);

    // Initialize the bids
    for (int i = 0; i < num_items; i++) {
        bids[i].item = items[i];
        bids[i].bid = 0;
        bids[i].time_placed = time(NULL);
    }

    // Run the auction for a specified amount of time
    time_t start_time = time(NULL);
    time_t end_time = start_time + 600; // 10 minutes

    while (time(NULL) < end_time) {
        // Allow users to place bids
        printf("Enter a bid (item, amount): ");
        char item[256];
        int amount;
        scanf("%s %d", item, &amount);

        // Find the index of the item being bid on
        int index = -1;
        for (int i = 0; i < num_items; i++) {
            if (strcmp(item, items[i]) == 0) {
                index = i;
                break;
            }
        }

        // If the item was found, update the bid
        if (index != -1) {
            bids[index].bid = amount;
            bids[index].time_placed = time(NULL);
        } else {
            printf("Invalid item.\n");
        }
    }

    // Sort the bids
    qsort(bids, num_items, sizeof(Bid), compare_bids);

    // Print the winning bids
    printf("Winning bids:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: %d\n", bids[i].item, bids[i].bid);
    }

    // Free the memory allocated for the bids
    free(bids);
}

int main() {
    // Create an array of items
    char *items[] = {"Painting", "Sculpture", "Vase", "Rug", "Clock"};

    // Run the auction
    run_auction(5, items);

    return 0;
}