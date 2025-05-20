//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char *name;
    int quantity;
    float price;
};

struct product *inventory = NULL;
int inventory_size = 0;

void add_product(char *name, int quantity, float price) {
    inventory = realloc(inventory, (inventory_size + 1) * sizeof(struct product));
    inventory[inventory_size].name = strdup(name);
    inventory[inventory_size].quantity = quantity;
    inventory[inventory_size].price = price;
    inventory_size++;
}

void remove_product(char *name) {
    int i;
    for (i = 0; i < inventory_size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            free(inventory[i].name);
            inventory_size--;
            memmove(inventory + i, inventory + i + 1, (inventory_size - i) * sizeof(struct product));
            return;
        }
    }
}

void update_product(char *name, int quantity, float price) {
    int i;
    for (i = 0; i < inventory_size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity = quantity;
            inventory[i].price = price;
            return;
        }
    }
}

void print_inventory() {
    int i;
    for (i = 0; i < inventory_size; i++) {
        printf("%s: %d (%f)\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    add_product("Apple", 100, 0.50);
    add_product("Orange", 50, 0.75);
    add_product("Banana", 25, 1.00);

    remove_product("Orange");

    update_product("Apple", 75, 0.60);

    print_inventory();

    return 0;
}