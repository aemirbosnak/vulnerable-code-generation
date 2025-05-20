//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: optimized
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

// Function to insert a node at the beginning of the linked list
void insertAtStart(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to delete the first node of the linked list
struct Node* deleteFirst(struct Node** head_ref) {
    struct Node* node = *head_ref;
    *head_ref = node->next;
    free(node);
    return node;
}

// Function to find the node with the given data and return its index
int findIndex(struct Node* head, int data) {
    int index = 0;
    struct Node* current = head;
    while (current != NULL && current->data != data) {
        index++;
        current = current->next;
    }
    return index;
}

// Function to reverse the linked list
void reverse(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* previous = NULL;
    while (current != NULL) {
        struct Node* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head_ref = previous;
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes
    insertAtStart(&head, 1);
    insertAtStart(&head, 2);
    insertAtStart(&head, 3);
    insertAtStart(&head, 4);

    // Delete the first node
    struct Node* node = deleteFirst(&head);
    printf("Deleted node: %d\n", node->data);

    // Find the index of a node
    int index = findIndex(head, 2);
    printf("Node with index %d: %d\n", index, head->data);

    // Reverse the linked list
    reverse(&head);
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}