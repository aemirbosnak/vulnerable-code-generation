//FormAI DATASET v1.0 Category: Digital Auction System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char *name;
    int price;
    int remaining_time;
} Item;

Item *getItem(char *name, int price, int remaining_time) {
    Item *item = (Item *)malloc(sizeof(Item));
    item->name = strdup(name);
    item->price = price;
    item->remaining_time = remaining_time;
    return item;
}

int main() {
    Item *items[3];
    items[0] = getItem("iPhone X", 1000, 60);
    items[1] = getItem("Macbook Pro", 1500, 120);
    items[2] = getItem("Samsung TV", 800, 180);

    int current_bid[3] = {0};
    int bidder_id[3] = {0};

    int current_time = 0;

    while (current_time <= 180) {
        printf("Current Time: %d\n", current_time);

        for (int i = 0; i < 3; i++) {
            if (current_bid[i] == 0 && items[i]->remaining_time > 0) {
                printf("%s is available for auction. Starting price is %d.\n", items[i]->name, items[i]->price);
            } else if (current_bid[i] > 0 && items[i]->remaining_time > 0) {
                printf("%s is being auctioned. Current bid is %d by bidder %d. Remaining time: %d seconds.\n", items[i]->name, current_bid[i], bidder_id[i], items[i]->remaining_time);
            } else {
                printf("%s is no longer available for auction.\n", items[i]->name);
            }
        }

        int choice, bid;
        printf("Enter 1 to bid or 2 to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the item number you want to bid for: ");
            scanf("%d", &choice);
            printf("Enter your bid: ");
            scanf("%d", &bid);

            if (bid > current_bid[choice-1] && items[choice-1]->remaining_time > 0) {
                current_bid[choice-1] = bid;
                bidder_id[choice-1] = rand() % 1000 + 1;
                printf("Bid successful! You are now the highest bidder for %s with %d. Your bidder id is %d.\n", items[choice-1]->name, bid, bidder_id[choice-1]);
            } else {
                printf("Bid unsuccessful! Please try again with a higher bid.\n");
            }
        } else if (choice == 2) {
            break;
        }

        printf("\n");
        current_time++;
        for (int i = 0; i < 3; i++) {
            if (items[i]->remaining_time > 0) {
                items[i]->remaining_time--;
            }
        }
    }

    printf("Auction has ended.\n");
    printf("Final bids:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: Highest bid is %d by bidder %d.\n", items[i]->name, current_bid[i], bidder_id[i]);
    }

    return 0;
}