//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDS 100

typedef struct {
    int id;
    char *name;
    float reserve_price;
} Item;

typedef struct {
    int id;
    int item_id;
    float amount;
} Bid;

Item items[MAX_ITEMS];
Bid bids[MAX_BIDS];
int num_items = 0;
int num_bids = 0;

void add_item(char *name, float reserve_price) {
    items[num_items].id = num_items + 1;
    items[num_items].name = strdup(name);
    items[num_items].reserve_price = reserve_price;
    num_items++;
}

void add_bid(int item_id, float amount) {
    bids[num_bids].id = num_bids + 1;
    bids[num_bids].item_id = item_id;
    bids[num_bids].amount = amount;
    num_bids++;
}

void print_items() {
    for (int i = 0; i < num_items; i++) {
        printf("Item %d: %s (reserve price: $%.2f)\n", items[i].id, items[i].name, items[i].reserve_price);
    }
}

void print_bids() {
    for (int i = 0; i < num_bids; i++) {
        printf("Bid %d: Item %d, $%.2f\n", bids[i].id, bids[i].item_id, bids[i].amount);
    }
}

int main() {
    add_item("Painting", 1000.0);
    add_item("Sculpture", 500.0);
    add_item("Vase", 200.0);

    add_bid(1, 1100.0);
    add_bid(2, 600.0);
    add_bid(3, 250.0);

    print_items();
    print_bids();

    return 0;
}