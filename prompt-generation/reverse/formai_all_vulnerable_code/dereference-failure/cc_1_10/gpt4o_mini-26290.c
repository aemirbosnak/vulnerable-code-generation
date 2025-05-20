//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node at the end of the linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a node by value from the linked list
void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev = NULL;

    // If the head node holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Key was not present in linked list
    if (temp == NULL) {
        printf("The value %d was not found in the list.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(Node* node) {
    if (node == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to free the entire linked list
void freeList(Node** head) {
    Node* current = *head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL; // Set head to NULL
}

// Main function to test the linked list operations
int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printf("Initial list: ");
    printList(head);

    insertAtBeginning(&head, 5);
    printf("After inserting at beginning: ");
    printList(head);

    deleteNode(&head, 20);
    printf("After deleting 20: ");
    printList(head);

    deleteNode(&head, 10);
    printf("After deleting 10: ");
    printList(head);

    deleteNode(&head, 100); // Trying to delete a non-existing element

    freeList(&head);
    printf("After freeing the list: ");
    printList(head); // List should be empty

    return 0;
}