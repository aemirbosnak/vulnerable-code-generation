//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
void push(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to add a node at the end of the list
void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    struct Node* last = *headRef;
    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }
    while (last->next!= NULL) {
        last = last->next;
    }
    last->next = newNode;
    return;
}

// Function to add a node after a given position
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    return;
}

// Function to delete a node with given data
void deleteNode(struct Node** headRef, int data) {
    struct Node* temp = *headRef, *prev;
    if (temp!= NULL && temp->data == data) {
        *headRef = temp->next;
        free(temp);            
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Driver program to test above functions
int main() {
    struct Node* head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    printList(head);
    append(&head, 6);
    printList(head);
    insertAfter(head->next, 4);
    printList(head);
    deleteNode(&head, 1);
    printList(head);
    deleteNode(&head, 7);
    printList(head);
    return 0;
}