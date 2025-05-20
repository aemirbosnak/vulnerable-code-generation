//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
    int qty;
    float price;
} Item;

typedef struct {
    Item* items;
    int capacity;
    int size;
} Inventory;

void initInventory(Inventory* inventory, int capacity) {
    inventory->items = malloc(capacity * sizeof(Item));
    inventory->capacity = capacity;
    inventory->size = 0;
}

void addItem(Inventory* inventory, Item item) {
    if (inventory->size == inventory->capacity) {
        printf("Inventory is full.\n");
        return;
    }
    inventory->items[inventory->size] = item;
    inventory->size++;
}

void displayInventory(Inventory inventory) {
    printf("Id\tName\tQty\tPrice\n");
    for (int i = 0; i < inventory.size; i++) {
        Item item = inventory.items[i];
        printf("%d\t%s\t%d\t%.2f\n", item.id, item.name, item.qty, item.price);
    }
}

int main() {
    Inventory inventory;
    initInventory(&inventory, 10);

    // add items
    Item item1 = {1, "Shoe", 5, 25.99};
    addItem(&inventory, item1);

    Item item2 = {2, "Shirt", 10, 12.50};
    addItem(&inventory, item2);

    Item item3 = {3, "Jeans", 8, 29.99};
    addItem(&inventory, item3);

    // display inventory
    displayInventory(inventory);

    return 0;
}