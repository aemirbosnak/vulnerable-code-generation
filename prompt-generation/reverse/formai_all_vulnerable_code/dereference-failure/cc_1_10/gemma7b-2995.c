//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
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
    char warehouse_name[20];
} Warehouse;

void insert_item(Warehouse* warehouse, char item[]) {
    Node* new_node = malloc(sizeof(Node));
    strcpy(new_node->item, item);
    new_node->next = NULL;

    if (warehouse->head == NULL) {
        warehouse->head = new_node;
    } else {
        warehouse->head->next = new_node;
    }

    warehouse->items_count++;
}

void print_items(Warehouse* warehouse) {
    Node* current_node = warehouse->head;

    while (current_node) {
        printf("%s ", current_node->item);
        current_node = current_node->next;
    }

    printf("\n");
}

int main() {
    Warehouse* warehouse = malloc(sizeof(Warehouse));
    warehouse->head = NULL;
    warehouse->items_count = 0;
    strcpy(warehouse->warehouse_name, "Example Warehouse");

    insert_item(warehouse, "Apple");
    insert_item(warehouse, "Banana");
    insert_item(warehouse, "Orange");
    insert_item(warehouse, "Mango");

    print_items(warehouse);

    return 0;
}