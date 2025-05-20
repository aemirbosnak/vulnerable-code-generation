//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

// Item struct
typedef struct {
    int id;
    char *name;
    double price;
} Item;

// Bid struct
typedef struct {
    int id;
    int item_id;
    double amount;
    char *timestamp;
} Bid;

// Auction struct
typedef struct {
    int id;
    int num_items;
    Item *items;
    int num_bids;
    Bid *bids;
    pthread_mutex_t lock;
} Auction;

// Create a new auction
Auction *create_auction(int num_items) {
    Auction *auction = (Auction *)malloc(sizeof(Auction));
    auction->id = rand();
    auction->num_items = num_items;
    auction->items = (Item *)malloc(sizeof(Item) * num_items);
    auction->num_bids = 0;
    auction->bids = NULL;
    pthread_mutex_init(&auction->lock, NULL);
    return auction;
}

// Add an item to the auction
void add_item(Auction *auction, Item item) {
    pthread_mutex_lock(&auction->lock);
    auction->items[auction->num_items++] = item;
    pthread_mutex_unlock(&auction->lock);
}

// Place a bid on an item
void place_bid(Auction *auction, Bid bid) {
    pthread_mutex_lock(&auction->lock);
    auction->bids = (Bid *)realloc(auction->bids, sizeof(Bid) * (auction->num_bids + 1));
    auction->bids[auction->num_bids++] = bid;
    pthread_mutex_unlock(&auction->lock);
}

// Get the current price of an item
double get_current_price(Auction *auction, int item_id) {
    pthread_mutex_lock(&auction->lock);
    for (int i = 0; i < auction->num_items; i++) {
        if (auction->items[i].id == item_id) {
            pthread_mutex_unlock(&auction->lock);
            return auction->items[i].price;
        }
    }
    pthread_mutex_unlock(&auction->lock);
    return -1;
}

// Get the highest bid for an item
Bid *get_highest_bid(Auction *auction, int item_id) {
    pthread_mutex_lock(&auction->lock);
    Bid *highest_bid = NULL;
    for (int i = 0; i < auction->num_bids; i++) {
        if (auction->bids[i].item_id == item_id && (highest_bid == NULL || auction->bids[i].amount > highest_bid->amount)) {
            highest_bid = &auction->bids[i];
        }
    }
    pthread_mutex_unlock(&auction->lock);
    return highest_bid;
}

// Close the auction
void close_auction(Auction *auction) {
    pthread_mutex_lock(&auction->lock);
    for (int i = 0; i < auction->num_items; i++) {
        Bid *highest_bid = get_highest_bid(auction, auction->items[i].id);
        if (highest_bid != NULL) {
            printf("Item %d sold for $%.2f to bidder %d\n", auction->items[i].id, highest_bid->amount, highest_bid->id);
        } else {
            printf("Item %d did not sell\n", auction->items[i].id);
        }
    }
    pthread_mutex_unlock(&auction->lock);
}

// Free the auction
void free_auction(Auction *auction) {
    pthread_mutex_destroy(&auction->lock);
    free(auction->items);
    free(auction->bids);
    free(auction);
}

int main() {
    srand(time(NULL));

    // Create a new auction
    Auction *auction = create_auction(5);

    // Add some items to the auction
    Item item1 = {1, "iPhone 13", 1000};
    add_item(auction, item1);
    Item item2 = {2, "MacBook Pro", 2000};
    add_item(auction, item2);
    Item item3 = {3, "iPad Air", 500};
    add_item(auction, item3);
    Item item4 = {4, "Apple Watch", 300};
    add_item(auction, item4);
    Item item5 = {5, "AirPods", 150};
    add_item(auction, item5);

    // Place some bids on the items
    Bid bid1 = {1, 1, 1100};
    place_bid(auction, bid1);
    Bid bid2 = {2, 2, 2100};
    place_bid(auction, bid2);
    Bid bid3 = {3, 3, 600};
    place_bid(auction, bid3);
    Bid bid4 = {4, 4, 350};
    place_bid(auction, bid4);
    Bid bid5 = {5, 5, 160};
    place_bid(auction, bid5);

    // Close the auction
    close_auction(auction);

    // Free the auction
    free_auction(auction);

    return 0;
}