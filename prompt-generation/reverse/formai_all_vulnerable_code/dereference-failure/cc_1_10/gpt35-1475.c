//FormAI DATASET v1.0 Category: Linked list operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define a struct for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node to the end of the linked list
void push(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    // Fill in the new node's data
    new_node->data = new_data;
    new_node->next = NULL;

    // If the linked list is empty, make the new node the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Otherwise, traverse the list to the end and add the new node there
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

// Function to delete a node with the given key from the linked list
void deleteNode(struct Node** head_ref, int key) {
    // Create a temporary node and two pointers
    struct Node* temp = *head_ref, *prev;

    // If the head node contains the key
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not found
    if (temp == NULL)
        return;

    // Remove the node
    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list contents
void traverse(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Add some nodes to the list
    push(&head, 1);
    push(&head, 3);
    push(&head, 5);
    push(&head, 7);
    push(&head, 9);

    // Print the initial list
    printf("Initial list contents: ");
    traverse(head);

    // Delete a node and print the updated list
    printf("Deleting node with value 5...\n");
    deleteNode(&head, 5);
    printf("Updated list contents: ");
    traverse(head);

    // Add more nodes and print the final list
    push(&head, 11);
    push(&head, 13);
    printf("Final list contents: ");
    traverse(head);

    // Free up memory used by the list
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}