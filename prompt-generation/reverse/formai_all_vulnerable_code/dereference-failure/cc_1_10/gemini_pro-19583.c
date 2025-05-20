//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct product {
    int id;                 // Unique ID of the product
    char name[100];         // Name of the product
    float current_bid;      // Current highest bid on the product
    int highest_bidder;    // ID of the highest bidder
} product;

// Structure to represent a bid
typedef struct bid {
    int product_id;        // ID of the product being bid on
    int bidder_id;         // ID of the bidder
    float amount;           // Amount of the bid
} bid;

// Structure to represent an auction
typedef struct auction {
    int id;                     // Unique ID of the auction
    char name[100];             // Name of the auction
    product products[100];      // Array of products being auctioned
    int num_products;           // Number of products being auctioned
    bid bids[100];              // Array of bids placed on the products
    int num_bids;               // Number of bids placed
    int current_bidder;        // ID of the current highest bidder
    float current_bid;          // Current highest bid
} auction;

// Function to create a new auction
auction* create_auction(char* name) {
    auction* new_auction = (auction*)malloc(sizeof(auction));
    strcpy(new_auction->name, name);
    new_auction->num_products = 0;
    new_auction->num_bids = 0;
    new_auction->current_bidder = -1;
    new_auction->current_bid = 0;
    return new_auction;
}

// Function to add a product to an auction
void add_product(auction* auction, product* product) {
    auction->products[auction->num_products++] = *product;
}

// Function to place a bid on a product
void place_bid(auction* auction, bid* bid) {
    // Check if the bid is valid
    if (bid->product_id >= auction->num_products) {
        printf("Invalid product ID\n");
        return;
    }
    if (bid->amount <= auction->products[bid->product_id].current_bid) {
        printf("Bid amount must be greater than the current bid\n");
        return;
    }

    // Update the highest bid
    auction->products[bid->product_id].current_bid = bid->amount;
    auction->products[bid->product_id].highest_bidder = bid->bidder_id;

    // Update the current highest bidder and bid
    auction->current_bidder = bid->bidder_id;
    auction->current_bid = bid->amount;

    // Add the bid to the array of bids
    auction->bids[auction->num_bids++] = *bid;
}

// Function to get the current highest bid on a product
float get_current_bid(auction* auction, int product_id) {
    return auction->products[product_id].current_bid;
}

// Function to get the ID of the current highest bidder on a product
int get_current_bidder(auction* auction, int product_id) {
    return auction->products[product_id].highest_bidder;
}

// Function to close the auction and determine the winners
void close_auction(auction* auction) {
    for (int i = 0; i < auction->num_products; i++) {
        printf("Product: %s\n", auction->products[i].name);
        printf("Highest Bid: %f\n", auction->products[i].current_bid);
        printf("Highest Bidder: %d\n\n", auction->products[i].highest_bidder);
    }
}

// Main function
int main() {
    // Create a new auction
    auction* auction = create_auction("My Auction");

    // Add some products to the auction
    product product1 = {1, "iPhone 13", 1000, -1};
    product product2 = {2, "MacBook Pro", 2000, -1};
    add_product(auction, &product1);
    add_product(auction, &product2);

    // Place some bids on the products
    bid bid1 = {1, 1, 1100};
    bid bid2 = {2, 2, 2100};
    bid bid3 = {1, 3, 1200};
    place_bid(auction, &bid1);
    place_bid(auction, &bid2);
    place_bid(auction, &bid3);

    // Get the current highest bid on each product
    printf("Current highest bid on iPhone 13: %f\n", get_current_bid(auction, 0));
    printf("Current highest bid on MacBook Pro: %f\n", get_current_bid(auction, 1));

    // Get the ID of the current highest bidder on each product
    printf("Current highest bidder on iPhone 13: %d\n", get_current_bidder(auction, 0));
    printf("Current highest bidder on MacBook Pro: %d\n", get_current_bidder(auction, 1));

    // Close the auction and determine the winners
    close_auction(auction);

    return 0;
}