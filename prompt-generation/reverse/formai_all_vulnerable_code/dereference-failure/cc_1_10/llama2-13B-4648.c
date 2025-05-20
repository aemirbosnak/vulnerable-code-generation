//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: retro
// RetroLinkedList.c - A blast from the past!

// Includes
#include <stdio.h>
#include <stdlib.h>

// Structs and constants
typedef struct Node {
    int data;
    struct Node *next;
} Node;

#define MAX_NODES 10

// Function prototypes
Node *createList(void);
void printList(Node *list);
Node *insertNode(Node *list, int data);
Node *deleteNode(Node *list, int data);
Node *searchNode(Node *list, int data);

int main(void) {
    Node *list = createList();

    // Print the initial list
    printList(list);

    // Insert some nodes
    list = insertNode(list, 5);
    list = insertNode(list, 10);
    list = insertNode(list, 15);

    // Delete a node
    list = deleteNode(list, 10);

    // Search for a node
    Node *found = searchNode(list, 15);

    // Print the final list
    printList(list);

    return 0;
}

// Functions

// Create an empty list
Node *createList(void) {
    Node *list = (Node *)malloc(sizeof(Node));
    list->data = 0;
    list->next = NULL;
    return list;
}

// Print the list
void printList(Node *list) {
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

// Insert a node
Node *insertNode(Node *list, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list;
    return list;
}

// Delete a node
Node *deleteNode(Node *list, int data) {
    Node *current = list;
    Node *prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            list = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }

    return list;
}

// Search for a node
Node *searchNode(Node *list, int data) {
    Node *current = list;

    while (current != NULL && current->data != data) {
        current = current->next;
    }

    return current;
}