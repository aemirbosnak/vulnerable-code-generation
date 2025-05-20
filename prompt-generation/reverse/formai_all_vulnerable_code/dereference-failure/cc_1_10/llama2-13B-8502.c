//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with a given value
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

// Function to delete the first node of the list
void deleteFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    struct Node* first = *head_ref;
    *head_ref = first->next;
    free(first);
}

// Function to delete the last node of the list
void deleteLast(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    struct Node* current = *head_ref;
    struct Node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous != NULL) {
        previous->next = NULL;
    } else {
        *head_ref = NULL;
    }
    free(current);
}

// Function to traverse the list in a zigzag pattern
void traverseZigZag(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    struct Node* current = *head_ref;
    while (current != NULL) {
        printf("%d ", current->data);
        if (current == *head_ref) {
            printf("-> ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes in a zigzag pattern
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    deleteFirst(&head);
    insertAtBeginning(&head, 3);
    deleteLast(&head);

    // Traverse the list in a zigzag pattern
    traverseZigZag(&head);

    return 0;
}