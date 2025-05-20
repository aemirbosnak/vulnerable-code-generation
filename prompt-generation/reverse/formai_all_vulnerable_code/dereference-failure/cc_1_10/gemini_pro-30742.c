//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *name;
    int price;
} Item;

typedef struct {
    Item *items;
    int num_items;
} Auction;

Auction *create_auction(int num_items) {
    Auction *auction = malloc(sizeof(Auction));
    auction->items = malloc(sizeof(Item) * num_items);
    auction->num_items = num_items;
    return auction;
}

void add_item(Auction *auction, char *name, int price) {
    auction->items[auction->num_items].name = malloc(strlen(name) + 1);
    strcpy(auction->items[auction->num_items].name, name);
    auction->items[auction->num_items].price = price;
    auction->num_items++;
}

void print_auction(Auction *auction) {
    for (int i = 0; i < auction->num_items; i++) {
        printf("%s: $%d\n", auction->items[i].name, auction->items[i].price);
    }
}

bool is_valid_bid(Auction *auction, int item_index, int bid) {
    return bid > auction->items[item_index].price;
}

void place_bid(Auction *auction, int item_index, char *bidder, int bid) {
    if (!is_valid_bid(auction, item_index, bid)) {
        printf("Invalid bid: bid must be higher than current price\n");
        return;
    }

    auction->items[item_index].price = bid;
    printf("%s has placed a bid of $%d on %s\n", bidder, bid, auction->items[item_index].name);
}

int main() {
    Auction *auction = create_auction(5);
    add_item(auction, "Painting", 100);
    add_item(auction, "Sculpture", 200);
    add_item(auction, "Vase", 300);
    add_item(auction, "Clock", 400);
    add_item(auction, "Lamp", 500);

    print_auction(auction);

    place_bid(auction, 0, "Alice", 120);
    place_bid(auction, 2, "Bob", 320);
    place_bid(auction, 4, "Carol", 520);

    print_auction(auction);

    return 0;
}