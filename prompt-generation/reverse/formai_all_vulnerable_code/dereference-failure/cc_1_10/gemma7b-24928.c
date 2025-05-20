//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int item_id;
    struct Node* next;
};

struct Warehouse {
    struct Node* head;
    int capacity;
    int current_items;
};

void insert_item(struct Warehouse* warehouse, int item_id) {
    if (warehouse->current_items == warehouse->capacity) {
        printf("Error: Warehouse is full!\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->item_id = item_id;
    new_node->next = NULL;

    if (warehouse->head == NULL) {
        warehouse->head = new_node;
    } else {
        struct Node* current_node = warehouse->head;
        while (current_node->next) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }

    warehouse->current_items++;
}

void search_item(struct Warehouse* warehouse, int item_id) {
    struct Node* current_node = warehouse->head;

    while (current_node) {
        if (current_node->item_id == item_id) {
            printf("Item found: item ID %d\n", item_id);
            return;
        }

        current_node = current_node->next;
    }

    printf("Item not found: item ID %d\n", item_id);
}

int main() {
    struct Warehouse warehouse;
    warehouse.capacity = 10;
    warehouse.current_items = 0;
    warehouse.head = NULL;

    insert_item(&warehouse, 1);
    insert_item(&warehouse, 2);
    insert_item(&warehouse, 3);
    insert_item(&warehouse, 4);

    search_item(&warehouse, 2);
    search_item(&warehouse, 5);

    return 0;
}