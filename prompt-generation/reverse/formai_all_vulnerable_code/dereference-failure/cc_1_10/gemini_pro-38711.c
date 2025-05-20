//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the inventory
#define MAX_ITEMS 100

// Define the structure of an item in the inventory
typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

// Define the structure of the inventory database
typedef struct {
    Item items[MAX_ITEMS];
    int numItems;
} Inventory;

// Create a new inventory database
Inventory* createInventory() {
    Inventory* inventory = (Inventory*) malloc(sizeof(Inventory));
    inventory->numItems = 0;
    return inventory;
}

// Add an item to the inventory
void addItem(Inventory* inventory, Item item) {
    if (inventory->numItems < MAX_ITEMS) {
        inventory->items[inventory->numItems] = item;
        inventory->numItems++;
    }
}

// Remove an item from the inventory
void removeItem(Inventory* inventory, char* name) {
    int i;
    for (i = 0; i < inventory->numItems; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            inventory->items[i] = inventory->items[inventory->numItems - 1];
            inventory->numItems--;
            break;
        }
    }
}

// Find an item in the inventory
Item* findItem(Inventory* inventory, char* name) {
    int i;
    for (i = 0; i < inventory->numItems; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            return &inventory->items[i];
        }
    }
    return NULL;
}

// Print the inventory
void printInventory(Inventory* inventory) {
    int i;
    for (i = 0; i < inventory->numItems; i++) {
        printf("%s %d %f\n", inventory->items[i].name, inventory->items[i].quantity, inventory->items[i].price);
    }
}

//Sherlock Holmes Mystery: Finding the stolen medicine
char* stolenMedicine = "Codeine";

void solveMystery(Inventory* inventory) {
    Item* stolenItem = findItem(inventory, stolenMedicine);
    if (stolenItem == NULL) {
        printf("The stolen medicine was not found in the inventory.\n");
    } else {
        printf("The stolen medicine is %s, which has a quantity of %d and a price of %f.\n", stolenMedicine, stolenItem->quantity, stolenItem->price);
    }
}

int main() {
    // Create an inventory database
    Inventory* inventory = createInventory();

    // Add some items to the inventory
    addItem(inventory, (Item) {"Aspirin", 100, 0.5});
    addItem(inventory, (Item) {"Ibuprofen", 50, 0.75});
    addItem(inventory, (Item) {"Codeine", 20, 1.0});

    // Print the inventory
    printf("Inventory:\n");
    printInventory(inventory);

    // Solve the mystery
    solveMystery(inventory);

    return 0;
}