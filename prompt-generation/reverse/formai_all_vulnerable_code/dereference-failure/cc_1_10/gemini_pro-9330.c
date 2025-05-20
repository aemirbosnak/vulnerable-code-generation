//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: Ada Lovelace
// Ada Lovelace's Digital Auction System

#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct item {
    int id;              // Item ID
    char *name;          // Item name
    float reserve_price;  // Reserve price
    float current_bid;   // Current bid
    int highest_bidder;  // ID of the highest bidder
} item;

// Structure to represent a bid
typedef struct bid {
    int item_id;      // Item ID
    float amount;      // Amount of the bid
    int bidder_id;    // ID of the bidder
} bid;

// Function to create a new item
item *create_item(int id, char *name, float reserve_price) {
    item *new_item = (item *)malloc(sizeof(item));
    new_item->id = id;
    new_item->name = strdup(name);
    new_item->reserve_price = reserve_price;
    new_item->current_bid = 0;
    new_item->highest_bidder = 0;
    return new_item;
}

// Function to create a new bid
bid *create_bid(int item_id, float amount, int bidder_id) {
    bid *new_bid = (bid *)malloc(sizeof(bid));
    new_bid->item_id = item_id;
    new_bid->amount = amount;
    new_bid->bidder_id = bidder_id;
    return new_bid;
}

// Function to add a bid to an item
void add_bid(item *item, bid *new_bid) {
    if (new_bid->amount >= item->reserve_price) {
        item->current_bid = new_bid->amount;
        item->highest_bidder = new_bid->bidder_id;
    }
}

// Function to print the details of an item
void print_item(item *item) {
    printf("Item ID: %d\n", item->id);
    printf("Item Name: %s\n", item->name);
    printf("Reserve Price: %.2f\n", item->reserve_price);
    printf("Current Bid: %.2f\n", item->current_bid);
    printf("Highest Bidder: %d\n\n", item->highest_bidder);
}

// Function to print the details of a bid
void print_bid(bid *bid) {
    printf("Item ID: %d\n", bid->item_id);
    printf("Amount: %.2f\n", bid->amount);
    printf("Bidder ID: %d\n\n", bid->bidder_id);
}

// Function to start the auction
void start_auction(item *items[], int num_items) {
    int i;
    printf("Welcome to the digital auction!\n\n");

    // Print the details of each item
    for (i = 0; i < num_items; i++) {
        print_item(items[i]);
    }

    // Get bids from users
    int bidder_id;
    int item_id;
    float amount;
    while (1) {
        printf("Enter your bidder ID: ");
        scanf("%d", &bidder_id);

        printf("Enter the ID of the item you want to bid on: ");
        scanf("%d", &item_id);

        printf("Enter the amount of your bid: ");
        scanf("%f", &amount);

        // Create a new bid
        bid *new_bid = create_bid(item_id, amount, bidder_id);

        // Add the bid to the item
        add_bid(items[item_id - 1], new_bid);

        // Print the details of the bid
        print_bid(new_bid);

        // Check if the user wants to continue bidding
        char choice;
        printf("Do you want to continue bidding? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }
    }

    // End the auction and print the winners
    printf("\nThe auction is now closed.\n\n");
    for (i = 0; i < num_items; i++) {
        if (items[i]->current_bid >= items[i]->reserve_price) {
            printf("Item %d was sold to bidder %d for %.2f.\n", items[i]->id, items[i]->highest_bidder, items[i]->current_bid);
        } else {
            printf("Item %d did not meet its reserve price.\n", items[i]->id);
        }
    }
}

// Main function
int main() {
    // Create the items
    item *items[] = {
        create_item(1, "Painting", 1000),
        create_item(2, "Sculpture", 500),
        create_item(3, "Vase", 200),
        create_item(4, "Book", 50),
        create_item(5, "Lamp", 100),
    };

    // Start the auction
    start_auction(items, 5);

    return 0;
}