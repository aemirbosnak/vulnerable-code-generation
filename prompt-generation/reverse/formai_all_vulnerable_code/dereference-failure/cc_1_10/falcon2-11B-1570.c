//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head_ref;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* prev = NULL;
    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        return; // Node not found
    }
    if (prev == NULL) {
        *head_ref = current->next; // Delete node if it's the last node
    } else {
        prev->next = current->next; // Delete node if it's not the last node
    }
    free(current); // Free memory used by deleted node
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning and end of the linked list
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Delete the node with data 10
    deleteNode(&head, 10);

    // Print the updated linked list
    printf("Updated Linked List: ");
    printList(head);

    return 0;
}