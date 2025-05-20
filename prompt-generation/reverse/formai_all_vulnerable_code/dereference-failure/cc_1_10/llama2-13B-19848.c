//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
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

// Function to remove the first node from the list
void removeFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* first_node = *head_ref;
    *head_ref = first_node->next;
    free(first_node);
}

// Function to traverse the list in a zigzag pattern
void traverseZigzag(struct Node* head) {
    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL) {
        if (current == head) {
            printf("Current node is the head\n");
        } else {
            printf("Current node is not the head\n");
        }

        if (previous == NULL) {
            printf("Traversing in a zigzag pattern\n");
        }

        previous = current;
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Remove the first node from the list
    removeFirst(&head);

    // Traverse the list in a zigzag pattern
    traverseZigzag(head);

    return 0;
}