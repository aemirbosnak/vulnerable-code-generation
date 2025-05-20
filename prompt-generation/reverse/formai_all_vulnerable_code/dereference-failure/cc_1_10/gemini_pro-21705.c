//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the item struct
typedef struct item {
    char name[50];
    float price;
    int quantity;
} item;

// Declare the auction struct
typedef struct auction {
    char name[50];
    int num_items;
    item *items;
} auction;

// Create a new auction
auction *new_auction(char *name) {
    auction *a = malloc(sizeof(auction));
    strcpy(a->name, name);
    a->num_items = 0;
    a->items = NULL;
    return a;
}

// Add an item to an auction
void add_item(auction *a, item *i) {
    a->items = realloc(a->items, (a->num_items + 1) * sizeof(item));
    a->items[a->num_items] = *i;
    a->num_items++;
}

// Print an auction
void print_auction(auction *a) {
    printf("Auction: %s\n", a->name);
    for (int i = 0; i < a->num_items; i++) {
        printf("  Item: %s\n", a->items[i].name);
        printf("    Price: %.2f\n", a->items[i].price);
        printf("    Quantity: %d\n", a->items[i].quantity);
    }
}

// Run an auction
void run_auction(auction *a) {
    // Initialize the current bid
    float current_bid = 0.0;

    // Loop through the items in the auction
    for (int i = 0; i < a->num_items; i++) {
        // Print the item
        printf("Item: %s\n", a->items[i].name);

        // Get the current bid
        printf("Current bid: %.2f\n", current_bid);

        // Get the new bid
        float new_bid;
        printf("Enter your bid: ");
        scanf("%f", &new_bid);

        // Check if the new bid is valid
        if (new_bid > current_bid) {
            // Update the current bid
            current_bid = new_bid;
        } else {
            // The new bid is not valid
            printf("Invalid bid. Please enter a bid greater than the current bid.\n");
        }
    }

    // Print the winning bid
    printf("Winning bid: %.2f\n", current_bid);
}

// Free the memory allocated for an auction
void free_auction(auction *a) {
    free(a->items);
    free(a);
}

// Main function
int main() {
    // Create a new auction
    auction *a = new_auction("My Auction");

    // Add some items to the auction
    item i1 = {"Item 1", 10.0, 10};
    add_item(a, &i1);
    item i2 = {"Item 2", 20.0, 5};
    add_item(a, &i2);
    item i3 = {"Item 3", 30.0, 2};
    add_item(a, &i3);

    // Print the auction
    print_auction(a);

    // Run the auction
    run_auction(a);

    // Free the memory allocated for the auction
    free_auction(a);

    return 0;
}