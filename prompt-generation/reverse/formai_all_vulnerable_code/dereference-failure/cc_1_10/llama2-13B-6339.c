//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

// Structure to represent a node in the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node with the given data
Node* newNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head_ref, int data) {
    Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head_ref, int data) {
    Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(data);
}

// Function to remove the first node from the list
Node* removeFirst(Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }
    Node* first = *head_ref;
    *head_ref = first->next;
    free(first);
    return first;
}

// Function to remove the last node from the list
Node* removeLast(Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }
    Node* current = *head_ref;
    Node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        // List is empty
        return NULL;
    }
    previous->next = NULL;
    free(current);
    return previous;
}

// Function to search for a node in the list
Node* search(Node* head, int data) {
    while (head != NULL) {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to traverse the list
void traverse(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list
    Node* head = NULL;
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Remove the first node
    Node* first = removeFirst(&head);
    printf("List after removing first node: ");
    traverse(head);

    // Remove the last node
    Node* last = removeLast(&head);
    printf("List after removing last node: ");
    traverse(head);

    // Search for a node
    Node* found = search(head, 3);
    if (found != NULL) {
        printf("Node found at position %d\n", found->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}