//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_HEAP_SIZE 1024
#define MAX_STRLEN 1024

typedef struct heap_node {
    char *str;
    size_t len;
    struct heap_node *parent;
    struct heap_node *child;
} heap_node_t;

typedef struct heap {
    heap_node_t *root;
    size_t size;
} heap_t;

void init_heap(heap_t *h) {
    h->root = NULL;
    h->size = 0;
}

void insert_heap(heap_t *h, char *str) {
    heap_node_t *node = malloc(sizeof(heap_node_t));
    node->str = str;
    node->len = strlen(str);
    node->parent = NULL;
    node->child = NULL;

    if (h->size == 0) {
        h->root = node;
    } else {
        heap_node_t *last = h->root;
        while (last->child != NULL) {
            last = last->child;
        }
        last->child = node;
    }

    h->size++;
}

void delete_heap(heap_t *h) {
    if (h->size == 0) {
        return;
    }

    heap_node_t *node = h->root;
    h->root = node->child;
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
        printf("%s ", node->str);
        node = node->child;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    heap_t *h = malloc(sizeof(heap_t));
    init_heap(h);

    for (int i = 0; i < 10; i++) {
        char *str = malloc(rand() % MAX_STRLEN + 1);
        insert_heap(h, str);
    }

    print_heap(h);

    for (int i = 0; i < 10; i++) {
        delete_heap(h);
    }

    print_heap(h);

    free(h);
    return 0;
}