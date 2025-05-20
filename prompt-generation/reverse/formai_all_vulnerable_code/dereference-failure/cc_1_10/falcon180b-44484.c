//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure definition
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Function declarations
Node* createNode(char* data);
void addNode(Node** head, char* data);
Node* searchNode(Node* head, char* data);
void printList(Node* head);

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, "apple");
    addNode(&head, "banana");
    addNode(&head, "cherry");
    addNode(&head, "date");
    addNode(&head, "elderberry");

    // Print the list
    printf("Original list:\n");
    printList(head);

    // Search for a node
    Node* foundNode = searchNode(head, "banana");

    // Print the found node
    if (foundNode!= NULL) {
        printf("\nFound node: %s\n", foundNode->data);
    } else {
        printf("\nNode not found.\n");
    }

    return 0;
}

// Function to create a new node
Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory error: could not allocate space for new node.\n");
        exit(1);
    }

    strcpy(newNode->data, data);
    newNode->next = NULL;

    return newNode;
}

// Function to add a node to the list
void addNode(Node** head, char* data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* currentNode = *head;

    while (currentNode->next!= NULL) {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
}

// Function to search for a node
Node* searchNode(Node* head, char* data) {
    Node* currentNode = head;

    while (currentNode!= NULL) {
        if (strcmp(currentNode->data, data) == 0) {
            return currentNode;
        }

        currentNode = currentNode->next;
    }

    return NULL;
}

// Function to print the list
void printList(Node* head) {
    Node* currentNode = head;

    while (currentNode!= NULL) {
        printf("%s -> ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("NULL\n");
}