//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDS 10
#define MAX_BID_AMOUNT 1000000

typedef struct {
    char *item_name;
    int item_id;
    int current_bid;
    char *current_bidder;
    time_t end_time;
} auction_item;

auction_item *items;
int num_items;

void print_auction_item(auction_item *item) {
    printf("Item: %s\n", item->item_name);
    printf("ID: %d\n", item->item_id);
    printf("Current bid: $%d\n", item->current_bid);
    printf("Current bidder: %s\n", item->current_bidder);
    printf("End time: %s\n", ctime(&item->end_time));
}

void print_all_auction_items() {
    for (int i = 0; i < num_items; i++) {
        print_auction_item(&items[i]);
        printf("\n");
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create some auction items
    num_items = 10;
    items = malloc(sizeof(auction_item) * num_items);

    for (int i = 0; i < num_items; i++) {
        // Generate a random item name
        char *item_name = malloc(20);
        sprintf(item_name, "Item %d", i + 1);

        // Generate a random item ID
        int item_id = rand() % 10000;

        // Generate a random current bid
        int current_bid = rand() % MAX_BID_AMOUNT;

        // Generate a random current bidder
        char *current_bidder = malloc(20);
        sprintf(current_bidder, "Bidder %d", rand() % 10000);

        // Generate a random end time
        time_t end_time = time(NULL) + (rand() % (60 * 60 * 24));

        // Store the item in the array
        items[i].item_name = item_name;
        items[i].item_id = item_id;
        items[i].current_bid = current_bid;
        items[i].current_bidder = current_bidder;
        items[i].end_time = end_time;
    }

    // Print all of the auction items
    print_all_auction_items();

    return 0;
}