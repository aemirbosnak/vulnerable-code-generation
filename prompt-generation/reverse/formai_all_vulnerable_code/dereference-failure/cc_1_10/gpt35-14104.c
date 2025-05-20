//FormAI DATASET v1.0 Category: Linked list operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Insert element at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Set new data and next pointer
    new_node->data = new_data;
    new_node->next = (*head_ref);
    // Update head pointer
    (*head_ref) = new_node;
}

// Insert element at the end of the list
void insertAtEnd(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Set new data and next pointer
    new_node->data = new_data;
    new_node->next = NULL;

    // If list is empty, set new node as head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Traverse to the last node
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // Link new node to the last node
    last->next = new_node;
}

// Delete a node with given key
void deleteNode(struct Node** head_ref, int key) {
    // Keep track of previous node
    struct Node* prev_node = NULL;
    // Traverse the list
    struct Node* curr_node = *head_ref;
    while (curr_node != NULL && curr_node->data != key) {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    // If key is not found
    if (curr_node == NULL) {
        printf("Key not found!\n");
        return;
    }

    // If key is at head
    if (prev_node == NULL) {
        *head_ref = curr_node->next;
    } else { // If key is in middle or end
        prev_node->next = curr_node->next;
    }

    // Free memory of deleted node
    free(curr_node);
}

// Print the list
void printList(struct Node* node) {
    // Traverse and print
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements at the beginning
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    printf("List after inserting at the beginning: ");
    printList(head);

    // Insert elements at the end
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    printf("List after inserting at the end: ");
    printList(head);

    // Delete nodes
    deleteNode(&head, 3);
    printf("List after deleting node with key 3: ");
    printList(head);
    deleteNode(&head, 6);
    printf("List after deleting node with key 6: ");
    printList(head);

    return 0;
}