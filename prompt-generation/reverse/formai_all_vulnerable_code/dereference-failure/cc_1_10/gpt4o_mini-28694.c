//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a Node in a doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function prototypes
Node* createNode(int data);
void append(Node** head_ref, int data);
void printList(Node* node);
void deleteNode(Node** head_ref, int position);
void freeList(Node** head_ref);

// Main function to demonstrate the doubly linked list
int main() {
    Node* head = NULL;

    // Let's create a dynamic environment with greetings
    printf("Welcome to the Lively Doubly Linked List Visualizer!\n");

    // Appending data to the list
    for (int i = 1; i <= 10; i++) {
        append(&head, i * 10);
    }

    printf("\nInitial List:\n");
    printList(head);

    // Deleting a node
    int pos = 4; // delete the 4th node
    printf("\nDeleting the node at position %d...\n", pos);
    deleteNode(&head, pos);
    
    printf("\nList after deletion:\n");
    printList(head);

    // Freeing the entire list
    freeList(&head);
    printf("\nAll nodes freed. Thank you for using the visualizer!\n");

    return 0;
}

// Function to create a new node with provided data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to append a new node at the end of the list
void append(Node** head_ref, int data) {
    Node* newNode = createNode(data);
    Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

// Function to print the nodes of the list
void printList(Node* node) {
    Node* last;
    printf("Traversal in forward direction:\n");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction:\n");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

// Function to delete a node at a specific position
void deleteNode(Node** head_ref, int position) {
    if (*head_ref == NULL || position <= 0) {
        printf("Position is out of bounds!\n");
        return;
    }

    Node* temp = *head_ref;
    
    // Traverse to position
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    // If position is more than number of nodes
    if (temp == NULL) {
        printf("Position does not exist!\n");
        return;
    }

    // Node is the node to be deleted
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else { // If node to be deleted is the head node
        *head_ref = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// Function to free the entire list
void freeList(Node** head_ref) {
    Node* current = *head_ref;
    Node* next;

    while (current != NULL) {
        next = current->next; // Store next node
        free(current); // Free current node
        current = next; // Move to next node
    }

    *head_ref = NULL; // Mark the list as empty
}