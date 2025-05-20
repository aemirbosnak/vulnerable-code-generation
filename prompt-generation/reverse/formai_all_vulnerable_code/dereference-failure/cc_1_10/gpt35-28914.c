//FormAI DATASET v1.0 Category: Linked list operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Struct for each node in the linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to add a new node to the beginning of the linked list
void addNode(Node **head, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to remove a node from the linked list
void removeNode(Node **head, int data) {
    Node *temp = *head, *prev;
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to print the data of each node in the linked list
void printList(Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node *head = NULL;
    // Example of adding nodes
    addNode(&head, 5);
    addNode(&head, 7);
    addNode(&head, 3);
    // Example of removing a node
    removeNode(&head, 7);
    // Example of printing the linked list
    printList(head);

    return 0;
}