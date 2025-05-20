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

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode(data);
}

// Function to print all the nodes in the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
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

// Function to remove all occurrences of a given value in the linked list
void removeAllOccurrences(struct Node** head_ref, int data) {
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
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes into the linked list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);

    // Print the linked list
    printList(head);

    // Remove the first occurrence of 2 from the linked list
    removeFirstOccurrence(&head, 2);

    // Print the updated linked list
    printList(head);

    // Remove all occurrences of 2 from the linked list
    removeAllOccurrences(&head, 2);

    // Print the updated linked list
    printList(head);

    return 0;
}