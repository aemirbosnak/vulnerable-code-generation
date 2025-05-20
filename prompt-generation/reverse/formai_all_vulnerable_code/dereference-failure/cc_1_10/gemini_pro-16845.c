//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct node {
    Item item;
    struct node *next;
} Node;

typedef struct warehouse {
    Node *head;
    Node *tail;
    int size;
} Warehouse;

Warehouse *create_warehouse() {
    Warehouse *warehouse = (Warehouse *)malloc(sizeof(Warehouse));
    warehouse->head = NULL;
    warehouse->tail = NULL;
    warehouse->size = 0;
    return warehouse;
}

void add_item(Warehouse *warehouse, Item item) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->item = item;
    new_node->next = NULL;

    if (warehouse->head == NULL) {
        warehouse->head = new_node;
        warehouse->tail = new_node;
    } else {
        warehouse->tail->next = new_node;
        warehouse->tail = new_node;
    }

    warehouse->size++;
}

void remove_item(Warehouse *warehouse, char *name) {
    Node *current_node = warehouse->head;
    Node *previous_node = NULL;

    while (current_node != NULL) {
        if (strcmp(current_node->item.name, name) == 0) {
            if (previous_node == NULL) {
                warehouse->head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }

            if (current_node == warehouse->tail) {
                warehouse->tail = previous_node;
            }

            free(current_node);
            warehouse->size--;
            return;
        }

        previous_node = current_node;
        current_node = current_node->next;
    }

    printf("Item not found.\n");
}

void print_warehouse(Warehouse *warehouse) {
    Node *current_node = warehouse->head;

    while (current_node != NULL) {
        printf("%s %d %.2f\n", current_node->item.name, current_node->item.quantity, current_node->item.price);
        current_node = current_node->next;
    }
}

void free_warehouse(Warehouse *warehouse) {
    Node *current_node = warehouse->head;
    Node *next_node;

    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    free(warehouse);
}

int main() {
    Warehouse *warehouse = create_warehouse();

    Item item1 = {"Apple", 10, 1.0};
    Item item2 = {"Orange", 5, 2.0};
    Item item3 = {"Banana", 15, 3.0};

    add_item(warehouse, item1);
    add_item(warehouse, item2);
    add_item(warehouse, item3);

    print_warehouse(warehouse);

    remove_item(warehouse, "Apple");

    print_warehouse(warehouse);

    free_warehouse(warehouse);

    return 0;
}