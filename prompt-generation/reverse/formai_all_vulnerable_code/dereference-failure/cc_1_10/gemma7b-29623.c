//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char item[20];
    struct Node* next;
};

struct Warehouse {
    struct Node* head;
    int items_count;
    char warehouse_name[20];
};

void insert_item(struct Warehouse* warehouse, char item) {
    struct Node* newNode = malloc(sizeof(struct Node));
    strcpy(newNode->item, item);
    newNode->next = NULL;

    if (warehouse->head == NULL) {
        warehouse->head = newNode;
    } else {
        struct Node* current = warehouse->head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    warehouse->items_count++;
}

void remove_item(struct Warehouse* warehouse, char item) {
    struct Node* previous = NULL;
    struct Node* current = warehouse->head;

    while (current) {
        if (strcmp(current->item, item) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                warehouse->head = current->next;
            }
            free(current);
            warehouse->items_count--;
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Item not found.\n");
}

int main() {
    struct Warehouse* warehouse = malloc(sizeof(struct Warehouse));
    warehouse->head = NULL;
    warehouse->items_count = 0;
    strcpy(warehouse->warehouse_name, "Crazy Cat Warehouse");

    insert_item(warehouse, "Canned Tuna");
    insert_item(warehouse, "Boxed Wine");
    insert_item(warehouse, "Frozen Pizza");
    insert_item(warehouse, "Big Lebowski");

    remove_item(warehouse, "Frozen Pizza");

    printf("Items in the warehouse:\n");
    struct Node* current = warehouse->head;
    while (current) {
        printf("%s\n", current->item);
    }

    return 0;
}