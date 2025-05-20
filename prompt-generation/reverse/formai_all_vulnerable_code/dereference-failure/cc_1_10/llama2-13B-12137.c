//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with a given value
struct Node* newNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
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

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int value) {
    struct Node* new_node = newNode(value);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to delete the first node of the list
void deleteFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Oops! The list is empty!\n");
        return;
    }
    struct Node* first_node = *head_ref;
    *head_ref = first_node->next;
    free(first_node);
}

// Function to traverse the list and find the first pair of nodes with the same value
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

    // Insert some nodes into the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 5);

    // Delete the first node of the list
    deleteFirst(&head);

    // Traverse the list and find the first pair of nodes with the same value
    struct Node* duplicate = findDuplicate(head);
    if (duplicate != NULL) {
        printf("Oops! Found a duplicate: %d\n", duplicate->data);
    } else {
        printf("Yay! No duplicates found!\n");
    }

    return 0;
}