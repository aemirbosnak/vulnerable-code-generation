//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char *name;
    int quantity;
    float price;
} Item;

Item *inventory;
int inventorySize = 0;

void addToInventory(char *name, int quantity, float price) {
    inventory = realloc(inventory, (inventorySize + 1) * sizeof(Item));
    inventory[inventorySize].name = strdup(name);
    inventory[inventorySize].quantity = quantity;
    inventory[inventorySize].price = price;
    inventorySize++;
}

void removeFromInventory(char *name, int quantity) {
    for (int i = 0; i < inventorySize; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity -= quantity;
            if (inventory[i].quantity <= 0) {
                free(inventory[i].name);
                for (int j = i; j < inventorySize - 1; j++) {
                    inventory[j] = inventory[j + 1];
                }
                inventorySize--;
            }
            return;
        }
    }
}

void printInventory() {
    printf("Inventory:\n");
    for (int i = 0; i < inventorySize; i++) {
        printf("  %s: %d @ $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void findItem(char *name) {
    for (int i = 0; i < inventorySize; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Found %s: %d @ $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Item not found.\n");
}

int main() {
    // Let's build up the inventory.
    addToInventory("Aspirin", 100, 2.99);
    addToInventory("Band-Aids", 500, 3.99);
    addToInventory("Cough Syrup", 10, 5.99);
    addToInventory("First Aid Kit", 20, 19.99);
    addToInventory("Gauze", 50, 4.99);

    // A mysterious buyer comes in and wants to purchase some items.
    removeFromInventory("Aspirin", 50);
    removeFromInventory("Band-Aids", 100);
    removeFromInventory("Cough Syrup", 5);

    // Let's check the inventory.
    printInventory();

    // The buyer asks if we have any "Gauze".
    findItem("Gauze");

    return 0;
}