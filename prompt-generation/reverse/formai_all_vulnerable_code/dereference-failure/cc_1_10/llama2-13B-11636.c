//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new linked list
struct Node* newList() {
    struct Node* head = NULL;
    return head;
}

// Function to insert an element at the beginning of the linked list
struct Node* insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    return new_node;
}

// Function to insert an element at the end of the linked list
struct Node* insertAtEnd(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        current->next = new_node;
    }

    return new_node;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to remove the first element of the linked list
struct Node* removeFirst(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* result = current->next;

    // If the list is empty, return NULL
    if (current->next == NULL) {
        free(current);
        *head_ref = NULL;
        return NULL;
    }

    // Update the head node to point to the second node
    current->next = current->next->next;

    return result;
}

// Function to remove the last element of the linked list
struct Node* removeLast(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    // If the list is empty, return NULL
    if (current == NULL) {
        return NULL;
    }

    // Update the head node to point to the previous node
    previous->next = NULL;

    return current;
}

int main() {
    struct Node* head = newList();

    // Insert elements at the beginning of the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Insert elements at the end of the list
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    // Print the list
    printList(head);

    // Remove the first element
    struct Node* first = removeFirst(&head);
    printList(head);

    // Remove the last element
    struct Node* last = removeLast(&head);
    printList(head);

    return 0;
}