//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the structure of an item
typedef struct item {
    char *name;
    int starting_bid;
    int highest_bid;
    char *highest_bidder;
} item;

// Declare the structure of an auction
typedef struct auction {
    item *items;
    int num_items;
    int current_item;
} auction;

// Initialize an auction
auction *init_auction(int num_items) {
    auction *a = malloc(sizeof(auction));
    a->items = malloc(sizeof(item) * num_items);
    a->num_items = num_items;
    a->current_item = 0;
    return a;
}

// Add an item to an auction
void add_item(auction *a, char *name, int starting_bid) {
    item *new_item = malloc(sizeof(item));
    new_item->name = strdup(name);
    new_item->starting_bid = starting_bid;
    new_item->highest_bid = starting_bid;
    new_item->highest_bidder = NULL;
    a->items[a->num_items] = *new_item;
    a->num_items++;
}

// Get the current item in an auction
item *get_current_item(auction *a) {
    return &a->items[a->current_item];
}

// Move to the next item in an auction
void next_item(auction *a) {
    a->current_item++;
}

// Place a bid on an item
void place_bid(item *i, char *bidder, int bid) {
    if (bid > i->highest_bid) {
        i->highest_bid = bid;
        i->highest_bidder = strdup(bidder);
    }
    else{
      printf("%s bid less than or equal to highest bid!!\n",bidder);
    }
}

// Print the current item in an auction
void print_current_item(item *i) {
    printf("Item: %s\n", i->name);
    printf("Starting bid: %d\n", i->starting_bid);
    printf("Highest bid: %d\n", i->highest_bid);
    if (i->highest_bidder != NULL) {
        printf("Highest bidder: %s\n", i->highest_bidder);
    }
    else{
      printf("No bids yet :(\n");
    }
}

// Run an auction
void run_auction(auction *a) {
    while (a->current_item < a->num_items) {
        item *i = get_current_item(a);
        print_current_item(i);
        char bidder[100];
        int bid;
        printf("Enter your bid (bidder name and amount): ");
        scanf("%s %d", bidder, &bid);
        place_bid(i, bidder, bid);
        next_item(a);
    }
}

// Clean up an auction
void cleanup_auction(auction *a) {
    for (int i = 0; i < a->num_items; i++) {
        free(a->items[i].name);
        if (a->items[i].highest_bidder != NULL) {
            free(a->items[i].highest_bidder);
        }
    }
    free(a->items);
    free(a);
}

int main() {
    // Create an auction
    auction *a = init_auction(3);

    // Add some items to the auction
    add_item(a, "Mona Lisa", 1000000);
    add_item(a, "Starry Night", 500000);
    add_item(a, "The Scream", 300000);

    // Run the auction
    run_auction(a);

    // Clean up the auction
    cleanup_auction(a);

    return 0;
}