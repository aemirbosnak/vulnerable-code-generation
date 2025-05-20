//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to store item details
typedef struct item {
    int id;
    char name[50];
    float starting_price;
    float current_bid;
    char highest_bidder[50];
} item;

// structure to store bid details
typedef struct bid {
    int item_id;
    char bidder_name[50];
    float bid_amount;
} bid;

// function to create a new item
item* create_item(int id, char* name, float starting_price) {
    item* new_item = (item*)malloc(sizeof(item));
    new_item->id = id;
    strcpy(new_item->name, name);
    new_item->starting_price = starting_price;
    new_item->current_bid = starting_price;
    strcpy(new_item->highest_bidder, "");
    return new_item;
}

// function to place a bid on an item
void place_bid(item* items, int num_items, bid* bids, int num_bids, int item_id, char* bidder_name, float bid_amount) {
    // check if item exists
    int item_found = 0;
    for (int i = 0; i < num_items; i++) {
        if (items[i].id == item_id) {
            item_found = 1;
            break;
        }
    }
    if (!item_found) {
        printf("Item not found.\n");
        return;
    }

    // check if bid is valid
    if (bid_amount <= items[item_id - 1].current_bid) {
        printf("Bid amount must be greater than the current bid.\n");
        return;
    }

    // update item details
    items[item_id - 1].current_bid = bid_amount;
    strcpy(items[item_id - 1].highest_bidder, bidder_name);

    // create new bid and add it to the list of bids
    bid new_bid;
    new_bid.item_id = item_id;
    strcpy(new_bid.bidder_name, bidder_name);
    new_bid.bid_amount = bid_amount;
    bids = (bid*)realloc(bids, (num_bids + 1) * sizeof(bid));
    bids[num_bids] = new_bid;

    printf("Bid placed successfully.\n");
}

// function to print the list of items
void print_items(item* items, int num_items) {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item ID: %d, Name: %s, Starting Price: %.2f, Current Bid: %.2f, Highest Bidder: %s\n",
            items[i].id, items[i].name, items[i].starting_price, items[i].current_bid, items[i].highest_bidder);
    }
}

// function to print the list of bids
void print_bids(bid* bids, int num_bids) {
    printf("Bids:\n");
    for (int i = 0; i < num_bids; i++) {
        printf("Item ID: %d, Bidder Name: %s, Bid Amount: %.2f\n",
            bids[i].item_id, bids[i].bidder_name, bids[i].bid_amount);
    }
}

int main() {
    // create a list of items
    item* items = (item*)malloc(3 * sizeof(item));
    items[0] = *create_item(1, "Painting", 100.0);
    items[1] = *create_item(2, "Sculpture", 200.0);
    items[2] = *create_item(3, "Vase", 50.0);

    // create a list of bids
    bid* bids = (bid*)malloc(0 * sizeof(bid));
    int num_bids = 0;

    // print the list of items
    print_items(items, 3);

    // place a bid on an item
    place_bid(items, 3, bids, num_bids, 1, "Alice", 120.0);

    // print the updated list of items
    print_items(items, 3);

    // print the list of bids
    print_bids(bids, num_bids);

    return 0;
}