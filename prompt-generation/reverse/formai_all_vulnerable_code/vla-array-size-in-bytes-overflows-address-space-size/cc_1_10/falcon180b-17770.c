//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char name[50];
    int bid;
} Bidder;

typedef struct {
    char name[50];
    int starting_price;
    int current_price;
    Bidder highest_bidder;
} Item;

void create_item(Item *item) {
    printf("Enter the name of the item: ");
    scanf("%s", item->name);

    printf("Enter the starting price of the item: ");
    scanf("%d", &item->starting_price);

    item->current_price = item->starting_price;
    item->highest_bidder.id = -1;
    item->highest_bidder.bid = 0;
}

void create_bidder(Bidder *bidder) {
    printf("Enter your name: ");
    scanf("%s", bidder->name);

    srand(time(NULL));
    bidder->id = rand() % 1000;
}

void place_bid(Item *item, Bidder *bidder) {
    printf("%s has placed a bid of $%d\n", bidder->name, item->current_price);

    if (item->highest_bidder.id == -1 || bidder->id > item->highest_bidder.id) {
        item->highest_bidder = *bidder;
        item->current_price += 10;
    }
}

void display_item(Item item) {
    printf("Item name: %s\n", item.name);
    printf("Starting price: $%d\n", item.starting_price);
    printf("Current price: $%d\n", item.current_price);
    printf("Highest bidder: %s ($%d)\n", item.highest_bidder.name, item.highest_bidder.bid);
}

int main() {
    Item item;
    create_item(&item);

    int num_bidders;
    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    Bidder bidders[num_bidders];
    for (int i = 0; i < num_bidders; i++) {
        create_bidder(&bidders[i]);
    }

    int highest_bid = 0;
    for (int i = 0; i < num_bidders; i++) {
        place_bid(&item, &bidders[i]);

        if (item.highest_bidder.id == bidders[i].id) {
            highest_bid = item.highest_bidder.bid;
        }
    }

    printf("The highest bid is $%d\n", highest_bid);

    return 0;
}