//FormAI DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * Auction Item Struct Definition 
 */
typedef struct auction_item
{
    int item_id;
    char item_name[50];
    float starting_bid;
    float current_bid;
    char bidder_name[50];
    int num_bids;
    int num_days_left;
} AuctionItem;

/* 
 * Function to create a new auction item 
 */
AuctionItem* create_auction_item(int item_id, char* item_name, float starting_bid, int num_days_left)
{
    AuctionItem* new_item = (AuctionItem*) malloc(sizeof(AuctionItem));

    new_item->item_id = item_id;
    strcpy(new_item->item_name, item_name);
    new_item->starting_bid = starting_bid;
    new_item->current_bid = starting_bid;
    strcpy(new_item->bidder_name, "");
    new_item->num_bids = 0;
    new_item->num_days_left = num_days_left;

    return new_item;
}

/* 
 * Function to handle a bid on an auction item 
 */
void handle_bid(AuctionItem* item, char* bidder_name, float bid_amount)
{
    if (bid_amount <= item->current_bid)
    {
        printf("Bid amount must be higher than current bid of %.2f\n", item->current_bid);
        return;
    }

    item->current_bid = bid_amount;
    strcpy(item->bidder_name, bidder_name);
    item->num_bids++;
    printf("%s has submitted a bid of %.2f on %s (ID: %d)\n", bidder_name, bid_amount, item->item_name, item->item_id);
}

/* 
 * Main Function 
 */
int main()
{
    // Create some sample auction items
    AuctionItem* item1 = create_auction_item(1, "Signed Baseball", 50.0, 5);
    AuctionItem* item2 = create_auction_item(2, "Vintage Watch", 100.0, 3);
    AuctionItem* item3 = create_auction_item(3, "Rare Coin Collection", 500.0, 7);

    // Allow bidders to bid on items
    handle_bid(item1, "John", 75.0);
    handle_bid(item2, "Sarah", 150.0);
    handle_bid(item3, "Mark", 1000.0);
    handle_bid(item1, "Jane", 100.0);
    handle_bid(item2, "David", 200.0);
    handle_bid(item3, "Michael", 1500.0);

    // Print the final bids for each item
    printf("\nFINAL BIDS:\n");
    printf("Item %d (%s): %.2f (Bidder: %s)\n", item1->item_id, item1->item_name, item1->current_bid, item1->bidder_name);
    printf("Item %d (%s): %.2f (Bidder: %s)\n", item2->item_id, item2->item_name, item2->current_bid, item2->bidder_name);
    printf("Item %d (%s): %.2f (Bidder: %s)\n", item3->item_id, item3->item_name, item3->current_bid, item3->bidder_name);

    // Free memory used by auction items
    free(item1);
    free(item2);
    free(item3);

    return 0;
}