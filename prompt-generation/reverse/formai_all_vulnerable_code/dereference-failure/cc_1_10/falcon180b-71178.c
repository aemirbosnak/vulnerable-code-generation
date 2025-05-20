//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(Node** headRef, int data) {
    Node* newNode = createNode(data);
    Node* last = *headRef;
    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }
    while (last->next!= NULL)
        last = last->next;
    last->next = newNode;
}

// Function to insert a node at the beginning of the list
void insertNode(Node** headRef, int data) {
    Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to delete a node with given data
void deleteNode(Node** headRef, int data) {
    Node* temp = *headRef;
    Node* prev;
    if (temp!= NULL && temp->data == data) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Driver program to test above functions
int main() {
    Node* head = NULL;
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    printList(head);

    insertNode(&head, 5);
    printList(head);

    deleteNode(&head, 20);
    printList(head);

    deleteNode(&head, 10);
    printList(head);

    deleteNode(&head, 30);
    printList(head);

    return 0;
}