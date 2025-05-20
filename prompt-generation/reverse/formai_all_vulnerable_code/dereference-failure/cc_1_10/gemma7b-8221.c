//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char item[20];
    struct Node* next;
} Node;

typedef struct Warehouse {
    Node* head;
    int items_count;
} Warehouse;

Warehouse* warehouse_init() {
    Warehouse* warehouse = malloc(sizeof(Warehouse));
    warehouse->head = NULL;
    warehouse->items_count = 0;
    return warehouse;
}

void warehouse_add_item(Warehouse* warehouse, char item[]) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->item, item);
    newNode->next = warehouse->head;
    warehouse->head = newNode;
    warehouse->items_count++;
}

void warehouse_print_items(Warehouse* warehouse) {
    Node* current = warehouse->head;
    while (current) {
        printf("%s ", current->item);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Warehouse* warehouse = warehouse_init();
    warehouse_add_item(warehouse, "Apple");
    warehouse_add_item(warehouse, "Banana");
    warehouse_add_item(warehouse, "Orange");
    warehouse_print_items(warehouse);

    warehouse_add_item(warehouse, "Mango");
    warehouse_print_items(warehouse);

    return 0;
}