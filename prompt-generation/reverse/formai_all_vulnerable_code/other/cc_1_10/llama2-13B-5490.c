//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(data);
}

// Function to remove the first node from the list
void removeFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    struct Node* first = *head_ref;
    *head_ref = first->next;
    free(first);
}

// Function to remove the last node from the list
void removeLast(struct Node** head_ref) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    free(current);
    *head_ref = NULL;
}

// Function to search for a node with the given data
struct Node* search(struct Node* head, int data) {
    while (head != NULL) {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    pthread_t threads[3];
    struct Node* head = NULL;

    // Create three threads to perform asynchronous operations
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, insertAtBeginning, &head);
    }

    // Wait for the threads to complete
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the list
    printList(head);

    // Remove the first node
    removeFirst(&head);

    // Print the list again
    printList(head);

    // Remove the last node
    removeLast(&head);

    // Print the list again
    printList(head);

    return 0;
}