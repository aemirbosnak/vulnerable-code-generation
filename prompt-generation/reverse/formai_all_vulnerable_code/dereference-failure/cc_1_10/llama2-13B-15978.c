//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a node in a linked list
struct node {
    int data;
    struct node* next;
};

// Define a function to allocate memory for a node
struct node* alloc_node(int data) {
    struct node* node = malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Define a function to deallocate memory for a node
void free_node(struct node** node) {
    if (*node != NULL) {
        free((*node)->next);
        free(*node);
        *node = NULL;
    }
}

// Define a function to create a linked list
struct node* create_list(int* data, int count) {
    struct node* head = NULL;
    int i;

    for (i = 0; i < count; i++) {
        head = alloc_node(data[i]);
        head->next = create_list(data + i + 1, count - i);
    }

    return head;
}

// Define a function to traverse a linked list
void traverse_list(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int count = sizeof(data) / sizeof(data[0]);

    struct node* head = create_list(data, count);
    traverse_list(head);

    free_node(&head);

    return 0;
}