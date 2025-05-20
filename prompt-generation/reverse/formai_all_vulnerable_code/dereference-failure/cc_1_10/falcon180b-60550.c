//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for a linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to print a linked list
void print_list(Node* head) {
    while (head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to reverse a linked list
Node* reverse_list(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    Node* head = NULL;

    // Create a linked list with some nodes
    head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);
    head->next->next->next->next = create_node(5);

    // Print the original list
    printf("Original list:\n");
    print_list(head);

    // Reverse the list
    head = reverse_list(head);

    // Print the reversed list
    printf("Reversed list:\n");
    print_list(head);

    return 0;
}