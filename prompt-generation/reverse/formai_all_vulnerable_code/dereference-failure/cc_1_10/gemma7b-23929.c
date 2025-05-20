//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char item[20];
    int quantity;
    struct Node* next;
} Node;

typedef struct Warehouse {
    Node* head;
    int size;
} Warehouse;

void insertNode(Warehouse* warehouse, char item, int quantity) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item[0] = item;
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (warehouse->head == NULL) {
        warehouse->head = newNode;
    } else {
        warehouse->head->next = newNode;
    }

    warehouse->size++;
}

void printWarehouse(Warehouse* warehouse) {
    Node* current = warehouse->head;
    while (current) {
        printf("%s: %d\n", current->item, current->quantity);
        current = current->next;
    }
}

int main() {
    Warehouse* warehouse = (Warehouse*)malloc(sizeof(Warehouse));
    warehouse->head = NULL;
    warehouse->size = 0;

    insertNode(warehouse, 'a', 10);
    insertNode(warehouse, 'b', 20);
    insertNode(warehouse, 'c', 30);

    printWarehouse(warehouse);

    return 0;
}