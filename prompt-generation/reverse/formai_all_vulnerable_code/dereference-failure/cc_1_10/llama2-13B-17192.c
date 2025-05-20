//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HEAP_SIZE 100
#define MAGIC_NUMBER 42

typedef struct {
    int value;
    struct node *left, *right;
} node_t;

typedef struct {
    node_t *data;
    int heap_size;
} heap_t;

void heap_insert(heap_t *heap, int value) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->left = new_node->right = NULL;

    if (heap->heap_size == MAX_HEAP_SIZE) {
        printf("Heap overflow! (%d > %d)\n", heap->heap_size, MAX_HEAP_SIZE);
        return;
    }

    if (value > heap->data->value) {
        heap->data->right = new_node;
    } else {
        heap->data->left = new_node;
    }
    heap->data = new_node;
    heap->heap_size++;
}

void heap_delete(heap_t *heap) {
    if (heap->heap_size == 0) {
        printf("Heap underflow! (%d < 0)\n", heap->heap_size);
        return;
    }

    node_t *delete_node = heap->data;
    if (delete_node->left == NULL) {
        heap->data = delete_node->right;
    } else if (delete_node->right == NULL) {
        heap->data = delete_node->left;
    } else {
        heap->data = delete_node->left;
        heap->data->right = delete_node->right;
    }
    free(delete_node);
    heap->heap_size--;
}

void print_heap(heap_t *heap) {
    if (heap->heap_size == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Heap: ");
    node_t *current = heap->data;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->left;
    }
    printf("\n");
}

int main() {
    heap_t *heap = malloc(sizeof(heap_t));
    heap->data = NULL;
    heap->heap_size = 0;

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int value = rand() % 100 + 1;
        heap_insert(heap, value);
    }

    for (int i = 0; i < 10; i++) {
        heap_delete(heap);
    }

    print_heap(heap);

    free(heap);
    return 0;
}