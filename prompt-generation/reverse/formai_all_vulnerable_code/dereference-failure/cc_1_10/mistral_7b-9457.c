//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int stock;
    int price;
    struct Node* next;
} Node;

Node* createNode(char name[], int stock, int price) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->stock = stock;
    newNode->price = price;
    newNode->next = NULL;
    return newNode;
}

void addProduct(Node** head, char name[], int stock, int price) {
    if (*head == NULL) {
        *head = createNode(name, stock, price);
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    Node* newNode = createNode(name, stock, price);
    current->next = newNode;
}

void searchProduct(Node* head, char name[]) {
    Node* current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Product %s found with stock %d and price %d\n", name, current->stock, current->price);
            return;
        }
        current = current->next;
    }

    printf("Product %s not found\n", name);
}

void recursiveSearchProduct(Node* head, char name[], int depth) {
    if (head == NULL) {
        printf("Product %s not found after %d levels\n", name, depth);
        return;
    }

    if (strcmp(head->name, name) == 0) {
        printf("Product %s found at level %d with stock %d and price %d\n", name, depth, head->stock, head->price);
        return;
    }

    recursiveSearchProduct(head->next, name, depth + 1);
}

void printInventory(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("%s : Stock %d Price %d\n", current->name, current->stock, current->price);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;

    addProduct(&head, "Apple", 10, 5);
    addProduct(&head, "Banana", 15, 3);
    addProduct(&head, "Orange", 7, 2);

    printInventory(head);

    searchProduct(head, "Apple");
    searchProduct(head, "Banana");
    searchProduct(head, "Orange");
    searchProduct(head, "Mango");

    recursiveSearchProduct(head, "Mango", 0);

    return 0;
}