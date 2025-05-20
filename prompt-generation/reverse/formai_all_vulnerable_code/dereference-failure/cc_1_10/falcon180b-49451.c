//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int quantity;
    float price;
} Item;

typedef struct {
    Item item;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

List* createList() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void addItem(List* list, char* name, int quantity, float price) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->item.name, name);
    node->item.quantity = quantity;
    node->item.price = price;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void displayList(List* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        printf("Name: %s\n", temp->item.name);
        printf("Quantity: %d\n", temp->item.quantity);
        printf("Price: $%.2f\n\n", temp->item.price);
        temp = temp->next;
    }
}

int main() {
    List* warehouse = createList();

    addItem(warehouse, "Romeo's Sword", 5, 50.00);
    addItem(warehouse, "Juliet's Dress", 3, 75.00);
    addItem(warehouse, "Capulet Wine", 10, 25.00);
    addItem(warehouse, "Montague Ale", 8, 30.00);

    displayList(warehouse);

    return 0;
}