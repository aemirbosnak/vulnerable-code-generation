//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
} Item;

typedef struct {
    Item *items;
    int count;
    int capacity;
} Warehouse;

Warehouse* create_warehouse(int capacity) {
    Warehouse* warehouse = (Warehouse*)malloc(sizeof(Warehouse));
    warehouse->capacity = capacity;
    warehouse->count = 0;
    warehouse->items = (Item*)malloc(capacity * sizeof(Item));
    return warehouse;
}

void add_item(Warehouse* warehouse, char* name, int quantity) {
    if (warehouse->count < warehouse->capacity) {
        strcpy(warehouse->items[warehouse->count].name, name);
        warehouse->items[warehouse->count].quantity = quantity;
        warehouse->count++;
        printf("Ah, sweet item! %s, thou art added with quantity: %d.\n", name, quantity);
    } else {
        printf("O, lament! The warehouse is full, no more items can be added!\n");
    }
}

void remove_item(Warehouse* warehouse, char* name) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Oh, cruel fate! Item: %s hath been removed from the warehouse.\n", name);
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            return;
        }
    }
    printf("Alas! Item: %s not found in this realm of stock!\n", name);
}

void display_warehouse(Warehouse* warehouse) {
    if (warehouse->count == 0) {
        printf("The warehouse is barren, void of items.\n");
    } else {
        printf("List of items in the warehouse:\n");
        for (int i = 0; i < warehouse->count; i++) {
            printf("Item: %s, Quantity: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
        }
    }
}

void destroy_warehouse(Warehouse* warehouse) {
    free(warehouse->items);
    free(warehouse);
    printf("The warehouse hath evacuated, leaving no trace behind!\n");
}

int main() {
    Warehouse* warehouse = create_warehouse(5);
    
    add_item(warehouse, "Juliet's Potion", 10);
    add_item(warehouse, "Romeo's Sword", 5);
    add_item(warehouse, "Love Letters", 15);
    add_item(warehouse, "Poison", 2);
    add_item(warehouse, "Roses", 20);

    display_warehouse(warehouse);
    
    add_item(warehouse, "Banished Treasures", 7); // Should fail, as it's full

    remove_item(warehouse, "Poison");
    display_warehouse(warehouse);

    remove_item(warehouse, "The Prince's Decree"); // Not found

    destroy_warehouse(warehouse);
    
    return 0;
}