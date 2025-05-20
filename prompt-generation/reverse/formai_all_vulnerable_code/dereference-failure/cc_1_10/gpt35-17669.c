//FormAI DATASET v1.0 Category: Digital Auction System ; Style: thoughtful
/* C Digital Auction System */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Struct for items being auctioned */
typedef struct {
    char name[50];
    float starting_bid;
    float current_bid;
    int bidder_id;
} Item;

/* Struct for bidders */
typedef struct {
    char name[50];
    float balance;
    int id;
} Bidder;

/* Function to display list of items being auctioned */
void display_items(Item* items, int num_items) {
    printf("\nCurrent Items for Auction:\n");
    for (int i=0; i<num_items; i++) {
        printf("%d. %s (Starting Bid: $%.2f)\n", i+1, items[i].name, items[i].starting_bid);
    }
}

/* Function to add new item to auction */
void add_item(Item* items, int* num_items) {
    printf("\nEnter Name of Item to Add: ");
    char name[50];
    scanf("%s", name);
    printf("Enter Starting Bid Price: $");
    float starting_bid;
    scanf("%f", &starting_bid);
    Item new_item = { .starting_bid=starting_bid, .current_bid=starting_bid };
    strcpy(new_item.name, name);
    items[*num_items] = new_item;
    (*num_items)++;
    printf("\nItem Added to Auction!\n");
}

/* Function to display information about a particular item */
void display_item_info(Item item) {
    printf("\nItem Name: %s\n", item.name);
    printf("Starting Bid: $%.2f\n", item.starting_bid);
    printf("Current Bid: $%.2f\n", item.current_bid);
    printf("Bidder ID: %d\n", item.bidder_id);
}

/* Function to start bidding on an item */
void start_bidding(Item* item, Bidder* bidders, int num_bidders) {
    printf("\nStarting bidding for: %s (Starting Bid: $%.2f)", item->name, item->starting_bid);
    int bidder_id = -1;
    float current_bid = item->starting_bid;

    // Loop through all bidders to accept bids
    while (1) {
        for (int i=0; i<num_bidders; i++) {
            printf("\n\nCurrent Bid: $%.2f\n", current_bid);
            printf("Current Highest Bidder: %s (%d)\n", bidders[bidder_id-1].name, bidder_id);
            printf("%s, enter your bid (enter -1 to exit): $", bidders[i].name);
            float bid;
            scanf("%f", &bid);

            // Check if bidder wants to exit bidding
            if (bid == -1) {
                printf("\nExiting Bidding for %s\n", item->name);
                return;
            }

            // Check if bid is highest so far, and if bidder has enough balance
            if (bid > current_bid && bid <= bidders[i].balance) {
                current_bid = bid;
                bidder_id = bidders[i].id;
                printf("New Bid: $%.2f (Bidder %s)\n", current_bid, bidders[i].name);
            }
            else if (bid > current_bid && bid > bidders[i].balance) {
                printf("\nBid not accepted. %s, you do not have a sufficient balance.", bidders[i].name);
            }
        }
    }
}

/* Main function */
int main() {
    printf("Welcome to the C Digital Auction System!\n");

    // Add example items and bidders
    Item items[5] = {
        { .name="iPhone 12 Pro Max", .starting_bid=1100.00, .current_bid=1100.00, .bidder_id=-1 },
        { .name="Samsung Galaxy S20", .starting_bid=900.00, .current_bid=900.00, .bidder_id=-1 },
        { .name="Sony PlayStation 5", .starting_bid=500.00, .current_bid=500.00, .bidder_id=-1 },
        { .name="LG 65-inch OLED TV", .starting_bid=2000.00, .current_bid=2000.00, .bidder_id=-1 },
        { .name="MacBook Pro 16-inch", .starting_bid=2500.00, .current_bid=2500.00, .bidder_id=-1 }
    };
    int num_items = 5;

    Bidder bidders[3] = {
        { .name="John", .balance=3000.00, .id=1 },
        { .name="Jane", .balance=2500.00, .id=2 },
        { .name="Bob", .balance=5000.00, .id=3 }
    };
    int num_bidders = 3;

    // Display menu options
    int choice = 0;
    while (1) {
        printf("\n\nChoose an Option:\n");
        printf("1. Display Items for Auction\n");
        printf("2. Add Item to Auction\n");
        printf("3. Display Item Information\n");
        printf("4. Start Bidding on Item\n");
        printf("5. Exit Program\n");
        scanf("%d", &choice);

        // Evaluate user's choice and perform appropriate action
        switch (choice) {
            case 1:
                display_items(items, num_items);
                break;
            case 2:
                add_item(items, &num_items);
                break;
            case 3:
                printf("\nEnter Item Number to View: ");
                int item_num;
                scanf("%d", &item_num);
                display_item_info(items[item_num-1]);
                break;
            case 4:
                printf("\nEnter Item Number to Bid On: ");
                int bid_item_num;
                scanf("%d", &bid_item_num);
                start_bidding(&items[bid_item_num-1], bidders, num_bidders);
                break;
            case 5:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("\nInvalid Choice. Please Try Again.\n");
                break;
        }
    }
}