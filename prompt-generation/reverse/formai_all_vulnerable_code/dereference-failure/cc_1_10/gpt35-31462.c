//FormAI DATASET v1.0 Category: Linked list operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node *next;
};

// Define the head of the list
struct Node *head = NULL;

// Function to insert a node at the beginning of the list
void insertAtBeginning(int value) {
    // Allocate memory for a new node
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    
    // Set the data and next pointer for the new node
    newNode->data = value;
    newNode->next = head;
    
    // Update the head to point to the new node
    head = newNode;
    
    printf("Inserted %d at the beginning of the list.\n", value);
}

// Function to insert a node at the end of the list
void insertAtEnd(int value) {
    // Allocate memory for a new node
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    
    // Set the data and next pointer for the new node
    newNode->data = value;
    newNode->next = NULL;
    
    // If the list is empty, set the head to point to the new node
    if (head == NULL) {
        head = newNode;
        printf("Inserted %d at the end of the list.\n", value);
        return;
    }
    
    // Traverse the list to find the last node
    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // Set the next pointer of the last node to point to the new node
    current->next = newNode;
    printf("Inserted %d at the end of the list.\n", value);
}

// Function to print all nodes in the list
void printList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    // Traverse the list and print each node's data
    struct Node *current = head;
    printf("List contents:\n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to delete a node with a given value
void deleteNode(int value) {
    // If the list is empty, nothing to delete
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    // If the first node has the value, update the head to point to the second node
    if (head->data == value) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        printf("Deleted node with value %d.\n", value);
        return;
    }
    
    // Traverse the list to find the node with the given value
    struct Node *current = head->next;
    struct Node *previous = head;
    while (current != NULL) {
        if (current->data == value) {
            // Update the previous node's next pointer to skip over the node to be deleted
            previous->next = current->next;
            free(current);
            printf("Deleted node with value %d.\n", value);
            return;
        }
        previous = current;
        current = current->next;
    }
    
    printf("Node with value %d not found in the list.\n", value);
}

// Example usage of the linked list functions
int main() {
    // Insert 10 at the beginning of the list
    insertAtBeginning(10);
    
    // Insert 5 at the beginning of the list
    insertAtBeginning(5);
    
    // Insert 20 at the end of the list
    insertAtEnd(20);
    
    // Print the contents of the list
    printList();
    
    // Delete node with value 5
    deleteNode(5);
    
    // Print the contents of the list again
    printList();
    
    return 0;
}