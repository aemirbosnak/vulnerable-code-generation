//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
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

// Function to remove the first node from the list
struct Node* removeFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
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

    return previous;
}

// Function to traverse the list and print the data
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Remove the first node from the list
    struct Node* first_node = removeFirst(&head);

    // Traverse the list and print the data
    printList(head);

    return 0;
}