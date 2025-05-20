//FormAI DATASET v1.0 Category: Digital Auction System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int item_number;
    char item_name[50];
    float item_price;
    int highest_bid;
    char highest_bidder[50];
} AuctionItem;

int main() {
    int num_items;
    printf("Enter number of items to auction: ");
    scanf("%d", &num_items);
    AuctionItem items[num_items];

    // Populating items
    for(int i=0; i<num_items; i++) {
        printf("\nEnter details for item %d:\n", i+1);
        items[i].item_number = i+1;
        printf("Enter name of item: ");
        scanf("%s", items[i].item_name);
        printf("Enter starting price: ");
        scanf("%f", &items[i].item_price);
        items[i].highest_bid = items[i].item_price;
        strcpy(items[i].highest_bidder, "No bidder yet");
    }

    int option;
    do {
        printf("\n1. View items for Auction\n");
        printf("2. Place bid\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nCurrent items for auction:\n");
                printf("Item Number\tItem Name\tStarting Price\tHighest Bid\tHighest Bidder\n");
                for(int i=0; i<num_items; i++) {
                    printf("%d\t%s\t%.2f\t\t%d\t%s\n", items[i].item_number, items[i].item_name, items[i].item_price, items[i].highest_bid, items[i].highest_bidder);
                }
                break;
            case 2:
                printf("\nEnter item number to place bid: ");
                int item_idx;
                scanf("%d", &item_idx);
                if(item_idx < 1 || item_idx > num_items) {
                    printf("Invalid item number!\n");
                    break;
                }
                printf("Enter bid amount: ");
                int bid_amount;
                scanf("%d", &bid_amount);
                if(bid_amount < items[item_idx-1].highest_bid) {
                    printf("Bid amount is less than current highest bid.\n");
                    break;
                }
                items[item_idx-1].highest_bid = bid_amount;
                printf("Enter your name: ");
                char bidder_name[50];
                scanf("%s", bidder_name);
                strcpy(items[item_idx-1].highest_bidder, bidder_name);
                printf("Bid placed successfully!\n");
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
                break;
        }
    } while(option != 3);

    return 0;
}