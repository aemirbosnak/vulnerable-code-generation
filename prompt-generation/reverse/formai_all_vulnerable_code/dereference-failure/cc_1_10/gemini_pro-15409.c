//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: artistic
// Welcome to the Warehouse of Wonders, a symphony of storage and order!
// Our shelves, a canvas of organization, hold treasures waiting to be found.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our warehouse, a masterpiece of efficiency
typedef struct Warehouse {
    char name[50];     // The name of our warehouse, a beacon of identity
    int numItems;      // The number of items within, a symphony of inventory
    char items[50][50]; // The items themselves, each a brushstroke on our canvas
} Warehouse;

// A new warehouse emerges from the void, ready to be filled with wonders
Warehouse* createWarehouse(char* name) {
    Warehouse* warehouse = malloc(sizeof(Warehouse)); // Allocating memory for our warehouse, a space for wonders
    strcpy(warehouse->name, name); // Setting its name, a proud declaration of its existence
    warehouse->numItems = 0; // Initially, it's an empty canvas, waiting to be painted with items
    return warehouse; // Returning our masterpiece, ready to be stocked
}

// Adding an item to our warehouse, a new melody in the symphony of inventory
void addItem(Warehouse* warehouse, char* item) {
    strcpy(warehouse->items[warehouse->numItems++], item); // Adding the item to our collection, a stroke on the canvas
}

// Removing an item from our warehouse, a note fading from the symphony
void removeItem(Warehouse* warehouse, char* item) {
    int index = -1; // Initializing the index to a non-existent value, a silent note in the symphony
    for (int i = 0; i < warehouse->numItems; i++) { // Traversing the items, a search for the missing note
        if (strcmp(warehouse->items[i], item) == 0) { // If we found the item, its index is our target
            index = i;
            break; // We break free from the loop, our search complete
        }
    }
    if (index != -1) { // If the index is valid, the item exists in our symphony
        for (int i = index; i < warehouse->numItems - 1; i++) { // Moving items to fill the void, a rearrangement in the harmony
            strcpy(warehouse->items[i], warehouse->items[i + 1]);
        }
        warehouse->numItems--; // Decreasing the count, a note fading into silence
    }
}

// Printing our warehouse, a display of our symphony of inventory
void printWarehouse(Warehouse* warehouse) {
    printf("Warehouse: %s\n", warehouse->name); // Announcing the warehouse's name, the conductor of our symphony
    printf("Items:\n"); // Declaring the list of items, the notes in our composition
    for (int i = 0; i < warehouse->numItems; i++) { // Traversing the items, a journey through the symphony
        printf(" - %s\n", warehouse->items[i]); // Printing each item, a note echoing through the warehouse
    }
    printf("\n"); // A pause in the symphony, a moment to appreciate its beauty
}

// The main function, our conductor leading the orchestra of code
int main() {
    Warehouse* warehouse1 = createWarehouse("Warehouse 1"); // Creating our first warehouse, a stage for wonders
    Warehouse* warehouse2 = createWarehouse("Warehouse 2"); // Creating our second warehouse, a symphony in itself
    addItem(warehouse1, "Item 1"); // Adding an item to warehouse 1, a new note in its symphony
    addItem(warehouse1, "Item 2"); // Adding another item, a harmony of inventory
    addItem(warehouse2, "Item 3"); // Adding an item to warehouse 2, a different melody
    addItem(warehouse2, "Item 4"); // Another item, a richer composition
    removeItem(warehouse1, "Item 1"); // Removing an item from warehouse 1, a note fading from its symphony
    printWarehouse(warehouse1); // Printing warehouse 1, showcasing its updated inventory
    printWarehouse(warehouse2); // Printing warehouse 2, revealing its unique melody
    return 0; // The symphony ends, but the warehouses remain, echoes of our artistic endeavor
}