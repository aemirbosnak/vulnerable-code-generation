//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int bid;
} Bidder;

typedef struct {
    char *item;
    int reserve_price;
    Bidder *highest_bidder;
} AuctionItem;

int compare_bids(const void *a, const void *b) {
    Bidder *bidder_a = (Bidder *)a;
    Bidder *bidder_b = (Bidder *)b;

    return bidder_b->bid - bidder_a->bid;
}

void print_auction_item(AuctionItem *item) {
    printf("Item: %s\n", item->item);
    printf("Reserve price: %d\n", item->reserve_price);
    if (item->highest_bidder) {
        printf("Highest bidder: %s\n", item->highest_bidder->name);
        printf("Highest bid: %d\n", item->highest_bidder->bid);
    } else {
        printf("No bids yet\n");
    }
    printf("\n");
}

int main() {
    // Create some auction items
    AuctionItem items[] = {
        {"Painting", 1000, NULL},
        {"Sculpture", 500, NULL},
        {"Vase", 200, NULL},
    };

    int num_items = sizeof(items) / sizeof(AuctionItem);

    // Get bids from users
    for (int i = 0; i < num_items; i++) {
        printf("Enter your name: ");
        char name[256];
        scanf("%s", name);

        printf("Enter your bid for %s: ", items[i].item);
        int bid;
        scanf("%d", &bid);

        // Create a new bidder
        Bidder *bidder = malloc(sizeof(Bidder));
        bidder->name = strdup(name);
        bidder->bid = bid;

        // Update the highest bidder for the item
        if (!items[i].highest_bidder || bid > items[i].highest_bidder->bid) {
            items[i].highest_bidder = bidder;
        }
    }

    // Print the auction results
    for (int i = 0; i < num_items; i++) {
        print_auction_item(&items[i]);
    }

    // Free the memory allocated for the bidders
    for (int i = 0; i < num_items; i++) {
        if (items[i].highest_bidder) {
            free(items[i].highest_bidder->name);
            free(items[i].highest_bidder);
        }
    }

    return 0;
}