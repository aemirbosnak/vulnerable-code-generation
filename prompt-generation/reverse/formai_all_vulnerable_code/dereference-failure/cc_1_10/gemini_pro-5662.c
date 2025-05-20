//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Item represents an auction item
typedef struct {
    int id;
    char *name;
    float reserve_price;
    float current_bid;
    int highest_bidder;
} Item;

// Auction represents an auction event
typedef struct {
    Item *items;
    int num_items;
    int current_bidder;
    float highest_bid;
} Auction;

// create a new auction
Auction *create_auction(int num_items) {
    Auction *auction = malloc(sizeof(Auction));
    auction->items = malloc(sizeof(Item) * num_items);
    auction->num_items = num_items;
    auction->current_bidder = -1;
    auction->highest_bid = 0;
    return auction;
}

// add an item to the auction
void add_item(Auction *auction, Item item) {
    auction->items[auction->num_items++] = item;
}

// start the auction
void start_auction(Auction *auction) {
    while (1) {
        // print the current items
        for (int i = 0; i < auction->num_items; i++) {
            printf("Item %d: %s\n", auction->items[i].id, auction->items[i].name);
            printf("Reserve Price: %.2f\n", auction->items[i].reserve_price);
            printf("Current Bid: %.2f\n", auction->items[i].current_bid);
            printf("Highest Bidder: %d\n", auction->items[i].highest_bidder);
            printf("\n");
        }

        // get the next bid
        int bidder;
        float bid;
        printf("Enter your bid (bidder id, bid amount): ");
        scanf("%d %f", &bidder, &bid);

        // check if the bid is valid
        if (bidder < 0 || bid < 0) {
            printf("Invalid bid!\n");
            continue;
        }

        // check if the bid is higher than the current bid
        if (bid <= auction->items[bidder].current_bid) {
            printf("Bid is too low!\n");
            continue;
        }

        // check if the bid meets the reserve price
        if (bid < auction->items[bidder].reserve_price) {
            printf("Bid does not meet the reserve price!\n");
            continue;
        }

        // update the current bid and highest bidder
        auction->items[bidder].current_bid = bid;
        auction->items[bidder].highest_bidder = bidder;
        auction->current_bidder = bidder;
        auction->highest_bid = bid;

        // check if the auction is over
        int all_items_sold = 1;
        for (int i = 0; i < auction->num_items; i++) {
            if (auction->items[i].current_bid < auction->items[i].reserve_price) {
                all_items_sold = 0;
            }
        }

        if (all_items_sold) {
            break;
        }
    }
}

// end the auction
void end_auction(Auction *auction) {
    // print the winners
    for (int i = 0; i < auction->num_items; i++) {
        printf("Item %d: %s\n", auction->items[i].id, auction->items[i].name);
        printf("Winner: %d\n", auction->items[i].highest_bidder);
        printf("Winning Bid: %.2f\n", auction->items[i].current_bid);
        printf("\n");
    }

    // free the auction memory
    free(auction->items);
    free(auction);
}

// main function
int main() {
    // create the auction
    Auction *auction = create_auction(3);

    // add some items to the auction
    Item item1 = {1, "Painting", 100, 0, -1};
    Item item2 = {2, "Sculpture", 200, 0, -1};
    Item item3 = {3, "Vase", 50, 0, -1};
    add_item(auction, item1);
    add_item(auction, item2);
    add_item(auction, item3);

    // start the auction
    start_auction(auction);

    // end the auction
    end_auction(auction);

    return 0;
}