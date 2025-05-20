//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for Inventory Item
struct Inventory_Item {
    int item_id;
    char item_name[50];
    int quantity;
    float price;
};

// Define structure for Warehouse
struct Warehouse {
    struct Inventory_Item *items_list;
    int num_items;
};

// Function to add item to the Warehouse
void add_item(struct Warehouse *warehouse, int item_id, char item_name[], int quantity, float price) {
    // Allocate memory for new Inventory Item
    struct Inventory_Item *new_item = (struct Inventory_Item *) malloc(sizeof(struct Inventory_Item));
    
    // Set values for new Inventory Item
    new_item->item_id = item_id;
    strcpy(new_item->item_name, item_name);
    new_item->quantity = quantity;
    new_item->price = price;
    
    // Allocate more memory for new list of Inventory Items
    warehouse->items_list = (struct Inventory_Item *) realloc(warehouse->items_list, (warehouse->num_items + 1) * sizeof(struct Inventory_Item));
    
    // Add new item to list
    warehouse->items_list[warehouse->num_items] = *new_item;
    
    // Increment number of items in Warehouse
    warehouse->num_items++;
    
    printf("Item added successfully.\n\n");
}

// Function to display all items in the Warehouse
void display_items(struct Warehouse warehouse) {
    printf("List of Items in Warehouse:\n");
    
    for (int i = 0; i < warehouse.num_items; i++) {
        struct Inventory_Item item = warehouse.items_list[i];
        
        printf("Item ID: %d\n", item.item_id);
        printf("Item Name: %s\n", item.item_name);
        printf("Quantity: %d\n", item.quantity);
        printf("Price: $%.2f\n\n", item.price);
    }
}

// Function to search for an item in the Warehouse by ID
void search_item(struct Warehouse warehouse, int search_id) {
    int found = 0;
    
    for (int i = 0; i < warehouse.num_items; i++) {
        struct Inventory_Item item = warehouse.items_list[i];
        
        if (item.item_id == search_id) {
            found = 1;
            printf("Item found:\n");
            printf("Item ID: %d\n", item.item_id);
            printf("Item Name: %s\n", item.item_name);
            printf("Quantity: %d\n", item.quantity);
            printf("Price: $%.2f\n\n", item.price);
            break;
        }
    }
    
    if (!found) {
        printf("Item with ID %d not found in Warehouse.\n\n", search_id);
    }
}

// Function to update quantity of an item in the Warehouse by ID
void update_quantity(struct Warehouse *warehouse, int update_id, int new_quantity) {
    int found = 0;
    
    for (int i = 0; i < warehouse->num_items; i++) {
        struct Inventory_Item *item = &(warehouse->items_list[i]);
        
        if (item->item_id == update_id) {
            found = 1;
            item->quantity = new_quantity;
            printf("Quantity of %s updated successfully.\nNew Quantity: %d.\n\n", item->item_name, new_quantity);
            break;
        }
    }
    
    if (!found) {
        printf("Item with ID %d not found in Warehouse.\n\n", update_id);
    }
}

int main() {
    // Initialize empty Warehouse
    struct Warehouse warehouse;
    warehouse.items_list = NULL;
    warehouse.num_items = 0;
    
    // Add some sample items to Warehouse
    add_item(&warehouse, 101, "Pen", 100, 1.50);
    add_item(&warehouse, 102, "Pencil", 200, 0.75);
    add_item(&warehouse, 103, "Eraser", 50, 1.00);
    
    // Display all items in Warehouse
    display_items(warehouse);
    
    // Search for an item in Warehouse by ID
    search_item(warehouse, 102);
    
    // Update quantity of an item in Warehouse by ID
    update_quantity(&warehouse, 101, 50);
    
    // Display all items in Warehouse again to confirm changes
    display_items(warehouse);
    
    // Free allocated memory
    free(warehouse.items_list);
    
    return 0;
}