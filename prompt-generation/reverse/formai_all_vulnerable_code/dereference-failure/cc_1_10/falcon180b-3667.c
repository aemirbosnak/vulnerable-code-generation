//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void append(struct Node** headRef, int newData) {
    struct Node* newNode = createNode(newData);
    struct Node* last = *headRef;

    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = newNode;

    return;
}

// Function to add a node at the beginning of the list
void prepend(struct Node** headRef, int newData) {
    struct Node* newNode = createNode(newData);

    newNode->next = *headRef;
    *headRef = newNode;

    return;
}

// Function to insert a node after a given position
void insertAfter(struct Node* prevNode, int newData) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    struct Node* newNode = createNode(newData);
    newNode->next = prevNode->next;
    prevNode->next = newNode;

    return;
}

// Function to delete a node by key
void deleteNode(struct Node **headRef, int key) {
    struct Node* temp = *headRef, *prev;

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
    return;
}

// Function to print the list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

// Driver program to test above functions
int main() {
    struct Node* head = NULL;

    append(&head, 7);
    prepend(&head, 1);
    prepend(&head, 6);
    append(&head, 9);

    printf("Created Linked List: ");
    printList(head);

    insertAfter(head->next, 4);
    printf("\nLinked List after inserting 4: ");
    printList(head);

    deleteNode(&head, 1);
    printf("\nLinked List after deleting 1: ");
    printList(head);

    deleteNode(&head, 6);
    printf("\nLinked List after deleting 6: ");
    printList(head);

    return 0;
}