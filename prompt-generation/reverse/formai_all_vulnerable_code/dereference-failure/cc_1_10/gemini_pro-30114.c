//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
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

void remove_product(int index) {
    if (index < 0 || index >= inventory_size) {
        return;
    }

    free(inventory[index].name);
    for (int i = index; i < inventory_size - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    inventory_size--;
}

void update_product(int index, char *name, int quantity, float price) {
    if (index < 0 || index >= inventory_size) {
        return;
    }

    free(inventory[index].name);
    inventory[index].name = strdup(name);
    inventory[index].quantity = quantity;
    inventory[index].price = price;
}

void print_inventory() {
    printf("Inventory:\n");
    for (int i = 0; i < inventory_size; i++) {
        printf("%s %d %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    add_product("Apples", 10, 1.0);
    add_product("Oranges", 5, 1.5);
    add_product("Bananas", 7, 1.25);

    print_inventory();

    remove_product(1);

    print_inventory();

    update_product(0, "Grapes", 12, 1.75);

    print_inventory();

    return 0;
}