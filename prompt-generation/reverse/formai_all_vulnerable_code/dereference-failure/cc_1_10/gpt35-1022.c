//FormAI DATASET v1.0 Category: Linked list operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct node {
    int data;
    struct node *next;
};

// Function to add a node at the beginning of the linked list
void push(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to add a node after a given node in the linked list
void insert_after(struct node *prev_node, int new_data) {
    if(prev_node == NULL) {
        printf("The given previous node cannot be NULL.");
        return;
    }
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to add a node at the end of the linked list
void append(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    struct node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL)
        last = last->next;
    last->next = new_node;
}

// Function to remove a node with the given key from the linked list
void delete_node(struct node **head_ref, int key) {
    struct node *temp = *head_ref, *prev;
    if(temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// Function to print out the contents of the linked list
void print_list(struct node *node) {
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Driver function to test the linked list functions
int main() {
    struct node *head = NULL;
    printf("Linked list operations program\n\n");
    printf("Adding nodes at the beginning:\n");
    push(&head, 3);
    push(&head, 1);
    push(&head, 7);
    print_list(head);
    printf("\n\nAdding nodes after a given node:\n");
    insert_after(head->next, 5);
    insert_after(head->next, 2);
    print_list(head);
    printf("\n\nAdding nodes at the end:\n");
    append(&head, 9);
    append(&head, 4);
    print_list(head);
    printf("\n\nDeleting a node with key 5:\n");
    delete_node(&head, 5);
    print_list(head);
    printf("\n\nDeleting a node with key 7:\n");
    delete_node(&head, 7);
    print_list(head);
    return 0;
}