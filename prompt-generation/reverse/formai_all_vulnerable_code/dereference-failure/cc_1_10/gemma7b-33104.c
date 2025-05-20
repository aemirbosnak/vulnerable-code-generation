//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char item[20];
    struct Node* next;
};

struct Warehouse {
    struct Node* head;
    struct Node* tail;
    int size;
};

void insertItem(struct Warehouse* warehouse, char item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->item, item);
    newNode->next = NULL;

    if (warehouse->head == NULL) {
        warehouse->head = newNode;
        warehouse->tail = newNode;
    } else {
        warehouse->tail->next = newNode;
        warehouse->tail = newNode;
    }

    warehouse->size++;
}

int searchItem(struct Warehouse* warehouse, char item) {
    struct Node* current = warehouse->head;

    while (current) {
        if (strcmp(current->item, item) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    struct Warehouse* warehouse = (struct Warehouse*)malloc(sizeof(struct Warehouse));
    warehouse->head = NULL;
    warehouse->tail = NULL;
    warehouse->size = 0;

    insertItem(warehouse, "Apple");
    insertItem(warehouse, "Banana");
    insertItem(warehouse, "Orange");
    insertItem(warehouse, "Peach");

    if (searchItem(warehouse, "Apple") == 1) {
        printf("Apple is in the warehouse.\n");
    }

    if (searchItem(warehouse, "Peach") == 1) {
        printf("Peach is in the warehouse.\n");
    }

    return 0;
}