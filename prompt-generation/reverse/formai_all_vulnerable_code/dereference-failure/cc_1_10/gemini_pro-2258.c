//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the auction
#define MAX_ITEMS 100

// Define the maximum length of an item name
#define MAX_NAME_LENGTH 50

// Define the structure of an item
typedef struct item {
    char name[MAX_NAME_LENGTH];
    float price;
} item;

// Define the structure of an auction
typedef struct auction {
    item items[MAX_ITEMS];
    int num_items;
} auction;

// Create a new auction
auction* create_auction() {
    auction* a = (auction*)malloc(sizeof(auction));
    a->num_items = 0;
    return a;
}

// Add an item to an auction
void add_item(auction* a, char* name, float price) {
    strcpy(a->items[a->num_items].name, name);
    a->items[a->num_items].price = price;
    a->num_items++;
}

// Print the items in an auction
void print_items(auction* a) {
    for (int i = 0; i < a->num_items; i++) {
        printf("%s: $%.2f\n", a->items[i].name, a->items[i].price);
    }
}

// Get the highest bid for an item
float get_highest_bid(auction* a, char* name) {
    float highest_bid = 0;
    for (int i = 0; i < a->num_items; i++) {
        if (strcmp(a->items[i].name, name) == 0) {
            if (a->items[i].price > highest_bid) {
                highest_bid = a->items[i].price;
            }
        }
    }
    return highest_bid;
}

// Place a bid on an item
void place_bid(auction* a, char* name, float bid) {
    for (int i = 0; i < a->num_items; i++) {
        if (strcmp(a->items[i].name, name) == 0) {
            if (bid > a->items[i].price) {
                a->items[i].price = bid;
            }
        }
    }
}

// Close the auction and print the winners
void close_auction(auction* a) {
    for (int i = 0; i < a->num_items; i++) {
        float highest_bid = get_highest_bid(a, a->items[i].name);
        if (highest_bid > 0) {
            printf("%s sold for $%.2f\n", a->items[i].name, highest_bid);
        }
    }
}

// Main function
int main() {
    // Create a new auction
    auction* a = create_auction();

    // Add some items to the auction
    add_item(a, "Painting", 100);
    add_item(a, "Sculpture", 200);
    add_item(a, "Vase", 50);

    // Print the items in the auction
    printf("Items in the auction:\n");
    print_items(a);

    // Place some bids on the items
    place_bid(a, "Painting", 120);
    place_bid(a, "Sculpture", 250);
    place_bid(a, "Vase", 60);

    // Print the updated items in the auction
    printf("Updated items in the auction:\n");
    print_items(a);

    // Close the auction and print the winners
    close_auction(a);

    return 0;
}