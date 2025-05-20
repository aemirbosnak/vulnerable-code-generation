//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Structure to represent a node in a singly-linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to allocate memory for a node
struct Node* alloc_node(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to deallocate memory for a node
void free_node(struct Node** node_ptr) {
    if (*node_ptr != NULL) {
        free((*node_ptr)->next);
        free(*node_ptr);
        *node_ptr = NULL;
    }
}

// Function to create a singly-linked list
struct Node* create_list(int data[], int size) {
    struct Node* head = NULL;
    struct Node* current = NULL;
    int i;

    for (i = 0; i < size; i++) {
        current = alloc_node(data[i]);
        if (head == NULL) {
            head = current;
        } else {
            current->next = head;
            head = current;
        }
    }

    return head;
}

// Function to print the list
void print_list(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    struct Node* head = create_list(data, size);
    print_list(head);

    // Testing memory deallocation
    free_node(&head);

    return 0;
}