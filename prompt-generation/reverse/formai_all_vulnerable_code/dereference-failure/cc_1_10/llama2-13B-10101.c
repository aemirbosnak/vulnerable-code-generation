//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new linked list node
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of a linked list
void insertAtStart(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of a linked list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(data);
}

// Function to remove the first node from a linked list
void removeFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    struct Node* first_node = *head_ref;
    *head_ref = first_node->next;
    free(first_node);
}

// Function to remove the last node from a linked list
void removeLast(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    struct Node* last_node = *head_ref;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = NULL;
}

// Function to reverse a linked list
void reverse(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    struct Node* current = *head_ref;
    struct Node* previous = NULL;
    while (current != NULL) {
        struct Node* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head_ref = previous;
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes
    insertAtStart(&head, 1);
    insertAtStart(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);

    // Remove the first node
    removeFirst(&head);

    // Remove the last node
    removeLast(&head);

    // Reverse the list
    reverse(&head);

    // Print the list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}