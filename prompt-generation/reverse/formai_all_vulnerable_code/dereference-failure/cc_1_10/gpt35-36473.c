//FormAI DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// define a structure name node
struct node {
    int data;
    struct node *next;
};

// Function to print the Linked List
void printList(struct node* head)
{
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to Insert a node at the beginning of a Linked List 
void push(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to Insert a node in the middle of a Linked List 
void insertAfter(struct node *prev_node, int new_data)
{
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node from a Linked List 
void deleteNode(struct node **head_ref, int key)
{
    struct node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

// Main function to demonstrate the use of Linked List
int main()
{
    struct node* head = NULL;

    // Add nodes to the Linked List
    push(&head, 3);
    push(&head, 8);
    push(&head, 1);
    push(&head, 13);

    // Print the Linked List
    printf("Linked List: ");
    printList(head);

    // Insert a node in the middle of the Linked List
    insertAfter(head->next->next, 5);

    // Print the Linked List
    printf("Linked List after inserting a node in the middle: ");
    printList(head);

    // Delete a node from the Linked List
    deleteNode(&head, 8);

    // Print the Linked List
    printf("Linked List after deleting a node: ");
    printList(head);

    return 0;
}