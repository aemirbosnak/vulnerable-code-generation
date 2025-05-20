//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: recursive
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

// Function to append a node to the end of the list
struct Node* appendNode(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
    return new_node;
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to find the first pair of nodes with the same data
struct Node* findDuplicate(struct Node* head) {
    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL) {
        if (current->data == previous->data) {
            return current;
        }
        previous = current;
        current = current->next;
    }

    return NULL;
}

int main() {
    struct Node* head = NULL;

    // Example usage of the list operations
    head = appendNode(&head, 1);
    head = appendNode(&head, 2);
    head = appendNode(&head, 3);

    // Print the list
    printList(head);

    // Find the first pair of nodes with the same data
    struct Node* duplicate = findDuplicate(head);
    if (duplicate != NULL) {
        printf("Found duplicate at index %d\n", duplicate->data);
    } else {
        printf("No duplicates found\n");
    }

    return 0;
}