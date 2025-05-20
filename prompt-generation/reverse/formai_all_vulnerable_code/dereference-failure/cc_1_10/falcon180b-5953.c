//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Function prototypes
void add_node(struct node** head_ref, int new_data);
void delete_node(struct node **head_ref, int key);
void print_list(struct node* node);

int main() {
    struct node* head = NULL;

    // Add nodes
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);

    // Print the list
    printf("List after adding nodes: \n");
    print_list(head);

    // Delete a node
    delete_node(&head, 3);

    // Print the list after deleting a node
    printf("\nList after deleting node with value 3: \n");
    print_list(head);

    return 0;
}

// Function to add a node at the beginning of the list
void add_node(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to delete a node with the given key
void delete_node(struct node **head_ref, int key) {
    struct node* temp = *head_ref;
    struct node* prev_node = NULL;

    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev_node = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev_node->next = temp->next;
    free(temp);
}

// Function to print the list
void print_list(struct node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}