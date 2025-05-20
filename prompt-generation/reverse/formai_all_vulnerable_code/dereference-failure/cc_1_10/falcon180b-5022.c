//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node *next;
} Node;

// Linked list functions
Node *createNode(char *data);
void deleteNode(Node *head, char *data);
void printList(Node *head);

// Main function
int main() {
    Node *head = NULL;

    // Create nodes
    head = createNode("Hello");
    head->next = createNode("World");

    // Print list
    printList(head);

    // Delete node
    deleteNode(head, "Hello");

    // Print list again
    printList(head);

    return 0;
}

// Create node function
Node *createNode(char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    return newNode;
}

// Delete node function
void deleteNode(Node *head, char *data) {
    Node *currNode = head;
    Node *prevNode = NULL;

    // Search for node to delete
    while (currNode!= NULL && strcmp(currNode->data, data)!= 0) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    // If node not found
    if (currNode == NULL) {
        printf("Node not found.\n");
        return;
    }

    // If head node
    if (prevNode == NULL) {
        head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }

    // Free memory
    free(currNode);
}

// Print list function
void printList(Node *head) {
    Node *currNode = head;

    while (currNode!= NULL) {
        printf("%s -> ", currNode->data);
        currNode = currNode->next;
    }

    printf("NULL\n");
}