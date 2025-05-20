//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct item {
    int id;
    char *name;
    int quantity;
    float price;
} item;

item *items[MAX_ITEMS];
int num_items = 0;

void add_item(item *i) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Inventory full\n");
        return;
    }

    items[num_items++] = i;
}

void remove_item(item *i) {
    int index = -1;

    for (int j = 0; j < num_items; j++) {
        if (items[j] == i) {
            index = j;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Item not found\n");
        return;
    }

    for (int j = index + 1; j < num_items; j++) {
        items[j - 1] = items[j];
    }

    num_items--;
}

void print_inventory() {
    printf("Inventory:\n");
    for (int j = 0; j < num_items; j++) {
        printf("  %s: %d @ $%.2f\n", items[j]->name, items[j]->quantity, items[j]->price);
    }
}

int main() {
    item *i1 = malloc(sizeof(item));
    i1->id = 1;
    i1->name = "Bottle of water";
    i1->quantity = 10;
    i1->price = 5.00;

    item *i2 = malloc(sizeof(item));
    i2->id = 2;
    i2->name = "Can of beans";
    i2->quantity = 5;
    i2->price = 2.00;

    item *i3 = malloc(sizeof(item));
    i3->id = 3;
    i3->name = "Box of ammo";
    i3->quantity = 1;
    i3->price = 10.00;

    add_item(i1);
    add_item(i2);
    add_item(i3);

    print_inventory();

    remove_item(i2);

    print_inventory();

    return 0;
}