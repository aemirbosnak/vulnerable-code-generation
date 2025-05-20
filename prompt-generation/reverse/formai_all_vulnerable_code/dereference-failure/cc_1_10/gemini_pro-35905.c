//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: shocked
// WAREHOUSE MANAGEMENT INTERFACE - READY FOR SHOCKING INVENTORY CONTROL!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Warehouse: a haven for goods, ready for the shock of management
typedef struct Warehouse {
    int num_items;                  // Number of items gracing our shelves
    char **item_names;             // Array of names, each a shock to remember
    int *item_quantities;           // Quantities, jolting our minds with availability
    float *item_prices;             // Prices, shocking our pockets with their impact
} Warehouse;

// Create a warehouse, electrifying the inventory scene
Warehouse* create_warehouse(int num_items) {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->num_items = num_items;
    warehouse->item_names = malloc(sizeof(char *) * num_items);
    warehouse->item_quantities = malloc(sizeof(int) * num_items);
    warehouse->item_prices = malloc(sizeof(float) * num_items);
    return warehouse;
}

// Destroy the warehouse, unleashing a shockwave of clearance
void destroy_warehouse(Warehouse *warehouse) {
    for (int i = 0; i < warehouse->num_items; i++) {
        free(warehouse->item_names[i]);
    }
    free(warehouse->item_names);
    free(warehouse->item_quantities);
    free(warehouse->item_prices);
    free(warehouse);
}

// Add an item to the warehouse, jolting the inventory with a new arrival
void add_item(Warehouse *warehouse, char *name, int quantity, float price) {
    warehouse->item_names[warehouse->num_items] = malloc(strlen(name) + 1);
    strcpy(warehouse->item_names[warehouse->num_items], name);
    warehouse->item_quantities[warehouse->num_items] = quantity;
    warehouse->item_prices[warehouse->num_items] = price;
    warehouse->num_items++;
}

// Remove an item from the warehouse, sending shockwaves through the inventory
void remove_item(Warehouse *warehouse, char *name) {
    int index = -1;
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->item_names[i], name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return; // No such item, no shock to inventory
    }
    for (int i = index + 1; i < warehouse->num_items; i++) {
        warehouse->item_names[i - 1] = warehouse->item_names[i];
        warehouse->item_quantities[i - 1] = warehouse->item_quantities[i];
        warehouse->item_prices[i - 1] = warehouse->item_prices[i];
    }
    free(warehouse->item_names[warehouse->num_items - 1]);
    warehouse->num_items--;
}

// Print the warehouse inventory, shocking with item details
void print_warehouse(Warehouse *warehouse) {
    printf("Warehouse Inventory:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("Item: %s, Quantity: %d, Price: %.2f\n",
            warehouse->item_names[i], warehouse->item_quantities[i], warehouse->item_prices[i]);
    }
}

int main() {
    // Create a warehouse, setting the stage for inventory shock therapy
    Warehouse *warehouse = create_warehouse(0);
    
    // Add items, sending ripples of excitement through the inventory
    add_item(warehouse, "Electric Toothbrush", 50, 29.99);
    add_item(warehouse, "Smartwatch", 75, 199.99);
    add_item(warehouse, "Robot Vacuum", 25, 399.99);

    // Remove an item, causing a shockwave of deletion
    remove_item(warehouse, "Robot Vacuum");
    
    // Print the warehouse inventory, revealing the transformed landscape
    print_warehouse(warehouse);
    
    // Destroy the warehouse, unleashing a final shock of obliteration
    destroy_warehouse(warehouse);
    
    return 0;
}