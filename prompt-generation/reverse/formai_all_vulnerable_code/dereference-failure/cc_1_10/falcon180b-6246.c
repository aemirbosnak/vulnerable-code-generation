//Falcon-180B DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct node {
    int data;
    struct node *next;
};

// Function to create a new node with given data
struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(struct node **head, int data) {
    struct node *newNode = createNode(data);
    struct node *temp = *head;

    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    while (temp->next!= NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = NULL;
}

// Function to delete a node with given data
void deleteNode(struct node **head, int data) {
    struct node *temp = *head, *prev;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
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

// Function to search for a node with given data
struct node *searchNode(struct node *head, int data) {
    struct node *temp = head;

    while (temp!= NULL && temp->data!= data)
        temp = temp->next;

    if (temp == NULL)
        return NULL;

    return temp;
}

// Function to print the list
void printList(struct node *node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node *head = NULL;

    // Adding nodes to the list
    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);
    addNode(&head, 20);

    // Printing the list
    printf("Original list: ");
    printList(head);

    // Deleting a node
    deleteNode(&head, 10);

    // Printing the list after deletion
    printf("\nList after deleting 10: ");
    printList(head);

    return 0;
}