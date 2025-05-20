//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
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

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node by its value
void deleteNode(Node** head, int value) {
    Node* temp = *head;
    Node* prev = NULL;

    // Check if the head needs to be removed
    if (temp != NULL && temp->data == value) {
        *head = temp->next; // Change the head to next node
        free(temp); // Free the old head
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not found in the list
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted from the list.\n", value);
}

// Function to count the number of nodes in the list
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to reverse the linked list
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current; // Move prev and current one step forward
        current = next;
    }
    *head = prev; // Reset head to the new front
}

// Main function to demonstrate linked list operations
int main() {
    Node* head = NULL; // Initialize head pointer

    // Insert nodes into the linked list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    // Display the current list
    displayList(head);

    // Count nodes in the list
    int length = countNodes(head);
    printf("Total nodes in the list: %d\n", length);

    // Delete a node by value
    deleteNode(&head, 30); // Attempt to delete node with value 30
    displayList(head); // Show list after deletion

    // Reverse the linked list
    reverseList(&head);
    printf("List after reversal:\n");
    displayList(head); // Show reversed list

    // Clean up the linked list
    while (head != NULL) {
        deleteNode(&head, head->data); // Free each node
    }

    // Final confirmation of cleanup
    printf("All nodes deleted. The list is now empty:\n");
    displayList(head); // Should indicate the list is empty

    return 0;
}