//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int quantity;
    float price;
} Item;

typedef struct {
    Item *items;
    int num_items;
} Inventory;

Inventory *create_inventory(void);
void add_item_to_inventory(Inventory *inv, Item *item);
void print_inventory(Inventory *inv);
void free_inventory(Inventory *inv);

int main(void) {
    Inventory *inv = create_inventory();

    Item *item1 = malloc(sizeof(Item));
    item1->name = "Sword";
    item1->quantity = 10;
    item1->price = 100.0f;

    Item *item2 = malloc(sizeof(Item));
    item2->name = "Shield";
    item2->quantity = 5;
    item2->price = 50.0f;

    Item *item3 = malloc(sizeof(Item));
    item3->name = "Potion";
    item3->quantity = 20;
    item3->price = 10.0f;

    add_item_to_inventory(inv, item1);
    add_item_to_inventory(inv, item2);
    add_item_to_inventory(inv, item3);

    print_inventory(inv);

    free_inventory(inv);

    return 0;
}

Inventory *create_inventory(void) {
    Inventory *inv = malloc(sizeof(Inventory));
    inv->items = malloc(sizeof(Item) * 10);
    inv->num_items = 0;

    return inv;
}

void add_item_to_inventory(Inventory *inv, Item *item) {
    inv->items[inv->num_items] = *item;
    inv->num_items++;
}

void print_inventory(Inventory *inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->num_items; i++) {
        printf("  %s x %d @ %.2f gp\n", inv->items[i].name, inv->items[i].quantity, inv->items[i].price);
    }
}

void free_inventory(Inventory *inv) {
    for (int i = 0; i < inv->num_items; i++) {
        free(inv->items[i].name);
    }

    free(inv->items);
    free(inv);
}