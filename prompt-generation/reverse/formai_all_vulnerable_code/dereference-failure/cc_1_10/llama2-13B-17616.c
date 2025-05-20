//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE 1024
#define MAX_STRLEN 1024

typedef struct heap_node {
    char *str;
    size_t len;
    struct heap_node *parent;
    struct heap_node *child_left;
    struct heap_node *child_right;
} heap_node_t;

typedef struct heap {
    heap_node_t *root;
    size_t heap_size;
} heap_t;

void init_heap(heap_t *heap) {
    heap->root = NULL;
    heap->heap_size = 0;
}

heap_node_t *insert_node(heap_t *heap, char *str) {
    heap_node_t *new_node = malloc(sizeof(heap_node_t));
    new_node->str = str;
    new_node->len = strlen(str);
    new_node->parent = NULL;
    new_node->child_left = NULL;
    new_node->child_right = NULL;

    if (heap->heap_size == 0) {
        heap->root = new_node;
    } else {
        int index = 0;
        heap_node_t *current = heap->root;
        while (index < heap->heap_size && strcmp(current->str, new_node->str) > 0) {
            index++;
            current = current->child_left;
        }
        new_node->parent = current;
        if (index == heap->heap_size) {
            heap->root = new_node;
        } else {
            if (strcmp(current->str, new_node->str) > 0) {
                current->child_left = new_node;
            } else {
                current->child_right = new_node;
            }
        }
    }
    heap->heap_size++;
    return new_node;
}

void print_heap(heap_t *heap) {
    heap_node_t *current = heap->root;
    while (current != NULL) {
        printf("%s\n", current->str);
        current = current->parent;
    }
}

int main() {
    heap_t *heap = malloc(sizeof(heap_t));
    init_heap(heap);

    char *strings[] = {
        "hello",
        "world",
        "abc",
        "def",
        "ghi"
    };

    for (int i = 0; i < sizeof(strings) / sizeof(strings[0]); i++) {
        insert_node(heap, strings[i]);
    }

    print_heap(heap);

    return 0;
}