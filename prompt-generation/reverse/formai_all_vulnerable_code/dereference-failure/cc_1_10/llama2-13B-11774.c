//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with a given value
struct node* newNode(int data) {
    struct node* node = malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct node** head_ref, int data) {
    struct node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct node** head_ref, int data) {
    struct node* current = *head_ref;
    struct node* new_node = newNode(data);
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to remove the first occurrence of a given value from the list
void removeFirstOccurrence(struct node** head_ref, int data) {
    struct node* current = *head_ref;
    struct node* previous = NULL;
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

// Function to remove all occurrences of a given value from the list
void removeAllOccurrences(struct node** head_ref, int data) {
    struct node* current = *head_ref;
    struct node* previous = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                *head_ref = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    struct node* head = NULL;

    // Insert some nodes
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Print the list
    printList(head);

    // Remove the first occurrence of 2
    removeFirstOccurrence(&head, 2);

    // Print the list again
    printList(head);

    // Remove all occurrences of 3
    removeAllOccurrences(&head, 3);

    // Print the list again
    printList(head);

    return 0;
}