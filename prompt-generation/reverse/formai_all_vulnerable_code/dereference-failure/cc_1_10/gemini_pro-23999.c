//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Item structure
typedef struct item {
    int id;
    char *name;
    float reserve_price;
    float current_bid;
    int num_bids;
    char **bidders;
} item;

// Bidder structure
typedef struct bidder {
    int id;
    char *name;
    float balance;
} bidder;

// Auction structure
typedef struct auction {
    int num_items;
    item **items;
    int num_bidders;
    bidder **bidders;
    int current_item;
    int current_bidder;
    float current_bid;
} auction;

// Create a new item
item *create_item(int id, char *name, float reserve_price) {
    item *new_item = malloc(sizeof(item));
    new_item->id = id;
    new_item->name = strdup(name);
    new_item->reserve_price = reserve_price;
    new_item->current_bid = 0.0;
    new_item->num_bids = 0;
    new_item->bidders = NULL;
    return new_item;
}

// Create a new bidder
bidder *create_bidder(int id, char *name, float balance) {
    bidder *new_bidder = malloc(sizeof(bidder));
    new_bidder->id = id;
    new_bidder->name = strdup(name);
    new_bidder->balance = balance;
    return new_bidder;
}

// Create a new auction
auction *create_auction(int num_items, item **items, int num_bidders, bidder **bidders) {
    auction *new_auction = malloc(sizeof(auction));
    new_auction->num_items = num_items;
    new_auction->items = items;
    new_auction->num_bidders = num_bidders;
    new_auction->bidders = bidders;
    new_auction->current_item = 0;
    new_auction->current_bidder = 0;
    new_auction->current_bid = 0.0;
    return new_auction;
}

// Print the details of an item
void print_item(item *item) {
    printf("Item %d: %s\n", item->id, item->name);
    printf("Reserve price: %.2f\n", item->reserve_price);
    printf("Current bid: %.2f\n", item->current_bid);
    printf("Number of bids: %d\n", item->num_bids);
    if (item->num_bids > 0) {
        printf("Bidders: ");
        for (int i = 0; i < item->num_bids; i++) {
            printf("%s ", item->bidders[i]);
        }
        printf("\n");
    }
}

// Print the details of a bidder
void print_bidder(bidder *bidder) {
    printf("Bidder %d: %s\n", bidder->id, bidder->name);
    printf("Balance: %.2f\n", bidder->balance);
}

// Print the details of an auction
void print_auction(auction *auction) {
    printf("Auction with %d items and %d bidders\n", auction->num_items, auction->num_bidders);
    for (int i = 0; i < auction->num_items; i++) {
        print_item(auction->items[i]);
    }
    for (int i = 0; i < auction->num_bidders; i++) {
        print_bidder(auction->bidders[i]);
    }
}

// Get the next bid from a bidder
float get_bid(bidder *bidder, float current_bid) {
    float bid;
    do {
        printf("Enter your bid (q to quit): ");
        scanf("%f", &bid);
        if (bid == 'q') {
            return -1.0;
        } else if (bid <= current_bid) {
            printf("Bid must be higher than the current bid\n");
        } else if (bid > bidder->balance) {
            printf("Bid must be less than or equal to your balance\n");
        }
    } while (bid <= current_bid || bid > bidder->balance);
    return bid;
}

// Run the auction
void run_auction(auction *auction) {
    // Loop through each item in the auction
    for (int i = 0; i < auction->num_items; i++) {
        item *item = auction->items[i];
        
        // Print the item details
        print_item(item);
        
        // Loop through each bidder in the auction
        for (int j = 0; j < auction->num_bidders; j++) {
            bidder *bidder = auction->bidders[j];
            
            // Get the bid from the bidder
            float bid = get_bid(bidder, item->current_bid);
            
            // Check if the bidder has quit
            if (bid == -1.0) {
                break;
            }
            
            // Update the item details
            item->current_bid = bid;
            item->num_bids++;
            
            // Add the bidder to the list of bidders
            item->bidders = realloc(item->bidders, sizeof(char *) * item->num_bids);
            item->bidders[item->num_bids - 1] = strdup(bidder->name);
            
            // Update the bidder's balance
            bidder->balance -= bid;
            
            // Print the updated item details
            print_item(item);
        }
        
        // Check if the reserve price has been met
        if (item->current_bid >= item->reserve_price) {
            // The reserve price has been met, so the item has been sold
            printf("Item %d has been sold to %s for %.2f\n", item->id, item->bidders[item->num_bids - 1], item->current_bid);
        } else {
            // The reserve price has not been met, so the item has not been sold
            printf("Item %d has not been sold\n", item->id);
        }
    }
}

// Free the memory allocated for an item
void free_item(item *item) {
    free(item->name);
    free(item->bidders);
    free(item);
}

// Free the memory allocated for a bidder
void free_bidder(bidder *bidder) {
    free(bidder->name);
    free(bidder);
}

// Free the memory allocated for an auction
void free_auction(auction *auction) {
    for (int i = 0; i < auction->num_items; i++) {
        free_item(auction->items[i]);
    }
    free(auction->items);
    for (int i = 0; i < auction->num_bidders; i++) {
        free_bidder(auction->bidders[i]);
    }
    free(auction->bidders);
    free(auction);
}

// Main function
int main() {
    // Create some items
    item *item1 = create_item(1, "Painting", 100.0);
    item *item2 = create_item(2, "Sculpture", 200.0);
    item *item3 = create_item(3, "Vase", 50.0);
    
    // Create some bidders
    bidder *bidder1 = create_bidder(1, "Alice", 1000.0);
    bidder *bidder2 = create_bidder(2, "Bob", 500.0);
    bidder *bidder3 = create_bidder(3, "Carol", 250.0);
    
    // Create an auction
    auction *auction = create_auction(3, &item1, 3, &bidder1);
    
    // Run the auction
    run_auction(auction);
    
    // Free the memory allocated for the auction
    free_auction(auction);
    
    return 0;
}