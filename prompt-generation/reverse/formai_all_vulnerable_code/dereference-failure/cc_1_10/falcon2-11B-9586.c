//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PRODUCTS 1000

typedef struct {
    char name[100];
    int quantity;
} Product;

typedef struct {
    Product* products;
    int size;
    int capacity;
} Inventory;

Inventory createInventory() {
    Inventory inventory;
    inventory.products = (Product*) malloc(MAX_PRODUCTS * sizeof(Product));
    inventory.size = 0;
    inventory.capacity = MAX_PRODUCTS;
    return inventory;
}

void destroyInventory(Inventory* inventory) {
    free(inventory->products);
    inventory->products = NULL;
    inventory->size = 0;
    inventory->capacity = 0;
}

void addProductToInventory(Inventory* inventory, const char* name, int quantity) {
    if (inventory->size >= inventory->capacity) {
        fprintf(stderr, "Inventory is full!\n");
        return;
    }

    Product* product = &inventory->products[inventory->size];
    strcpy(product->name, name);
    product->quantity = quantity;

    inventory->size++;
}

void removeProductFromInventory(Inventory* inventory, const char* name) {
    for (int i = 0; i < inventory->size; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            inventory->size--;
            for (int j = i; j < inventory->size; j++) {
                inventory->products[j] = inventory->products[j+1];
            }
            return;
        }
    }

    fprintf(stderr, "Product not found in inventory!\n");
}

void printInventory(Inventory inventory) {
    printf("Inventory:\n");
    for (int i = 0; i < inventory.size; i++) {
        printf("Product: %s, Quantity: %d\n", inventory.products[i].name, inventory.products[i].quantity);
    }
}

int main() {
    Inventory inventory = createInventory();

    addProductToInventory(&inventory, "Apple", 10);
    addProductToInventory(&inventory, "Banana", 5);
    addProductToInventory(&inventory, "Orange", 20);

    printInventory(inventory);

    removeProductFromInventory(&inventory, "Banana");

    printInventory(inventory);

    destroyInventory(&inventory);

    return 0;
}