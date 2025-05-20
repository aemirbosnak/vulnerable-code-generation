//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a node in a linked list
struct node {
    int data;
    struct node *next;
};

// Function to allocate memory for a node
struct node* alloc_node(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to deallocate memory for a node
void free_node(struct node* node) {
    free(node);
}

// Function to create a linked list of integers
struct node* create_list(int* arr, int len) {
    struct node* head = NULL;
    for (int i = 0; i < len; i++) {
        head = alloc_node(arr[i]);
        head->next = alloc_node(arr[i + 1]);
        head = head->next;
    }
    head->next = NULL;
    return head;
}

// Function to traverse the linked list
void traverse(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    struct node* head = create_list(arr, len);
    traverse(head);

    // Allocate memory for a new node
    struct node* new_node = alloc_node(7);

    // Append the new node to the end of the list
    head->next = new_node;
    head = new_node;

    // Traverse the list again
    traverse(head);

    // Deallocate memory for the list
    free_node(head);

    return 0;
}