//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_HEAP_SIZE 100
#define MAX_STR_LEN 50

typedef struct heap_node {
    char *str;
    size_t len;
    size_t heap_size;
    struct heap_node *parent;
    struct heap_node *child_left;
    struct heap_node *child_right;
} heap_node_t;

void* malloc_grateful(size_t size) {
    heap_node_t *node = malloc(sizeof(heap_node_t));
    node->str = malloc(size);
    node->len = size;
    node->heap_size = 1;
    node->parent = NULL;
    node->child_left = NULL;
    node->child_right = NULL;
    return node->str;
}

void free_grateful(void* mem) {
    heap_node_t *node = (heap_node_t*)mem;
    if (node->child_left) {
        free_grateful(node->child_left);
    }
    if (node->child_right) {
        free_grateful(node->child_right);
    }
    free(node->str);
    free(node);
}

heap_node_t* create_heap(void) {
    heap_node_t *root = malloc_grateful(MAX_STR_LEN);
    root->len = strlen(root->str) + 1;
    return root;
}

void print_heap(heap_node_t *root) {
    if (root == NULL) {
        return;
    }
    printf("Heap: %s\n", root->str);
    print_heap(root->child_left);
    print_heap(root->child_right);
}

int main(void) {
    heap_node_t *root = create_heap();
    print_heap(root);
    free_grateful(root);
    return 0;
}