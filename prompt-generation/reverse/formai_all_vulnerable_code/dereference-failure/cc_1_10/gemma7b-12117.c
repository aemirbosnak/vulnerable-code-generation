//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char item[20];
    int quantity;
    struct Node* next;
} Node;

typedef struct Warehouse {
    Node* head;
    int totalItems;
} Warehouse;

Warehouse* createWarehouse() {
    Warehouse* warehouse = malloc(sizeof(Warehouse));
    warehouse->head = NULL;
    warehouse->totalItems = 0;
    return warehouse;
}

void addToWarehouse(Warehouse* warehouse, char item, int quantity) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->item, item);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (warehouse->head == NULL) {
        warehouse->head = newNode;
    } else {
        Node* tempNode = warehouse->head;
        while (tempNode->next != NULL) {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
    }

    warehouse->totalItems++;
}

void printInventory(Warehouse* warehouse) {
    Node* current = warehouse->head;
    while (current) {
        printf("%s: %d\n", current->item, current->quantity);
        current = current->next;
    }
}

int main() {
    Warehouse* warehouse = createWarehouse();

    addToWarehouse(warehouse, "Apple", 10);
    addToWarehouse(warehouse, "Banana", 20);
    addToWarehouse(warehouse, "Orange", 30);

    printInventory(warehouse);

    return 0;
}