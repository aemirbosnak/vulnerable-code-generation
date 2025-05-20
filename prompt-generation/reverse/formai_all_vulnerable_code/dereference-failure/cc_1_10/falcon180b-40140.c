//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
Node* create_node(int data);
void add_node(Node** head, int data);
void delete_node(Node** head, int data);
void print_list(Node* head);

int main() {
    // Create an empty list
    Node* head = NULL;

    // Add nodes to the list
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);

    // Print the list
    printf("Original List:\n");
    print_list(head);

    // Delete a node from the list
    delete_node(&head, 2);

    // Print the updated list
    printf("\nList after deleting node with data 2:\n");
    print_list(head);

    return 0;
}

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node at the end of the list
void add_node(Node** head, int data) {
    Node* new_node = create_node(data);
    Node* temp = *head;

    // If the list is empty, set the new node as the head
    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
        return;
    }

    // Traverse the list to find the end
    while (temp->next!= NULL)
        temp = temp->next;

    // Add the new node at the end
    temp->next = new_node;
    new_node->next = NULL;
}

// Function to delete a node with given data from the list
void delete_node(Node** head, int data) {
    Node* temp = *head;

    // If the list is empty, return
    if (*head == NULL)
        return;

    // If the head node has the given data, set the next node as the new head
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Traverse the list to find the node with the given data
    while (temp->next!= NULL && temp->next->data!= data)
        temp = temp->next;

    // If the node is not found, return
    if (temp->next == NULL)
        return;

    // Delete the node
    Node* del_node = temp->next;
    temp->next = temp->next->next;
    free(del_node);
}

// Function to print the list
void print_list(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}