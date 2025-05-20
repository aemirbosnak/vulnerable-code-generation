//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char *name;
    int quantity;
    float price;
};

struct inventory {
    struct item items[MAX_ITEMS];
    int num_items;
};

struct inventory *create_inventory() {
    struct inventory *inventory = malloc(sizeof(struct inventory));
    inventory->num_items = 0;
    return inventory;
}

void add_item(struct inventory *inventory, char *name, int quantity, float price) {
    if (inventory->num_items >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }

    inventory->items[inventory->num_items].name = strdup(name);
    inventory->items[inventory->num_items].quantity = quantity;
    inventory->items[inventory->num_items].price = price;
    inventory->num_items++;
}

void print_inventory(struct inventory *inventory) {
    printf("Inventory:\n");
    for (int i = 0; i < inventory->num_items; i++) {
        printf("  %s x%d @ %.2f gold\n", inventory->items[i].name, inventory->items[i].quantity, inventory->items[i].price);
    }
}

void destroy_inventory(struct inventory *inventory) {
    for (int i = 0; i < inventory->num_items; i++) {
        free(inventory->items[i].name);
    }
    free(inventory);
}

int main() {
    struct inventory *inventory = create_inventory();

    add_item(inventory, "Sword", 1, 10.0);
    add_item(inventory, "Shield", 1, 5.0);
    add_item(inventory, "Potion", 5, 2.0);

    print_inventory(inventory);

    destroy_inventory(inventory);

    return 0;
}