//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in a singly-linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to allocate memory for a node
Node* allocate_node(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to deallocate memory for a node
void deallocate_node(Node* node) {
    free(node);
}

// Function to create a singly-linked list
Node* create_list(int* data, int size) {
    Node* head = NULL;
    for (int i = 0; i < size; i++) {
        head = allocate_node(data[i]);
        head->next = allocate_node(data[i + 1]);
    }
    return head;
}

// Function to traverse a singly-linked list
void traverse_list(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    // Create a singly-linked list
    Node* head = create_list(data, size);

    // Traverse the list
    traverse_list(head);

    // Deallocate memory for the list
    deallocate_node(head);

    return 0;
}