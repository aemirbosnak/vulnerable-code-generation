//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for storing warehouse products
typedef struct product {
    char name[20];
    int id;
    int quantity;
} Product;

// Define a structure for storing a warehouse location
typedef struct location {
    char aisle;
    int shelf;
    int bin;
} Location;

// Define a structure for storing a warehouse inventory item
typedef struct inventoryItem {
    Product *product;
    Location *location;
} InventoryItem;

// Define a function for adding a new product to the warehouse
Product* addProduct(int id, char name[], int quantity) {
    Product *p = (Product*) malloc(sizeof(Product));
    p->id = id;
    strcpy(p->name, name);
    p->quantity = quantity;
    return p;
}

// Define a function for adding a new location to the warehouse
Location* addLocation(char aisle, int shelf, int bin) {
    Location *l = (Location*) malloc(sizeof(Location));
    l->aisle = aisle;
    l->shelf = shelf;
    l->bin = bin;
    return l;
}

// Define a function for creating a new inventory item
InventoryItem* createInventoryItem(Product *p, Location *l) {
    InventoryItem *item = (InventoryItem*) malloc(sizeof(InventoryItem));
    item->product = p;
    item->location = l;
    return item;
}

// Main function to test the Warehouse Management System
int main() {
    // Create some products
    Product *p1 = addProduct(1, "Widget A", 100);
    Product *p2 = addProduct(2, "Widget B", 50);
    Product *p3 = addProduct(3, "Widget C", 25);

    // Create some locations
    Location *l1 = addLocation('A', 1, 1);
    Location *l2 = addLocation('B', 2, 1);
    Location *l3 = addLocation('C', 3, 1);

    // Create some inventory items
    InventoryItem *item1 = createInventoryItem(p1, l1);
    InventoryItem *item2 = createInventoryItem(p2, l2);
    InventoryItem *item3 = createInventoryItem(p3, l3);

    // Print out the inventory
    printf("Inventory:\n");
    printf("%s (%d units) - aisle %c, shelf %d, bin %d\n", item1->product->name, item1->product->quantity, item1->location->aisle, item1->location->shelf, item1->location->bin);
    printf("%s (%d units) - aisle %c, shelf %d, bin %d\n", item2->product->name, item2->product->quantity, item2->location->aisle, item2->location->shelf, item2->location->bin);
    printf("%s (%d units) - aisle %c, shelf %d, bin %d\n", item3->product->name, item3->product->quantity, item3->location->aisle, item3->location->shelf, item3->location->bin);

    // Clean up memory
    free(p1);
    free(p2);
    free(p3);
    free(l1);
    free(l2);
    free(l3);
    free(item1);
    free(item2);
    free(item3);

    return 0;
}