//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: retro
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

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the linked list
struct Node* insertNode(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
    return new_node;
}

// Function to delete the node with the given value from the linked list
struct Node* deleteNode(struct Node** head_ref, int data) {
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
            return current;
        }
        previous = current;
        current = current->next;
    }

    return NULL;
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes
    head = insertNode(&head, 10);
    head = insertNode(&head, 20);
    head = insertNode(&head, 30);

    // Print the linked list
    printList(head);

    // Delete the node with value 20
    head = deleteNode(&head, 20);

    // Print the updated linked list
    printList(head);

    return 0;
}