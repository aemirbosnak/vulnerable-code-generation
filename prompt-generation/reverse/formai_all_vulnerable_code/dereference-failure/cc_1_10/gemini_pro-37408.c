//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Cyberpunk
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
            inventory[i] = inventory[inventory_size - 1];
            inventory_size--;
            break;
        }
    }
}

void list_products() {
    int i;
    for (i = 0; i < inventory_size; i++) {
        printf("%s %d %f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    // Initialize the inventory
    inventory = malloc(0);
    inventory_size = 0;

    // Add some products to the inventory
    add_product("Cyberpunk 2077", 10, 59.99);
    add_product("The Witcher 3: Wild Hunt", 5, 39.99);
    add_product("Grand Theft Auto V", 7, 29.99);

    // List the products in the inventory
    list_products();

    // Remove a product from the inventory
    remove_product("Cyberpunk 2077");

    // List the products in the inventory again
    list_products();

    return 0;
}