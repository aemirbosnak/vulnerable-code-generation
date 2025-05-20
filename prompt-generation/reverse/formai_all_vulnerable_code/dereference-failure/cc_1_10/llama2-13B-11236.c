//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: statistical
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

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* new_node = newNode(data);
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->next = NULL;
}

// Function to remove the first node from the list
void removeFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    struct Node* first = *head_ref;
    *head_ref = first->next;
    free(first);
}

// Function to remove the last node from the list
void removeLast(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        return;
    }
    previous->next = NULL;
    free(current);
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes at the beginning of the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Insert some nodes at the end of the list
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    // Remove the first node from the list
    removeFirst(&head);

    // Remove the last node from the list
    removeLast(&head);

    // Print the linked list
    printList(head);

    return 0;
}