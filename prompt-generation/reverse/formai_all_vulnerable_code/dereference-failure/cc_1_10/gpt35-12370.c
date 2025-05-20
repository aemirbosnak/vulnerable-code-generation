//FormAI DATASET v1.0 Category: Data structures visualization ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define a basic linked list structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node into the list at a specified index
void insertNode(struct Node** head, int index, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    
    // If the index is 0, insert the node at the beginning of the list
    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        // Find the node just before the specified index
        struct Node* prevNode = *head;
        for (int i = 0; i < index - 1; i++) {
            prevNode = prevNode->next;
        }
        
        // Insert the new node
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
}

// Function to remove a node from the list at a specified index
void removeNode(struct Node** head, int index) {
    // If the index is 0, remove the first node in the list
    if (index == 0) {
        struct Node* nodeToRemove = *head;
        *head = (*head)->next;
        free(nodeToRemove);
    } else {
        // Find the node just before the specified index
        struct Node* prevNode = *head;
        for (int i = 0; i < index - 1; i++) {
            prevNode = prevNode->next;
        }
        
        // Remove the node
        struct Node* nodeToRemove = prevNode->next;
        prevNode->next = nodeToRemove->next;
        free(nodeToRemove);
    }
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
}

int main() {
    struct Node* head = NULL;
    
    // Insert some nodes into the list
    insertNode(&head, 0, 5);
    insertNode(&head, 1, 10);
    insertNode(&head, 2, 15);
    insertNode(&head, 1, 20);
    
    // Print the list
    printf("Initial list: ");
    printList(head);
    printf("\n");
    
    // Remove a node from the list
    removeNode(&head, 2);
    
    // Print the updated list
    printf("Updated list: ");
    printList(head);
    printf("\n");
    
    return 0;
}