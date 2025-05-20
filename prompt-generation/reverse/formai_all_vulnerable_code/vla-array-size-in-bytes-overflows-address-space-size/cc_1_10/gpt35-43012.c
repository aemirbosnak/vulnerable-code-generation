//FormAI DATASET v1.0 Category: Digital Auction System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[50];
    int price;
};

int main() {
    int num_items, i, max_bid = 0, second_max = 0, max_index = 0;
    printf("Enter the number of items to be auctioned: ");
    scanf("%d", &num_items);
    struct item items[num_items];

    // Get input
    for (i = 0; i < num_items; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter the starting price of item %d: ", i+1);
        scanf("%d", &items[i].price);
    }

    // Auction
    for (i = 0; i < num_items; i++) {
        printf("\n\nAuctioning item %d: %s\n", i+1, items[i].name);
        printf("Starting price: %d\n", items[i].price);
        int bidder;
        while (1) {
            printf("Enter bid amount (enter -1 to end bidding): ");
            scanf("%d", &bidder);
            if (bidder == -1) {
                break;
            }
            if (bidder > items[i].price) {
                second_max = max_bid;
                max_bid = bidder;
                max_index = i;
                printf("Bid accepted!\n");
            }
        }
        if (max_bid > items[i].price) {
            printf("%s sold for $%d to bidder %d!\n", items[max_index].name, max_bid, max_index+1);
        } else {
            printf("%s did not sell.\n", items[i].name);
        }
    }

    return 0;
}