//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int item_id;
    char item_name[20];
    int quantity;
    struct Node* next;
};

struct Warehouse {
    struct Node* head;
    struct Node* tail;
    int total_items;
};

void insert_node(struct Warehouse* warehouse, int item_id, char item_name[], int quantity) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->item_id = item_id;
    strcpy(new_node->item_name, item_name);
    new_node->quantity = quantity;
    new_node->next = NULL;

    if (warehouse->head == NULL) {
        warehouse->head = new_node;
        warehouse->tail = new_node;
    } else {
        warehouse->tail->next = new_node;
        warehouse->tail = new_node;
    }

    warehouse->total_items++;
}

int search_item(struct Warehouse* warehouse, int item_id) {
    struct Node* current_node = warehouse->head;

    while (current_node) {
        if (current_node->item_id == item_id) {
            return 1;
        }
        current_node = current_node->next;
    }

    return 0;
}

int main() {
    struct Warehouse* warehouse = (struct Warehouse*)malloc(sizeof(struct Warehouse));
    warehouse->head = NULL;
    warehouse->tail = NULL;
    warehouse->total_items = 0;

    insert_node(warehouse, 1, "Apple", 10);
    insert_node(warehouse, 2, "Banana", 20);
    insert_node(warehouse, 3, "Orange", 15);

    if (search_item(warehouse, 2) == 1) {
        printf("Item found!\n");
    } else {
        printf("Item not found.\n");
    }

    return 0;
}