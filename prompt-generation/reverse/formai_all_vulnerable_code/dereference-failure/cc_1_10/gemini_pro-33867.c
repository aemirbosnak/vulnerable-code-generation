//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store an item
typedef struct Item {
    char name[50];
    int starting_price;
    int current_bid;
    char highest_bidder[50];
} Item;

// Structure to store an auction
typedef struct Auction {
    Item items[100];
    int num_items;
} Auction;

// Function to create a new auction
Auction *create_auction(int num_items) {
    Auction *auction = malloc(sizeof(Auction));
    auction->num_items = num_items;
    return auction;
}

// Function to add an item to an auction
void add_item(Auction *auction, char *name, int starting_price) {
    Item item;
    strcpy(item.name, name);
    item.starting_price = starting_price;
    item.current_bid = starting_price;
    strcpy(item.highest_bidder, "");
    auction->items[auction->num_items++] = item;
}

// Function to start an auction
void start_auction(Auction *auction) {
    int i;
    for (i = 0; i < auction->num_items; i++) {
        printf("Item: %s\n", auction->items[i].name);
        printf("Starting price: $%d\n", auction->items[i].starting_price);
        printf("Current bid: $%d\n", auction->items[i].current_bid);
        printf("Highest bidder: %s\n\n", auction->items[i].highest_bidder);
    }

    // Loop until all items have been sold
    while (1) {
        int item_index;
        int bid_amount;
        char bidder_name[50];

        // Get the item index
        printf("Enter the item number you want to bid on: ");
        scanf("%d", &item_index);

        // Get the bid amount
        printf("Enter your bid amount: ");
        scanf("%d", &bid_amount);

        // Get the bidder name
        printf("Enter your name: ");
        scanf("%s", bidder_name);

        // Check if the bid is valid
        if (bid_amount < auction->items[item_index].current_bid) {
            printf("Your bid is too low. Please enter a higher bid.\n");
        } else {
            // Update the item's current bid and highest bidder
            auction->items[item_index].current_bid = bid_amount;
            strcpy(auction->items[item_index].highest_bidder, bidder_name);

            // Print the updated item information
            printf("Item: %s\n", auction->items[item_index].name);
            printf("Starting price: $%d\n", auction->items[item_index].starting_price);
            printf("Current bid: $%d\n", auction->items[item_index].current_bid);
            printf("Highest bidder: %s\n\n", auction->items[item_index].highest_bidder);
        }

        // Check if all items have been sold
        int all_sold = 1;
        for (i = 0; i < auction->num_items; i++) {
            if (auction->items[i].current_bid == auction->items[i].starting_price) {
                all_sold = 0;
            }
        }

        if (all_sold) {
            break;
        }
    }

    // Print the winning bids
    printf("The winning bids are:\n");
    for (i = 0; i < auction->num_items; i++) {
        printf("Item: %s\n", auction->items[i].name);
        printf("Winning bid: $%d\n", auction->items[i].current_bid);
        printf("Winning bidder: %s\n\n", auction->items[i].highest_bidder);
    }
}

// Main function
int main() {
    // Create a new auction
    Auction *auction = create_auction(3);

    // Add items to the auction
    add_item(auction, "Painting", 100);
    add_item(auction, "Sculpture", 200);
    add_item(auction, "Vase", 50);

    // Start the auction
    start_auction(auction);

    return 0;
}