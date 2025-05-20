//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

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
struct Node* insertNode(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
    return new_node;
}

// Function to insert a node at the end of the list
struct Node* insertNodeAtEnd(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(data);
    return current->next;
}

// Function to delete the first occurrence of a given node
struct Node* deleteNode(struct Node** head_ref, struct Node* node) {
    if (*head_ref == node) {
        *head_ref = node->next;
        free(node);
        return *head_ref;
    }
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        if (current->next == node) {
            current->next = node->next;
            free(node);
            return current->next;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete all nodes with the given data
struct Node* deleteAllNodesWithData(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current != NULL) {
        if (current->data == data) {
            current = deleteNode(head_ref, current);
            if (current == NULL) {
                break;
            }
        }
        current = current->next;
    }
    return *head_ref;
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes
    head = insertNodeAtEnd(&head, 1);
    head = insertNodeAtEnd(&head, 2);
    head = insertNodeAtEnd(&head, 3);

    // Delete all nodes with data 2
    head = deleteAllNodesWithData(&head, 2);

    // Print the linked list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}