//FormAI DATASET v1.0 Category: Digital Auction System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Auction_Item {
    int item_id;
    char item_name[100];
    int starting_bid;
    int current_bid;
    int bidder_id;
};

struct Bidder {
    int bidder_id;
    char bidder_name[100];
    int balance;
};

int main() {
    int num_items, num_bidders;
    printf("Enter number of items: ");
    scanf("%d", &num_items);
    printf("Enter number of bidders: ");
    scanf("%d", &num_bidders);
    
    struct Auction_Item items[num_items];
    printf("\nEnter details of items:\n");
    for (int i=0; i<num_items; i++) {
        printf("Item %d:\n", i+1);
        items[i].item_id = i+1;
        printf("Enter name: ");
        scanf("%s", items[i].item_name);
        printf("Enter starting bid: ");
        scanf("%d", &items[i].starting_bid);
        items[i].current_bid = items[i].starting_bid;
        items[i].bidder_id = 0;
    }
    
    struct Bidder bidders[num_bidders];
    printf("\nEnter details of bidders:\n");
    for (int i=0; i<num_bidders; i++) {
        printf("Bidder %d:\n", i+1);
        bidders[i].bidder_id = i+1;
        printf("Enter name: ");
        scanf("%s", bidders[i].bidder_name);
        printf("Enter balance: ");
        scanf("%d", &bidders[i].balance);
    }
    
    int curr_item = 0;
    while (curr_item < num_items) {
        int max_bid = 0, max_bidder_id = 0;
        printf("\nCurrent item: %s\n", items[curr_item].item_name);
        printf("Starting bid: %d\n", items[curr_item].starting_bid);
        printf("Current bid: %d\n", items[curr_item].current_bid);
        printf("Bidders:\n");
        for (int i=0; i<num_bidders; i++) {
            printf("%d. %s (Balance: %d)\n", bidders[i].bidder_id, bidders[i].bidder_name, bidders[i].balance);
        }
        printf("Enter bidder id or 0 to exit: ");
        int bidder_id;
        scanf("%d", &bidder_id);
        if (bidder_id == 0) {
            break;
        }
        else if (bidder_id < 1 || bidder_id > num_bidders) {
            printf("Invalid bidder id entered!\n");
            continue;
        }
        printf("Enter bid amount: ");
        int bid_amount;
        scanf("%d", &bid_amount);
        if (bid_amount <= items[curr_item].current_bid) {
            printf("Bid amount should be greater than current bid!\n");
            continue;
        }
        if (bid_amount > bidders[bidder_id-1].balance) {
            printf("Bid amount exceeds bidder balance!\n");
            continue;
        }
        items[curr_item].current_bid = bid_amount;
        max_bid = bid_amount;
        max_bidder_id = bidder_id;
        items[curr_item].bidder_id = max_bidder_id;
        printf("Bid successful! %s is the highest bidder for %s with bid amount of %d\n", bidders[max_bidder_id-1].bidder_name, items[curr_item].item_name, max_bid);
        curr_item++;
    }
    printf("Auction complete!\n");
    return 0;
}