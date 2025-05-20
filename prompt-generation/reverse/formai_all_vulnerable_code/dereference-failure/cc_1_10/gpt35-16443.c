//FormAI DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Define the linked list node
struct node {
    int data;
    struct node *next;
};

// Function to add a new node to the linked list
void insertNode(int data, struct node **head) {
    // Create a new node
    struct node *newNode = malloc(sizeof(struct node));

    // Set the node data
    newNode->data = data;

    // Set the node's next pointer
    newNode->next = *head;

    // Set the head pointer to the new node
    *head = newNode;
}

// Function to delete a node from the linked list
void deleteNode(int data, struct node **head) {
    // If the list is empty, do nothing
    if (*head == NULL) {
        return;
    }

    // If the node to be deleted is at the head
    if ((*head)->data == data) {
        // Save the next node
        struct node *nextNode = (*head)->next;

        // Free the head node
        free(*head);

        // Update the head pointer to the next node
        *head = nextNode;

        return;
    }

    // If the node is not at the head, search for it
    struct node *currentNode = *head;

    while (currentNode->next != NULL) {
        // Save the next node
        struct node *nextNode = currentNode->next;

        // If the next node has the desired data, delete it
        if (nextNode->data == data) {
            // Set the current node's next pointer to the node after the next node
            currentNode->next = nextNode->next;

            // Delete the next node
            free(nextNode);

            return;
        }

        // Advance to the next node
        currentNode = nextNode;
    }
}

// Function to print the contents of the linked list
void printList(struct node *head) {
    printf("List contents:\n");

    struct node *currentNode = head;

    while (currentNode != NULL) {
        printf("%d ", currentNode->data);

        currentNode = currentNode->next;
    }

    printf("\n");
}

// Main function
int main() {
    // Initialize an empty linked list
    struct node *head = NULL;

    // Insert some nodes
    insertNode(3, &head);
    insertNode(5, &head);
    insertNode(7, &head);
    insertNode(9, &head);

    // Print the list
    printList(head);

    // Delete a node
    deleteNode(5, &head);

    // Print the list again
    printList(head);

    return 0;
}