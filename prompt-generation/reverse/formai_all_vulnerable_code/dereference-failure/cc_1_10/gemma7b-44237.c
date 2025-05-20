//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    double price;
    struct Item* next;
} Item;

typedef struct Warehouse {
    Item* head;
    int items_count;
    double total_value;
} Warehouse;

Warehouse* create_warehouse() {
    Warehouse* warehouse = (Warehouse*)malloc(sizeof(Warehouse));
    warehouse->head = NULL;
    warehouse->items_count = 0;
    warehouse->total_value = 0.0;
    return warehouse;
}

void add_item(Warehouse* warehouse, char* name, int quantity, double price) {
    Item* item = (Item*)malloc(sizeof(Item));
    strcpy(item->name, name);
    item->quantity = quantity;
    item->price = price;
    item->next = NULL;

    if (warehouse->head == NULL) {
        warehouse->head = item;
    } else {
        warehouse->head->next = item;
    }

    warehouse->items_count++;
    warehouse->total_value += item->quantity * item->price;
}

void print_items(Warehouse* warehouse) {
    Item* item = warehouse->head;
    while (item) {
        printf("%s: %d, $%.2lf\n", item->name, item->quantity, item->price);
        item = item->next;
    }
}

int main() {
    Warehouse* warehouse = create_warehouse();

    add_item(warehouse, "Apple", 10, 1.20);
    add_item(warehouse, "Banana", 20, 0.80);
    add_item(warehouse, "Orange", 15, 0.90);

    print_items(warehouse);

    printf("Total items: %d\n", warehouse->items_count);
    printf("Total value: $%.2lf\n", warehouse->total_value);

    return 0;
}