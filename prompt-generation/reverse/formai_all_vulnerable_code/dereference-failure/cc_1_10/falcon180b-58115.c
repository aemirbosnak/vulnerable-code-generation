//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define structure for a node
typedef struct node {
    int data;
    struct node* next;
} node;

// Function to create a new node with the given data
node* createNode(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
void push(node** headRef, int newData) {
    node* newNode = createNode(newData);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to add a node at the end of the list
void append(node** headRef, int newData) {
    node* newNode = createNode(newData);
    newNode->next = NULL;
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    node* last = *headRef;
    while (last->next!= NULL)
        last = last->next;
    last->next = newNode;
}

// Function to add a node after a given position
void insertAfter(node* prevNode, int newData) {
    node* newNode = createNode(newData);
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to delete a node by key
void deleteNode(node** headRef, int key) {
    node* temp = *headRef, *prev;
    if (temp!= NULL && temp->data == key) {
        *headRef = temp->next; 
        free(temp);            
        return;
    }
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(node* node) {
    while (node!= NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    node* head = NULL;
    push(&head, 5);
    append(&head, 3);
    append(&head, 7);
    insertAfter(head->next, 2);
    insertAfter(head->next->next, 4);
    printList(head);
    deleteNode(&head, 2);
    deleteNode(&head, 7);
    printList(head);
    return 0;
}