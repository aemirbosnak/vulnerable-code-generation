//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Function prototypes
void addNode(struct node** headRef, int data);
void deleteNode(struct node** headRef, int data);
void printList(struct node* node);
int countNodes(struct node* node);

// Main function
int main() {
    struct node* head = NULL;

    // Adding nodes
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);

    // Printing list
    printf("Original List: ");
    printList(head);

    // Deleting nodes
    deleteNode(&head, 2);
    deleteNode(&head, 4);

    // Printing list after deletion
    printf("\nList after deleting nodes with data 2 and 4: ");
    printList(head);

    // Counting nodes
    int count = countNodes(head);
    printf("\nNumber of nodes in the list: %d", count);

    return 0;
}

// Function to add a node at the end of the list
void addNode(struct node** headRef, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*headRef == NULL) {
        newNode->next = newNode;
        *headRef = newNode;
    } else {
        struct node* last = *headRef;
        while (last->next!= *headRef) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *headRef;
    }
}

// Function to delete a node with the given data
void deleteNode(struct node** headRef, int data) {
    struct node* temp = *headRef;
    struct node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(struct node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to count the number of nodes in the list
int countNodes(struct node* node) {
    int count = 0;
    while (node!= NULL) {
        count++;
        node = node->next;
    }
    return count;
}