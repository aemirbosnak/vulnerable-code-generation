//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the linked list
typedef struct Node {
    char* name;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(const char* name);
void appendNode(Node** head, const char* name);
void displayList(Node* head);
void freeList(Node* head);
void memoryManager(Node* head);

int main() {
    Node* head = NULL;
    
    // Adding nodes to the linked list dynamically with unique names
    printf("Creating a dynamic linked list of names:\n");
    appendNode(&head, "Alice");
    appendNode(&head, "Bob");
    appendNode(&head, "Charlie");
    appendNode(&head, "Diana");
    appendNode(&head, "Edward");

    // Display the list before freeing memory
    printf("\nCurrent list of names:\n");
    displayList(head);

    // Memory management demonstration
    memoryManager(head);

    return 0;
}

// Function to create a new node
Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed for new node.\n");
        exit(1);
    }
    
    // Allocate memory for the name
    newNode->name = (char*)malloc(strlen(name) + 1);
    if (!newNode->name) {
        printf("Memory allocation failed for name.\n");
        free(newNode);
        exit(1);
    }

    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Function to append a new node to the end of the list
void appendNode(Node** head, const char* name) {
    Node* newNode = createNode(name);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the names in the list
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

// Function to free the memory used by the linked list
void freeList(Node* head) {
    Node* current = head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current->name);  // Free the name memory
        free(current);        // Free the node itself
        current = nextNode;
    }
}

// Function to manage and free memory dynamically
void memoryManager(Node* head) {
    printf("\nFreeing the memory allocated for the linked list...\n");
    
    // Free the list
    freeList(head);
    
    printf("Memory freed successfully! The linked list no longer exists.\n");
}