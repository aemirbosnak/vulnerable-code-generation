//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int quantity;
    float price;
} product;

product *inventory;
int inventory_size = 0;

void add_product(char *name, int quantity, float price) {
    inventory = realloc(inventory, (inventory_size + 1) * sizeof(product));
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
            memmove(&inventory[i], &inventory[i + 1], (inventory_size - i) * sizeof(product));
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
        printf("%s %d %f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    add_product("Apple", 10, 1.00);
    add_product("Orange", 5, 1.50);
    add_product("Banana", 15, 2.00);

    print_inventory();

    remove_product("Orange");

    print_inventory();

    update_product("Apple", 20, 1.25);

    print_inventory();

    return 0;
}