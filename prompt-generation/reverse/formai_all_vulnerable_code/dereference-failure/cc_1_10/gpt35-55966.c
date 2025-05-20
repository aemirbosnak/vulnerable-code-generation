//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10 // Maximum number of bids allowed per item
#define MAX_ITEMS 5 // Maximum number of items in the auction
#define MAX_NAME_LEN 20 // Maximum length of bidder/item names
#define MAX_PASS_LEN 10 // Maximum length of bidder passwords

// Bidder structure
typedef struct {
    char name[MAX_NAME_LEN];
    char password[MAX_PASS_LEN];
    int bids[MAX_ITEMS];
    int num_bids;
} Bidder;

// Item structure
typedef struct {
    char name[MAX_NAME_LEN];
    int highest_bid;
    int highest_bidder;
    int num_bids;
    Bidder bidders[MAX_BIDS];
} Item;

// Auction structure
typedef struct {
    int num_items;
    Item items[MAX_ITEMS];
} Auction;

// Function to add a new bidder to the auction
void add_bidder(Bidder *bidders, int *num_bidders) {
    if (*num_bidders >= MAX_BIDS) {
        printf("Sorry, the maximum number of bidders has been reached.\n");
        return;
    }
    
    printf("Enter bidder name: ");
    scanf("%s", bidders[*num_bidders].name);
    printf("Enter bidder password: ");
    scanf("%s", bidders[*num_bidders].password);
    
    // Set number of bids to 0
    bidders[*num_bidders].num_bids = 0;
    
    (*num_bidders)++;
}

// Function to add a new item to the auction
void add_item(Item *items, int *num_items) {
    if (*num_items >= MAX_ITEMS) {
        printf("Sorry, the maximum number of items has been reached.\n");
        return;
    }
    
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter starting bid: ");
    scanf("%d", &items[*num_items].highest_bid);
    
    // Set highest bidder to -1 (no bidder yet)
    items[*num_items].highest_bidder = -1;
    
    // Set number of bids to 0
    items[*num_items].num_bids = 0;
    
    (*num_items)++;
}

// Function to display all items in the auction
void display_items(Item *items, int num_items) {
    printf("Items in auction:\n");
    
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - Highest Bid: %d\n", i+1, items[i].name, items[i].highest_bid);
    }
    
    printf("\n");
}

// Function to display all bidders in the auction
void display_bidders(Bidder *bidders, int num_bidders) {
    printf("Bidders in auction:\n");
    
    for (int i = 0; i < num_bidders; i++) {
        printf("%d. %s\n", i+1, bidders[i].name);
    }
    
    printf("\n");
}

// Function to find bidder by name and password
int find_bidder(Bidder *bidders, int num_bidders, char *name, char *password) {
    for (int i = 0; i < num_bidders; i++) {
        if (strcmp(bidders[i].name, name) == 0 && strcmp(bidders[i].password, password) == 0) {
            return i;
        }
    }
    
    return -1;
}

// Function to place a bid on an item
void place_bid(Item *items, Bidder *bidders, int num_items, int num_bidders) {
    int item_num, bidder_num, amount;
    char name[MAX_NAME_LEN], password[MAX_PASS_LEN];
    
    display_items(items, num_items);
    printf("Enter item number to bid on: ");
    scanf("%d", &item_num);
    
    if (item_num < 1 || item_num > num_items) {
        printf("Invalid item number.\n\n");
        return;
    }
    
    Item *item = &items[item_num-1];
    
    display_bidders(item->bidders, item->num_bids);
    printf("Enter bidder name: ");
    scanf("%s", name);
    printf("Enter bidder password: ");
    scanf("%s", password);
    
    bidder_num = find_bidder(bidders, num_bidders, name, password);
    
    if (bidder_num == -1) {
        printf("Invalid bidder name or password.\n\n");
        return;
    }
    
    printf("Enter bid amount: ");
    scanf("%d", &amount);
    
    if (amount <= item->highest_bid || amount <= 0) {
        printf("Invalid bid amount.\n\n");
        return;
    }
    
    // Update highest bid and bidder
    item->highest_bid = amount;
    item->highest_bidder = bidder_num;
    
    // Add bid to bidder's list of bids
    Bidder *bidder = &bidders[bidder_num];
    bidder->bids[bidder->num_bids] = amount;
    bidder->num_bids++;
    
    // Add bidder to item's list of bidders if not already on it
    for (int i = 0; i < item->num_bids; i++) {
        if (strcmp(item->bidders[i].name, bidder->name) == 0) {
            return;
        }
    }
    
    item->bidders[item->num_bids] = *bidder;
    item->num_bids++;
}

int main(void) {
    Auction auction;
    auction.num_items = 0;
    
    Bidder bidders[MAX_BIDS];
    int num_bidders = 0;
    
    int choice;
    
    do {
        printf("Digital Auction System\n");
        printf("----------------------\n");
        printf("1. Add bidder\n");
        printf("2. Add item\n");
        printf("3. Place bid\n");
        printf("4. Exit\n");
        
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1:
                add_bidder(bidders, &num_bidders);
                break;
            
            case 2:
                add_item(auction.items, &auction.num_items);
                break;
            
            case 3:
                place_bid(auction.items, bidders, auction.num_items, num_bidders);
                break;
            
            case 4:
                printf("Goodbye!\n");
                break;
            
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}