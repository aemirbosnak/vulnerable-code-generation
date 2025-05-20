//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void addNode(struct Node** headRef, int newData);
void printList(struct Node* node);
void deleteNode(struct Node** headRef, int key);
void searchNode(struct Node* head, int key);

int main() {
    struct Node* head = NULL;

    // Adding nodes
    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);

    // Printing list
    printf("List after adding nodes: ");
    printList(head);

    // Deleting nodes
    deleteNode(&head, 10);
    deleteNode(&head, 15);

    // Printing list after deleting nodes
    printf("\nList after deleting nodes: ");
    printList(head);

    // Searching for node
    int key = 5;
    searchNode(head, key);

    return 0;
}

// Function to add a node at the beginning of the list
void addNode(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

// Function to print the list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Function to delete a node with the given key
void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = *headRef, *prev;

    // If head node itself holds the key or if list is empty
    if (temp!= NULL && temp->data == key) {
        temp = temp->next;
        *headRef = temp;
        free(temp);
        return;
    }

    // Search for the key to be deleted
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
}

// Function to search for a node with the given key
void searchNode(struct Node* head, int key) {
    struct Node* current = head;

    // Search for the key in linked list
    while (current!= NULL) {
        if (current->data == key)
            printf("\nNode found! ");
        else
            printf("\nNode not found! ");
        current = current->next;
    }
}