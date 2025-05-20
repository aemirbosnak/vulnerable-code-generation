//FormAI DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY_SIZE 1024  // Maximum memory size in bytes.
#define MIN_BLOCK_SIZE 16     // Minimum block size in bytes.

typedef struct node_t {
    size_t size;             // Total size of the block in bytes.
    struct node_t *prev;     // Previous node.
    struct node_t *next;     // Next node.
    int used;                // 1 if block is currently in use, 0 otherwise.
} node;

node *head = NULL;           // Head of the linked list.

// Function to split a block of memory into two smaller blocks.
void split(node *n, size_t size) {
    node *new_node = (node *)((char *)n + size);
    new_node->size = n->size - size - sizeof(node);
    new_node->prev = n;
    new_node->next = n->next;
    new_node->used = 0;
    
    if (n->next != NULL) {
        n->next->prev = new_node;
    }
    
    n->size = size;
    n->next = new_node;
}

// Function to merge a block with its previous block.
void merge_prev(node *n) {
    if (n->prev != NULL && !(n->prev->used)) {
        n->prev->size += n->size + sizeof(node);
        n->prev->next = n->next;
        
        if (n->next != NULL) {
            n->next->prev = n->prev;
        }
        
        n = n->prev;
    }
}

// Function to merge a block with its next block.
void merge_next(node *n) {
    if (n->next != NULL && !(n->next->used)) {
        n->size += n->next->size + sizeof(node);
        n->next = n->next->next;
        
        if (n->next != NULL) {
            n->next->prev = n;
        }
    }
}

// Function to allocate memory from the linked list.
void *my_alloc(size_t size) {
    if (head == NULL) {
        node *new_node = (node *)malloc(size + sizeof(node));
        if (new_node == NULL) {
            return NULL;
        }
        new_node->size = size;
        new_node->prev = NULL;
        new_node->next = NULL;
        new_node->used = 1;
        head = new_node;
        return (void *)((char *)new_node + sizeof(node));
    }
    
    node *n = head;
    while (n != NULL) {
        if (!(n->used) && (n->size >= size)) {
            if (n->size >= size + MIN_BLOCK_SIZE + sizeof(node)) {
                split(n, size);
            }
            n->used = 1;
            return (void *)((char *)n + sizeof(node));
        }
        n = n->next;
    }
    
    node *new_node = (node *)malloc(size + sizeof(node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->size = size;
    new_node->prev = head;
    new_node->next = NULL;
    new_node->used = 1;
    head->next = new_node;
    head = new_node;
    return (void *)((char *)new_node + sizeof(node));
}

// Function to deallocate memory in the linked list.
void my_free(void *ptr) {
    if (ptr == NULL) {
        return;
    }
    
    node *n = (node *)((char *)ptr - sizeof(node));
    n->used = 0;
    merge_prev(n);
    merge_next(n);
    
    if (n->prev == NULL && n->next == NULL) {
        head = NULL;
        free(n);
    } else if (n->prev == NULL) {
        head = n->next;
        n->next->prev = NULL;
        free(n);
    } else if (n->next == NULL) {
        n->prev->next = NULL;
        free(n);
    } else {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        free(n);
    }
}

int main() {
    int *arr = my_alloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    printf("Array contents:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    double *d = my_alloc(sizeof(double));
    *d = 3.14159;
    printf("Double value: %f\n\n", *d);
    
    my_free(arr);
    my_free(d);
    
    return 0;
}