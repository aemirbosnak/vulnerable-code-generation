//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char item_name[20];
    int quantity;
    struct Node* next;
} Node;

typedef struct Warehouse {
    Node* head;
    int total_items;
} Warehouse;

void insert_item(Warehouse* warehouse, char item_name, int quantity) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->item_name, item_name);
    new_node->quantity = quantity;
    new_node->next = NULL;

    if (warehouse->head == NULL) {
        warehouse->head = new_node;
    } else {
        Node* tail = warehouse->head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = new_node;
    }

    warehouse->total_items++;
}

void update_quantity(Warehouse* warehouse, char item_name, int new_quantity) {
    Node* node = warehouse->head;
    while (node) {
        if (strcmp(node->item_name, item_name) == 0) {
            node->quantity = new_quantity;
            break;
        }
        node = node->next;
    }

    if (node == NULL) {
        printf("Item not found.\n");
    }
}

void search_item(Warehouse* warehouse, char item_name) {
    Node* node = warehouse->head;
    while (node) {
        if (strcmp(node->item_name, item_name) == 0) {
            printf("Item name: %s\n", node->item_name);
            printf("Quantity: %d\n", node->quantity);
            break;
        }
        node = node->next;
    }

    if (node == NULL) {
        printf("Item not found.\n");
    }
}

int main() {
    Warehouse warehouse;
    warehouse.head = NULL;
    warehouse.total_items = 0;

    insert_item(&warehouse, "Apple", 10);
    insert_item(&warehouse, "Banana", 20);
    insert_item(&warehouse, "Orange", 30);

    update_quantity(&warehouse, "Banana", 25);

    search_item(&warehouse, "Orange");

    return 0;
}