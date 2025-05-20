//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: Cryptic
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int id;
    char *name;
    int bid;
} Item;

typedef struct {
    int max_id;
    int num_items;
    Item *items;
} Auction;

Auction *create_auction() {
    Auction *auction = malloc(sizeof(Auction));
    auction->max_id = 0;
    auction->num_items = 0;
    auction->items = NULL;
    return auction;
}

void destroy_auction(Auction *auction) {
    for (int i = 0; i < auction->num_items; i++) {
        free(auction->items[i].name);
    }
    free(auction->items);
    free(auction);
}

int add_item(Auction *auction, char *name, int bid) {
    auction->max_id++;
    auction->items = realloc(auction->items, sizeof(Item) * auction->max_id);
    auction->items[auction->num_items].id = auction->max_id;
    auction->items[auction->num_items].name = strdup(name);
    auction->items[auction->num_items].bid = bid;
    auction->num_items++;
    return auction->max_id;
}

void remove_item(Auction *auction, int id) {
    for (int i = 0; i < auction->num_items; i++) {
        if (auction->items[i].id == id) {
            free(auction->items[i].name);
            for (int j = i + 1; j < auction->num_items; j++) {
                auction->items[j - 1] = auction->items[j];
            }
            auction->num_items--;
            break;
        }
    }
}

void place_bid(Auction *auction, int id, int bid) {
    for (int i = 0; i < auction->num_items; i++) {
        if (auction->items[i].id == id) {
            auction->items[i].bid = bid;
            break;
        }
    }
}

int get_max_bid(Auction *auction) {
    int max_bid = 0;
    for (int i = 0; i < auction->num_items; i++) {
        if (auction->items[i].bid > max_bid) {
            max_bid = auction->items[i].bid;
        }
    }
    return max_bid;
}

Item *get_item_with_max_bid(Auction *auction) {
    int max_bid = get_max_bid(auction);
    for (int i = 0; i < auction->num_items; i++) {
        if (auction->items[i].bid == max_bid) {
            return &auction->items[i];
        }
    }
    return NULL;
}

void print_auction(Auction *auction) {
    printf("Auction Results:\n");
    for (int i = 0; i < auction->num_items; i++) {
        printf("Item %d: %s, Bid: %d\n", auction->items[i].id, auction->items[i].name, auction->items[i].bid);
    }
}

int main() {
    Auction *auction = create_auction();

    add_item(auction, "Item 1", 100);
    add_item(auction, "Item 2", 200);
    add_item(auction, "Item 3", 300);

    place_bid(auction, 1, 150);
    place_bid(auction, 3, 350);

    print_auction(auction);

    Item *item = get_item_with_max_bid(auction);
    printf("Item with highest bid: %s, Bid: %d\n", item->name, item->bid);

    destroy_auction(auction);

    return 0;
}