//FormAI DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Function to add a node at the beginning of the linked list
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head_ref, int key)
{
    struct Node* temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change its 'next' pointer
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    // Free memory
    free(temp);
}

// Driver program
int main()
{
    // Initialize linked list as 1->2->3->4
    struct Node* head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Linked list before deletion: ");
    printList(head);

    // Delete node with key value 3
    deleteNode(&head, 3);

    printf("\nLinked list after deletion of 3: ");
    printList(head);

    // Delete node with key value 1
    deleteNode(&head, 1);

    printf("\nLinked list after deletion of 1: ");
    printList(head);

    return 0;
}