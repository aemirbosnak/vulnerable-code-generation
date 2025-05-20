//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    char name[50];
    int quantity;
    float price;
    struct Item* next;
};

struct Warehouse {
    struct Item* head;
    int items_count;
    struct Warehouse* next;
};

void insert_item(struct Warehouse* warehouse, char* name, int quantity, float price) {
    struct Item* new_item = (struct Item*)malloc(sizeof(struct Item));
    strcpy(new_item->name, name);
    new_item->quantity = quantity;
    new_item->price = price;
    new_item->next = NULL;

    if (warehouse->head == NULL) {
        warehouse->head = new_item;
    } else {
        warehouse->head->next = new_item;
    }

    warehouse->items_count++;
}

void print_items(struct Warehouse* warehouse) {
    struct Item* current_item = warehouse->head;
    while (current_item) {
        printf("%s: %d, $%.2f\n", current_item->name, current_item->quantity, current_item->price);
        current_item = current_item->next;
    }
}

int main() {
    struct Warehouse* warehouse = (struct Warehouse*)malloc(sizeof(struct Warehouse));
    warehouse->head = NULL;
    warehouse->items_count = 0;
    warehouse->next = NULL;

    insert_item(warehouse, "Apple", 10, 1.20);
    insert_item(warehouse, "Banana", 5, 0.80);
    insert_item(warehouse, "Orange", 7, 0.90);

    print_items(warehouse);

    return 0;
}