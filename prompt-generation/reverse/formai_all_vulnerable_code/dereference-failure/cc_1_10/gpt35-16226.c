//FormAI DATASET v1.0 Category: Linked list operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node {
    int data;
    struct node *next;
};

// Define a function to insert a new node at the beginning of the list
void insert_at_beginning(struct node** head_ref, int value) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Define a function to append a new node at the end of the list
void append(struct node** head_ref, int value) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* last = *head_ref;
    new_node->data = value;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

// Define a function to insert a new node after a given node in the list
void insert_after_node(struct node* prev_node, int value) {
    if (prev_node == NULL) {
        printf("The previous node cannot be NULL!\n");
        return;
    }
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Define a function to delete a node with the given key
void delete_node(struct node** head_ref, int key) {
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
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// Define a function to print the entire list
void print_list(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Define the main function
int main() {
    // Create the first node
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    printf("Initially: \n");
    print_list(head);

    // Insert a new node at the beginning of the list
    printf("\nAfter inserting a node at the beginning: \n");
    insert_at_beginning(&head, 0);
    print_list(head);

    // Append a new node at the end of the list
    printf("\nAfter appending a node at the end: \n");
    append(&head, 4);
    print_list(head);

    // Insert a new node after the second node
    printf("\nAfter inserting a node after the second node: \n");
    insert_after_node(second, 10);
    print_list(head);

    // Delete a node with the given key
    printf("\nAfter deleting the node with the key 3: \n");
    delete_node(&head, 3);
    print_list(head);

    return 0;
}