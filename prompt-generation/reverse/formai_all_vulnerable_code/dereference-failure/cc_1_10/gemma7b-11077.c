//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: introspective
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
    char warehouse[1000];
};

void insertItem(struct Warehouse* warehouse, char item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->item[0] = item;
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

void removeItem(struct Warehouse* warehouse, char item) {
    struct Node* current = warehouse->head;
    struct Node* previous = NULL;

    while (current) {
        if (strcmp(current->item, item) == 0) {
            if (previous) {
                previous->next = current->next;
                warehouse->tail = previous;
            } else {
                warehouse->head = current->next;
                warehouse->tail = warehouse->head;
            }
            free(current);
            warehouse->size--;
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Item not found.\n");
}

int main() {
    struct Warehouse warehouse;
    warehouse.head = NULL;
    warehouse.tail = NULL;
    warehouse.size = 0;

    insertItem(&warehouse, 'a');
    insertItem(&warehouse, 'b');
    insertItem(&warehouse, 'c');
    insertItem(&warehouse, 'd');
    insertItem(&warehouse, 'e');

    removeItem(&warehouse, 'c');

    struct Node* current = warehouse.head;
    while (current) {
        printf("%c ", current->item);
        current = current->next;
    }

    printf("\nSize: %d\n", warehouse.size);

    return 0;
}