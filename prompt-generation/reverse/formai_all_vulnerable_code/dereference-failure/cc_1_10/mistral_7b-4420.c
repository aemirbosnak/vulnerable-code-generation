//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node** createLinkedList() {
    Node** list = (Node**)calloc(1, sizeof(Node*));
    *list = NULL;
    return list;
}

void addNode(Node** list, int data) {
    Node* newNode = createNode(data);
    Node* current = *list;
    if (*list == NULL) {
        *list = newNode;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node** list) {
    Node* current = *list;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void deleteNode(Node** list, int data) {
    Node* current = *list;
    Node* previous = NULL;

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: Node not found\n");
        return;
    }

    if (previous == NULL) {
        *list = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

void freeList(Node** list) {
    Node* current = *list;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(*list);
    *list = NULL;
}

int main() {
    Node** list = createLinkedList();

    addNode(list, 5);
    addNode(list, 10);
    addNode(list, 15);

    printList(list);

    deleteNode(list, 10);

    printList(list);

    freeList(list);

    return 0;
}