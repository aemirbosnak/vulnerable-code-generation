//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

// Structure to represent a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with the given data
Node* newNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node** head_ref, int data) {
    Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head_ref, int data) {
    Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(data);
}

// Function to delete the first occurrence of a given value in the linked list
void deleteFirstOccurrence(Node** head_ref, int data) {
    Node* current = *head_ref;
    Node* previous = NULL;

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        if (previous == NULL) {
            *head_ref = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

// Function to delete all occurrences of a given value in the linked list
void deleteAllOccurrences(Node** head_ref, int data) {
    Node* current = *head_ref;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                *head_ref = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
        }
        previous = current;
        current = current->next;
    }
}

// Function to search for a given value in the linked list
int search(Node* head, int data) {
    Node* current = head;

    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list with some nodes
    Node* head = NULL;
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Delete all occurrences of 3 in the linked list
    deleteAllOccurrences(&head, 3);

    // Print the linked list
    printList(head);

    return 0;
}