//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} product;

product *inventory;
int inventory_size = 0;

void add_product(char *name, int quantity, float price) {
    inventory = realloc(inventory, (inventory_size + 1) * sizeof(product));
    strcpy(inventory[inventory_size].name, name);
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

    if (i < inventory_size) {
        for (int j = i; j < inventory_size - 1; j++) {
            inventory[j] = inventory[j + 1];
        }
        inventory_size--;
    }
}

void update_product(char *name, int quantity, float price) {
    int i;
    for (i = 0; i < inventory_size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            break;
        }
    }

    if (i < inventory_size) {
        inventory[i].quantity = quantity;
        inventory[i].price = price;
    }
}

void print_inventory() {
    printf("Inventory:\n");
    for (int i = 0; i < inventory_size; i++) {
        printf("%s %d %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    add_product("Apple", 10, 1.0);
    add_product("Banana", 20, 1.5);
    add_product("Orange", 30, 2.0);

    print_inventory();

    remove_product("Banana");

    print_inventory();

    update_product("Apple", 15, 1.2);

    print_inventory();

    return 0;
}