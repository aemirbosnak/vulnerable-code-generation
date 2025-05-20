//FormAI DATASET v1.0 Category: Digital Auction System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int num_items;
    printf("Enter the number of items to be auctioned: ");
    scanf("%d", &num_items);

    char item_names[num_items][50];
    int item_ids[num_items];
    int item_prices[num_items];
    int bid_prices[num_items];
    int bids_placed[num_items];
    int winner_ids[num_items];

    for (int i = 0; i < num_items; i++) {
        printf("\nEnter the name of item %d: ", i+1);
        scanf("%s", item_names[i]);

        printf("Enter the ID of item %d: ", i+1);
        scanf("%d", &item_ids[i]);

        printf("Enter the starting price of item %d: ", i+1);
        scanf("%d", &item_prices[i]);

        bid_prices[i] = item_prices[i];
        bids_placed[i] = 0;
        winner_ids[i] = -1;
    }

    printf("\n%s %10s %10s %10s %10s\n", "Item Name", "Item ID", "Start Price", "Bid Price", "Bids Placed");
    for (int i = 0; i < num_items; i++) {
        printf("%-10s %5d %10d %10d %10d\n", item_names[i], item_ids[i], item_prices[i], bid_prices[i], bids_placed[i]);
    }

    int option = -1;
    while (option != 0) {
        printf("\nAuction Menu:\n");
        printf("1. Place Bid\n");
        printf("2. View Items\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        if (option == 1) {
            int item_id;
            printf("\nEnter the item ID you wish to bid on: ");
            scanf("%d", &item_id);

            int bid_price;
            printf("Enter your bid amount: ");
            scanf("%d", &bid_price);

            int found = 0;
            for (int i = 0; i < num_items; i++) {
                if (item_ids[i] == item_id) {
                    found = 1;
                    if (bid_price > bid_prices[i]) {
                        bid_prices[i] = bid_price;
                        bids_placed[i]++;
                        winner_ids[i] = rand() % 100 + 1;
                        printf("\nBid successfully placed on %s for $%d.\n", item_names[i], bid_price);
                        printf("Current winning bid: $%d\n", bid_prices[i]);
                    } else {
                        printf("\nBid must be higher than current bid of $%d.\n", bid_prices[i]);
                    }
                    break;
                }
            }

            if (!found) {
                printf("\nItem not found.\n");
            }
        } else if (option == 2) {
            printf("\n%s %10s %10s %10s %15s %15s\n", "Item Name", "Item ID", "Start Price", "Bid Price", "Bids Placed", "Winner ID");
            for (int i = 0; i < num_items; i++) {
                printf("%-10s %5d %10d %10d %10d", item_names[i], item_ids[i], item_prices[i], bid_prices[i], bids_placed[i]);
                if (winner_ids[i] == -1) {
                    printf("%15s\n", "No Winner");
                } else {
                    printf("%15d\n", winner_ids[i]);
                }
            }
        } else if (option == 0) {
            printf("\nExiting auction system.\n");
            break;
        }
    }

    return 0;
}