//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int stock;
    int reorder_level;
    struct node *next;
} InventoryItem;

typedef struct node {
    InventoryItem data;
    struct node *next;
} Node;

Node *head = NULL;

void addItem(char *name, int stock, int reorder_level) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data.stock = stock;
    newNode->data.reorder_level = reorder_level;
    strcpy(newNode->data.name, name);
    newNode->next = head;
    head = newNode;
}

void displayInventory() {
    Node *currentNode = head;
    printf("\n-------- Warehouse Inventory --------\n");
    printf("| %-40s | %-10s | %-10s |\n", "Item Name", "Stock", "Reorder Level");
    while (currentNode != NULL) {
        printf("| %-40s | %-10d | %-10d |\n", currentNode->data.name, currentNode->data.stock, currentNode->data.reorder_level);
        currentNode = currentNode->next;
    }
}

void checkReorder() {
    Node *currentNode = head;
    while (currentNode != NULL) {
        if (currentNode->data.stock < currentNode->data.reorder_level) {
            printf("\n%s stock is low, reorder required.\n", currentNode->data.name);
        }
        currentNode = currentNode->next;
    }
}

int main() {
    addItem("Laptop", 10, 5);
    addItem("Monitor", 8, 7);
    addItem("Keyboard", 20, 10);
    addItem("Mouse", 15, 8);

    displayInventory();

    checkReorder();

    return 0;
}