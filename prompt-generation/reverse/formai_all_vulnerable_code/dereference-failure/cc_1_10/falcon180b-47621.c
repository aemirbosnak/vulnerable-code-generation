//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to append a node at the end of the list
void append_node(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    Node* last = *head_ref;
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

// Function to insert a node at the beginning of the list
void insert_node(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
    return;
}

// Function to delete a node with given data
void delete_node(Node** head_ref, int data) {
    Node* temp = *head_ref;
    Node* prev = NULL;
    if (temp!= NULL && temp->data == data) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
    return;
}

// Function to search for a node with given data
Node* search_node(Node* head, int data) {
    Node* current = head;
    while (current!= NULL && current->data!= data)
        current = current->next;
    if (current == NULL)
        return NULL;
    return current;
}

// Function to print the list
void print_list(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function
int main() {
    Node* head = NULL;

    // Inserting nodes
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);

    // Printing the list
    printf("Original list: ");
    print_list(head);

    // Deleting a node
    delete_node(&head, 2);

    // Printing the list
    printf("\nList after deleting node with data 2: ");
    print_list(head);

    // Searching for a node
    Node* found_node = search_node(head, 3);
    if (found_node!= NULL)
        printf("\nFound node with data 3.\n");
    else
        printf("\nNode with data 3 not found.\n");

    // Inserting a node at the beginning
    insert_node(&head, 0);

    // Printing the list
    printf("\nList after inserting node with data 0: ");
    print_list(head);

    return 0;
}