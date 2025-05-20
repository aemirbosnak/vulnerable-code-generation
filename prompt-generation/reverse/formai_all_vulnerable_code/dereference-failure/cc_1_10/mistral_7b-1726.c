//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

void createNode(Node** node, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*node != NULL) {
        (*node)->prev = newNode;
        newNode->next = *node;
    }

    *node = newNode;
}

void display(Node* node) {
    if (node == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Data: %d, Address of next: %p, Address of prev: %p\n", node->data, node->next, node->prev);

    if (node->next != NULL)
        display(node->next);
}

void displayList(Node* node) {
    if (node == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Node [%p]: Data: %d\n", node, node->data);

    if (node->next != NULL) {
        printf("-> ");
        displayList(node->next);
    }
}

int main() {
    Node* head = NULL;

    createNode(&head, 10);
    createNode(&head, 20);
    createNode(&head, 30);
    createNode(&head, 40);

    displayList(head);

    free(head);

    return 0;
}