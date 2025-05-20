//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char item[20];
    struct Node* next;
} Node;

typedef struct Warehouse {
    Node* head;
    int size;
} Warehouse;

void insert(Warehouse* warehouse, char item) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->item, item);
    newNode->next = NULL;

    if (warehouse->head == NULL) {
        warehouse->head = newNode;
    } else {
        warehouse->head->next = newNode;
    }

    warehouse->size++;
}

void search(Warehouse* warehouse, char item) {
    Node* current = warehouse->head;

    while (current) {
        if (strcmp(current->item, item) == 0) {
            printf("Item found: %s\n", current->item);
            return;
        }

        current = current->next;
    }

    printf("Item not found.\n");
}

int main() {
    Warehouse* warehouse = malloc(sizeof(Warehouse));
    warehouse->head = NULL;
    warehouse->size = 0;

    insert(warehouse, "Apple");
    insert(warehouse, "Banana");
    insert(warehouse, "Orange");

    search(warehouse, "Apple");
    search(warehouse, "Peach");

    return 0;
}