//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_HEAP_SIZE 1024
#define MAX_NODE_SIZE 128

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef struct heap {
    node_t *root;
    int size;
} heap_t;

void init_heap(heap_t *h) {
    h->root = NULL;
    h->size = 0;
}

void insert_heap(heap_t *h, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (h->size == 0) {
        h->root = new_node;
    } else {
        node_t *current = h->root;
        while (current->left != NULL) {
            current = current->left;
        }
        current->left = new_node;
    }

    h->size++;
}

void delete_heap(heap_t *h) {
    if (h->size == 0) {
        return;
    }

    node_t *current = h->root;
    node_t *previous = NULL;

    while (current != NULL) {
        if (current->left == NULL) {
            break;
        }

        previous = current;
        current = current->left;
    }

    if (previous == NULL) {
        h->root = current->right;
    } else {
        previous->right = current->right;
    }

    free(current);
    h->size--;
}

void print_heap(heap_t *h) {
    if (h->size == 0) {
        printf("Heap is empty\n");
        return;
    }

    node_t *current = h->root;
    printf("Heap: ");

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->left;
    }

    printf("\n");
}

int main() {
    heap_t *h = malloc(sizeof(heap_t));
    init_heap(h);

    for (int i = 0; i < 10; i++) {
        insert_heap(h, i * 2);
    }

    print_heap(h);

    for (int i = 0; i < 10; i++) {
        delete_heap(h);
    }

    print_heap(h);

    free(h);
    return 0;
}