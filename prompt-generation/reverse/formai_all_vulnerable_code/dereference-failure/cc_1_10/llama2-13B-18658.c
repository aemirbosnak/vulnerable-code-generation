//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE 1024
#define MAX_STR_LEN 100

typedef struct heap_node {
    char *str;
    size_t len;
    struct heap_node *parent;
    struct heap_node *left;
    struct heap_node *right;
} heap_node_t;

typedef struct heap {
    heap_node_t *root;
    size_t size;
} heap_t;

void init_heap(heap_t *h);
void insert_heap(heap_t *h, char *str, size_t len);
void delete_heap(heap_t *h, size_t index);
void print_heap(heap_t *h);

heap_t *create_heap(void);

int main() {
    heap_t *h = create_heap();

    char *str1 = "Hello, world!";
    size_t len1 = strlen(str1);
    insert_heap(h, str1, len1);

    char *str2 = "Grateful programming";
    size_t len2 = strlen(str2);
    insert_heap(h, str2, len2);

    delete_heap(h, 1);

    print_heap(h);

    return 0;
}

heap_t *create_heap() {
    heap_t *h = (heap_t *)calloc(1, sizeof(heap_t));
    h->root = NULL;
    h->size = 0;
    return h;
}

void init_heap(heap_t *h) {
    h->root = NULL;
    h->size = 0;
}

void insert_heap(heap_t *h, char *str, size_t len) {
    heap_node_t *node = (heap_node_t *)calloc(1, sizeof(heap_node_t));
    node->str = str;
    node->len = len;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;

    if (h->size == 0) {
        h->root = node;
    } else {
        heap_node_t *current = h->root;
        while (current->left != NULL) {
            current = current->left;
        }
        current->left = node;
    }

    h->size++;
}

void delete_heap(heap_t *h, size_t index) {
    if (h->size == 0) {
        return;
    }

    heap_node_t *node = h->root;
    heap_node_t *parent = NULL;

    while (node->left != NULL) {
        parent = node;
        node = node->left;
    }

    if (index == 0) {
        h->root = node->right;
    } else if (index == h->size - 1) {
        h->root = node->left;
    } else {
        parent->left = node->right;
    }

    free(node);
    h->size--;
}

void print_heap(heap_t *h) {
    if (h->size == 0) {
        printf("Heap is empty\n");
        return;
    }

    heap_node_t *node = h->root;
    printf("Heap: ");

    while (node != NULL) {
        printf("%s%s", node->str, node->left != NULL ? "->" : "");
        node = node->left;
    }

    printf("\n");
}