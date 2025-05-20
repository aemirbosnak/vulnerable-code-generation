//FormAI DATASET v1.0 Category: Linked list operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Defining the Node Structure
struct Node {
    int data;
    struct Node* next;
};

// Function to initialize a linked list
void init(struct Node** head_ref) {
    *head_ref = NULL;
}

// Function to add a node at the end of the list
void addNode(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

// Function to delete a node from the list
void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to print the list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("[%d]->", node->data);
        node = node->next;
    }
    printf("[NULL]\n");
}

// Main function
int main() {
    // Initialize the Linked List
    struct Node* head;
    init(&head);
    // Add 5 nodes to the Linked List
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);
    printf("Initial Linked List:\n");
    printList(head);
    // Delete the node with the value 30
    deleteNode(&head, 30);
    printf("Linked List After Deleting 30:\n");
    printList(head);
    // Delete the node with the value 10
    deleteNode(&head, 10);
    printf("Linked List After Deleting 10:\n");
    printList(head);
    // Delete the node with the value 5 (which doesn't exist in the list)
    deleteNode(&head, 5);
    printf("Linked List After Deleting 5:\n");
    printList(head);
    return 0;
}