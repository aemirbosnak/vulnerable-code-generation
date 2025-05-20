//FormAI DATASET v1.0 Category: Linked list operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to insert a node at the end of the linked list
void insert_node(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct node *last = *head_ref;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

// Function to delete a node from the linked list
void delete_node(struct node **head_ref, int key) {
    struct node *temp = *head_ref, *prev;

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

// Function to print the linked list
void print_list(struct node *node_list) {
    while (node_list != NULL) {
        printf("%d ", node_list->data);
        node_list = node_list->next;
    }
}

// Driver program to test the above functions
int main() {
    struct node *head = NULL;

    // Insert nodes
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 5);

    // Print the linked list
    printf("Linked list before deletion: ");
    print_list(head);

    // Delete node with key = 3
    delete_node(&head, 3);

    // Print the linked list again
    printf("\nLinked list after deletion: ");
    print_list(head);

    return 0;
}