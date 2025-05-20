//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to insert a new node at the beginning of the linked list
void insertNode(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head_ref, int data_to_delete) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    struct Node* current = *head_ref;

    while (current!= NULL && current->data!= data_to_delete) {
        prev = current;
        current = current->next;
    }

    if (current!= NULL) {
        if (prev == NULL) {
            *head_ref = current->next;
            free(current);
        } else {
            prev->next = current->next;
            free(current);
        }
    }
}

int main() {
    // Create the head node
    struct Node* head = NULL;

    // Insert some nodes into the linked list
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Print the original linked list
    printf("Original Linked List:\n");
    printList(head);

    // Delete the node with data 2
    deleteNode(&head, 2);

    // Print the updated linked list
    printf("Updated Linked List:\n");
    printList(head);

    return 0;
}