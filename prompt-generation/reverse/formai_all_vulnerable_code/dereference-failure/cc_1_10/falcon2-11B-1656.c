//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** headRef, int data) {
    Node* newNode = createNode(data);
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void insertAtEnd(Node** headRef, int data) {
    Node* newNode = createNode(data);
    Node* current = (*headRef);
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deleteNode(Node** headRef, int data) {
    Node* current = (*headRef);
    Node* previous = NULL;
    while (current!= NULL && current->data!= data) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node not found");
        return;
    }
    if (previous == NULL) {
        (*headRef) = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

int main() {
    Node* head = NULL;
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 4);
    printList(head);
    printf("\n");
    deleteNode(&head, 2);
    printList(head);
    printf("\n");
    deleteNode(&head, 3);
    printList(head);
    printf("\n");
    return 0;
}