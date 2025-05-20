//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Brave-style linked list operations example program

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with a given value
struct Node* newNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node** head_ref, int value) {
    struct Node* new_node = newNode(value);
    new_node->next = *head_ref;
    *head_ref = new_node;
    return new_node;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node** head_ref, int value) {
    struct Node* current = *head_ref;
    struct Node* new_node = newNode(value);

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    new_node->next = NULL;

    return new_node;
}

// Function to delete the first node of the linked list
struct Node* deleteFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }

    struct Node* temp = *head_ref;
    *head_ref = temp->next;
    free(temp);

    return *head_ref;
}

// Function to delete the last node of the linked list
struct Node* deleteLast(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }

    struct Node* current = *head_ref;
    struct Node* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        *head_ref = NULL;
    } else {
        previous->next = NULL;
    }

    free(current);

    return *head_ref;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning of the list
    head = insertAtBeginning(&head, 1);
    head = insertAtBeginning(&head, 2);
    head = insertAtBeginning(&head, 3);

    // Insert nodes at the end of the list
    head = insertAtEnd(&head, 4);
    head = insertAtEnd(&head, 5);
    head = insertAtEnd(&head, 6);

    // Print the linked list
    printList(head);

    // Delete the first node of the list
    head = deleteFirst(&head);

    // Print the linked list again
    printList(head);

    // Delete the last node of the list
    head = deleteLast(&head);

    // Print the linked list again
    printList(head);

    return 0;
}