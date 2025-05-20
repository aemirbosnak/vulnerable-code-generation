//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: medieval
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

Inventory *create_inventory() {
    Inventory *inventory = malloc(sizeof(Inventory));
    inventory->items = malloc(sizeof(Item) * 10);
    inventory->num_items = 0;
    return inventory;
}

void add_item(Inventory *inventory, Item item) {
    inventory->items[inventory->num_items] = item;
    inventory->num_items++;
}

void print_inventory(Inventory *inventory) {
    for (int i = 0; i < inventory->num_items; i++) {
        printf("%s: %d @ %f\n", inventory->items[i].name, inventory->items[i].quantity, inventory->items[i].price);
    }
}

int main() {
    Inventory *inventory = create_inventory();

    Item health_potion = {"Health Potion", 10, 10.0};
    Item mana_potion = {"Mana Potion", 5, 5.0};
    Item sword = {"Sword", 1, 20.0};
    Item shield = {"Shield", 1, 15.0};

    add_item(inventory, health_potion);
    add_item(inventory, mana_potion);
    add_item(inventory, sword);
    add_item(inventory, shield);

    print_inventory(inventory);

    return 0;
}