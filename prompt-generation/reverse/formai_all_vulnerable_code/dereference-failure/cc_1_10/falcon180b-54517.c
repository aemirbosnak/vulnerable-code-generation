//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addAtBeginning(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    newNode->next = *headRef;
    *headRef = newNode;
}

void addAtEnd(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    Node* last = *headRef;
    while (last->next!= NULL)
        last = last->next;
    last->next = newNode;
}

void addAtPosition(Node** headRef, int data, int pos) {
    Node* newNode = createNode(data);
    if (pos == 1) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }
    Node* temp = *headRef;
    for (int i = 1; i < pos - 1 && temp!= NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef;
    if (temp!= NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= key) {
        temp = temp->next;
    }
    if (temp == NULL)
        printf("Node not found\n");
}

void display(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;
    addAtBeginning(&head, 5);
    addAtBeginning(&head, 3);
    addAtEnd(&head, 7);
    addAtPosition(&head, 4, 2);
    display(head);
    deleteNode(&head, 3);
    display(head);
    return 0;
}