//FormAI DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data; // Data stored in the node
    struct Node* next; // Pointer to the next node in the list
};

// Function to create a new node and initialize it with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new node
    newNode->data = data; // Set the data for the new node
    newNode->next = NULL; // Set the pointer to the next node to NULL
    return newNode; // Return the new node
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data); // Create a new node with the given data
    newNode->next = *head; // Set the pointer to the next node to the current head
    *head = newNode; // Set the head of the list to the new node
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data); // Create a new node with the given data
    if (*head == NULL) { // If the list is empty, set the head to the new node
        *head = newNode;
        return;
    }
    struct Node* current = *head; // Set a pointer to the head of the list
    while (current->next != NULL) { // Traverse the list to find the last node
        current = current->next;
    }
    current->next = newNode; // Set the pointer to the next node of the last node to the new node
}

// Function to insert a node at a given position in the list
void insertAtPosition(struct Node** head, int data, int position) {
    if (position == 0) { // If the position is 0, insert at the beginning of the list
        insertAtBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data); // Create a new node with the given data
    struct Node* current = *head; // Set a pointer to the head of the list
    for (int i = 0; i < position - 1 && current != NULL; i++) { // Traverse the list to find the previous node of the position
        current = current->next;
    }
    if (current == NULL) { // If the position is invalid, return
        printf("Invalid position\n");
        return;
    }
    newNode->next = current->next; // Set the pointer to the next node of the new node to the next node of the current node
    current->next = newNode; // Set the pointer to the next node of the current node to the new node
}

// Function to delete the first occurrence of a node with the given data in the list
void deleteNode(struct Node** head, int data) {
    struct Node* current = *head; // Set a pointer to the head of the list
    struct Node* previous = NULL; // Set a pointer to the previous node of the current node
    while (current != NULL && current->data != data) { // Traverse the list to find the node with the given data
        previous = current;
        current = current->next;
    }
    if (current == NULL) { // If the node is not found in the list, return
        printf("Node not found\n");
        return;
    }
    if (previous == NULL) { // If the node is the first node in the list, set the head of the list to the next node of the current node
        *head = current->next;
    } else { // Otherwise, set the pointer to the next node of the previous node to the next node of the current node
        previous->next = current->next;
    }
    free(current); // Free the memory of the current node
}

// Function to display the contents of the list
void displayList(struct Node* head) {
    printf("List: ");
    struct Node* current = head; // Set a pointer to the head of the list
    while (current != NULL) { // Traverse the list and print each node's data
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL; // Initialize the head of the list to NULL

    insertAtBeginning(&head, 5); // Insert a node with data 5 at the beginning of the list
    insertAtEnd(&head, 10); // Insert a node with data 10 at the end of the list
    displayList(head); // Display the contents of the list: 5 10

    insertAtPosition(&head, 7, 1); // Insert a node with data 7 at position 1 in the list
    displayList(head); // Display the contents of the list: 5 7 10

    insertAtPosition(&head, 3, 0); // Insert a node with data 3 at position 0 in the list (equivalent to inserting at the beginning of the list)
    displayList(head); // Display the contents of the list: 3 5 7 10

    deleteNode(&head, 7); // Delete the node with data 7 from the list
    displayList(head); // Display the contents of the list: 3 5 10

    deleteNode(&head, 4); // Delete a node with data 4 (which does not exist in the list)
    displayList(head); // Display the contents of the list: 3 5 10

    return 0; // End of the program
}