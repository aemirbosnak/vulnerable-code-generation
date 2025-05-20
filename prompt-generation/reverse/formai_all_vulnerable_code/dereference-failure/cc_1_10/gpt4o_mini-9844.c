//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float weight;
} WarehouseItem;

typedef struct {
    WarehouseItem items[MAX_ITEMS];
    int itemCount;
} Warehouse;

Warehouse* createWarehouse() {
    Warehouse* w = (Warehouse*)malloc(sizeof(Warehouse));
    w->itemCount = 0;
    return w;
}

void addItem(Warehouse* warehouse, const char* name, int quantity, float weight) {
    if (warehouse->itemCount < MAX_ITEMS) {
        strcpy(warehouse->items[warehouse->itemCount].name, name);
        warehouse->items[warehouse->itemCount].quantity = quantity;
        warehouse->items[warehouse->itemCount].weight = weight;
        warehouse->itemCount++;
        printf("Added item: %s, Quantity: %d, Weight: %.2f\n", name, quantity, weight);
    } else {
        printf("Warehouse is full! Unable to add item: %s\n", name);
    }
}

void removeItem(Warehouse* warehouse, const char* name) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Removed item: %s\n", name);
            warehouse->items[i] = warehouse->items[warehouse->itemCount - 1]; // replace with last item
            warehouse->itemCount--;
            return;
        }
    }
    printf("Item %s not found!\n", name);
}

void displayItems(Warehouse* warehouse) {
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("Item %d: %s, Quantity: %d, Weight: %.2f\n", 
                i + 1, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].weight);
    }
}

float calculateTotalWeight(Warehouse* warehouse) {
    float totalWeight = 0.0;
    for (int i = 0; i < warehouse->itemCount; i++) {
        totalWeight += warehouse->items[i].weight * warehouse->items[i].quantity;
    }
    return totalWeight;
}

void cleanWarehouse(Warehouse* warehouse) {
    free(warehouse);
    printf("Warehouse cleaned from the remnants of the past!\n");
}

int main() {
    Warehouse* warehouse = createWarehouse();
    printf("Welcome to the Post-Apocalyptic Warehouse Management System\n");
    
    addItem(warehouse, "Canned Beans", 50, 0.5);
    addItem(warehouse, "Water Bottles", 100, 0.3);
    addItem(warehouse, "First Aid Kit", 10, 1.2);
    
    displayItems(warehouse);
    
    printf("Total Weight: %.2f kg\n", calculateTotalWeight(warehouse));
    
    removeItem(warehouse, "Canned Beans");
    displayItems(warehouse);
    
    addItem(warehouse, "Survival Knife", 5, 0.8);
    displayItems(warehouse);
    
    printf("Total Weight: %.2f kg\n", calculateTotalWeight(warehouse));
    
    cleanWarehouse(warehouse);
    return 0;
}