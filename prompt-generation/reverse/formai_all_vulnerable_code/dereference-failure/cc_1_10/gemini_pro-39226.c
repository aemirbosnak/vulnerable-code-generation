//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <time.h>

// Item struct
typedef struct {
    int id;
    char* name;
    double price;
    bool sold;
} Item;

// Bid struct
typedef struct {
    int id;
    int item_id;
    double amount;
    pthread_t thread;
} Bid;

// List of items
Item* items;
int num_items;

// List of bids
Bid* bids;
int num_bids;

// Mutex for protecting shared data
pthread_mutex_t mutex;

// Condition variable for waiting for bids
pthread_cond_t cond_var;

// Function to initialize the auction system
void init_auction_system(int num_items) {
    // Allocate memory for items
    items = malloc(sizeof(Item) * num_items);

    // Initialize items
    for (int i = 0; i < num_items; i++) {
        items[i].id = i;
        items[i].name = malloc(10);
        sprintf(items[i].name, "Item %d", i);
        items[i].price = 0.0;
        items[i].sold = false;
    }

    // Allocate memory for bids
    bids = malloc(sizeof(Bid) * 100);

    // Initialize bids
    for (int i = 0; i < 100; i++) {
        bids[i].id = i;
        bids[i].item_id = -1;
        bids[i].amount = 0.0;
        bids[i].thread = 0;
    }

    // Initialize mutex and condition variable
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_var, NULL);
}

// Function to create a new bid
Bid* create_bid(int item_id, double amount) {
    // Allocate memory for bid
    Bid* bid = malloc(sizeof(Bid));

    // Initialize bid
    bid->id = num_bids++;
    bid->item_id = item_id;
    bid->amount = amount;
    bid->thread = 0;

    return bid;
}

// Function to submit a bid
void submit_bid(Bid* bid) {
    // Lock mutex
    pthread_mutex_lock(&mutex);

    // Check if item is already sold
    if (items[bid->item_id].sold) {
        // Unlock mutex
        pthread_mutex_unlock(&mutex);

        // Print error message
        printf("Error: Item %d is already sold.\n", bid->item_id);
        return;
    }

    // Add bid to list of bids
    bids[num_bids++] = *bid;

    // Signal condition variable
    pthread_cond_signal(&cond_var);

    // Unlock mutex
    pthread_mutex_unlock(&mutex);
}

// Function to run the auction
void run_auction() {
    // Lock mutex
    pthread_mutex_lock(&mutex);

    // Wait for bids
    while (num_bids == 0) {
        pthread_cond_wait(&cond_var, &mutex);
    }

    // Iterate over bids
    for (int i = 0; i < num_bids; i++) {
        // Get bid
        Bid bid = bids[i];

        // Check if bid is valid
        if (bid.item_id < 0 || bid.item_id >= num_items) {
            // Print error message
            printf("Error: Invalid item ID in bid %d.\n", bid.id);
            continue;
        }

        // Check if bid amount is greater than current price
        if (bid.amount > items[bid.item_id].price) {
            // Update item price
            items[bid.item_id].price = bid.amount;

            // Mark item as sold
            items[bid.item_id].sold = true;

            // Print message
            printf("Item %d sold to bidder %d for $%.2f.\n", bid.item_id, bid.id, bid.amount);
        }
    }

    // Unlock mutex
    pthread_mutex_unlock(&mutex);
}

// Function to create a new bidder thread
void* bidder_thread(void* arg) {
    // Get bid
    Bid* bid = (Bid*) arg;

    // Submit bid
    submit_bid(bid);

    return NULL;
}

// Function to test the auction system
int main() {
    // Initialize auction system
    init_auction_system(10);

    // Create 100 bidder threads
    pthread_t threads[100];
    for (int i = 0; i < 100; i++) {
        // Create bid
        Bid* bid = create_bid(rand() % num_items, rand() % 1000);

        // Create thread
        pthread_create(&threads[i], NULL, bidder_thread, (void*) bid);
    }

    // Join threads
    for (int i = 0; i < 100; i++) {
        pthread_join(threads[i], NULL);
    }

    // Run auction
    run_auction();

    return 0;
}