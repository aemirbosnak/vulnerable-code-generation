//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int stock;
} Item;

typedef struct Node {
    Item data;
    struct Node* next;
} Node;

Node* head = NULL;

void addItem(char* name, int stock) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->data.name, name);
    newNode->data.stock = stock;
    newNode->next = head;
    head = newNode;
}

void displayInventory() {
    Node* current = head;
    printf("\nCurrent Inventory:\n");
    while (current != NULL) {
        printf("%s: %d\n", current->data.name, current->data.stock);
        current = current->next;
    }
}

int main() {
    addItem("Laptop", 10);
    addItem("Monitor", 5);
    addItem("Mouse", 20);
    addItem("Keyboard", 15);

    displayInventory();

    printf("\nAdding 2 laptops to inventory:\n");
    addItem("Laptop", 2);
    displayInventory();

    printf("\nRemoving 5 keyboards from inventory:\n");
    for (int i = 0; i < 5; i++) {
        if (head->data.name[0] == 'K' && head->data.name[1] == 'e' && head->data.name[2] == 'y' && head->data.name[3] == 'b' && head->data.name[4] == 'o' && head->data.name[5] == 'a' && head->data.name[6] == 'r' && head->data.name[7] == 'd') {
            Node* temp = head;
            head = head->next;
            free(temp);
            i--;
        } else {
            head = head->next;
        }
    }

    displayInventory();

    return 0;
}