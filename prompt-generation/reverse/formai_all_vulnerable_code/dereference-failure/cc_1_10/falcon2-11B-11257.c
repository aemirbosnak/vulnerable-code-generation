//Falcon2-11B DATASET v1.0 Category: System administration ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the list
void insert_at_beginning(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to print the list
void print_list(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to delete the list
void delete_list(Node** head_ref) {
    Node* current = *head_ref;
    Node* prev = NULL;
    while (current!= NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

int main() {
    // Create a new node and insert it at the beginning of the list
    Node* head = NULL;
    insert_at_beginning(&head, 1);

    // Print the list
    print_list(head);

    // Delete the list
    delete_list(&head);

    return 0;
}