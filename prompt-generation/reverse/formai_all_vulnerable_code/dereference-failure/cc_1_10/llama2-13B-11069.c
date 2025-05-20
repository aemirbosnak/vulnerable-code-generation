//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;   // Data stored in the node
    struct Node *next; // Pointer to the next node in the list
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

// Function to remove the first node from the list
void removeFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = *head_ref;
    struct Node* previous = NULL;

    // Find the next node in the list
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    // Remove the first node
    previous->next = NULL;
    free(current);
    *head_ref = previous;
}

// Function to find a node with a given value
struct Node* findNode(struct Node* head, int data) {
    while (head != NULL) {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Remove the first node from the list
    removeFirst(&head);

    // Find a node with a given value
    struct Node* found = findNode(head, 2);

    // Print the list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}