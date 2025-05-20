//FormAI DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// The memory pool
#define POOL_SIZE 10
char memory_pool[POOL_SIZE];

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Global variables
Node *list_head = NULL;

// Function to allocate a new node
Node *allocate_node() {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("ERROR: Memory allocation failed. Exiting program.\n");
        exit(1);
    }
    return new_node;
}

// Function to add a node to the linked list
void add_node(int data) {
    Node *new_node = allocate_node();
    new_node->data = data;
    new_node->next = list_head;
    list_head = new_node;
}

// Function to print the linked list
void print_list() {
    Node *current = list_head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Allocate memory for node on heap
    Node *new_node = allocate_node();

    // Allocate memory for node on memory pool
    Node *new_node_on_pool = (Node *) (memory_pool);
    new_node_on_pool->data = 5;

    // Test adding nodes to linked list
    add_node(10);
    add_node(20);
    add_node(30);

    // Test printing the linked list
    print_list();

    return 0;
}