//FormAI DATASET v1.0 Category: Digital Auction System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDS 50
#define MAX_NAME_LEN 20
#define MAX_ITEM_LEN 50

typedef struct {
    int bid_num;
    char bidder_name[MAX_NAME_LEN];
    float bid_amt;
} Bid;

typedef struct {
    char item_name[MAX_ITEM_LEN];
    float min_bid;
    Bid bids[MAX_BIDS];
    int num_bids;
} Auction_item;

void display_menu();
void create_auction_item(Auction_item *item);
void display_auction_list(Auction_item *items, int num_items);
void bid_on_item(Auction_item *item);
void display_bids(Auction_item *item);

int main() {
    int choice;
    int num_items = 0;
    Auction_item items[MAX_BIDS];
    
    srand(time(NULL));
    
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create_auction_item(&items[num_items]);
                num_items++;
                break;
            case 2:
                display_auction_list(items, num_items);
                break;
            case 3:
                bid_on_item(items);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void display_menu() {
    printf("Welcome to the Digital Auction System!\n");
    printf("1. Create a new auction item\n");
    printf("2. Display current auction items\n");
    printf("3. Bid on an auction item\n");
    printf("4. Exit program\n");
    printf("Enter your choice (1-4): ");
}

void create_auction_item(Auction_item *item) {
    printf("Enter the name of the item: ");
    scanf("%s", item->item_name);
    printf("Enter the minimum bid amount: ");
    scanf("%f", &item->min_bid);
    printf("Item created successfully!\n");
}

void display_auction_list(Auction_item *items, int num_items) {
    printf("Current auction items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s (minimum bid: $%.2f)\n", i+1, items[i].item_name, items[i].min_bid);
        if (items[i].num_bids > 0) {
            printf("    Current bid: $%.2f by %s\n", items[i].bids[items[i].num_bids-1].bid_amt, items[i].bids[items[i].num_bids-1].bidder_name);
        }
    }
}

void bid_on_item(Auction_item *item) {
    int item_num;
    float bid_amt;
    char bidder_name[MAX_NAME_LEN];
    
    display_auction_list(item, 1);
    
    printf("Enter the item number you wish to bid on: ");
    scanf("%d", &item_num);
    item_num--;
    
    if (item_num >= 0 && item_num < 1) {
        printf("Enter your name: ");
        scanf("%s", bidder_name);
        printf("Enter your bid amount: ");
        scanf("%f", &bid_amt);
        
        if (bid_amt >= item[item_num].min_bid) {
            Bid new_bid;
            new_bid.bid_num = rand() % 1000 + 1;
            strcpy(new_bid.bidder_name, bidder_name);
            new_bid.bid_amt = bid_amt;
            item[item_num].bids[item[item_num].num_bids] = new_bid;
            item[item_num].num_bids++;
            
            printf("Bid accepted! Thank you, %s.\n", bidder_name);
        } else {
            printf("Sorry, that bid is not high enough. Please try again.\n");
        }
    } else {
        printf("Invalid item number. Try again.\n");
    }
}

void display_bids(Auction_item *item) {
    int item_num;
    
    display_auction_list(item, 1);
    
    printf("Enter the item number you wish to view bids for: ");
    scanf("%d", &item_num);
    item_num--;
    
    if (item_num >= 0 && item_num < 1) {
        printf("Bids for %s:\n", item[item_num].item_name);
        
        if (item[item_num].num_bids > 0) {
            for (int i = 0; i < item[item_num].num_bids; i++) {
                printf("%d. Bid #%d: $%.2f by %s\n", i+1, item[item_num].bids[i].bid_num, item[item_num].bids[i].bid_amt, item[item_num].bids[i].bidder_name);
            }
        } else {
            printf("No bids yet.\n");
        }
    } else {
        printf("Invalid item number. Try again.\n");
    }
}