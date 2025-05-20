//FormAI DATASET v1.0 Category: Linked list operations ; Style: Ada Lovelace
// Ada Lovelace style Linked List example program in C

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the Linked List
struct node {
    int data;
    struct node *next;
};

// Function to print out the Linked List
void printList(struct node *head) {
    struct node *current = head;

    printf("List: ");

    // Traverse through the Linked List
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Function to insert a new node at the beginning of the Linked List
void push(struct node **head_ref, int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

// Function to insert a new node after a given node in the Linked List
void insertAfter(struct node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Error: Given node cannot be NULL.\n");
        return;
    }

    struct node *new_node = (struct node*) malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = prev_node->next;

    prev_node->next = new_node;
}

// Function to insert a new node at the end of the Linked List
void append(struct node **head_ref, int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    struct node *last = (*head_ref);

    new_node->data = data;
    new_node->next = NULL;

    if ((*head_ref) == NULL) {
        (*head_ref) = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Function to delete a node from the Linked List
void delete(struct node **head_ref, int data) {
    struct node *temp = (*head_ref), *prev;

    // If head node itself holds the data to be deleted
    if (temp != NULL && temp->data == data) {
        (*head_ref) = temp->next;
        free(temp);
        return;
    }

    // Traverse through the Linked List to find the node to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the data was not found in the Linked List
    if (temp == NULL) {
        printf("Error: Data not found in the List.\n");
        return;
    }

    // Unlink the node from the Linked List
    prev->next = temp->next;
    free(temp);
}

int main() {
    // Start with an empty Linked List
    struct node *head = NULL;

    // Insert nodes into the Linked List
    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);

    // Print out the original Linked List
    printList(head);

    // Delete a node from the Linked List
    delete(&head, 1);

    // Print out the updated Linked List
    printList(head);

    return 0;
}