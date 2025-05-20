//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given value
struct Node* newNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node** head_ref, int value) {
    struct Node* new_node = newNode(value);
    new_node->next = *head_ref;
    *head_ref = new_node;
    return *head_ref;
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node** head_ref, int value) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    struct Node* new_node = newNode(value);
    current->next = new_node;
    return *head_ref;
}

// Function to delete the first node from the list
struct Node* deleteFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }
    struct Node* first = *head_ref;
    *head_ref = first->next;
    free(first);
    return *head_ref;
}

// Function to delete the last node from the list
struct Node* deleteLast(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;
    while (current != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        return NULL;
    }
    previous->next = NULL;
    free(current);
    return previous;
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes at the beginning of the list
    head = insertAtBeginning(&head, 1);
    head = insertAtBeginning(&head, 2);
    head = insertAtBeginning(&head, 3);

    // Insert some nodes at the end of the list
    head = insertAtEnd(&head, 4);
    head = insertAtEnd(&head, 5);
    head = insertAtEnd(&head, 6);

    // Delete the first node from the list
    head = deleteFirst(&head);

    // Delete the last node from the list
    head = deleteLast(&head);

    // Print the final linked list
    printList(head);

    return 0;
}