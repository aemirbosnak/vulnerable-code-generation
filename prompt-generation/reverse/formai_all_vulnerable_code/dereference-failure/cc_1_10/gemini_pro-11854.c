//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct product {
    int id;
    char *name;
    float price;
    int quantity;
} product;

product *inventory;
int inventorySize = 0;

void addItem(int id, char *name, float price, int quantity) {
    inventory = realloc(inventory, (inventorySize + 1) * sizeof(product));
    product p = {id, name, price, quantity};
    inventory[inventorySize++] = p;
}

void removeItem(int id) {
    for (int i = 0; i < inventorySize; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < inventorySize - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            inventorySize--;
            break;
        }
    }
}

void updateItem(int id, char *name, float price, int quantity) {
    for (int i = 0; i < inventorySize; i++) {
        if (inventory[i].id == id) {
            inventory[i].name = name;
            inventory[i].price = price;
            inventory[i].quantity = quantity;
            break;
        }
    }
}

void printInventory() {
    printf("Inventory:\n");
    for (int i = 0; i < inventorySize; i++) {
        product p = inventory[i];
        printf("id: %d, name: %s, price: %f, quantity: %d\n", p.id, p.name, p.price, p.quantity);
    }
}

int main() {
    // Add some items to the inventory
    addItem(1, "Apple", 1.00, 10);
    addItem(2, "Orange", 1.50, 20);
    addItem(3, "Banana", 0.75, 30);

    // Print the inventory
    printInventory();

    // Remove an item from the inventory
    removeItem(2);

    // Update an item in the inventory
    updateItem(1, "Apple", 1.20, 15);

    // Print the inventory again
    printInventory();

    free(inventory);
    return 0;
}