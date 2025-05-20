//FormAI DATASET v1.0 Category: Digital Auction System ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_BIDS 10
#define MAX_NAME_LENGTH 100

struct Bid {
    char name[MAX_NAME_LENGTH];
    float amount;
};

struct Item {
    char name[MAX_NAME_LENGTH];
    struct Bid bids[MAX_BIDS];
    int current_bids;
    float current_highest_bid;
};

int main() {
    srand(time(NULL)); // seed random number generator
    
    int num_items;
    printf("Enter the number of items to auction: ");
    scanf("%d", &num_items);
    struct Item items[num_items]; // array of items
    
    // initialize items
    for(int i=0; i<num_items; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", items[i].name);
        items[i].current_bids = 0;
        items[i].current_highest_bid = 0;
    }
    
    // auction loop
    int current_item = 0;
    while(current_item < num_items) {
        printf("\nAuctioning %s...\n", items[current_item].name);
        
        // display current highest bid
        printf("Current highest bid: $%.2f\n", items[current_item].current_highest_bid);
        
        // get new bid
        char bidder_name[MAX_NAME_LENGTH];
        float bid_amount;
        printf("Enter bidder name: ");
        scanf("%s", bidder_name);
        printf("Enter bid amount: ");
        scanf("%f", &bid_amount);
        
        // check if new bid is higher than current highest bid
        if(bid_amount > items[current_item].current_highest_bid) {
            // add new bid to item's list of bids
            struct Bid new_bid;
            strcpy(new_bid.name, bidder_name);
            new_bid.amount = bid_amount;
            items[current_item].bids[items[current_item].current_bids] = new_bid;
            items[current_item].current_bids++;
            items[current_item].current_highest_bid = bid_amount;
            
            printf("New highest bid! $%.2f by %s.\n", bid_amount, bidder_name);
        } else {
            printf("Bid not accepted. Please enter a higher bid.\n");
        }
        
        // randomly move to next item
        current_item = (current_item + rand() % num_items) % num_items;
    }
    
    // auction is over, display results
    printf("\nAuction has ended! Results:\n");
    for(int i=0; i<num_items; i++) {
        printf("%s:\n", items[i].name);
        printf("\tCurrent highest bid: $%.2f\n", items[i].current_highest_bid);
        printf("\tTotal number of bids: %d\n", items[i].current_bids);
        printf("\tBids:\n");
        for(int j=0; j<items[i].current_bids; j++) {
            printf("\t\t$%.2f by %s\n", items[i].bids[j].amount, items[i].bids[j].name);
        }
    }
    
    return 0;
}