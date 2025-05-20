//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
Node* create_node(int data);
Node* insert_node(Node* head, int data);
Node* delete_node(Node* head, int data);
void print_list(Node* head);

int main() {
    Node* head = NULL;

    // Insert nodes into linked list
    head = insert_node(head, 1);
    head = insert_node(head, 2);
    head = insert_node(head, 3);
    head = insert_node(head, 4);

    // Print linked list
    print_list(head);

    // Delete node from linked list
    head = delete_node(head, 2);

    // Print linked list after deletion
    print_list(head);

    return 0;
}

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node with given data at the beginning of the list
Node* insert_node(Node* head, int data) {
    Node* new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Function to delete a node with given data from the list
Node* delete_node(Node* head, int data) {
    Node* temp = head;
    Node* prev = NULL;

    // If head node is to be deleted
    if (temp!= NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search for the node to be deleted
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    // If node not found in the list
    if (temp == NULL)
        return head;

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);

    return head;
}

// Function to print the linked list
void print_list(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}