//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** headRef, int data) {
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

void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef;
    Node* prev;
    if (temp!= NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

void reverseList(Node** headRef) {
    Node* prev = NULL;
    Node* current = *headRef;
    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headRef = prev;
}

int main() {
    Node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);
    printList(head);
    deleteNode(&head, 3);
    printList(head);
    reverseList(&head);
    printList(head);
    return 0;
}