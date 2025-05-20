//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store item details
typedef struct item {
    int id;
    char name[50];
    float reserve_price;
    float current_bid;
    int highest_bidder;
} item;

// Structure to store bid details
typedef struct bid {
    int bidder_id;
    int item_id;
    float bid_amount;
} bid;

// Function to compare two bids
int compare_bids(const void *a, const void *b) {
    bid *bid1 = (bid *)a;
    bid *bid2 = (bid *)b;
    if (bid1->bid_amount > bid2->bid_amount) {
        return -1;
    } else if (bid1->bid_amount < bid2->bid_amount) {
        return 1;
    } else {
        return 0;
    }
}

// Function to process bids
void process_bids(item *items, int num_items, bid *bids, int num_bids) {
    // Sort the bids in descending order
    qsort(bids, num_bids, sizeof(bid), compare_bids);

    // Iterate over the bids
    for (int i = 0; i < num_bids; i++) {
        // Get the item associated with the bid
        item *item = &items[bids[i].item_id];

        // Check if the bid meets the reserve price
        if (bids[i].bid_amount >= item->reserve_price) {
            // Update the item's current bid and highest bidder
            item->current_bid = bids[i].bid_amount;
            item->highest_bidder = bids[i].bidder_id;
        }
    }
}

// Function to print the results of the auction
void print_results(item *items, int num_items) {
    printf("Auction Results:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item %d: %s\n", items[i].id, items[i].name);
        printf("Reserve price: %.2f\n", items[i].reserve_price);
        if (items[i].current_bid == 0) {
            printf("No bids received.\n");
        } else {
            printf("Current bid: %.2f\n", items[i].current_bid);
            printf("Highest bidder: %d\n", items[i].highest_bidder);
        }
        printf("\n");
    }
}

int main() {
    // Define the items for auction
    item items[] = {
        {1, "Painting 1", 100.0f, 0.0f, 0},
        {2, "Sculpture 2", 200.0f, 0.0f, 0},
        {3, "Vase 3", 50.0f, 0.0f, 0}
    };
    int num_items = sizeof(items) / sizeof(items[0]);

    // Define the bids received
    bid bids[] = {
        {1, 1, 120.0f},
        {2, 2, 250.0f},
        {3, 1, 150.0f},
        {4, 3, 60.0f}
    };
    int num_bids = sizeof(bids) / sizeof(bids[0]);

    // Process the bids
    process_bids(items, num_items, bids, num_bids);

    // Print the results of the auction
    print_results(items, num_items);

    return 0;
}