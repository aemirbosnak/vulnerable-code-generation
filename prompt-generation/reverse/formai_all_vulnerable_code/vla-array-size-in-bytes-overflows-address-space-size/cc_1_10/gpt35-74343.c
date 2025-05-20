//FormAI DATASET v1.0 Category: Digital Auction System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct AuctionItem {
    char name[50];
    float current_bid;
    int bidder_id;
};

void print_item(struct AuctionItem item) {
    printf("%s\tCurrent Bid: $%.2f\tBidder ID: %d\n", item.name, item.current_bid, item.bidder_id);
}

void bid(struct AuctionItem *item, float bid, int bidder_id) {
    if (bid > item->current_bid) {
        item->current_bid = bid;
        item->bidder_id = bidder_id;
        printf("Bid accepted!\n");
        print_item(*item);
    } else {
        printf("Bid must be greater than current bid of $%.2f\n", item->current_bid);
    }
}

int main() {
    int n_items, n_bidders, i, j;
    float starting_bid;
    char item_name[50];

    srand(time(NULL));

    printf("Enter number of items: ");
    scanf("%d", &n_items);

    printf("Enter number of bidders: ");
    scanf("%d", &n_bidders);

    struct AuctionItem items[n_items];
    int bidders[n_bidders];

    for (i = 0; i < n_items; i++) {
        printf("Enter name of item %d: ", i+1);
        scanf("%s", item_name);
        strcpy(items[i].name, item_name);

        printf("Enter starting bid for %s: $", items[i].name);
        scanf("%f", &starting_bid);
        items[i].current_bid = starting_bid;
        items[i].bidder_id = -1;
    }

    for (i = 0; i < n_bidders; i++) {
        bidders[i] = i+1;
    }

    for (i = 0; i < n_items; i++) {
        printf("\n==============================================\n");
        printf("Auctioning item %s\nStarting Bid: $%.2f\n", items[i].name, items[i].current_bid);
        printf("Bidders: ");
        for (j = 0; j < n_bidders; j++) {
            printf("%d ", bidders[j]);
        }
        printf("\n");

        while (items[i].bidder_id == -1) {
            int bidder_id = bidders[rand() % n_bidders];
            float bid_amount = items[i].current_bid + (rand() % 10 + 1) * 0.5;
            printf("Bidder %d placed a bid of $%.2f\n", bidder_id, bid_amount);
            bid(&items[i], bid_amount, bidder_id);
        }

        printf("Item %s sold to bidder %d for $%.2f\n", items[i].name, items[i].bidder_id, items[i].current_bid);
    }
    return 0;
}