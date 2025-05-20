//FormAI DATASET v1.0 Category: Digital Auction System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define struct for auction item
typedef struct auction_item {
    int id;
    char name[50];
    int min_bid;
    int current_bid;
    char seller[50];
    char winner[50];
    int days_left;
} AuctionItem;

// Define global variables
int num_items = 0;
AuctionItem items[50];

// Function to print menu options
void print_menu() {
    printf("Welcome to the Digital Auction System.\n");
    printf("Please select one of the following options:\n");
    printf("1. View all items currently being auctioned.\n");
    printf("2. Place a bid on an item.\n");
    printf("3. Sell an item.\n");
    printf("4. View winners of past auctions.\n");
    printf("5. Exit the program.\n");
}

// Function to add an item to the auction
void add_item() {
    AuctionItem new_item;
    printf("Enter item name: ");
    scanf("%s", new_item.name);
    printf("Enter minimum bid: ");
    scanf("%d", &new_item.min_bid);
    new_item.id = num_items + 1;
    new_item.current_bid = new_item.min_bid;
    strcpy(new_item.seller, "Unknown");
    strcpy(new_item.winner, "None");
    new_item.days_left = 7;
    items[num_items] = new_item;
    num_items++;
    printf("Item added to auction successfully!\n");
}

// Function to print all items being auctioned
void print_items() {
    printf("All items currently being auctioned:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item ID: %d\n", items[i].id);
        printf("Item name: %s\n", items[i].name);
        printf("Minimum bid: %d\n", items[i].min_bid);
        printf("Current bid: %d\n", items[i].current_bid);
        printf("Seller: %s\n", items[i].seller);
        printf("Winner: %s\n", items[i].winner);
        printf("Days left in auction: %d\n", items[i].days_left);
        printf("\n");
    }
}

// Function to place a bid on an item
void place_bid() {
    int item_id, bid_amount;
    printf("Enter the ID of the item you wish to bid on: ");
    scanf("%d", &item_id);
    printf("Enter your bid amount: ");
    scanf("%d", &bid_amount);
    AuctionItem item = items[item_id-1];
    if (bid_amount > item.current_bid && item.days_left > 0) {
        item.current_bid = bid_amount;
        strcpy(item.winner, "Unknown");
        printf("Bid placed successfully!\n");
    }
    else {
        printf("Error: Bid must be higher than current bid and there must be time left in the auction.\n");
    }
}

// Function to sell an item
void sell_item() {
    int item_id;
    printf("Enter the ID of the item you wish to sell: ");
    scanf("%d", &item_id);
    strcpy(items[item_id-1].seller, "You");
    printf("Item sold successfully!\n");
}

// Function to print past auction winners
void print_winners() {
    printf("Previous auction winners:\n");
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].winner, "None") != 0) {
            printf("Item name: %s\n", items[i].name);
            printf("Winner: %s\n", items[i].winner);
            printf("Selling Price: %d\n", items[i].current_bid);
            printf("\n");
        }
    }
}

// Function to decrement days left for each item in the auction
void decrement_days() {
    for (int i = 0; i < num_items; i++) {
        items[i].days_left--;
        if (items[i].days_left == 0) {
            strcpy(items[i].winner, "Unknown");
            printf("Item \"%s\" has been sold to %s for %d.\n", items[i].name, items[i].winner, items[i].current_bid);
        }
    }
}

// Function to randomly select a winner for each item in the auction
void select_winners() {
    srand(time(NULL));
    for (int i = 0; i < num_items; i++) {
        if (items[i].days_left == 0 && strcmp(items[i].winner, "Unknown") == 0) {
            int winner_index = rand() % 3;
            strcpy(items[i].winner, "Survivor");
        }
    }
}

int main() {
    int choice;
    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                print_items();
                break;
            case 2:
                place_bid();
                break;
            case 3:
                sell_item();
                break;
            case 4:
                print_winners();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
        decrement_days();
        select_winners();
    }
    return 0;
}