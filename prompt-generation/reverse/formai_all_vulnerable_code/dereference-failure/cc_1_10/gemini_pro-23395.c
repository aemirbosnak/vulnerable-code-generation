//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct AuctionItem {
    int id;
    char *name;
    float reserve_price;
    float current_bid;
    char *bidder;
};

struct Auction {
    int num_items;
    struct AuctionItem *items;
};

struct Bid {
    int item_id;
    float amount;
    char *bidder;
};

struct Auction *create_auction(int num_items) {
    struct Auction *auction = malloc(sizeof(struct Auction));
    auction->num_items = num_items;
    auction->items = malloc(sizeof(struct AuctionItem) * num_items);
    return auction;
}

void add_item_to_auction(struct Auction *auction, int id, char *name, float reserve_price) {
    struct AuctionItem item;
    item.id = id;
    item.name = strdup(name);
    item.reserve_price = reserve_price;
    item.current_bid = 0.0;
    item.bidder = NULL;
    auction->items[auction->num_items++] = item;
}

void print_auction(struct Auction *auction) {
    for (int i = 0; i < auction->num_items; i++) {
        struct AuctionItem item = auction->items[i];
        printf("%d: %s - Reserve Price: $%.2f - Current Bid: $%.2f - Bidder: %s\n", item.id, item.name, item.reserve_price, item.current_bid, item.bidder);
    }
}

struct Bid *create_bid(int item_id, float amount, char *bidder) {
    struct Bid *bid = malloc(sizeof(struct Bid));
    bid->item_id = item_id;
    bid->amount = amount;
    bid->bidder = strdup(bidder);
    return bid;
}

int process_bid(struct Auction *auction, struct Bid *bid) {
    struct AuctionItem *item = &auction->items[bid->item_id];
    if (bid->amount >= item->current_bid && bid->amount >= item->reserve_price) {
        item->current_bid = bid->amount;
        item->bidder = strdup(bid->bidder);
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Create an auction with 3 items
    struct Auction *auction = create_auction(3);

    // Add items to the auction
    add_item_to_auction(auction, 1, "Painting", 1000.0);
    add_item_to_auction(auction, 2, "Sculpture", 500.0);
    add_item_to_auction(auction, 3, "Vase", 200.0);

    // Print the auction
    printf("Auction Items:\n");
    print_auction(auction);

    // Process bids
    struct Bid *bid1 = create_bid(1, 1100.0, "John Doe");
    process_bid(auction, bid1);

    struct Bid *bid2 = create_bid(2, 600.0, "Jane Smith");
    process_bid(auction, bid2);

    struct Bid *bid3 = create_bid(3, 250.0, "John Doe");
    process_bid(auction, bid3);

    // Print the auction again
    printf("\nAuction Results:\n");
    print_auction(auction);

    return 0;
}