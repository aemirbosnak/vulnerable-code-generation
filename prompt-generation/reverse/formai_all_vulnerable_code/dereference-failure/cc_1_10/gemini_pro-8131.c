//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDS 1000

typedef struct {
    int id;
    char *name;
    double reserve_price;
} Item;

typedef struct {
    int id;
    int item_id;
    double bid_price;
    char *bidder_name;
} Bid;

Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int num_items = 0;
int num_bids = 0;

void add_item(int id, char *name, double reserve_price) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }
    items[num_items].id = id;
    items[num_items].name = strdup(name);
    items[num_items].reserve_price = reserve_price;
    num_items++;
}

void add_bid(int id, int item_id, double bid_price, char *bidder_name) {
    if (num_bids >= MAX_BIDS) {
        printf("Error: Maximum number of bids reached.\n");
        return;
    }
    bids[num_bids].id = id;
    bids[num_bids].item_id = item_id;
    bids[num_bids].bid_price = bid_price;
    bids[num_bids].bidder_name = strdup(bidder_name);
    num_bids++;
}

void print_items() {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("  %d %s %f\n", items[i].id, items[i].name, items[i].reserve_price);
    }
}

void print_bids() {
    printf("Bids:\n");
    for (int i = 0; i < num_bids; i++) {
        printf("  %d %d %f %s\n", bids[i].id, bids[i].item_id, bids[i].bid_price, bids[i].bidder_name);
    }
}

int main() {
    // Initialize the random number generator.
    srand(time(NULL));

    // Add some items to the auction.
    add_item(1, "Mona Lisa", 1000000.00);
    add_item(2, "Starry Night", 500000.00);
    add_item(3, "Guernica", 300000.00);

    // Add some bids to the auction.
    add_bid(1, 1, 1100000.00, "Alice");
    add_bid(2, 1, 1200000.00, "Bob");
    add_bid(3, 2, 600000.00, "Charlie");
    add_bid(4, 2, 700000.00, "Dave");
    add_bid(5, 3, 400000.00, "Eve");
    add_bid(6, 3, 500000.00, "Frank");

    // Print the items and bids.
    print_items();
    print_bids();

    // Determine the winning bids.
    for (int i = 0; i < num_items; i++) {
        double highest_bid = -1.0;
        int winning_bid_id = -1;
        for (int j = 0; j < num_bids; j++) {
            if (bids[j].item_id == items[i].id && bids[j].bid_price > highest_bid) {
                highest_bid = bids[j].bid_price;
                winning_bid_id = bids[j].id;
            }
        }
        if (winning_bid_id == -1) {
            printf("No bids for item %d.\n", items[i].id);
        } else {
            printf("Winning bid for item %d: %s %f\n", items[i].id, bids[winning_bid_id].bidder_name, bids[winning_bid_id].bid_price);
        }
    }

    return 0;
}