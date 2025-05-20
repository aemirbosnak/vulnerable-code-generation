//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Cryptic
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
    inventory = realloc(inventory, sizeof(product) * (inventory_size + 1));
    inventory[inventory_size].name = strdup(name);
    inventory[inventory_size].quantity = quantity;
    inventory[inventory_size].price = price;
    inventory_size++;
}

void remove_product(char *name) {
    int i;
    for (i = 0; i < inventory_size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            break;
        }
    }
    if (i == inventory_size) {
        printf("Product not found\n");
        return;
    }
    for (; i < inventory_size - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    inventory_size--;
}

void print_inventory() {
    int i;
    for (i = 0; i < inventory_size; i++) {
        printf("%s %d %f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    add_product("Apple", 10, 1.0);
    add_product("Orange", 20, 1.5);
    add_product("Banana", 30, 2.0);
    print_inventory();
    remove_product("Orange");
    print_inventory();
    return 0;
}