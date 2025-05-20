//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Goods types
typedef enum {
    GOODS_FOOD,
    GOODS_WEAPON,
    GOODS_ARMOR,
    GOODS_MISC
} GoodsType;

// Goods item
typedef struct {
    int id;
    char *name;
    GoodsType type;
    int quantity;
} GoodsItem;

// Warehouse
typedef struct {
    GoodsItem *items;
    int size;
    int capacity;
} Warehouse;

// Initialize warehouse
Warehouse *init_warehouse(int capacity) {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->items = malloc(sizeof(GoodsItem) * capacity);
    warehouse->size = 0;
    warehouse->capacity = capacity;
    return warehouse;
}

// Add item to warehouse
void add_item(Warehouse *warehouse, GoodsItem item) {
    if (warehouse->size >= warehouse->capacity) {
        printf("Warehouse is full, cannot add more items.\n");
        return;
    }
    warehouse->items[warehouse->size++] = item;
}

// Remove item from warehouse
void remove_item(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->size; i++) {
        if (warehouse->items[i].id == id) {
            // Found item, remove it
            for (int j = i + 1; j < warehouse->size; j++) {
                warehouse->items[j - 1] = warehouse->items[j];
            }
            warehouse->size--;
            return;
        }
    }
    printf("Item with id %d not found in warehouse.\n", id);
}

// Print warehouse contents
void print_warehouse(Warehouse *warehouse) {
    printf("Warehouse contents:\n");
    for (int i = 0; i < warehouse->size; i++) {
        GoodsItem item = warehouse->items[i];
        printf("Item %d: %s (%d units)\n", item.id, item.name, item.quantity);
    }
}

// Initialize goods items
GoodsItem *init_goods_items() {
    GoodsItem *items = malloc(sizeof(GoodsItem) * 4);
    items[0] = (GoodsItem) {1, "Bread", GOODS_FOOD, 10};
    items[1] = (GoodsItem) {2, "Sword", GOODS_WEAPON, 5};
    items[2] = (GoodsItem) {3, "Armor", GOODS_ARMOR, 2};
    items[3] = (GoodsItem) {4, "Potion", GOODS_MISC, 10};
    return items;
}

int main() {
    // Create a warehouse with a capacity of 10 items
    Warehouse *warehouse = init_warehouse(10);

    // Initialize goods items
    GoodsItem *items = init_goods_items();

    // Add items to the warehouse
    for (int i = 0; i < 4; i++) {
        add_item(warehouse, items[i]);
    }

    // Print the warehouse contents
    print_warehouse(warehouse);

    // Remove an item from the warehouse
    remove_item(warehouse, 2);

    // Print the warehouse contents again
    print_warehouse(warehouse);

    // Free the allocated memory
    free(items);
    free(warehouse->items);
    free(warehouse);

    return 0;
}