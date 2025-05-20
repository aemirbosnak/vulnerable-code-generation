//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine *inventory;
int inventorySize = 0;

void addMedicine(Medicine medicine) {
    inventory = realloc(inventory, (inventorySize + 1) * sizeof(Medicine));
    inventory[inventorySize++] = medicine;
}

void printInventory() {
    printf("Our Love Potion Inventory:\n");
    for (int i = 0; i < inventorySize; i++) {
        printf("%s: %d units, $%.2f each\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void sellMedicine(char *name, int quantity) {
    for (int i = 0; i < inventorySize; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            if (inventory[i].quantity >= quantity) {
                inventory[i].quantity -= quantity;
                printf("Sold %d units of %s for a total of $%.2f\n", quantity, name, quantity * inventory[i].price);
            } else {
                printf("Sorry, we don't have that much %s in stock\n", name);
            }
            return;
        }
    }
    printf("Sorry, we don't have that medicine in stock\n");
}

int main() {
    // Initialize our inventory with some love potions
    addMedicine((Medicine) {"Cupid's Arrow", 10, 10.00});
    addMedicine((Medicine) {"Love Potion No. 9", 5, 20.00});
    addMedicine((Medicine) {"Eternal Flame", 3, 30.00});

    // Print our inventory
    printInventory();

    // Sell some love potions
    sellMedicine("Cupid's Arrow", 2);
    sellMedicine("Love Potion No. 9", 1);

    // Print our inventory again
    printInventory();

    return 0;
}