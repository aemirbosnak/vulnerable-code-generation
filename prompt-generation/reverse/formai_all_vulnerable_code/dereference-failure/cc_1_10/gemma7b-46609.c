//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char item[20];
    int quantity;
    struct Node* next;
};

struct Warehouse {
    struct Node* head;
    struct Node* tail;
    int size;
};

void insert(struct Warehouse* warehouse, char item, int quantity) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->item[0] = item;
    newNode->quantity = quantity;
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

void search(struct Warehouse* warehouse, char item) {
    struct Node* current = warehouse->head;
    while (current) {
        if (strcmp(current->item, item) == 0) {
            printf("Item: %s, Quantity: %d\n", current->item, current->quantity);
            return;
        }
        current = current->next;
    }
    printf("Item not found.\n");
}

int main() {
    struct Warehouse* warehouse = (struct Warehouse*)malloc(sizeof(struct Warehouse));
    warehouse->head = NULL;
    warehouse->tail = NULL;
    warehouse->size = 0;

    insert(warehouse, "Apple", 10);
    insert(warehouse, "Banana", 20);
    insert(warehouse, "Orange", 30);

    search(warehouse, "Apple");
    search(warehouse, "Banana");
    search(warehouse, "Orange");
    search(warehouse, "Peach");

    return 0;
}