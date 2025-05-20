//Falcon-180B DATASET v1.0 Category: Memory management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    int size;
    struct node* next;
} Node;

Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->size = 0;
    newNode->next = NULL;
    return newNode;
}

Node* addNode(Node* head, char* data, int size) {
    Node* newNode = createNode();
    strcpy(newNode->data, data);
    newNode->size = size;
    newNode->next = head;
    return newNode;
}

Node* removeNode(Node* head, char* data) {
    Node* current = head;
    Node* previous = NULL;

    while (current!= NULL && strcmp(current->data, data)!= 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return head;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    return head;
}

void printList(Node* head) {
    Node* current = head;

    while (current!= NULL) {
        printf("Data: %s, Size: %d\n", current->data, current->size);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;

    head = addNode(head, "Hello", 5);
    head = addNode(head, "World", 5);

    printList(head);

    head = removeNode(head, "Hello");

    printList(head);

    return 0;
}