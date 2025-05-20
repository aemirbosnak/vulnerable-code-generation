//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    int quantity;
} Item;

typedef struct Node {
    Item data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* current = NULL;

void addItem(Item newItem) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newItem;
    newNode->next = head;
    head = newNode;
}

void removeItem(char* name) {
    if (head == NULL) {
        printf("Warehouse is empty.\n");
        return;
    }

    if (strcmp(head->data.name, name) == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    current = head;
    while (current->next != NULL && strcmp(current->next->data.name, name) != 0) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Item not found.\n");
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void viewInventory() {
    if (head == NULL) {
        printf("Warehouse is empty.\n");
        return;
    }

    current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->data.name, current->data.quantity);
        current = current->next;
    }
}

void searchItem(char* name) {
    if (head == NULL) {
        printf("Warehouse is empty.\n");
        return;
    }

    current = head;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            printf("%s: %d\n", current->data.name, current->data.quantity);
            return;
        }
        current = current->next;
    }

    printf("Item not found.\n");
}

int main() {
    Item newItem = {"Apple", 10};
    addItem(newItem);

    Item banana = {"Banana", 5};
    addItem(banana);

    viewInventory();

    searchItem("Apple");
    searchItem("Orange");

    removeItem("Apple");

    viewInventory();

    return 0;
}