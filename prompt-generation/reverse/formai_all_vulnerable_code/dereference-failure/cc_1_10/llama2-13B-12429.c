//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a node in a linked list
struct node {
    int data;
    struct node* next;
};

// Function to allocate memory for a node
struct node* allocate_node(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to deallocate memory for a node
void deallocate_node(struct node** node_ptr) {
    if (*node_ptr != NULL) {
        free((*node_ptr)->next);
        free(*node_ptr);
        *node_ptr = NULL;
    }
}

// Function to create a linked list of integers
struct node* create_list(int* array, int size) {
    struct node* head = NULL;
    int i;

    for (i = 0; i < size; i++) {
        struct node* node = allocate_node(array[i]);
        if (head == NULL) {
            head = node;
        } else {
            head->next = node;
        }
        head = node;
    }

    return head;
}

// Function to print the linked list
void print_list(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);

    struct node* head = create_list(array, size);
    print_list(head);

    // Modify the list in place
    head->data = 10;
    head = head->next;
    head->data = 20;
    head = head->next;
    head->data = 30;

    print_list(head);

    // Deallocate the list
    deallocate_node(&head);

    return 0;
}