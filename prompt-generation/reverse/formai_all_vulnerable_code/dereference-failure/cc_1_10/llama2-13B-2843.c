//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;  // data stored in the node
    struct Node* next; // pointer to the next node in the list
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to delete the first node from the list
struct Node* deleteFirst(struct Node** head_ref) {
    struct Node* first_node = *head_ref;
    *head_ref = first_node->next;
    free(first_node);
    return first_node;
}

// Function to find and delete a node with the given data
struct Node* findAndDelete(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    while (current != NULL) {
        if (current->data == data) {
            struct Node* next = current->next;
            free(current);
            return next;
        }
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

    // Delete the first node from the list
    struct Node* first_node = deleteFirst(&head);
    printf("Deleted first node: %d\n", first_node->data);

    // Find and delete a node with the data 2
    struct Node* node_to_delete = findAndDelete(&head, 2);
    printf("Deleted node: %d\n", node_to_delete->data);

    // Print the remaining nodes in the list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}