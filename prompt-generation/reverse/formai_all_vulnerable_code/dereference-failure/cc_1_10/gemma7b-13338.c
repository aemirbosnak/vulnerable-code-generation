//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct Item {
    char name[20];
    int quantity;
    double price;
};

struct Node {
    struct Item item;
    struct Node* next;
};

struct Warehouse {
    struct Node* head;
    int items_count;
    double total_value;
};

void insert_item(struct Warehouse* warehouse, char* name, int quantity, double price) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    strcpy(new_node->item.name, name);
    new_node->item.quantity = quantity;
    new_node->item.price = price;

    if (warehouse->head == NULL) {
        warehouse->head = new_node;
    } else {
        new_node->next = warehouse->head;
        warehouse->head = new_node;
    }

    warehouse->items_count++;
    warehouse->total_value += new_node->item.quantity * new_node->item.price;
}

void print_items(struct Warehouse* warehouse) {
    struct Node* current_node = warehouse->head;

    printf("Items in the warehouse:\n");
    while (current_node) {
        printf("%s - %d - %.2lf\n", current_node->item.name, current_node->item.quantity, current_node->item.price);
        current_node = current_node->next;
    }
}

int main() {
    struct Warehouse warehouse;
    warehouse.head = NULL;
    warehouse.items_count = 0;
    warehouse.total_value = 0.0;

    insert_item(&warehouse, "Apple", 10, 1.2);
    insert_item(&warehouse, "Banana", 20, 0.8);
    insert_item(&warehouse, "Orange", 15, 0.9);

    print_items(&warehouse);

    return 0;
}