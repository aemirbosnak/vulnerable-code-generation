//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with a given value
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to append a node to the end of a linked list
void appendNode(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at a specific position in the linked list
void insertNodeAt(struct Node** head_ref, int position, int data) {
    struct Node* current = *head_ref;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    struct Node* new_node = newNode(data);
    new_node->next = current->next;
    current->next = new_node;
}

// Function to remove the first occurrence of a given value in the linked list
void removeFirstOccurrence(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                *head_ref = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;

    // Create a linked list with the following nodes:
    // 1 -> 2 -> 3 -> 4 -> 5
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    // Insert a node at position 2:
    insertNodeAt(&head, 2, 6);

    // Remove the first occurrence of 3:
    removeFirstOccurrence(&head, 3);

    // Print the linked list:
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}