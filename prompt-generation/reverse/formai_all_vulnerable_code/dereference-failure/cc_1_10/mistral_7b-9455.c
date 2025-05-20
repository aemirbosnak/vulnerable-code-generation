//MISTRAL-7B DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Bid {
    char name[50];
    int bid;
} Bid;

typedef struct Item {
    char name[50];
    int reserve_price;
    int current_bid;
    int num_bids;
    Bid *bids;
} Item;

void print_item(Item *item) {
    printf("\n------------------------\n");
    printf("| %s |\n", item->name);
    printf("|------------------------|\n");
    printf("| Current Bid: %d |\n", item->current_bid);
    printf("|------------------------|\n");
    printf("| Reserver Price: %d |\n", item->reserve_price);
    printf("|------------------------|\n");
    printf("| Number of Bids: %d |\n", item->num_bids);
    printf("|------------------------|\n");
}

void add_bid(Item *item, char *name, int bid) {
    Bid new_bid = {name, bid};
    if (item->num_bids == 0) {
        item->bids = malloc(sizeof(Bid));
        item->bids[0] = new_bid;
        item->num_bids++;
        item->current_bid = bid;
    } else {
        int i;
        for (i = 0; i < item->num_bids; i++) {
            if (item->bids[i].bid <= bid) {
                for (int j = item->num_bids; j > i; j--) {
                    item->bids[j] = item->bids[j - 1];
                }
                item->bids[i] = new_bid;
                item->num_bids++;
                item->current_bid = bid;
                break;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    Item item = {"Apple", 10, 0, 0, NULL};
    print_item(&item);

    int num_bids;
    char name[50];
    int bid;

    for (int i = 0; i < 5; i++) {
        printf("Bidder %d: ", i + 1);
        scanf("%s %d", name, &bid);

        add_bid(&item, name, bid);
        print_item(&item);

        num_bids = item.num_bids;
        if (num_bids > 4 && item.current_bid >= item.reserve_price) {
            printf("\nSold to %s for %d!\n", item.bids[num_bids - 1].name, item.current_bid);
            break;
        }

        if (rand() % 2) {
            printf("\nOops! An error occurred. Please try again.\n");
            i--;
        }
    }

    free(item.bids);

    return 0;
}