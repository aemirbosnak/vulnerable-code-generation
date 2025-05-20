//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Declare a struct to represent a node in the search graph
struct node {
    int data;
    struct node* next;
};

// Declare a function to create a new node
struct node* new_node(int data) {
    struct node* node = malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Declare a function to search for a node with a given data value
struct node* search(struct node* head, int data) {
    struct node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Declare a function to perform a depth-first search
struct node* dfs(struct node* head, int data) {
    struct node* current = head;
    struct node* previous = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                printf("Found the node with value %d\n", data);
            } else {
                printf("Found the node with value %d, previous node was %d\n", data, previous->data);
            }
            return current;
        }
        previous = current;
        current = current->next;
    }
    return NULL;
}

int main() {
    // Create a list of nodes
    struct node* head = NULL;
    head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(4);

    // Perform a depth-first search
    struct node* result = dfs(head, 4);
    if (result != NULL) {
        printf("Found the node with value %d\n", result->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}