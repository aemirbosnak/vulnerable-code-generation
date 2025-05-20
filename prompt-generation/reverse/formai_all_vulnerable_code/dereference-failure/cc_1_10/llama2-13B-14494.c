//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to insert an element at the beginning of the list
void insertAtBeginning(struct Node **head_ref, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert an element at the end of the list
void insertAtEnd(struct Node **head_ref, int data) {
    struct Node *current = *head_ref;
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to delete an element from the list
void delete(struct Node **head_ref, int data) {
    struct Node *current = *head_ref;
    struct Node *previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (current == *head_ref) {
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

// Function to check if an element exists in the list
int contains(struct Node **head_ref, int data) {
    struct Node *current = *head_ref;

    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Function to traverse the list and print out all the elements
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;

    // Insert some elements at the beginning of the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Insert some elements at the end of the list
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    // Delete some elements from the list
    delete(&head, 2);
    delete(&head, 4);
    delete(&head, 6);

    // Check if an element exists in the list
    if (contains(&head, 3)) {
        printf("Element 3 exists in the list\n");
    } else {
        printf("Element 3 does not exist in the list\n");
    }

    // Traverse the list and print out all the elements
    printList(head);

    return 0;
}