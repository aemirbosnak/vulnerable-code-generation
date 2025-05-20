//FormAI DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[50];
    int id;
    int price;
    int bid_count;
    char bidder[50];
};

struct auction {
    char name[50];
    int num_items;
    struct item *items;
};

void create_auction(struct auction *auction) {
    printf("\nEnter name of the auction: ");
    scanf("%s", auction->name);
    printf("Enter number of items in the auction: ");
    scanf("%d", &auction->num_items);
    auction->items = (struct item *)malloc(auction->num_items * sizeof(struct item));
}

void create_item(struct item *item) {
    printf("\nEnter name of the item: ");
    scanf("%s", item->name);
    printf("Enter id of the item: ");
    scanf("%d", &item->id);
    printf("Enter starting price of the item: ");
    scanf("%d", &item->price);
    item->bid_count = 0;
    strcpy(item->bidder, "");
}

void display_auction(struct auction *auction) {
    printf("\nAuction name: %s\n", auction->name);
    printf("Number of items: %d\n", auction->num_items);
    for (int i = 0; i < auction->num_items; i++) {
        printf("\nItem name: %s\n", auction->items[i].name);
        printf("Item id: %d\n", auction->items[i].id);
        printf("Item starting price: %d\n", auction->items[i].price);
        printf("Current bid count: %d\n", auction->items[i].bid_count);
        printf("Current highest bidder: %s\n", auction->items[i].bidder);
    }
}

void make_bid(struct auction *auction) {
    char item_name[50];
    printf("\nEnter name of the item you want to bid for: ");
    scanf("%s", item_name);
    for (int i = 0; i < auction->num_items; i++) {
        if (strcmp(auction->items[i].name, item_name) == 0) {
            printf("Enter your bid: ");
            int bid;
            scanf("%d", &bid);
            if (bid > auction->items[i].price) {
                auction->items[i].price = bid;
                auction->items[i].bid_count++;
                printf("Congratulations, your bid is now the highest for this item!\n");
                printf("Enter your name: ");
                scanf("%s", auction->items[i].bidder);
                return;
            } else {
                printf("Your bid is not higher than the current highest bid for this item.\n");
                return;
            }
        }
    }
    printf("Item not found in auction.\n");
}

int main() {
    struct auction my_auction;
    create_auction(&my_auction);
    for (int i = 0; i < my_auction.num_items; i++) {
        printf("\nCreating item %d...\n", i+1);
        create_item(&my_auction.items[i]);
    }
    display_auction(&my_auction);
    make_bid(&my_auction);
    display_auction(&my_auction);
    return 0;
}