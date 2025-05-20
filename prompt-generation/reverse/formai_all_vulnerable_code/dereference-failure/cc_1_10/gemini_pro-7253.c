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
int num_products;

void add_product(char *name, int quantity, float price) {
    inventory = realloc(inventory, (num_products + 1) * sizeof(product));
    strcpy(inventory[num_products].name, name);
    inventory[num_products].quantity = quantity;
    inventory[num_products].price = price;
    num_products++;
}

void remove_product(char *name) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            break;
        }
    }
    if (i < num_products) {
        memmove(&inventory[i], &inventory[i + 1], (num_products - i - 1) * sizeof(product));
        num_products--;
    }
}

void update_product(char *name, int quantity, float price) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity = quantity;
            inventory[i].price = price;
            break;
        }
    }
}

void print_inventory() {
    int i;
    printf("Product Inventory:\n");
    for (i = 0; i < num_products; i++) {
        printf("%s (%d units, $%.2f)\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    add_product("Apple", 10, 0.50);
    add_product("Orange", 15, 0.75);
    add_product("Banana", 20, 1.00);
    add_product("Grape", 25, 1.25);
    add_product("Strawberry", 30, 1.50);

    print_inventory();

    remove_product("Banana");

    update_product("Apple", 15, 0.60);

    print_inventory();

    return 0;
}