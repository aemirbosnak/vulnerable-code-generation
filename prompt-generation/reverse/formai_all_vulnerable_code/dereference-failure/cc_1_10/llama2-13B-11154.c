//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
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

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int value) {
    struct Node* new_node = newNode(value);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to delete the first node of the linked list
void deleteFirst(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Oops! The list is empty!\n");
        return;
    }
    struct Node* current = *head_ref;
    *head_ref = current->next;
    free(current);
}

// Function to find a node in the linked list
struct Node* findNode(struct Node* head, int value) {
    while (head != NULL) {
        if (head->data == value) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Print the linked list
    printList(head);

    // Delete the first node
    deleteFirst(&head);

    // Print the linked list again
    printList(head);

    // Find a node in the linked list
    struct Node* found = findNode(head, 2);
    if (found != NULL) {
        printf("Found node with value %d\n", found->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}