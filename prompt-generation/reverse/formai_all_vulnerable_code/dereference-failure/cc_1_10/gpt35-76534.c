//FormAI DATASET v1.0 Category: Digital Auction System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the auction item
typedef struct {
    char name[50];
    double starting_price;
    double current_bid;
    char bidder_name[50];
} AuctionItem;

// Function to display the details of an auction item
void displayItem(AuctionItem item) {
    printf("Item Name: %s\n", item.name);
    printf("Starting Price: $%.2f\n", item.starting_price);
    printf("Current Bid: $%.2f\n", item.current_bid);
    printf("Bidder Name: %s\n", item.bidder_name);
}

// Function to update the current bid of an auction item
void updateBid(AuctionItem *item, char *bidder_name, double bid_amount) {
    if (bid_amount > item->current_bid) {
        item->current_bid = bid_amount;
        strcpy(item->bidder_name, bidder_name);
    }
}

// Main function to run the auction program
int main() {
    int num_items;
    printf("Enter the number of items to be auctioned: ");
    scanf("%d", &num_items);

    // Allocate memory for the auction item array
    AuctionItem *items = (AuctionItem*) malloc(num_items * sizeof(AuctionItem));

    // Populate the auction item array with user input
    for (int i = 0; i < num_items; i++) {
        printf("\nEnter details for Item #%d:\n", i+1);
        printf("Name: ");
        scanf("%s", items[i].name);
        printf("Starting Price: $");
        scanf("%lf", &items[i].starting_price);
        items[i].current_bid = items[i].starting_price;
        strcpy(items[i].bidder_name, "None");
    }

    int auction_done = 0;
    while (!auction_done) {
        printf("\n");
        for (int i = 0; i < num_items; i++) {
            printf("Item #%d:\n", i+1);
            displayItem(items[i]);
            printf("\n");
        }

        int item_num;
        double bid_amount;
        char bidder_name[50];
        printf("Enter item number to bid on (0 to end auction): ");
        scanf("%d", &item_num);

        if (item_num == 0) {
            auction_done = 1;
            break;
        }

        printf("Enter your name: ");
        scanf("%s", bidder_name);

        printf("Enter your bid amount for Item #%d: $", item_num);
        scanf("%lf", &bid_amount);

        updateBid(&items[item_num-1], bidder_name, bid_amount);
    }

    // Display the final auction results
    printf("\nFINAL RESULTS:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item #%d:\n", i+1);
        displayItem(items[i]);
        printf("\n");
    }

    // Free the allocated memory
    free(items);

    return 0;
}