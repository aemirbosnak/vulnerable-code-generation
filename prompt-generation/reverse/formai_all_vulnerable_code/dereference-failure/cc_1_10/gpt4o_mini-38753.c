//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the linked list
typedef struct Node {
    char data[100];
    struct Node* next;
} Node;

// Function declarations
Node* createNode(const char* data);
void appendNode(Node** head, const char* data);
void deleteNode(Node** head, const char* key);
void displayList(Node* node);
void freeList(Node* node);

/**
 * Create a new node with the given data.
 */
Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

/**
 * Append a node with given data to the end of the linked list.
 */
void appendNode(Node** head, const char* data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* lastNode = *head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

/**
 * Delete the first node that matches the given key.
 */
void deleteNode(Node** head, const char* key) {
    if (*head == NULL) return;

    Node* temp = *head;
    Node* prev = NULL;

    if (strcmp(temp->data, key) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    
    while (temp != NULL && strcmp(temp->data, key) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

/**
 * Display the content of the linked list.
 */
void displayList(Node* node) {
    while (node != NULL) {
        printf("%s -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

/**
 * Free all the nodes in the linked list.
 */
void freeList(Node* node) {
    Node* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

/**
 * The main function to demonstrate the linked list operations.
 */
int main() {
    Node* head = NULL;
    
    printf("Creating a linked list...\n");
    
    appendNode(&head, "Node 1");
    appendNode(&head, "Node 2");
    appendNode(&head, "Node 3");
    appendNode(&head, "Node 4");
    
    printf("Current linked list:\n");
    displayList(head);

    printf("Deleting 'Node 2'...\n");
    deleteNode(&head, "Node 2");
    
    printf("Linked list after deletion:\n");
    displayList(head);
    
    printf("Adding more nodes...\n");
    appendNode(&head, "Node 5");
    appendNode(&head, "Node 6");

    printf("Final linked list:\n");
    displayList(head);

    // Clean up memory before exit
    freeList(head);
    
    return 0;
}