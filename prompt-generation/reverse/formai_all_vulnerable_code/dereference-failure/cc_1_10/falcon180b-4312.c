//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to add a node at the end of the list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;
    return;
}

// Function to add a node after a given position
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }

    struct Node* new_node = newNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    return;
}

// Function to delete a node by key
void deleteNode(struct Node **head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev;

    // If head node itself holds the key or if list is empty
    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;   
        free(temp);            
        return;
    }

    // Search for the key to be deleted
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);  
    return;
}

// Function to search for a node with given data
struct Node* search(struct Node* head, int x) {
    struct Node* current = head;
    while (current!= NULL) {
        if (current->data == x)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;

    // Insert 7 at the beginning.
    push(&head, 7);

    // Insert 1 at the end.
    append(&head, 1);

    // Insert 6 at position 1.
    insertAfter(head->next, 6);

    // Print the list.
    printf("Created Linked List: ");
    printList(head);

    // Search for a node.
    struct Node* found_node = search(head, 6);
    if (found_node == NULL)
        printf("\n6 not present in linked list");
    else
        printf("\n6 found in linked list");

    // Delete a node.
    deleteNode(&head, 1);
    printf("\nLinked List after deleting 1: ");
    printList(head);

    return 0;
}