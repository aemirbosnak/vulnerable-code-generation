//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HEAP_SIZE 1024
#define MAX_STRLEN 1024

typedef struct node {
    char *word;
    size_t len;
    struct node *parent;
    struct node *left;
    struct node *right;
} node_t;

typedef struct heap {
    node_t *root;
    size_t size;
} heap_t;

static inline void heap_insert(heap_t *h, node_t *n) {
    n->parent = NULL;
    n->left = NULL;
    n->right = NULL;
    if (h->size == MAX_HEAP_SIZE) {
        printf("Heap overflow! (%zu > %zu)\n", h->size, MAX_HEAP_SIZE);
        return;
    }
    if (h->root == NULL) {
        h->root = n;
    } else {
        node_t *curr = h->root;
        while (curr->left != NULL) {
            curr = curr->left;
        }
        curr->left = n;
        n->parent = curr;
    }
    h->size++;
}

static inline void heap_delete(heap_t *h, node_t *n) {
    if (h->size == 1) {
        printf("Heap underflow! (%zu < 1)\n", h->size);
        return;
    }
    if (n == h->root) {
        h->root = n->left;
        if (n->left != NULL) {
            n->left->parent = h->root;
        }
    } else {
        node_t *curr = h->root;
        while (curr->left != n) {
            curr = curr->left;
        }
        curr->right = n->left;
        if (n->left != NULL) {
            n->left->parent = curr;
        }
    }
    h->size--;
}

static inline void heap_sift_up(heap_t *h, node_t *n) {
    if (n->parent == NULL) {
        return;
    }
    if (n->parent->left == n) {
        node_t *ll = n->parent->left;
        if (ll->len > n->len) {
            n->parent->left = n;
            n->parent = ll->parent;
            ll->parent = n;
        }
    } else {
        node_t *rr = n->parent->right;
        if (rr->len > n->len) {
            n->parent->right = n;
            n->parent = rr->parent;
            rr->parent = n;
        }
    }
    heap_sift_up(h, n->parent);
}

static inline void heap_sort(heap_t *h) {
    while (h->size > 0) {
        node_t *n = h->root;
        heap_sift_up(h, n);
        heap_delete(h, n);
    }
}

int main() {
    heap_t h;
    h.root = NULL;
    h.size = 0;

    char *words[] = {"hello", "world", "genius", "programmer", "coder"};
    size_t word_len[] = {5, 4, 7, 9, 6};
    size_t i;

    for (i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
        node_t *n = (node_t *) malloc(sizeof(node_t));
        n->word = words[i];
        n->len = word_len[i];
        heap_insert(&h, n);
    }

    heap_sort(&h);

    while (h.root != NULL) {
        printf("%s (%zu)\n", h.root->word, h.root->len);
        heap_delete(&h, h.root);
    }

    return 0;
}