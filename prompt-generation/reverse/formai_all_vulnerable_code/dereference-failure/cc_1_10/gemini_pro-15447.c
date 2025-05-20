//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 10

typedef struct {
    int id;
    char *name;
    float reserve_price;
} Item;

typedef struct {
    int id;
    int item_id;
    float amount;
} Bid;

Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int num_items = 0;
int num_bids = 0;

// Function to add an item to the auction
void add_item(char *name, float reserve_price) {
    items[num_items].id = num_items + 1;
    items[num_items].name = strdup(name);
    items[num_items].reserve_price = reserve_price;
    num_items++;
}

// Function to add a bid to the auction
void add_bid(int item_id, float amount) {
    bids[num_bids].id = num_bids + 1;
    bids[num_bids].item_id = item_id;
    bids[num_bids].amount = amount;
    num_bids++;
}

// Function to print the auction results
void print_results() {
    for (int i = 0; i < num_items; i++) {
        printf("Item: %s\n", items[i].name);
        printf("Reserve Price: %.2f\n", items[i].reserve_price);

        float highest_bid = 0;
        int highest_bidder = 0;
        for (int j = 0; j < num_bids; j++) {
            if (bids[j].item_id == items[i].id && bids[j].amount > highest_bid) {
                highest_bid = bids[j].amount;
                highest_bidder = bids[j].id;
            }
        }

        if (highest_bid >= items[i].reserve_price) {
            printf("Sold to Bidder %d for %.2f\n", highest_bidder, highest_bid);
        } else {
            printf("Not sold\n");
        }

        printf("\n");
    }
}

int main() {
    // Add some items to the auction
    add_item("Painting", 1000.00);
    add_item("Sculpture", 500.00);
    add_item("Vase", 200.00);

    // Add some bids to the auction
    add_bid(1, 1100.00);
    add_bid(2, 550.00);
    add_bid(3, 250.00);

    // Print the auction results
    print_results();

    return 0;
}