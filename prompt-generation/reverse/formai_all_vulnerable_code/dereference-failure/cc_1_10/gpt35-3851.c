//FormAI DATASET v1.0 Category: Linked list operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Create a structure for our linked list node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to print the linked list
void printLinkedList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node **head, int data) {
    // Create a new node and set its data value
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    // Set the new node's next pointer to the current head
    newNode->next = *head;

    // Update the head pointer to the new node
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node **head, int data) {
    // Create a new node and set its data value
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the linked list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
    } else {
        // Traverse the linked list to find the last node
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Set the last node's next pointer to the new node
        current->next = newNode;
    }
}

// Function to delete the first node of the linked list
void deleteFirstNode(Node **head) {
    // If the linked list is empty, return
    if (*head == NULL) {
        return;
    }

    // Save a reference to the current head node and update the head pointer
    Node *oldHead = *head;
    *head = (*head)->next;

    // Free the memory occupied by the old head node
    free(oldHead);
}

// Function to delete the last node of the linked list
void deleteLastNode(Node **head) {
    // If the linked list is empty, return
    if (*head == NULL) {
        return;
    }

    // If the linked list has only one node, delete it and set the head to NULL
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    // Traverse the linked list to find the second-last node
    Node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // Save a reference to the last node and update the second-last node's next pointer
    Node *oldLast = current->next;
    current->next = NULL;

    // Free the memory occupied by the old last node
    free(oldLast);
}

// Function to delete a node with a given value from the linked list
void deleteNodeWithValue(Node **head, int value) {
    // If the linked list is empty, return
    if (*head == NULL) {
        return;
    }

    // If the node to be deleted is the head node, delete it and update the head pointer
    if ((*head)->data == value) {
        Node *oldHead = *head;
        *head = (*head)->next;
        free(oldHead);
        return;
    }

    // Traverse the linked list to find the node with the given value
    Node *current = *head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    // If the node with the given value was not found, return
    if (current->next == NULL) {
        return;
    }

    // Save a reference to the node to be deleted and update the previous node's next pointer
    Node *oldNode = current->next;
    current->next = current->next->next;

    // Free the memory occupied by the old node
    free(oldNode);
}

int main() {
    // Initialize an empty linked list
    Node *head = NULL;

    // Insert some nodes at the beginning of the linked list
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);

    // Insert some more nodes at the end of the linked list
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);
    insertAtEnd(&head, 30);

    // Delete the first and last nodes of the linked list
    deleteFirstNode(&head);
    deleteLastNode(&head);

    // Delete a node with a given value from the linked list
    deleteNodeWithValue(&head, 10);

    // Print the final linked list
    printLinkedList(head);

    return 0;
}