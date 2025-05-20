//Falcon-180B DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function prototypes
void addNode(Node **head, int data);
void deleteNode(Node **head, int data);
void printList(Node *head);

int main() {
    Node *head = NULL;

    // Add some nodes
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);

    // Print the list
    printf("Original List:\n");
    printList(head);

    // Delete a node
    deleteNode(&head, 2);

    // Print the list again
    printf("\nList after deleting node with data 2:\n");
    printList(head);

    return 0;
}

// Function to add a node at the end of the list
void addNode(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node with given data
void deleteNode(Node **head, int data) {
    Node *temp = *head;
    Node *prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
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
void printList(Node *head) {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}