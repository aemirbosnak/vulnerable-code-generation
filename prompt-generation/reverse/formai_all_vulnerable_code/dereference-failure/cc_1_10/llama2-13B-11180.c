//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE 1024
#define MAX_STR_LEN 256

typedef struct heap_node {
    char *str;
    size_t len;
    size_t size;
    struct heap_node *parent;
    struct heap_node *left;
    struct heap_node *right;
} heap_node_t;

typedef struct heap {
    heap_node_t *root;
    size_t count;
} heap_t;

void init_heap(heap_t *h) {
    h->root = NULL;
    h->count = 0;
}

void insert_str(heap_t *h, char *str) {
    heap_node_t *node = malloc(sizeof(heap_node_t));
    node->str = str;
    node->len = strlen(str);
    node->size = node->len + 1;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    if (h->count == 0) {
        h->root = node;
    } else {
        heap_node_t *last = h->root;
        while (last->left != NULL) {
            last = last->left;
        }
        last->left = node;
        node->parent = last;
    }
    h->count++;
}

void delete_str(heap_t *h, char *str) {
    heap_node_t *node = NULL;
    heap_node_t *last = NULL;
    for (int i = 0; i < h->count; i++) {
        if (h->root->str == str) {
            node = h->root;
            break;
        }
        last = h->root;
        h->root = h->root->left;
    }
    if (node != NULL) {
        if (node->left == NULL) {
            last->right = node->right;
        } else {
            last->left = node->left;
        }
        free(node);
        h->count--;
    }
}

void print_heap(heap_t *h) {
    for (int i = 0; i < h->count; i++) {
        printf("%s (%zu)\n", h->root->str, h->root->size);
        h->root = h->root->left;
    }
}

int main() {
    heap_t *h = malloc(sizeof(heap_t));
    init_heap(h);

    char *str1 = "Hello";
    char *str2 = "World";
    char *str3 = "C++";

    insert_str(h, str1);
    insert_str(h, str2);
    insert_str(h, str3);

    print_heap(h);

    delete_str(h, str2);

    print_heap(h);

    return 0;
}