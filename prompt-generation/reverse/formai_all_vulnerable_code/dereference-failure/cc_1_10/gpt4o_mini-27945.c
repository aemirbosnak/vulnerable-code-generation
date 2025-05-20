//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

// Function to create a new node with given data
Node *createNode(const char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed for new node.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = (char *)malloc(strlen(data) + 1);
    if (newNode->data == NULL) {
        fprintf(stderr, "Memory allocation failed for node data.\n");
        free(newNode);
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to free the memory of all nodes in the linked list
void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->data); // free the data
        free(temp);       // free the node itself
    }
}

// Function to print the linked list
void printList(Node *head) {
    while (head != NULL) {
        printf("%s -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    // Allocate memory for nodes in the linked list
    head = createNode("Node 1");
    second = createNode("Node 2");
    third = createNode("Node 3");

    // Linking the nodes together
    head->next = second;
    second->next = third;

    // Print the linked list
    printf("Linked List before freeing:\n");
    printList(head);

    // Free the allocated memory for the linked list
    freeList(head);

    // Verify the list is cleared
    head = NULL; // Set head to NULL to avoid dangling pointer
    printf("Linked List has been freed.\n");

    return 0;
}