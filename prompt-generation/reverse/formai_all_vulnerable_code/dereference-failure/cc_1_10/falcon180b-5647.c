//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
void push(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node at the end of the list
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next!= NULL)
        last = last->next;
    last->next = newNode;
}

// Function to add a node after a given position
void insertAfter(Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to remove a node by key
void deleteNode(Node** head, int key) {
    Node* temp = *head;
    if (temp!= NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= key) {
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    Node* next = temp->next;
    free(temp);
    temp = next;
}

// Function to print the list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function
int main() {
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    printList(head);
    append(&head, 4);
    printList(head);
    insertAfter(head->next, 5);
    printList(head);
    deleteNode(&head, 2);
    printList(head);
    return 0;
}