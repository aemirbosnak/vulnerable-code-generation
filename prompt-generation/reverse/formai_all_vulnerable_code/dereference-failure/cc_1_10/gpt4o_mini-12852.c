//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data; // Data to hold
    struct Node* next; // Pointer to next node
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node with a specific value
void deleteNode(Node** head, int value) {
    if (*head == NULL) return;

    Node* temp = *head;
    Node* prev = NULL;

    // Check for the head node
    if (temp != NULL && temp->data == value) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        return;
    }

    // Search for the value to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If value not found
    if (temp == NULL) {
        printf("Value %d not found!\n", value);
        return;
    }

    // Unlink the node
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to clear the entire list
void clearList(Node** head) {
    Node* current = *head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL; // Set head to NULL after clearing
}

// Main function to operate the list
int main() {
    Node* head = NULL; // Initialize head

    // Random insertions
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    printf("Initial list:\n");
    displayList(head);

    // Deletion
    printf("Deleting 20...\n");
    deleteNode(&head, 20);
    displayList(head);

    // Attempting to delete a non-existent value
    printf("Attempting to delete 40...\n");
    deleteNode(&head, 40);

    // Inserting more nodes
    insertEnd(&head, 40);
    insertEnd(&head, 50);
    printf("List after insertions:\n");
    displayList(head);

    // Clear the list
    printf("Clearing the list...\n");
    clearList(&head);
    displayList(head); // Should show empty list

    // Free remaining head if any
    return 0;
}