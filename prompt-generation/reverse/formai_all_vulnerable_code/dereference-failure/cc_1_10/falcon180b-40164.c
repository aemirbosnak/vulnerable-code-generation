//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
Node* create_node(int data);
void append_node(Node** head, int data);
void prepend_node(Node** head, int data);
void delete_node(Node** head, int data);
void print_list(Node* head);

int main() {
    Node* head = NULL;

    // Create a linked list with nodes containing data 1, 2, and 3
    append_node(&head, 1);
    append_node(&head, 2);
    prepend_node(&head, 3);

    // Print the linked list to verify that it was created correctly
    print_list(head);

    // Delete the node containing data 2
    delete_node(&head, 2);

    // Print the linked list again to verify that the node was deleted
    print_list(head);

    return 0;
}

// Create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Append a new node with the given data to the end of the linked list
void append_node(Node** head, int data) {
    Node* new_node = create_node(data);
    Node* temp = *head;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Prepend a new node with the given data to the beginning of the linked list
void prepend_node(Node** head, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Delete the first node in the linked list that contains the given data
void delete_node(Node** head, int data) {
    Node* temp = *head;
    if (temp == NULL) {
        printf("Error: Linked list is empty.\n");
        return;
    }
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Error: Data not found in linked list.\n");
        return;
    }
    Node* node_to_delete = temp->next;
    temp->next = temp->next->next;
    free(node_to_delete);
}

// Print the linked list
void print_list(Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    printf("Linked list: ");
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}