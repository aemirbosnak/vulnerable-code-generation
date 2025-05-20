//FormAI DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a function to insert a new node at the beginning of the list
void insertNode(struct Node** headRef, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Define a function to delete a node from the list
void deleteNode(struct Node** headRef, int data) {
    // Find the first node with matching data
    struct Node* currentNode = *headRef;
    struct Node* previousNode = NULL;

    while (currentNode != NULL && currentNode->data != data) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    // If the node was found, delete it
    if (currentNode != NULL) {
        if (previousNode == NULL) {
            *headRef = currentNode->next;
        } else {
            previousNode->next = currentNode->next;
        }
        free(currentNode);
    }
}

// Define a function to print the list
void printList(struct Node* head) {
    struct Node* currentNode = head;

    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("\n");
}

int main() {
    // Create an empty list
    struct Node* head = NULL;

    // Insert some nodes
    insertNode(&head, 5);
    insertNode(&head, 10);
    insertNode(&head, 15);
    insertNode(&head, 20);

    // Print the list
    printf("Original list: ");
    printList(head);

    // Delete a node from the list
    deleteNode(&head, 10);

    // Print the list again
    printf("Modified list: ");
    printList(head);

    // Delete all the nodes from the list
    while (head != NULL) {
        deleteNode(&head, head->data);
    }

    // Print the list one last time (should be empty)
    printf("Final list: ");
    printList(head);

    return 0;
}