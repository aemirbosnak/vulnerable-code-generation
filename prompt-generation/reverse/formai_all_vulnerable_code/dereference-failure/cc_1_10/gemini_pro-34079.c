//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom memory manager
void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    if (ptr != NULL) free(ptr);
}

// Create a linked list of integers
struct node {
    int data;
    struct node *next;
};

struct node *create_list(int n) {
    struct node *head = NULL;
    for (int i = 0; i < n; i++) {
        struct node *new_node = my_malloc(sizeof(struct node));
        new_node->data = i;
        new_node->next = head;
        head = new_node;
    }
    return head;
}

// Print the linked list
void print_list(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Free the linked list
void free_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        struct node *next = current->next;
        my_free(current);
        current = next;
    }
}

// Main function
int main(void) {
    // Create a linked list of 10 integers
    struct node *head = create_list(10);

    // Print the linked list
    print_list(head);

    // Free the linked list
    free_list(head);

    return 0;
}