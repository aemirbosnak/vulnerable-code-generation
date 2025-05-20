//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Cryptic
#include <stdlib.h>
#include <stdio.h>

typedef struct _product {
    char name[256];
    int quantity;
    float price;
} product;

product *inventory;
int inventory_size;

void init_inventory(int size) {
    inventory = malloc(sizeof(product) * size);
    inventory_size = size;
}

void add_product(char *name, int quantity, float price) {
    if (inventory_size <= 0) {
        init_inventory(10);
    }
    int i;
    for (i = 0; i < inventory_size; i++) {
        if (inventory[i].name[0] == '\0') {
            strcpy(inventory[i].name, name);
            inventory[i].quantity = quantity;
            inventory[i].price = price;
            return;
        }
    }
    inventory_size *= 2;
    inventory = realloc(inventory, sizeof(product) * inventory_size);
    add_product(name, quantity, price);
}

void remove_product(char *name) {
    int i;
    for (i = 0; i < inventory_size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].name[0] = '\0';
            return;
        }
    }
}

product *get_product(char *name) {
    int i;
    for (i = 0; i < inventory_size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return &inventory[i];
        }
    }
    return NULL;
}

void print_inventory() {
    int i;
    for (i = 0; i < inventory_size; i++) {
        if (inventory[i].name[0] != '\0') {
            printf("%s: %d @ $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

int main() {
    init_inventory(0);
    add_product("Apple", 10, 1.0);
    add_product("Orange", 20, 2.0);
    add_product("Banana", 30, 3.0);
    print_inventory();
    remove_product("Orange");
    print_inventory();
    product *apple = get_product("Apple");
    if (apple != NULL) {
        printf("Apple: %d @ $%.2f\n", apple->quantity, apple->price);
    }
    return 0;
}