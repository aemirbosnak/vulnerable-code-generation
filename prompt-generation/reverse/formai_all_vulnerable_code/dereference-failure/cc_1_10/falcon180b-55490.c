//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
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

    if (*head_ref == NULL)
        return;

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
    struct Node* temp = *head_ref, *prev;

    // If head node itself holds the key or if list is empty
    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;   
        free(temp);            
        return;
    }

    // Delete node from any other position
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp); 
    return;
}

// Function to search for a value in the list
struct Node* search(struct Node* head, int x) {
    struct Node* current = head;
    while (current!= NULL) {
        if (current->data == x)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Driver program to test above functions
int main() {
    struct Node* head = NULL;

    // Add 7 to the beginning.
    push(&head, 7);

    // Add 1 to the end.
    append(&head, 1);

    // Add 6 at position 2
    struct Node* last = search(head, 7);
    insertAfter(last, 6);

    // Print the list
    printf("Created Linked List: ");
    printList(head);

    // Delete node which has data as 1
    deleteNode(&head, 1);

    // Print the list after deleting 1
    printf("\nLinked List after deleting first occurrence of 1: ");
    printList(head);

    return 0;
}