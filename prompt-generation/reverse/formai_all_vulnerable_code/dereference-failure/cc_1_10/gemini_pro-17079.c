//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store item details
typedef struct item {
    char name[50];
    int price;
    int quantity;
} item;

// Structure to store bid details
typedef struct bid {
    int bidder_id;
    int item_id;
    int amount;
} bid;

// Function to generate a random item
item generate_item() {
    item item;
    strcpy(item.name, "Item ");
    char num[10];
    sprintf(num, "%d", rand() % 100);
    strcat(item.name, num);
    item.price = rand() % 1000;
    item.quantity = rand() % 10;
    return item;
}

// Function to generate a random bid
bid generate_bid(int num_items) {
    bid bid;
    bid.bidder_id = rand() % 100;
    bid.item_id = rand() % num_items;
    bid.amount = rand() % 1000;
    return bid;
}

// Function to print an item
void print_item(item item) {
    printf("Item Name: %s\n", item.name);
    printf("Price: %d\n", item.price);
    printf("Quantity: %d\n", item.quantity);
}

// Function to print a bid
void print_bid(bid bid) {
    printf("Bidder ID: %d\n", bid.bidder_id);
    printf("Item ID: %d\n", bid.item_id);
    printf("Amount: %d\n", bid.amount);
}

// Function to compare two bids
int compare_bids(bid bid1, bid bid2) {
    return bid1.amount - bid2.amount;
}

// Function to conduct the auction
void conduct_auction(item items[], int num_items, bid bids[], int num_bids) {
    // Sort the bids in descending order
    qsort(bids, num_bids, sizeof(bid), compare_bids);

    // Iterate over the bids
    for (int i = 0; i < num_bids; i++) {
        // Get the current bid
        bid bid = bids[i];

        // Get the corresponding item
        item item = items[bid.item_id];

        // Check if the bid is valid
        if (bid.amount >= item.price && item.quantity > 0) {
            // Reduce the quantity of the item
            item.quantity--;

            // Print the winning bid
            printf("Winning Bid:\n");
            print_bid(bid);
            printf("\n");
        }
    }
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate random items
    item items[10];
    for (int i = 0; i < 10; i++) {
        items[i] = generate_item();
    }

    // Generate random bids
    bid bids[100];
    for (int i = 0; i < 100; i++) {
        bids[i] = generate_bid(10);
    }

    // Conduct the auction
    conduct_auction(items, 10, bids, 100);

    return 0;
}