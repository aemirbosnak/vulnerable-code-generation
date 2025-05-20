//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Defining the structure of a Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front of the linked list
void insertAtFront(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to delete a node by value
void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = *headRef, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *headRef = temp->next; // Changed head
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // Key was not present

    prev->next = temp->next; // Unlink the node
    free(temp); // Free memory
}

// Function to search for a value in the linked list
int searchList(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to free the linked list memory
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

// Main function to demonstrate linked list operations
int main() {
    struct Node* head = NULL; // Initialize the head of the list

    insertAtFront(&head, 10);
    insertAtFront(&head, 20);
    insertAtEnd(&head, 30);
    insertAtFront(&head, 40);
    insertAtEnd(&head, 50);
    
    printf("Linked List after insertions:\n");
    printList(head);

    printf("Searching for 30: %s\n", searchList(head, 30) ? "Found" : "Not Found");
    printf("Searching for 100: %s\n", searchList(head, 100) ? "Found" : "Not Found");

    deleteNode(&head, 20);
    printf("Linked List after deleting 20:\n");
    printList(head);

    deleteNode(&head, 40);
    printf("Linked List after deleting 40:\n");
    printList(head);
   
    // Clean up the memory
    freeList(head);
    head = NULL; // avoid dangling pointer

    return 0;
}