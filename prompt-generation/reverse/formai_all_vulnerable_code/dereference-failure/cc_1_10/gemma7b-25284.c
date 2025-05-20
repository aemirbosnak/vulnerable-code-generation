//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[50];
    int quantity;
    float price;
};

struct Node {
    struct Item item;
    struct Node* next;
};

struct Warehouse {
    struct Node* head;
    struct Node* tail;
};

void insertItem(struct Warehouse* warehouse, struct Item* item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->item = *item;
    newNode->next = NULL;

    if (warehouse->head == NULL) {
        warehouse->head = newNode;
        warehouse->tail = newNode;
    } else {
        warehouse->tail->next = newNode;
        warehouse->tail = newNode;
    }
}

void printItems(struct Warehouse* warehouse) {
    struct Node* current = warehouse->head;
    while (current) {
        printf("%s - %d - %.2f\n", current->item.name, current->item.quantity, current->item.price);
        current = current->next;
    }
}

int main() {
    struct Warehouse* warehouse = (struct Warehouse*)malloc(sizeof(struct Warehouse));
    warehouse->head = NULL;
    warehouse->tail = NULL;

    struct Item* item1 = (struct Item*)malloc(sizeof(struct Item));
    item1->name[0] = 'A';
    item1->quantity = 10;
    item1->price = 10.00;
    insertItem(warehouse, item1);

    struct Item* item2 = (struct Item*)malloc(sizeof(struct Item));
    item2->name[0] = 'B';
    item2->quantity = 20;
    item2->price = 20.00;
    insertItem(warehouse, item2);

    struct Item* item3 = (struct Item*)malloc(sizeof(struct Item));
    item3->name[0] = 'C';
    item3->quantity = 30;
    item3->price = 30.00;
    insertItem(warehouse, item3);

    printItems(warehouse);

    return 0;
}