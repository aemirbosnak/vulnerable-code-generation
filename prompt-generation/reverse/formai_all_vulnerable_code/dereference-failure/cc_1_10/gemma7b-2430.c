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
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->item_id = item_id;
    new_node->next = NULL;

    if (warehouse->head == NULL) {
        warehouse->head = new_node;
    } else {
        struct Node* temp = warehouse->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    warehouse->current_items++;
}

void remove_item(struct Warehouse* warehouse, int item_id) {
    struct Node* temp = warehouse->head;
    struct Node* prev = NULL;

    while (temp && temp->item_id != item_id) {
        prev = temp;
        temp = temp->next;
    }

    if (prev) {
        prev->next = temp->next;
    } else {
        warehouse->head = temp->next;
    }

    warehouse->current_items--;
}

int main() {
    struct Warehouse warehouse;
    warehouse.capacity = 100;
    warehouse.current_items = 0;
    warehouse.head = NULL;

    insert_item(&warehouse, 1);
    insert_item(&warehouse, 2);
    insert_item(&warehouse, 3);
    insert_item(&warehouse, 4);

    remove_item(&warehouse, 2);

    struct Node* temp = warehouse.head;
    while (temp) {
        printf("%d ", temp->item_id);
        temp = temp->next;
    }

    printf("\nNumber of items: %d", warehouse.current_items);

    return 0;
}